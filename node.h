#ifndef NODE_H
#define NODE_H

#include <cstdlib> // rand()
#include <iostream>
#include <vector>
#include "packet.h"
#include "link.h" // Link Ŭ���� ����

class Node {
protected:
    static int idCounter_;
    int id_;
    std::vector<Link *> links_; // ��ũ�� ������ ���� �߰�

public:
    Node() : id_(++idCounter_) {}

    int id() const { return id_; }

    virtual void send(Packet *packet);
    virtual void receive(Packet *packet);

    // ��ũ ���� �Լ���
    void addLink(Link *link) { links_.push_back(link); }
    const std::vector<Link *> &links() const { return links_; }
};

#endif