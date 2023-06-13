#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// Структура для хранения информации о товаре
struct Item {
    std::string name;
    std::string certificate;
};

// Функция для чтения товаров из файла и возврата в виде вектора
std::vector<Item> readItemsFromFile(const std::string& filename) {
    std::vector<Item> items;
    std::ifstream file(filename);

    // Проверка, удалось ли открыть файл
    if (!file) {
        std::cout << "Ошибка открытия файла " << filename << std::endl;
        return items;
    }

    std::string line;
    // Чтение файла построчно
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, certificate;
        // Разделение строки по запятой на имя и сертификат
        if (std::getline(ss, name, ',') && std::getline(ss, certificate)) {
            // Создание нового товара и добавление его в вектор
            items.push_back({ name, certificate });
        }
    }

    file.close();
    return items;
}

// Функция для обработки заказа
void processOrder(const std::vector<Item>& items, const std::string& orderName, const std::vector<std::string>& certificates) {
    std::cout << "Заказ: " << orderName << std::endl;
    std::cout << "Сертификаты: ";
    // Вывод сертификатов заказа
    for (const auto& certificate : certificates) {
        std::cout << certificate << " ";
    }
    std::cout << std::endl;

    std::cout << "Найденные товары:" << std::endl;
    // Поиск товаров, соответствующих сертификатам заказа
    for (const auto& item : items) {
        if (std::find(certificates.begin(), certificates.end(), item.certificate) != certificates.end()) {
            // Вывод найденных товаров
            std::cout << "- " << item.name << " (Сертификат: " << item.certificate << ")" << std::endl;
        }
    }

    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string itemsFilename = "items.txt";
    // Чтение товаров из файла
    std::vector<Item> items = readItemsFromFile(itemsFilename);

    std::string ordersFilename = "orders.txt";
    std::ifstream ordersFile(ordersFilename);

    // Проверка, удалось ли открыть файл с заказами
    if (!ordersFile) {
        std::cout << "Ошибка открытия файла " << ordersFilename << std::endl;
        return 1;
    }

    std::vector<std::string> orderNames;
    std::string line;
    // Чтение файла с заказами построчно
    while (std::getline(ordersFile, line)) {
        std::stringstream ss(line);
        std::string orderName, itemNames;
        // Разделение строки по двоеточию на имя заказа и список товаров
        if (std::getline(ss, orderName, ':') && std::getline(ss, itemNames)) {
            // Добавление имени заказа в вектор
            orderNames.push_back(orderName);
        }
    }

    ordersFile.close();

    // Проверка, что файл заказов не пустой
    if (orderNames.empty()) {
        std::cout << "Файл заказов пуст." << std::endl;
        return 0;
    }

    std::cout << "Доступные заказы:" << std::endl;
    // Вывод доступных заказов
    for (size_t i = 0; i < orderNames.size(); ++i) {
        std::cout << i + 1 << ". " << orderNames[i] << std::endl;
    }

    int selectedOrderIndex;
    do {
        std::cout << "Выберите номер заказа (1-" << orderNames.size() << "): ";
        std::cin >> selectedOrderIndex;
    } while (selectedOrderIndex < 1);

    std::string selectedOrderName = orderNames[selectedOrderIndex - 1];

    std::string certificatesInput;
    std::cout << "Введите сертификаты через запятую: ";
    std::cin.ignore();  // Игнорируем символ новой строки перед getline
    std::getline(std::cin, certificatesInput);

    std::vector<std::string> certificates;
    std::stringstream certificatesSS(certificatesInput);
    std::string certificate;
    // Разделение строки сертификатов по запятой
    while (std::getline(certificatesSS, certificate, ',')) {
        // Добавление сертификата в вектор
        certificates.push_back(certificate);
    }

    // Обработка выбранного заказа
    processOrder(items, selectedOrderName, certificates);

    return 0;
}