#pragma once
#include "Graph.h"
#include <msclr/marshal_cppstd.h>
#include <sstream>  
#include <iostream>
namespace TryAgain {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm4
	/// </summary>
	public ref class MyForm4 : public System::Windows::Forms::Form
	{
	public:
		MyForm4(Graph* graphRef)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			// 
			graph = graphRef;
			UpdateCitiesList();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm4()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Graph* graph;
		System::Windows::Forms::ComboBox^ cmbCities;
		System::Windows::Forms::Button^ btnBFS;
		System::Windows::Forms::Button^ btnDFS;
		System::Windows::Forms::RichTextBox^ rtbOutput;
		System::Windows::Forms::Label^ lblSelectCity;
		System::Windows::Forms::Button^ btnClose;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->cmbCities = (gcnew System::Windows::Forms::ComboBox());
			this->btnBFS = (gcnew System::Windows::Forms::Button());
			this->btnDFS = (gcnew System::Windows::Forms::Button());
			this->rtbOutput = (gcnew System::Windows::Forms::RichTextBox());
			this->lblSelectCity = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// cmbCities
			// 
			this->cmbCities->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cmbCities->FormattingEnabled = true;
			this->cmbCities->Location = System::Drawing::Point(210, 30);
			this->cmbCities->Margin = System::Windows::Forms::Padding(0);
			this->cmbCities->Name = L"cmbCities";
			this->cmbCities->Size = System::Drawing::Size(371, 54);
			this->cmbCities->TabIndex = 0;
			// 
			// btnBFS
			// 
			this->btnBFS->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnBFS->Location = System::Drawing::Point(45, 109);
			this->btnBFS->Margin = System::Windows::Forms::Padding(0);
			this->btnBFS->Name = L"btnBFS";
			this->btnBFS->Size = System::Drawing::Size(200, 77);
			this->btnBFS->TabIndex = 1;
			this->btnBFS->Text = L"Run BFS";
			this->btnBFS->UseVisualStyleBackColor = true;
			this->btnBFS->Click += gcnew System::EventHandler(this, &MyForm4::btnBFS_Click);
			// 
			// btnDFS
			// 
			this->btnDFS->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnDFS->Location = System::Drawing::Point(300, 109);
			this->btnDFS->Margin = System::Windows::Forms::Padding(0);
			this->btnDFS->Name = L"btnDFS";
			this->btnDFS->Size = System::Drawing::Size(197, 77);
			this->btnDFS->TabIndex = 2;
			this->btnDFS->Text = L"Run DFS";
			this->btnDFS->UseVisualStyleBackColor = true;
			this->btnDFS->Click += gcnew System::EventHandler(this, &MyForm4::btnDFS_Click);
			// 
			// rtbOutput
			// 
			this->rtbOutput->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->rtbOutput->Location = System::Drawing::Point(45, 230);
			this->rtbOutput->Margin = System::Windows::Forms::Padding(0);
			this->rtbOutput->Name = L"rtbOutput";
			this->rtbOutput->ReadOnly = true;
			this->rtbOutput->Size = System::Drawing::Size(898, 279);
			this->rtbOutput->TabIndex = 3;
			this->rtbOutput->Text = L"";
			// 
			// lblSelectCity
			// 
			this->lblSelectCity->AutoSize = true;
			this->lblSelectCity->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblSelectCity->Location = System::Drawing::Point(20, 30);
			this->lblSelectCity->Margin = System::Windows::Forms::Padding(0);
			this->lblSelectCity->Name = L"lblSelectCity";
			this->lblSelectCity->Size = System::Drawing::Size(234, 46);
			this->lblSelectCity->TabIndex = 4;
			this->lblSelectCity->Text = L"Select City:";
			// 
			// btnClose
			// 
			this->btnClose->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnClose->Location = System::Drawing::Point(339, 543);
			this->btnClose->Margin = System::Windows::Forms::Padding(0);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(306, 87);
			this->btnClose->TabIndex = 5;
			this->btnClose->Text = L"Close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &MyForm4::btnClose_Click);
			// 
			// MyForm4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(980, 706);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->lblSelectCity);
			this->Controls->Add(this->rtbOutput);
			this->Controls->Add(this->btnDFS);
			this->Controls->Add(this->btnBFS);
			this->Controls->Add(this->cmbCities);
			this->Margin = System::Windows::Forms::Padding(0);
			this->Name = L"MyForm4";
			this->Text = L"BFS/DFS";
			this->Load += gcnew System::EventHandler(this, &MyForm4::MyForm4_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}


		void UpdateCitiesList()
		{
			this->cmbCities->Items->Clear();
			auto cities = graph->getAllCities();
			for (auto& city : cities)
			{
				this->cmbCities->Items->Add(gcnew String(city.c_str()));
			}
			if (this->cmbCities->Items->Count > 0)
			{
				this->cmbCities->SelectedIndex = 0;
			}
		}
#pragma endregion
	private: System::Void MyForm4_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private:
		System::Void btnBFS_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (cmbCities->SelectedItem == nullptr)
			{
				MessageBox::Show("Please select a city first!", "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			String^ selectedCity = cmbCities->SelectedItem->ToString();
			std::string city = msclr::interop::marshal_as<std::string>(selectedCity);

			//  BFS output
			std::stringstream buffer;
			std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

			graph->BFS(city);			
			std::cout.rdbuf(old);
			rtbOutput->Text = "BFS Traversal:\n" + gcnew System::String(buffer.str().c_str());
		}

		System::Void btnDFS_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (cmbCities->SelectedItem == nullptr)
			{
				MessageBox::Show("Please select a city first!", "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			String^ selectedCity = cmbCities->SelectedItem->ToString();
			std::string city = msclr::interop::marshal_as<std::string>(selectedCity);

			// بيعيد توجيه  output dfs
			std::stringstream buffer;
			std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

			graph->DFS(city);

			//  cout بيرجع يخزن
			std::cout.rdbuf(old);

			// بيطلع الoutput
			rtbOutput->Text = "DFS Traversal:\n" + gcnew System::String(buffer.str().c_str());
		}

		System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}
	};
}
