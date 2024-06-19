#ifndef ECHO_SERVICE_INSTALLER_H
#define ECHO_SERVICE_INSTALLER_H

#include "address.h"
#include "echo_service.h"
#include "service_installer.h"

class EchoServiceInstaller : public ServiceInstaller {
private:
  // ��Ŷ�� ������ ��Ʈ
  short listenPort_;

public:
  EchoServiceInstaller(short listenPort) : listenPort_(listenPort) {}

  // ȣ��Ʈ�� EchoService�� ��ġ�Ѵ�.
  EchoService *install(Host *host);
};

#endif