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
			toolTip1->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			toolTip1->ToolTipTitle = "Information";

			toolTip1->SetToolTip(textBox1, "Enter first num");
			toolTip1->SetToolTip(textBox2, "Enter second num");
		}
	private: System::Windows::Forms::ToolTip^ toolTip1;
	public:

	protected:
		System::Drawing::Color c;
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
	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
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
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
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
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(12, 60);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(80, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			this->button1->MouseEnter += gcnew System::EventHandler(this, &MyForm::button1_MouseEnter);
			this->button1->MouseLeave += gcnew System::EventHandler(this, &MyForm::button1_MouseLeave);
			// 
			// button2
			// 
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(98, 60);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(80, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"substract";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			this->button2->MouseEnter += gcnew System::EventHandler(this, &MyForm::button2_MouseEnter);
			this->button2->MouseLeave += gcnew System::EventHandler(this, &MyForm::button2_MouseLeave);
			// 
			// button3
			// 
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(184, 60);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(80, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"multiply";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			this->button3->MouseEnter += gcnew System::EventHandler(this, &MyForm::button3_MouseEnter);
			this->button3->MouseLeave += gcnew System::EventHandler(this, &MyForm::button3_MouseLeave);
			// 
			// button4
			// 
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Location = System::Drawing::Point(270, 60);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(80, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"divide";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			this->button4->MouseEnter += gcnew System::EventHandler(this, &MyForm::button4_MouseEnter);
			this->button4->MouseLeave += gcnew System::EventHandler(this, &MyForm::button4_MouseLeave);
			// 
			// button5
			// 
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Location = System::Drawing::Point(12, 90);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(338, 23);
			this->button5->TabIndex = 6;
			this->button5->Text = L"clear";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// textBox3
			// 
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(11, 12);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(339, 32);
			this->textBox3->TabIndex = 7;
			this->textBox3->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(363, 120);
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
			this->Name = L"MyForm";
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
				if (d2 == 0) {
					MessageBox::Show("Dont divide by 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
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


		System::Void button1_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
			button1->BackColor = Color::Aqua;
		}
		System::Void button1_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
			button1->BackColor = Drawing::SystemColors::Control;
		}
		System::Void button2_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
			button2->BackColor = Color::PaleVioletRed;
		}
		System::Void button2_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
			button2->BackColor = Drawing::SystemColors::Control;
		}
		System::Void button3_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
			button3->BackColor = Color::MediumPurple;
		}
		System::Void button3_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
			button3->BackColor = Drawing::SystemColors::Control;
		}
		System::Void button4_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
			button4->BackColor = Color::Coral;
		}
		System::Void button4_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
			button4->BackColor = Drawing::SystemColors::Control;
		}

	};
}
