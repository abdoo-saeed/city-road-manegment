#pragma once
#include "Graph.h"
#include <msclr/marshal_cppstd.h>
namespace TryAgain {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(Graph* graphRef)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			graph = graphRef;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
			delete graph;
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Graph* graph;
		System::Windows::Forms::TextBox^ txtDeleteCity;
		System::Windows::Forms::Button^ btnDeleteCity;
		System::Windows::Forms::TextBox^ txtDeleteFromCity;
		System::Windows::Forms::TextBox^ txtDeleteToCity;
		System::Windows::Forms::Button^ btnDeleteConnection; 		
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtDeleteCity = (gcnew System::Windows::Forms::TextBox());
			this->btnDeleteCity = (gcnew System::Windows::Forms::Button());
			this->txtDeleteFromCity = (gcnew System::Windows::Forms::TextBox());
			this->txtDeleteToCity = (gcnew System::Windows::Forms::TextBox());
			this->btnDeleteConnection = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtDeleteCity
			// 
			this->txtDeleteCity->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtDeleteCity->Location = System::Drawing::Point(42, 57);
			this->txtDeleteCity->Name = L"txtDeleteCity";
			this->txtDeleteCity->Size = System::Drawing::Size(333, 53);
			this->txtDeleteCity->TabIndex = 0;
			// 
			// btnDeleteCity
			// 
			this->btnDeleteCity->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnDeleteCity->Location = System::Drawing::Point(42, 122);
			this->btnDeleteCity->Name = L"btnDeleteCity";
			this->btnDeleteCity->Size = System::Drawing::Size(333, 101);
			this->btnDeleteCity->TabIndex = 1;
			this->btnDeleteCity->Text = L"Delete City";
			this->btnDeleteCity->UseVisualStyleBackColor = true;
			this->btnDeleteCity->Click += gcnew System::EventHandler(this, &MyForm2::btnDeleteCity_Click);
			// 
			// txtDeleteFromCity
			// 
			this->txtDeleteFromCity->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtDeleteFromCity->Location = System::Drawing::Point(374, 360);
			this->txtDeleteFromCity->Name = L"txtDeleteFromCity";
			this->txtDeleteFromCity->Size = System::Drawing::Size(342, 53);
			this->txtDeleteFromCity->TabIndex = 2;
			this->txtDeleteFromCity->Text = L"From City";
			// 
			// txtDeleteToCity
			// 
			this->txtDeleteToCity->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtDeleteToCity->Location = System::Drawing::Point(374, 425);
			this->txtDeleteToCity->Name = L"txtDeleteToCity";
			this->txtDeleteToCity->Size = System::Drawing::Size(342, 53);
			this->txtDeleteToCity->TabIndex = 3;
			this->txtDeleteToCity->Text = L"To City";
			// 
			// btnDeleteConnection
			// 
			this->btnDeleteConnection->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnDeleteConnection->Location = System::Drawing::Point(374, 513);
			this->btnDeleteConnection->Name = L"btnDeleteConnection";
			this->btnDeleteConnection->Size = System::Drawing::Size(333, 86);
			this->btnDeleteConnection->TabIndex = 4;
			this->btnDeleteConnection->Text = L"Delete Edge";
			this->btnDeleteConnection->UseVisualStyleBackColor = true;
			this->btnDeleteConnection->Click += gcnew System::EventHandler(this, &MyForm2::btnDeleteConnection_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(741, 712);
			this->Controls->Add(this->btnDeleteConnection);
			this->Controls->Add(this->txtDeleteToCity);
			this->Controls->Add(this->txtDeleteFromCity);
			this->Controls->Add(this->btnDeleteCity);
			this->Controls->Add(this->txtDeleteCity);
			this->Name = L"MyForm2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"DELETE";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm2_Load(System::Object^ sender, System::EventArgs^ e) {
		
	} 
	private:System::Void btnDeleteCity_Click(System::Object^ sender, System::EventArgs^ e) {
	    String^ cityName = txtDeleteCity->Text;
		if (!String::IsNullOrEmpty(cityName)) {
		graph->deleteCity(msclr::interop::marshal_as<std::string>(cityName));
		
		txtDeleteCity->Text = "";
		MessageBox::Show("City deleted successfully!", "Success");
		}
		else
		{
			MessageBox::Show("city is not found to deleted!", "failed");
		}
	}

	private:System::Void btnDeleteConnection_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ fromCity = txtDeleteFromCity->Text;
		String^ toCity = txtDeleteToCity->Text;

		if (!String::IsNullOrEmpty(fromCity) && !String::IsNullOrEmpty(toCity)) {
		graph->deleteEdge(
		msclr::interop::marshal_as<std::string>(fromCity),
		msclr::interop::marshal_as<std::string>(toCity));
				  
		txtDeleteFromCity->Text = "";
		txtDeleteToCity->Text = "";
		MessageBox::Show("Connection deleted successfully!", "Success");
		}
	}

	

	};
}
