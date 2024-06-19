#include "link.h"
#include "node.h"
#include <iostream>

// �Ű������� �־��� ��尡 �ƴ� �ݴ��� ��带 ���Ѵ�.
Node *Link::other(const Node *node) const {
    return node == nodeA_ ? nodeB_ : nodeA_;
}

// Link Ŭ������ ���� ��Ŷ�� �����ϴ� �Լ�
void Link::transmit(Node *from, Packet *packet) {
    Node *to = other(from);
    std::cout << "Link: forwarding packet from node #" << from->id() 
              << ", to node #" << to->id() << std::endl;
    to->receive(packet); // ����� receive �Լ� ȣ��
}