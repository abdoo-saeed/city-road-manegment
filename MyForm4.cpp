#include "MyForm4.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main4(Graph* graph)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew TryAgain::MyForm4(graph));
    return 0;
}