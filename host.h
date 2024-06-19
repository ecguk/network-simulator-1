#ifndef HOST_H
#define HOST_H

#include "address.h"
#include "packet.h"
#include "service.h"
#include "link.h"
#include "node.h"
#include <vector>

class Host : public Node {
    friend class ServiceInstaller;

private:
    Address address_;
    std::vector<Service *> services_;
    std::vector<Link *> links_;

public:
    Address address() const { return address_; }
    Host(Address address) : Node(), address_(address) {}

    void initialize();
    void send(Packet *packet);

    void addLink(Link *link) { links_.push_back(link); }
    const std::vector<Link *> &links() const { return links_; }

    int nodeId() const { return id(); } // Node 클래스의 id() 함수 사용
};

#endif