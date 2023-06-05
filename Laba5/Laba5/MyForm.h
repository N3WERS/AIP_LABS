#include "SysSelect.h"

namespace Laba5 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:

	public:
		SysSelect^ sysSelect = gcnew SysSelect();
		MyForm(void)
		{

			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ListBox^ listBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(28, 49);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(129, 20);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(294, 94);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 58);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Добавить зависимость";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(28, 94);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(260, 173);
			this->listBox1->TabIndex = 2;
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(464, 248);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(131, 160);
			this->listBox2->TabIndex = 5;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(601, 75);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(116, 58);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Добавить телефон";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(163, 49);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(125, 20);
			this->textBox2->TabIndex = 3;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(601, 49);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(116, 20);
			this->textBox3->TabIndex = 6;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(601, 248);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(116, 63);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Показать операционные системы";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->Location = System::Drawing::Point(464, 49);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(131, 160);
			this->listBox3->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Название телефона";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(160, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(180, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Название операционной системы";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(598, 33);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(109, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Название телефона";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(754, 496);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ phone = textBox1->Text;
		String^ os = textBox2->Text;

		sysSelect->AddCompatibility(os, phone);

		String^ compatibility = phone + ": " + os;
		listBox1->Items->Add(compatibility);

		textBox1->Clear();
		textBox2->Clear();
	}


	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ phone = textBox3->Text;
		textBox3->Clear();
		listBox2->Items->Clear();
		listBox3->Items->Add(phone);
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		List<String^>^ smartphones = gcnew List<String^>();

		for each (Object ^ item in listBox3->Items)
		{
			String^ compatibility = dynamic_cast<String^>(item);
			smartphones->Add(compatibility);
		}

		List<String^>^ selectedOS = sysSelect->SelectOperatingSystems(smartphones);
		listBox3->Items->Clear();

		for each (String ^ os in selectedOS)
		{
			listBox2->Items->Add(os);
		}
	}
};
}
