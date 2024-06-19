#include "host.h"
#include <cstdlib> // for rand()
#include <iostream>

void Host::initialize() {
    // 호스트 초기화 코드
    services_.clear(); // 서비스 목록 초기화
    links_.clear();    // 링크 목록 초기화
}

void Host::send(Packet *packet) {
    if (!links_.empty()) {
        // 랜덤으로 링크 선택
        int index = rand() % links_.size();
        links_[index]->transmit(this, packet);
        std::cout << "Host #" << id_ << ": sending packet (from: " 
                  << packet->srcAddress().toString() << ", to: " 
                  << packet->destAddress().toString() << ", " 
                  << packet->data().size() << " bytes)" << std::endl;
    }
}