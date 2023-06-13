#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Item.cpp"

// Класс для чтения товаров из файла
class ItemReader {
public:
    ItemReader(const std::string& filename)
        : filename(filename) {}

    std::vector<Item> readItems() const {
        std::vector<Item> items;
        std::ifstream file(filename);

        if (!file) {
            std::cout << "Ошибка открытия файла " << filename << std::endl;
            return items;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string name, certificate;

            if (std::getline(ss, name, ',') && std::getline(ss, certificate)) {
                items.push_back(Item(name, certificate));
            }
        }

        file.close();
        return items;
    }

private:
    std::string filename;
};
