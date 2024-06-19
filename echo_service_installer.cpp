#include "echo_service_installer.h"

EchoService *EchoServiceInstaller::install(Host *host) {
  return new EchoService(host, listenPort_);
}