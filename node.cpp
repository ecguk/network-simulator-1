#include "node.h"
#include "packet.h"
#include "link.h"
#include "host.h"

int Node::idCounter_ = 0;

void Node::send(Packet* packet) {
    // �⺻ ����: ������ ��ũ�� ��Ŷ�� ����
    if (!links_.empty()) {
        int index = rand() % links_.size();
        links_[index]->transmit(this, packet);
        std::cout << "Node #" << id_ << ": sending packet (from: " 
                  << packet->srcAddress().toString() << ", to: " 
                  << packet->destAddress().toString() << ", " 
                  << packet->data().size() << " bytes)" << std::endl;
    }
}

void Node::receive(Packet* packet) {
    std::cout << "Node #" << id_ << ": received packet, destination port: " 
              << packet->destPort() << std::endl;
}