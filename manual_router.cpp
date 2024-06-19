#include "manual_router.h"

void ManualRouter::addRoutingEntry(const Address &destination, Link *nextLink) {
    // 라우팅 엔트리를 추가한다.
    routingTable_.push_back({destination, nextLink});
}