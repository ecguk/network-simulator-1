#include "service.h"
#include "host.h"
#include "packet.h"

// �⺻ �����ڿ� �Ҹ��� �߰� (�ʿ��)
Service::Service(Host *host, int port) : host_(host), port_(port) {}

Service::~Service() {}