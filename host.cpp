#include "host.h"
#include <cstdlib> // for rand()
#include <iostream>

void Host::initialize() {
    // ȣ��Ʈ �ʱ�ȭ �ڵ�
    services_.clear(); // ���� ��� �ʱ�ȭ
    links_.clear();    // ��ũ ��� �ʱ�ȭ
}

void Host::send(Packet *packet) {
    if (!links_.empty()) {
        // �������� ��ũ ����
        int index = rand() % links_.size();
        links_[index]->transmit(this, packet);
        std::cout << "Host #" << id_ << ": sending packet (from: " 
                  << packet->srcAddress().toString() << ", to: " 
                  << packet->destAddress().toString() << ", " 
                  << packet->data().size() << " bytes)" << std::endl;
    }
}