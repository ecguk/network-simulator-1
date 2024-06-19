#include "message_service.h"

void MessageService::send(std::string message) {
    // ��Ŷ ����
    Packet packet(host_->address(), destAddress_, port_, destPort_, message);

    // ��Ŷ ����
    host_->send(&packet);

    std::cout << "MessageService: sent message \"" << message << "\""
              << " to " << destAddress_.toString() << ":" << destPort_ << std::endl;
}