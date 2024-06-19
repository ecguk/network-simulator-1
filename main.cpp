#include "host.h"
#include "router.h"
#include "manual_router.h"
#include "link_installer.h"
#include "message_service_installer.h"
#include "echo_service_installer.h"
#include <vector>

#define ECHO_PORT 3000

int main() {
    // first.cpp 시나리오
    {
        std::cout << "First Scenario:" << std::endl;

        // 호스트, 라우터, 링크 설정
        Host *echoServer = new Host(1);
        Host *messageClient = new Host(0);

        EchoServiceInstaller echoServiceInstaller(ECHO_PORT);
        echoServiceInstaller.install(echoServer);

        MessageServiceInstaller messageServiceInstaller(echoServer->address(), ECHO_PORT);
        MessageService *messageService = messageServiceInstaller.install(messageClient);

        std::vector<ManualRouter *> routers;
        for (int i = 0; i < 4; i++) {
            routers.push_back(new ManualRouter());
        }

        LinkInstaller linkInstaller;
        std::vector<Link *> links;
        links.push_back(linkInstaller.install(routers[0], echoServer));    // 0
        links.push_back(linkInstaller.install(routers[0], routers[1]));    // 1
        links.push_back(linkInstaller.install(routers[0], routers[2]));    // 2
        links.push_back(linkInstaller.install(routers[1], routers[3]));    // 3
        links.push_back(linkInstaller.install(routers[2], routers[3]));    // 4
        links.push_back(linkInstaller.install(routers[3], messageClient)); // 5

        routers[0]->addRoutingEntry(echoServer->address(), links[0]);
        routers[0]->addRoutingEntry(messageClient->address(), links[1]);
        routers[0]->addRoutingEntry(messageClient->address(), links[2]);

        routers[1]->addRoutingEntry(echoServer->address(), links[1]);
        routers[1]->addRoutingEntry(messageClient->address(), links[3]);

        routers[2]->addRoutingEntry(echoServer->address(), links[2]);
        routers[2]->addRoutingEntry(messageClient->address(), links[4]);

        routers[3]->addRoutingEntry(echoServer->address(), links[3]);
        routers[3]->addRoutingEntry(echoServer->address(), links[4]);
        routers[3]->addRoutingEntry(messageClient->address(), links[5]);

        echoServer->initialize();
        messageClient->initialize();

        messageService->send("Hello, world!");
        messageService->send("Bye, world!");

        // 메모리 해제
        for (size_t i = 0; i < links.size(); i++) {
            delete links[i];
        }

        for (size_t i = 0; i < routers.size(); i++) {
            delete routers[i];
        }

        delete echoServer;
        delete messageClient;
    }

    // second.cpp 시나리오
    {
        std::cout << "Second Scenario:" << std::endl;

        std::vector<Host *> servers;
        std::vector<Host *> clients;

        for (int i = 0; i < 3; i++) {
            servers.push_back(new Host(123 + i));
            clients.push_back(new Host(456 + i));
        }

        EchoServiceInstaller echoServiceInstaller(ECHO_PORT);
        for (int i = 0; i < 3; i++) {
            echoServiceInstaller.install(servers[i]);
        }

        std::vector<MessageServiceInstaller> messageServiceInstallers = {
            MessageServiceInstaller(servers[0]->address(), ECHO_PORT),
            MessageServiceInstaller(servers[1]->address(), ECHO_PORT),
            MessageServiceInstaller(servers[2]->address(), ECHO_PORT),
            // Invalid address
            MessageServiceInstaller(0, ECHO_PORT),
            // Invalid port
            MessageServiceInstaller(servers[0]->address(), 0),
        };

        std::vector<MessageService *> messageServices;

        for (size_t i = 0; i < messageServiceInstallers.size(); i++) {
            for (int j = 0; j < 3; j++) {
                messageServices.push_back(
                    messageServiceInstallers[i].install(clients[j]));
            }
        }

        ManualRouter *router = new ManualRouter();

        LinkInstaller linkInstaller;
        std::vector<Link *> clientLinks;
        std::vector<Link *> serverLinks;

        for (int i = 0; i < 3; i++) {
            clientLinks.push_back(linkInstaller.install(router, clients[i]));
            serverLinks.push_back(linkInstaller.install(router, servers[i]));
        }

        for (int i = 0; i < 3; i++) {
            router->addRoutingEntry(servers[i]->address(), serverLinks[i]);
            router->addRoutingEntry(clients[i]->address(), clientLinks[i]);
        }

        for (int i = 0; i < 3; i++) {
            clients[i]->initialize();
            servers[i]->initialize();
        }

        for (int x = 0; x < 3; x++) {
            for (size_t i = 0; i < messageServices.size(); i++) {
                messageServices[i]->send("Hello " + std::to_string(x));
            }
        }

        delete router;

        for (int i = 0; i < 3; i++) {
            delete servers[i];
            delete clients[i];
            delete serverLinks[i];
            delete clientLinks[i];
        }
    }

    return 0;
}