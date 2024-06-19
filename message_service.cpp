#include "message_service.h"

void MessageService::send(std::string message) {
    // 패킷 생성
    Packet packet(host_->address(), destAddress_, port_, destPort_, message);

    // 패킷 전송
    host_->send(&packet);

    std::cout << "MessageService: sent message \"" << message << "\""
              << " to " << destAddress_.toString() << ":" << destPort_ << std::endl;
}