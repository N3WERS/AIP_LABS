#pragma once
#include <string>
// ����� ��� �������� ���������� � ������
class Item {
public:
    Item(const std::string& name, const std::string& certificate)
        : name(name), certificate(certificate) {}

    std::string getName() const {
        return name;
    }

    std::string getCertificate() const {
        return certificate;
    }

private:
    std::string name;
    std::string certificate;
};

