#include "MyForm1.h"
#include "array"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main1(){
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Graph* graph = new Graph();

    Application::Run(gcnew TryAgain::MyForm1(graph));
   
    delete graph;
    return 0;
}