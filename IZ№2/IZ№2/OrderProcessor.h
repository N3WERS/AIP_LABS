#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Item.cpp"

// ����� ��� ��������� ������
class OrderProcessor {
public:
    OrderProcessor(const std::vector<Item>& items, const std::string& orderName, const std::vector<std::string>& certificates)
        : items(items), orderName(orderName), certificates(certificates) {}

    void processOrder() const {
        std::cout << "�����: " << orderName << std::endl;
        std::cout << "�����������: ";
        for (const auto& certificate : certificates) {
            std::cout << certificate << " ";
        }
        std::cout << std::endl;

        std::cout << "��������� ������:" << std::endl;
        for (const auto& item : items) {
            if (std::find(certificates.begin(), certificates.end(), item.getCertificate()) != certificates.end()) {
                std::cout << "- " << item.getName() << " (����������: " << item.getCertificate() << ")" << std::endl;
            }
        }

        std::cout << std::endl;
    }

private:
    std::vector<Item> items;
    std::string orderName;
    std::vector<std::string> certificates;
};