#include "link_installer.h"
#include "link.h"

Link *LinkInstaller::install(Node *a, Node *b) {
    return new Link(a, b);
}