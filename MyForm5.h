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
	/// Summary for MyForm5
	/// </summary>
	public ref class MyForm5 : public System::Windows::Forms::Form
	{
	public:
		MyForm5(Graph* graphRef)
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
		~MyForm5()
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
		System::Windows::Forms::ComboBox^ cmbStartCity;
		System::Windows::Forms::ComboBox^ cmbEndCity;
		System::Windows::Forms::Button^ btnFindPath;
		System::Windows::Forms::RichTextBox^ rtbOutput;
		System::Windows::Forms::Label^ lblStartCity;
		System::Windows::Forms::Label^ lblEndCity;
		System::Windows::Forms::Button^ btnClose;

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->cmbStartCity = (gcnew System::Windows::Forms::ComboBox());
			this->cmbEndCity = (gcnew System::Windows::Forms::ComboBox());
			this->btnFindPath = (gcnew System::Windows::Forms::Button());
			this->rtbOutput = (gcnew System::Windows::Forms::RichTextBox());
			this->lblStartCity = (gcnew System::Windows::Forms::Label());
			this->lblEndCity = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// cmbStartCity
			// 
			this->cmbStartCity->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cmbStartCity->FormattingEnabled = true;
			this->cmbStartCity->Location = System::Drawing::Point(229, 25);
			this->cmbStartCity->Margin = System::Windows::Forms::Padding(0);
			this->cmbStartCity->Name = L"cmbStartCity";
			this->cmbStartCity->Size = System::Drawing::Size(354, 54);
			this->cmbStartCity->TabIndex = 0;
			// 
			// cmbEndCity
			// 
			this->cmbEndCity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->cmbEndCity->FormattingEnabled = true;
			this->cmbEndCity->Location = System::Drawing::Point(218, 103);
			this->cmbEndCity->Margin = System::Windows::Forms::Padding(0);
			this->cmbEndCity->Name = L"cmbEndCity";
			this->cmbEndCity->Size = System::Drawing::Size(354, 39);
			this->cmbEndCity->TabIndex = 1;
			// 
			// btnFindPath
			// 
			this->btnFindPath->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnFindPath->Location = System::Drawing::Point(40, 168);
			this->btnFindPath->Margin = System::Windows::Forms::Padding(0);
			this->btnFindPath->Name = L"btnFindPath";
			this->btnFindPath->Size = System::Drawing::Size(373, 81);
			this->btnFindPath->TabIndex = 2;
			this->btnFindPath->Text = L"Find Shortest Path";
			this->btnFindPath->UseVisualStyleBackColor = true;
			this->btnFindPath->Click += gcnew System::EventHandler(this, &MyForm5::btnFindPath_Click);
			// 
			// rtbOutput
			// 
			this->rtbOutput->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->rtbOutput->Location = System::Drawing::Point(40, 289);
			this->rtbOutput->Margin = System::Windows::Forms::Padding(0);
			this->rtbOutput->Name = L"rtbOutput";
			this->rtbOutput->ReadOnly = true;
			this->rtbOutput->Size = System::Drawing::Size(970, 265);
			this->rtbOutput->TabIndex = 3;
			this->rtbOutput->Text = L"";
			// 
			// lblStartCity
			// 
			this->lblStartCity->AutoSize = true;
			this->lblStartCity->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblStartCity->Location = System::Drawing::Point(20, 25);
			this->lblStartCity->Margin = System::Windows::Forms::Padding(0);
			this->lblStartCity->Name = L"lblStartCity";
			this->lblStartCity->Size = System::Drawing::Size(209, 46);
			this->lblStartCity->TabIndex = 4;
			this->lblStartCity->Text = L"Start City:";
			// 
			// lblEndCity
			// 
			this->lblEndCity->AutoSize = true;
			this->lblEndCity->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblEndCity->Location = System::Drawing::Point(34, 96);
			this->lblEndCity->Margin = System::Windows::Forms::Padding(0);
			this->lblEndCity->Name = L"lblEndCity";
			this->lblEndCity->Size = System::Drawing::Size(193, 46);
			this->lblEndCity->TabIndex = 5;
			this->lblEndCity->Text = L"End City:";
			// 
			// btnClose
			// 
			this->btnClose->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnClose->Location = System::Drawing::Point(409, 593);
			this->btnClose->Margin = System::Windows::Forms::Padding(0);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(208, 81);
			this->btnClose->TabIndex = 6;
			this->btnClose->Text = L"Close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &MyForm5::btnClose_Click);
			// 
			// MyForm5
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1028, 712);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->lblEndCity);
			this->Controls->Add(this->lblStartCity);
			this->Controls->Add(this->rtbOutput);
			this->Controls->Add(this->btnFindPath);
			this->Controls->Add(this->cmbEndCity);
			this->Controls->Add(this->cmbStartCity);
			this->Margin = System::Windows::Forms::Padding(0);
			this->Name = L"MyForm5";
			this->Text = L"Dijkstra\'s Shortest Path";
			this->Load += gcnew System::EventHandler(this, &MyForm5::MyForm5_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}


		void UpdateCitiesList()
		{
			this->cmbStartCity->Items->Clear();
			this->cmbEndCity->Items->Clear();
			auto cities = graph->getAllCities();
			for (auto& city : cities)
			{
				this->cmbStartCity->Items->Add(gcnew String(city.c_str()));
				this->cmbEndCity->Items->Add(gcnew String(city.c_str()));
			}
			if (this->cmbStartCity->Items->Count > 0)
			{
				this->cmbStartCity->SelectedIndex = 0;
				this->cmbEndCity->SelectedIndex = 0;
			}
		}
#pragma endregion
	private: System::Void MyForm5_Load(System::Object^ sender, System::EventArgs^ e) {
	}
		   System::Void btnFindPath_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (cmbStartCity->SelectedItem == nullptr || cmbEndCity->SelectedItem == nullptr)
			   {
				   MessageBox::Show("Please select both start and end cities!", "Error",
					   MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }

			   String^ startCity = cmbStartCity->SelectedItem->ToString();
			   String^ endCity = cmbEndCity->SelectedItem->ToString();

			   std::string start = msclr::interop::marshal_as<std::string>(startCity);
			   std::string end = msclr::interop::marshal_as<std::string>(endCity); 
			   
			   std::stringstream buffer;
			   std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

			   graph->dijkstra(start, end); 
			   
			   std::cout.rdbuf(old); 
			   
			   rtbOutput->Text = gcnew System::String(buffer.str().c_str());
		   }

		   System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   this->Close();
		   }
	};
}
