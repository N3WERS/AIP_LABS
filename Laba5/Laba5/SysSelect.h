#pragma once
using namespace System;
using namespace System::Collections::Generic;
#include "SysSelect.h"

ref class SysSelect {
private:
    Dictionary<String^, List<String^>^>^ compatibilityMap;

public:
    SysSelect() {
        compatibilityMap = gcnew Dictionary<String^, List<String^>^>();
    }

    void AddCompatibility(String^ os, String^ smartphone) {
        // Добавляем связь между операционной системой и смартфоном
        if (!compatibilityMap->ContainsKey(smartphone)) {
            compatibilityMap->Add(smartphone, gcnew List<String^>());
        }
        compatibilityMap[smartphone]->Add(os);
    }

    List<String^>^ SelectOperatingSystems(List<String^>^ smartphones) {
        List<String^>^ selectedOS = gcnew List<String^>();

        for each (String ^ phone in smartphones) {
            // Проверяем, есть ли у смартфона связанные операционные системы
            if (compatibilityMap->ContainsKey(phone)) {
                // Получаем список операционных систем, совместимых с данным смартфоном
                List<String^>^ compatibleOS = compatibilityMap[phone];

                // Добавляем операционные системы в выбранные операционные системы
                selectedOS->AddRange(compatibleOS);
            }
        }

        return selectedOS;
    }
};