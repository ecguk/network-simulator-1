#include "../echo_service.h"
#include "../echo_service_installer.h"
#include "../host.h"
#include "../link_installer.h"
#include "../manual_router.h"
#include "../message_service_installer.h"
#include <vector>

#define ECHO_PORT 3000

int main() {
  // ---------- //
  // �������� ���� //
  // ---------- //

  // ȣ��Ʈ�� �����Ѵ�
  Host *echoServer = new Host(1);
  Host *messageClient = new Host(0);

  // ���񽺸� ��ġ�Ѵ�
  EchoServiceInstaller echoServiceInstaller(ECHO_PORT);
  echoServiceInstaller.install(echoServer);
  MessageServiceInstaller messageServiceInstaller(echoServer->address(),
                                                  ECHO_PORT);
  MessageService *messageService =
      messageServiceInstaller.install(messageClient);

  // ����͸� �����Ѵ�.
  std::vector<ManualRouter *> routers;
  for (int i = 0; i < 4; i++) {
    routers.push_back(new ManualRouter());
  }

  // ����Ϳ� ȣ��Ʈ ���� ��ũ�� �����Ѵ�.
  LinkInstaller linkInstaller;
  std::vector<Link *> links;
  links.push_back(linkInstaller.install(routers[0], echoServer));    // 0
  links.push_back(linkInstaller.install(routers[0], routers[1]));    // 1
  links.push_back(linkInstaller.install(routers[0], routers[2]));    // 2
  links.push_back(linkInstaller.install(routers[1], routers[3]));    // 3
  links.push_back(linkInstaller.install(routers[2], routers[3]));    // 4
  links.push_back(linkInstaller.install(routers[3], messageClient)); // 5

  // ����� ���̺��� �����Ѵ�.
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

  // ���������� ���� �׸��� ����:
  //
  //   echoServer
  //       |
  //     router0
  //      /   |
  // router1  router2
  //      \   |
  //     router3
  //       |
  //  messageClient

  // ------------ //
  // �ùķ��̼� ���� //
  // ------------ //

  // �� ȣ��Ʈ�� �ʱ�ȭ�Ѵ�.
  echoServer->initialize();
  messageClient->initialize();

  // �޽����� �����Ѵ�.
  messageService->send("Hello, world!");
  messageService->send("Bye, world!");

  // --- //
  // ���� //
  // --- //

  // ������ ��ü�� �����Ѵ�.
  for (size_t i = 0; i < links.size(); i++) {
    delete links[i];
  }

  for (size_t i = 0; i < routers.size(); i++) {
    delete routers[i];
  }

  delete echoServer;
  delete messageClient;
}