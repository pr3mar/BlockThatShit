#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ argv)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//admin rights stuff
	System::Security::Principal::WindowsPrincipal^ principal;
	principal = gcnew System::Security::Principal::WindowsPrincipal(System::Security::Principal::WindowsIdentity::GetCurrent());

	bool adminMode = principal->IsInRole(System::Security::Principal::WindowsBuiltInRole::Administrator);

	if (!adminMode)
	{
		System::Diagnostics::ProcessStartInfo^ startinfo = gcnew System::Diagnostics::ProcessStartInfo();

		startinfo->Verb = "runas";
		startinfo->FileName = Application::ExecutablePath;

		try
		{
			System::Diagnostics::Process::Start(startinfo);
		}
		catch (...)
		{
			return (-1);
		}
		return (0);
	}

	BlockerApp::MainForm form;
	Application::Run(%form);

	return (0);
}