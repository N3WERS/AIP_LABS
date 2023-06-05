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
        // ��������� ����� ����� ������������ �������� � ����������
        if (!compatibilityMap->ContainsKey(smartphone)) {
            compatibilityMap->Add(smartphone, gcnew List<String^>());
        }
        compatibilityMap[smartphone]->Add(os);
    }

    List<String^>^ SelectOperatingSystems(List<String^>^ smartphones) {
        List<String^>^ selectedOS = gcnew List<String^>();

        for each (String ^ phone in smartphones) {
            // ���������, ���� �� � ��������� ��������� ������������ �������
            if (compatibilityMap->ContainsKey(phone)) {
                // �������� ������ ������������ ������, ����������� � ������ ����������
                List<String^>^ compatibleOS = compatibilityMap[phone];

                // ��������� ������������ ������� � ��������� ������������ �������
                selectedOS->AddRange(compatibleOS);
            }
        }

        return selectedOS;
    }
};