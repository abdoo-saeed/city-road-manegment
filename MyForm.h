#pragma once
#include "Graph.h"
#include <msclr/marshal_cppstd.h>
#include<string>
#include "MyForm1.h"
#include "MyForm2.h"
#include "MyForm3.h"
#include "MyForm4.h"
#include "MyForm5.h"
namespace TryAgain {

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
			graph = new Graph();
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
			delete graph;
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		
		Graph* graph;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;

		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(719, 42);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(473, 77);
			this->button1->TabIndex = 0;
			this->button1->Text = L"ADD";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(449, 141);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(459, 89);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Delete";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(762, 249);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(472, 87);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Save To File";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(466, 352);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(474, 85);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Load Form File";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(762, 455);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(491, 86);
			this->button5->TabIndex = 6;
			this->button5->Text = L"DisplayGraph";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(436, 559);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(494, 77);
			this->button6->TabIndex = 7;
			this->button6->Text = L"BFS/DFS";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(765, 656);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(488, 85);
			this->button7->TabIndex = 8;
			this->button7->Text = L"Shortest path ";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1447, 973);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"وصلنى";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm1^ obj1 = gcnew MyForm1(this->graph);
		obj1->ShowDialog(); 
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm2^ obj2 = gcnew MyForm2(this->graph);
		obj2->ShowDialog(); 
	}
    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->saveFileDialog1->Filter = "Graph Files|*.graph|All Files|*.*";
		this->saveFileDialog1->Title = "Save Graph Data";
		this->saveFileDialog1->DefaultExt = "graph";

		if (this->saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				String^ filePath = this->saveFileDialog1->FileName;
				std::string filename = msclr::interop::marshal_as<std::string>(filePath);
				graph->saveToFile(filename);
				MessageBox::Show("Graph data saved successfully!", "Success");
			}
			catch (const std::exception& e) {
				MessageBox::Show(gcnew String(e.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

    private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->openFileDialog1->Filter = "Graph Files|*.graph|All Files|*.*";
		this->openFileDialog1->Title = "Load Graph Data";

		if (this->openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				String^ filePath = this->openFileDialog1->FileName;
				std::string filename = msclr::interop::marshal_as<std::string>(filePath);
				graph->loadFromFile(filename);
				MessageBox::Show("Graph data loaded successfully!", "Success");
			}
			catch (const std::exception& e) {
				MessageBox::Show(gcnew String(e.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}  
		
    }
	
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm3^ obj3 = gcnew MyForm3(this->graph);
		obj3->ShowDialog();
	}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	MyForm4^ obj4 = gcnew MyForm4(this->graph);
	obj4->ShowDialog();
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	MyForm5^ obj5 = gcnew MyForm5(this->graph);
	obj5->ShowDialog();
}
};
}
