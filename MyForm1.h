#pragma once
#include "Graph.h"
#include <msclr/marshal_cppstd.h>
#include<string>
namespace TryAgain {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(Graph* graphRef)
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
		
		~MyForm1()
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
		System::Windows::Forms::TextBox^ txtCity;
		System::Windows::Forms::Button^ btnAddCity;
		System::Windows::Forms::ListBox^ lstCities;
		System::Windows::Forms::TextBox^ txtFromCity;
		System::Windows::Forms::TextBox^ txtToCity;
		System::Windows::Forms::TextBox^ txtDistance;
		System::Windows::Forms::Button^ btnAddConnection;		
		System::Windows::Forms::Button^ btnShowConnections;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtCity = (gcnew System::Windows::Forms::TextBox());
			this->btnAddCity = (gcnew System::Windows::Forms::Button());
			this->lstCities = (gcnew System::Windows::Forms::ListBox());
			this->txtFromCity = (gcnew System::Windows::Forms::TextBox());
			this->txtToCity = (gcnew System::Windows::Forms::TextBox());
			this->txtDistance = (gcnew System::Windows::Forms::TextBox());
			this->btnAddConnection = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtCity
			// 
			this->txtCity->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 8.1F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtCity->Location = System::Drawing::Point(32, 29);
			this->txtCity->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->txtCity->Name = L"txtCity";
			this->txtCity->Size = System::Drawing::Size(393, 41);
			this->txtCity->TabIndex = 0;
			// 
			// btnAddCity
			// 
			this->btnAddCity->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnAddCity->Location = System::Drawing::Point(448, 10);
			this->btnAddCity->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->btnAddCity->Name = L"btnAddCity";
			this->btnAddCity->Size = System::Drawing::Size(267, 74);
			this->btnAddCity->TabIndex = 1;
			this->btnAddCity->Text = L"Add City";
			this->btnAddCity->UseVisualStyleBackColor = true;
			this->btnAddCity->Click += gcnew System::EventHandler(this, &MyForm1::btnAddCity_Click);
			// 
			// lstCities
			// 
			this->lstCities->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lstCities->FormattingEnabled = true;
			this->lstCities->ItemHeight = 46;
			this->lstCities->Location = System::Drawing::Point(32, 98);
			this->lstCities->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->lstCities->Name = L"lstCities";
			this->lstCities->Size = System::Drawing::Size(676, 372);
			this->lstCities->TabIndex = 2;
			// 
			// txtFromCity
			// 
			this->txtFromCity->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtFromCity->Location = System::Drawing::Point(32, 486);
			this->txtFromCity->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->txtFromCity->Name = L"txtFromCity";
			this->txtFromCity->Size = System::Drawing::Size(393, 53);
			this->txtFromCity->TabIndex = 3;
			this->txtFromCity->Text = L"From City";
			// 
			// txtToCity
			// 
			this->txtToCity->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtToCity->Location = System::Drawing::Point(32, 548);
			this->txtToCity->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->txtToCity->Name = L"txtToCity";
			this->txtToCity->Size = System::Drawing::Size(393, 53);
			this->txtToCity->TabIndex = 4;
			this->txtToCity->Text = L"To City";
			// 
			// txtDistance
			// 
			this->txtDistance->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtDistance->Location = System::Drawing::Point(32, 610);
			this->txtDistance->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->txtDistance->Name = L"txtDistance";
			this->txtDistance->Size = System::Drawing::Size(393, 53);
			this->txtDistance->TabIndex = 5;
			this->txtDistance->Text = L"Distance";
			// 
			// btnAddConnection
			// 
			this->btnAddConnection->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnAddConnection->Location = System::Drawing::Point(448, 548);
			this->btnAddConnection->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->btnAddConnection->Name = L"btnAddConnection";
			this->btnAddConnection->Size = System::Drawing::Size(267, 55);
			this->btnAddConnection->TabIndex = 6;
			this->btnAddConnection->Text = L"Add Edge";
			this->btnAddConnection->UseVisualStyleBackColor = true;
			this->btnAddConnection->Click += gcnew System::EventHandler(this, &MyForm1::btnAddConnection_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(741, 712);
			this->Controls->Add(this->btnAddConnection);
			this->Controls->Add(this->txtDistance);
			this->Controls->Add(this->txtToCity);
			this->Controls->Add(this->txtFromCity);
			this->Controls->Add(this->lstCities);
			this->Controls->Add(this->btnAddCity);
			this->Controls->Add(this->txtCity);
			this->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->Name = L"MyForm1";
			this->Text = L"ADD";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
    private:
	  System::Void btnAddCity_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ cityName = txtCity->Text;
		if (!String::IsNullOrEmpty(cityName)) {
			graph->addCity(msclr::interop::marshal_as<std::string>(cityName));
			UpdateCitiesList();
			txtCity->Text = "";
		}
	  }

	  System::Void btnAddConnection_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ fromCity = txtFromCity->Text;
		String^ toCity = txtToCity->Text;
		int distance = 0;

		if (Int32::TryParse(txtDistance->Text, distance)) {
			graph->addEdge(
				msclr::interop::marshal_as<std::string>(fromCity),
				msclr::interop::marshal_as<std::string>(toCity),
				distance
			);
			txtFromCity->Text = "";
			txtToCity->Text = "";
			txtDistance->Text = "";
		}
		else {
			MessageBox::Show("Please enter a valid distance", "Error");
		}
	  }
	 

	
	  void UpdateCitiesList() {
		lstCities->Items->Clear();
		auto cities = graph->getAllCities();
		for (auto& city : cities) {
			lstCities->Items->Add(gcnew String(city.c_str()));
		}
	
	  }





	

    };
}
