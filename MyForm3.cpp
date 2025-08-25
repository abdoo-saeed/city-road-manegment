#include "MyForm3.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main3(Graph* graph) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew TryAgain::MyForm3(graph));
}