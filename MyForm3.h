#pragma once
#include "Graph.h"
#include <msclr/marshal_cppstd.h>
#include <sstream>
namespace TryAgain {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm3
	/// </summary>
	public ref class MyForm3 : public System::Windows::Forms::Form
	{
	public:
		MyForm3(Graph* graphRef)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			graph = graphRef;
			DisplayGraphData();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary> 
		
		~MyForm3()
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
		
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(12, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(776, 400);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(169, 436);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(366, 65);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Close";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm3::btnClose_Click);
			// 
			// MyForm3
			// 
			this->ClientSize = System::Drawing::Size(800, 552);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"MyForm3";
			this->Text = L"Graph Display";
			this->ResumeLayout(false);

		}





	

#pragma endregion




	void DisplayGraphData()
	{

		if (graph == nullptr) return;
		  
		std::stringstream buffer;
		std::streambuf* old = std::cout.rdbuf(buffer.rdbuf()); 	  

		graph->displayGraph(); 
	    std::cout.rdbuf(old);			   
		std::string graphData = buffer.str();			   
		richTextBox1->Text = gcnew System::String(graphData.c_str());
	}

		  
private: System::Void MyForm3_Load(System::Object^ sender, System::EventArgs^ e) {
        }
private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	
};
}
