#include "message_service_installer.h"

MessageService *MessageServiceInstaller::install(Host *host) {
    // MessageService 인스턴스 생성 및 초기화
    MessageService *messageService = new MessageService(host, destPort_, destAddress_, destPort_);

    // 서비스 설치
    ServiceInstaller::install(host, messageService);

    return messageService;
}