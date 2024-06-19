#include "packet.h"

// ��Ŷ ������ - ���ڿ� �����͸� �޾Ƽ� ���ͷ� ��ȯ
Packet::Packet(Address srcAddress, Address destAddress, short srcPort, short destPort, std::string data)
    : srcAddress_(srcAddress), destAddress_(destAddress), srcPort_(srcPort), destPort_(destPort) {
    for (size_t i = 0; i < data.size(); i++) {
        data_.push_back(data[i]);
    }
}

// ��Ŷ ������ - ���� �����͸� ���� �޾Ƽ� �ʱ�ȭ
Packet::Packet(Address srcAddress, Address destAddress, short srcPort, short destPort, std::vector<char> data)
    : srcAddress_(srcAddress), destAddress_(destAddress), srcPort_(srcPort), destPort_(destPort), data_(data) {}

// ������ �ּҸ� ��ȯ�ϴ� �Լ�
Address Packet::srcAddress() {
    return srcAddress_;
}

// ������ �ּҸ� ��ȯ�ϴ� �Լ�
Address Packet::destAddress() {
    return destAddress_;
}

// ������ ��Ʈ�� ��ȯ�ϴ� �Լ�
short Packet::srcPort() {
    return srcPort_;
}

// ������ ��Ʈ�� ��ȯ�ϴ� �Լ�
short Packet::destPort() {
    return destPort_;
}

// ��Ŷ �����͸� ��ȯ�ϴ� �Լ�
const std::vector<char>& Packet::data() {
    return data_;
}

// ��Ŷ �����͸� ���ڿ��� ��ȯ�ϴ� �Լ�
std::string Packet::dataString() {
    std::string str;
    for (size_t i = 0; i < data_.size(); i++) {
        str += data_[i];
    }
    return str;
}