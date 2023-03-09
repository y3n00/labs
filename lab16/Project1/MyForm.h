#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
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
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TextBox^ textBox3;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(13, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(166, 32);
			this->textBox1->TabIndex = 0;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(185, 12);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(166, 32);
			this->textBox2->TabIndex = 1;
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox2_KeyPress);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 76);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(80, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(99, 76);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(80, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"substract";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(185, 76);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(80, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"multiply";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(271, 76);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(80, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"divide";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(13, 106);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(338, 23);
			this->button5->TabIndex = 6;
			this->button5->Text = L"clear";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(12, 12);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(339, 32);
			this->textBox3->TabIndex = 7;
			this->textBox3->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(367, 141);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Calculator";
			this->ShowIcon = false;
			this->Text = L"Calculator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
			if (!(e->KeyChar == '.' || (e->KeyChar >= '0' && e->KeyChar <= '9') || e->KeyChar == '\b' || e->KeyChar == '-'))
				e->Handled = true;
		}
		System::Void textBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
			if (!(e->KeyChar == '.' || (e->KeyChar >= '0' && e->KeyChar <= '9') || e->KeyChar == '\b' || e->KeyChar == '-'))
				e->Handled = true;
		}
		bool TBAreSetted() {
			return (textBox1->Text->Length > 0 && textBox2->Text->Length > 0);
		}
		Double removeDots(System::String^ str) {
			array<wchar_t>^ sep = { '.' };
			auto strs = str->Split(sep, StringSplitOptions::RemoveEmptyEntries);
			if (strs->Length > 1)
				return Double::Parse(strs[0] + "." + strs[1]);
			else
				return Double::Parse(strs[0]);
		}
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			if (TBAreSetted()) {
				textBox1->Hide();
				textBox2->Hide();
				textBox3->Show();
				Double d1 = removeDots(textBox1->Text);
				Double d2 = removeDots(textBox2->Text);
				textBox3->Text = (d1 + d2).ToString();
			}
		}
		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			if (TBAreSetted()) {
				textBox1->Hide();
				textBox2->Hide();
				textBox3->Show();
				Double d1 = removeDots(textBox1->Text);
				Double d2 = removeDots(textBox2->Text);
				textBox3->Text = (d1 - d2).ToString();
			}
		}
		System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			if (TBAreSetted()) {
				textBox1->Hide();
				textBox2->Hide();
				textBox3->Show();
				Double d1 = removeDots(textBox1->Text);
				Double d2 = removeDots(textBox2->Text);
				textBox3->Text = (d1 * d2).ToString();
			}
		}
		System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
			if (TBAreSetted()) {
				textBox1->Hide();
				textBox2->Hide();
				textBox3->Show();
				Double d1 = removeDots(textBox1->Text);
				Double d2 = removeDots(textBox2->Text);
				textBox3->Text = (d1 / d2).ToString();
			}
		}
		System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Clear();
			textBox2->Clear();
			textBox3->Clear();
			textBox3->Hide();

			textBox1->Show();
			textBox2->Show();

		}
	};
}
