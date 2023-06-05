#include "pch.h"
#include "OperatingSysSelector.h"
using namespace System;
using namespace System::Collections::Generic;


int main() {
    // Создаем экземпляр класса выбора операционных систем
    OperatingSysSelector^ osSelector = gcnew OperatingSysSelector();

    // Создаем список смартфонов для проверки
    List<String^>^ smartphones = gcnew List<String^>();
    smartphones->Add("Samsung Galaxy");
    smartphones->Add("iPhone");
    smartphones->Add("Nokia Lumia");

    // Добавляем связи между операционными системами и смартфонами
    osSelector->AddCompatibility("Android", "Samsung Galaxy");
    osSelector->AddCompatibility("iOS", "iPhone");
    osSelector->AddCompatibility("Windows", "Nokia Lumia");

    // Выполняем отбор операционных систем для смартфонов
    List<String^>^ selectedOS = osSelector->SelectOperatingSystems(smartphones);

    // Выводим результаты
    Console::WriteLine("Selected operating systems:");
    for each (String ^ os in selectedOS) {
        Console::WriteLine(os);
    }

    return 0;
}