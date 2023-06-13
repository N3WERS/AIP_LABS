#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Item.cpp"
#include "ItemReader.cpp"
#include "OrderProcessor.cpp"

int main() {
    setlocale(LC_ALL, "Russian");

    std::string itemsFilename = "items.txt";
    ItemReader itemReader(itemsFilename);
    std::vector<Item> items = itemReader.readItems();

    std::string ordersFilename = "orders.txt";
    std::ifstream ordersFile(ordersFilename);

    if (!ordersFile) {
        std::cout << "Ошибка открытия файла " << ordersFilename << std::endl;
        return 1;
    }

    std::vector<std::string> orderNames;
    std::vector<std::vector<std::string>> orderItems; // Хранение списков товаров для каждого заказа
    std::string line;
    while (std::getline(ordersFile, line)) {
        std::stringstream ss(line);
        std::string orderName, itemNames;

        if (std::getline(ss, orderName, ':') && std::getline(ss, itemNames)) {
            orderNames.push_back(orderName);

            std::vector<std::string> itemsForOrder;
            std::stringstream itemsSS(itemNames);
            std::string itemName;
            while (std::getline(itemsSS, itemName, ',')) {
                itemsForOrder.push_back(itemName);
            }
            orderItems.push_back(itemsForOrder);
        }
    }

    ordersFile.close();

    if (orderNames.empty()) {
        std::cout << "Файл заказов пуст." << std::endl;
        return 0;
    }

    std::cout << "Доступные заказы:" << std::endl;
    for (size_t i = 0; i < orderNames.size(); ++i) {
        std::cout << i + 1 << ". " << orderNames[i] << std::endl;
    }

    int selectedOrderIndex;
    do {
        std::cout << "Выберите номер заказа (1-" << orderNames.size() << "): ";
        std::cin >> selectedOrderIndex;
    } while (selectedOrderIndex < 1);

    std::string selectedOrderName = orderNames[selectedOrderIndex - 1];
    std::vector<std::string> selectedOrderItems = orderItems[selectedOrderIndex - 1];

    std::string certificatesInput;
    std::cout << "Введите сертификаты через запятую: ";
    std::cin.ignore();
    std::getline(std::cin, certificatesInput);

    std::vector<std::string> certificates;
    std::stringstream certificatesSS(certificatesInput);
    std::string certificate;
    while (std::getline(certificatesSS, certificate, ',')) {
        certificates.push_back(certificate);
    }

    std::vector<Item> itemsForOrder;
    for (const auto& item : items) {
        if (std::find(selectedOrderItems.begin(), selectedOrderItems.end(), item.getName()) != selectedOrderItems.end()) {
            itemsForOrder.push_back(item);
        }
    }

    OrderProcessor orderProcessor(itemsForOrder, selectedOrderName, certificates);
    orderProcessor.processOrder();

    return 0;
}