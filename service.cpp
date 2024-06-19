#include "service.h"
#include "host.h"
#include "packet.h"

// 기본 생성자와 소멸자 추가 (필요시)
Service::Service(Host *host, int port) : host_(host), port_(port) {}

Service::~Service() {}