#ifndef SERVICE_H
#define SERVICE_H

#include "node.h"

class Host;

class Service {
  friend class ServiceInstaller;

protected:
  // ���񽺰� ��ġ�� ȣ��Ʈ
  Host *host_;

  // ���񽺰� ����ϴ� ��Ʈ
  short port_;

  Service(Host *host, int port) : host_(host), port_(port) {}
};

#endif