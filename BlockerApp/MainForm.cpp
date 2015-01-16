#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args)
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
			return;
		}
		return;
	}

	BlockerApp::MainForm form;
	Application::Run(%form);
}