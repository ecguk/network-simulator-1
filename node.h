#ifndef NODE_H
#define NODE_H

#include <cstdlib> // rand()
#include <iostream>
#include <vector>
#include "packet.h"
#include "link.h" // Link 클래스 포함

class Node {
protected:
    static int idCounter_;
    int id_;
    std::vector<Link *> links_; // 링크를 저장할 벡터 추가

public:
    Node() : id_(++idCounter_) {}

    int id() const { return id_; }

    virtual void send(Packet *packet);
    virtual void receive(Packet *packet);

    // 링크 관리 함수들
    void addLink(Link *link) { links_.push_back(link); }
    const std::vector<Link *> &links() const { return links_; }
};

#endif