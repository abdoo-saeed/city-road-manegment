#include "MyForm2.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main2() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Graph* graph = new Graph();
    Application::Run(gcnew TryAgain::MyForm2(graph));
    
    delete graph;
    return 0;
}