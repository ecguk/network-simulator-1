#ifndef SERVICE_INSTALLER_H
#define SERVICE_INSTALLER_H

#include "host.h"
#include "service.h"

// ���񽺸� ��ġ�ϴ� ����
class ServiceInstaller {
protected:
  // ȣ��Ʈ�� ���� ������ ���踦 �����Ѵ�.
  void install(Host *host, Service *service);
};

#endif