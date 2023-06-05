#include "MyForm.h"
#include "SysSelect.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array <String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Laba5::MyForm form;
	Application::Run(% form);
}
