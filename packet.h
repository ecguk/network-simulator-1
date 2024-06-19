#ifndef PACKET_H
#define PACKET_H

#include "address.h"
#include <string>
#include <vector>

class Packet {
public:
  Packet(Address srcAddress, Address destAddress, short srcPort, short destPort,
         std::string data)
      : srcAddress_(srcAddress), destAddress_(destAddress), srcPort_(srcPort),
        destPort_(destPort) {
    for (size_t i = 0; i < data.size(); i++) {
      data_.push_back(data[i]);
    }
  }

  Packet(Address srcAddress, Address destAddress, short srcPort, short destPort,
         std::vector<char> data)
      : srcAddress_(srcAddress), destAddress_(destAddress), srcPort_(srcPort),
        destPort_(destPort), data_(data) {}

  // ������ �ּ�
  Address srcAddress() { return srcAddress_; }

  // ������ �ּ�
  Address destAddress() { return destAddress_; }

  // ������ ��Ʈ
  short srcPort() { return srcPort_; }

  // ������ ��Ʈ
  short destPort() { return destPort_; }

  // ��Ŷ ������
  const std::vector<char> &data() { return data_; }

  // ��Ŷ �����͸� ���ڿ��� ��ȯ�Ѵ�
  std::string dataString() {
    std::string str;
    for (size_t i = 0; i < data_.size(); i++) {
      str += data_[i];
    }
    return str;
  }

private:
  Address srcAddress_;
  Address destAddress_;
  short srcPort_;
  short destPort_;
  std::vector<char> data_;
};

#endif