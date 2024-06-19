#include "packet.h"

// 패킷 생성자 - 문자열 데이터를 받아서 벡터로 변환
Packet::Packet(Address srcAddress, Address destAddress, short srcPort, short destPort, std::string data)
    : srcAddress_(srcAddress), destAddress_(destAddress), srcPort_(srcPort), destPort_(destPort) {
    for (size_t i = 0; i < data.size(); i++) {
        data_.push_back(data[i]);
    }
}

// 패킷 생성자 - 벡터 데이터를 직접 받아서 초기화
Packet::Packet(Address srcAddress, Address destAddress, short srcPort, short destPort, std::vector<char> data)
    : srcAddress_(srcAddress), destAddress_(destAddress), srcPort_(srcPort), destPort_(destPort), data_(data) {}

// 전송자 주소를 반환하는 함수
Address Packet::srcAddress() {
    return srcAddress_;
}

// 수신자 주소를 반환하는 함수
Address Packet::destAddress() {
    return destAddress_;
}

// 전송자 포트를 반환하는 함수
short Packet::srcPort() {
    return srcPort_;
}

// 수신자 포트를 반환하는 함수
short Packet::destPort() {
    return destPort_;
}

// 패킷 데이터를 반환하는 함수
const std::vector<char>& Packet::data() {
    return data_;
}

// 패킷 데이터를 문자열로 변환하는 함수
std::string Packet::dataString() {
    std::string str;
    for (size_t i = 0; i < data_.size(); i++) {
        str += data_[i];
    }
    return str;
}