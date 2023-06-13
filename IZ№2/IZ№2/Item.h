#pragma once
#include <string>
// Класс для хранения информации о товаре
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

