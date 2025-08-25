#include "MyForm5.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main5(Graph* graph)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew TryAgain::MyForm5(graph));
    return 0;
}