#ifndef PING_SERVICE_INSTALLER_H
#define PING_SERVICE_INSTALLER_H

#include "address.h"
#include "message_service.h"
#include "service_installer.h"

class MessageServiceInstaller : public ServiceInstaller {
private:
  // ������ �ּ�
  Address destAddress_;
  // ������ ��Ʈ
  short destPort_;

public:
  MessageServiceInstaller(const Address &destAddress, short destPort)
      : destAddress_(destAddress), destPort_(destPort) {}

  // ȣ��Ʈ�� MessageService�� ��ġ�Ѵ�
  MessageService *install(Host *host);
};

#endif