#ifndef IP_H
#define IP_H

#include <string>

// �ּҸ� ��Ÿ���� Ŭ����
class Address {
private:
  int address_;

public:
  Address(int address) : address_(address) {}
  std::string toString() const { return std::to_string(address_); }
  bool operator==(const Address &rhs) const { return address_ == rhs.address_; }
};

#endif