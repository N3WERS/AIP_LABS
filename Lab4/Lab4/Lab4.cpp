#include "pch.h"
#include "OperatingSysSelector.h"
using namespace System;
using namespace System::Collections::Generic;


int main() {
    // ������� ��������� ������ ������ ������������ ������
    OperatingSysSelector^ osSelector = gcnew OperatingSysSelector();

    // ������� ������ ���������� ��� ��������
    List<String^>^ smartphones = gcnew List<String^>();
    smartphones->Add("Samsung Galaxy");
    smartphones->Add("iPhone");
    smartphones->Add("Nokia Lumia");

    // ��������� ����� ����� ������������� ��������� � �����������
    osSelector->AddCompatibility("Android", "Samsung Galaxy");
    osSelector->AddCompatibility("iOS", "iPhone");
    osSelector->AddCompatibility("Windows", "Nokia Lumia");

    // ��������� ����� ������������ ������ ��� ����������
    List<String^>^ selectedOS = osSelector->SelectOperatingSystems(smartphones);

    // ������� ����������
    Console::WriteLine("Selected operating systems:");
    for each (String ^ os in selectedOS) {
        Console::WriteLine(os);
    }

    return 0;
}