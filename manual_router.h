#ifndef MANUAL_ROUTER_H
#define MANUAL_ROUTER_H

#include "address.h"
#include "router.h"

class ManualRouter : public Router {

public:
  // ������ �ּҿ� ���� ���� ��ũ�� �����Ѵ�.
  void addRoutingEntry(const Address &destination, Link *nextLink);
};

#endif