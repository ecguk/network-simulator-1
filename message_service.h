#ifndef MESSAGE_SERVICE_H
#define MESSAGE_SERVICE_H

#include "address.h"
#include "host.h"
#include "service.h"
#include <iostream>

// send �Լ��� ȣ���Ͽ� �޽����� ������ �� �ִ� ����
class MessageService : public Service {
  friend class MessageServiceInstaller;

private:
  // ������ �ּ�
  Address destAddress_;
  // ������ ��Ʈ
  short destPort_;
  MessageService(Host *host, short port, Address destAddress, short destPort)
      : Service(host, port), destAddress_(destAddress), destPort_(destPort) {}

public:
  // �޽����� �����Ѵ�
  void send(std::string message);
};

#endif