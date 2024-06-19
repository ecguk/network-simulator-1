#include "link.h"
#include "node.h"
#include <iostream>

// 매개변수로 주어진 노드가 아닌 반대편 노드를 구한다.
Node *Link::other(const Node *node) const {
    return node == nodeA_ ? nodeB_ : nodeA_;
}

// Link 클래스를 통해 패킷을 전송하는 함수
void Link::transmit(Node *from, Packet *packet) {
    Node *to = other(from);
    std::cout << "Link: forwarding packet from node #" << from->id() 
              << ", to node #" << to->id() << std::endl;
    to->receive(packet); // 노드의 receive 함수 호출
}