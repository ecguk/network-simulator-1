#include "message_service_installer.h"

MessageService *MessageServiceInstaller::install(Host *host) {
    // MessageService �ν��Ͻ� ���� �� �ʱ�ȭ
    MessageService *messageService = new MessageService(host, destPort_, destAddress_, destPort_);

    // ���� ��ġ
    ServiceInstaller::install(host, messageService);

    return messageService;
}