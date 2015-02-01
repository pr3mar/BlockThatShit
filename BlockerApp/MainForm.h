#pragma once


namespace BlockerApp
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Timers;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
		public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			initTimer();
		}

		protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
		private: System::Windows::Forms::MenuStrip^  menuStrip1;
		protected:
		private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  blockToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem1;
		private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem1;
		private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
		private: System::Windows::Forms::TabControl^  tabControl1;
		private: System::Windows::Forms::TabPage^  tabPage1;
		private: System::Windows::Forms::TabPage^  tabPage2;
		private: System::Windows::Forms::NotifyIcon^  notifyIcon1;
		private: System::Windows::Forms::TabPage^  tabPage3;
		private: System::Windows::Forms::TextBox^  textBox1;
		private: System::Windows::Forms::ListBox^  listBox1;
		private: System::Windows::Forms::Button^  button1;
		private: System::Windows::Forms::Button^  button2;
		private: System::Windows::Forms::Button^  button4;
		private: System::Windows::Forms::Button^  button3;
		private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
		private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
		private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;
		private: System::Windows::Forms::RadioButton^  radioButton2;
		private: System::Windows::Forms::RadioButton^  radioButton1;
		private: System::Windows::Forms::Button^  button5;
		private: System::Windows::Forms::Label^  label1;
		private: System::Timers::Timer^ timer = gcnew System::Timers::Timer();
		private: int clockTime = 0;
		private: int alarmTime = 0;
		private: String^ systemPath = Environment::GetFolderPath(Environment::SpecialFolder::System);
		private: String^ path = System::IO::Path::Combine(systemPath, "drivers\\etc\\hosts");
		private: String^ backuppath = System::IO::Path::Combine(systemPath, "drivers\\etc\\hostsb");
		private: String^ blockedpath = System::IO::Path::Combine(systemPath, "drivers\\etc\\hostsblocked");
		private: String^ txtpath = System::IO::Path::Combine(System::IO::Path::GetTempPath(), "blocker.txt");


		private: System::ComponentModel::IContainer^  components;


		private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->timer = (gcnew System::Timers::Timer());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->blockToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->timer))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->SynchronizingObject = this;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3)
			{
				this->fileToolStripMenuItem,
					this->aboutToolStripMenuItem1, this->exitToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(784, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3)
			{
				this->blockToolStripMenuItem,
					this->aboutToolStripMenuItem, this->exitToolStripMenuItem1
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// blockToolStripMenuItem
			// 
			this->blockToolStripMenuItem->Name = L"blockToolStripMenuItem";
			this->blockToolStripMenuItem->Size = System::Drawing::Size(106, 22);
			this->blockToolStripMenuItem->Text = L"Open";
			this->blockToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::blockToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(106, 22);
			this->aboutToolStripMenuItem->Text = L"Block!";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::aboutToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem1
			// 
			this->exitToolStripMenuItem1->Name = L"exitToolStripMenuItem1";
			this->exitToolStripMenuItem1->Size = System::Drawing::Size(106, 22);
			this->exitToolStripMenuItem1->Text = L"Exit";
			this->exitToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::exitToolStripMenuItem1_Click);
			// 
			// aboutToolStripMenuItem1
			// 
			this->aboutToolStripMenuItem1->Name = L"aboutToolStripMenuItem1";
			this->aboutToolStripMenuItem1->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem1->Text = L"About";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exitToolStripMenuItem_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Appearance = System::Windows::Forms::TabAppearance::FlatButtons;
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(12, 27);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(760, 523);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->listBox1);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(752, 494);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Sites";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(247, 454);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(260, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Clear list";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(247, 425);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(260, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Import a file";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(381, 73);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(177, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Remove";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(247, 116);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(260, 290);
			this->listBox1->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(198, 73);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(177, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->AcceptsReturn = true;
			this->textBox1->Location = System::Drawing::Point(198, 38);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(360, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::textBox1_KeyPress);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->radioButton2);
			this->tabPage2->Controls->Add(this->radioButton1);
			this->tabPage2->Controls->Add(this->dateTimePicker2);
			this->tabPage2->Controls->Add(this->dateTimePicker1);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(752, 494);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Schedule";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(202, 277);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(43, 17);
			this->radioButton2->TabIndex = 4;
			this->radioButton2->Text = L"24h";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(202, 253);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(62, 17);
			this->radioButton1->TabIndex = 3;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Regular";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton1_CheckedChanged);
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->CustomFormat = L"       HH:mm:tt";
			this->dateTimePicker2->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker2->Location = System::Drawing::Point(202, 201);
			this->dateTimePicker2->MinDate = System::DateTime(2015, 1, 15, 0, 0, 0, 0);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->ShowUpDown = true;
			this->dateTimePicker2->Size = System::Drawing::Size(106, 20);
			this->dateTimePicker2->TabIndex = 2;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(328, 201);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 1;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->label1);
			this->tabPage3->Controls->Add(this->button5);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(752, 494);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Start";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(134, 229);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(437, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"You have been blocked. Please wait until the timer runs out, or input the super s"
				L"ecret code!";
			this->label1->Visible = false;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(205, 113);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(300, 245);
			this->button5->TabIndex = 0;
			this->button5->Text = L"Block";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->BalloonTipText = L"Maximize Blocker";
			this->notifyIcon1->BalloonTipTitle = L"Blocker";
			this->notifyIcon1->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"notifyIcon1.Icon")));
			this->notifyIcon1->Text = L"Blocker";
			this->notifyIcon1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::notifyIcon1_MouseDoubleClick);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"Text Files|*.txt";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::openFileDialog1_FileOk);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 562);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"Blocker";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->Resize += gcnew System::EventHandler(this, &MainForm::MainForm_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->timer))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		//check if window is open - if yes, when minimized the tray icon is visible
		//and the form is hidden

		//MAINFORM MINIMIZE TO TRAY
		private: System::Void MainForm_Resize(System::Object^  sender, System::EventArgs^  e)
		{
			notifyIcon1->BalloonTipTitle = "Minimized to tray!";
			notifyIcon1->BalloonTipText = "Blocker has been minimized to the system tray. It will continue to run in the background!";

			if (FormWindowState::Minimized == this->WindowState)
			{
				notifyIcon1->Visible = true;
				notifyIcon1->ShowBalloonTip(500);
				this->Hide();
			}

			else if (FormWindowState::Normal == this->WindowState)
			{
				notifyIcon1->Visible = false;
			}
		}
				 //ON TRAY ICON DOUBLECLICK
		private: System::Void notifyIcon1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		{
			this->Show();
			this->WindowState = FormWindowState::Normal;
		}
				 //ADD LISTBOX ITEMS
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (textBox1->TextLength != 0)
			{
				listBox1->Items->Add(textBox1->Text);
				textBox1->Clear();
			}
		}
				 //REMOVE LISTBOX ITEMS
		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
		{
			listBox1->Items->Remove(listBox1->SelectedItem);
		}
				 //CLEAR LISTBOX ITEMS
		private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e)
		{
			listBox1->Items->Clear();
		}

				 //TEXTBOX ENTER KEY PRESS
		private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^ e)
		{
			if ((e->KeyChar == 13) && (textBox1->TextLength != 0))
			{
				listBox1->Items->Add(textBox1->Text);
				textBox1->Clear();
			}
		}
				 //OPEN FILE DIALOG
		private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
		{
			openFileDialog1->ShowDialog();
		}
				 //ON FILE OK -> DO
		private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
		{
			listBox1->Items->AddRange(IO::File::ReadAllLines(openFileDialog1->FileName));

		}
				 //ON TOOLSTRIP MENU EXIT BUTTON CLICK
		private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			Application::Exit();
		}
		private: System::Void exitToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e)
		{
			Application::Exit();
		}
		private: System::Void blockToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			openFileDialog1->ShowDialog();
		}
		private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (openFileDialog1->FileName != "\n")
			{
				MessageBox::Show("Please enter a website to block first!", "Error!", MessageBoxButtons::OK);
			}
			else
			{
				//TODO
			}
		}
		private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
		{
			dateTimePicker2->CustomFormat = "          HH:mm";
		}
		private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
		{
			dateTimePicker2->CustomFormat = "       HH:mm:tt";
		}
		private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e)
		{
			dateTimePicker1->MaxDate = DateTime::Now.AddDays(3);
			dateTimePicker1->MinDate = DateTime::Now;

			this->timer->Stop();

			checkPrevState();
		}
				 //custom methods
				 //check whether file with date and time exists (ex. if app was closed in the meantime)
		private: System::Void checkPrevState()
		{

		}
				 //write to .txt file in the temp directory with the chosen date and time;
		private: System::Void writeTimeToFile()
		{
			System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(txtpath);

			sw->WriteLine(this->alarmTime);
			sw->Flush();
			sw->Close();


		}
				 //open the hosts file and write the designated webpages
		private: System::Void block()
		{
			System::IO::StreamWriter^ sw = System::IO::File::AppendText(path);
			try
			{
				sw->WriteLine("## blocker begin list");

				for each (auto item in listBox1->Items)
				{
					sw->WriteLine("127.0.0.1 " + item->ToString());
					sw->WriteLine("127.0.0.1 www." + item->ToString());
				}
				sw->WriteLine("## blocker end list");
			}
			finally
			{
				sw->Close();
			}

			System::IO::File::Copy(path, blockedpath, 1);
		}

		private: System::Void backup()
		{
			System::IO::File::Copy(path, backuppath, 1);
		}


		private: System::Void unblock()
		{


			System::IO::File::Copy(backuppath, path, 1);

			System::IO::File::Delete(backuppath);
			System::IO::File::Delete(txtpath);
			System::IO::File::Delete(blockedpath);

			timer->Stop();

			if (FormWindowState::Minimized == this->WindowState)
			{
				notifyIcon1->BalloonTipText = "Unblocked.";
				notifyIcon1->BalloonTipTitle = "";
				notifyIcon1->ShowBalloonTip(500);
			}
			else
			{
				this->WindowState = FormWindowState::Minimized;
				this->Show();
				this->WindowState = FormWindowState::Normal;

				MessageBox::Show("UNBLOCKED!");
			}



			label1->Visible = false;
			button5->Visible = true;
			button5->Enabled = true;
		}

				 //block button click
		private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e)
		{
			backup();

			block();

			button5->Visible = false;
			button5->Enabled = false;
			label1->Visible = true;

			inputToSeconds();
			this->clockTime = currentTimeToSeconds();
			this->timer->Start();
			writeTimeToFile();
		}

				 //TIMER CODE!
		public: System::Void initTimer()
		{
			this->timer->Elapsed += gcnew System::Timers::ElapsedEventHandler(this, &MainForm::OnTimer);
			this->timer->Interval = 1000;
			this->timer->Enabled = true;
		}

		public: System::Void OnTimer(System::Object ^object, System::Timers::ElapsedEventArgs ^e)
		{
			int tempTime = 0;
			int blockedHostsFileSize = System::IO::FileInfo(blockedpath).Length;
			int currentHostsFileSize = 0;

			try
			{
				this->clockTime++;
				tempTime++;
				int countdown = this->alarmTime - this->clockTime;

				if (this->alarmTime != 0)
				{
					//countdown
				}

				if (this->clockTime == this->alarmTime)
				{
					unblock();
				}
				else
				{
					if (tempTime == 30)
					{
						tempTime = 0;
						currentHostsFileSize = System::IO::FileInfo(path).Length;

						if (currentHostsFileSize != blockedHostsFileSize)
						{
							System::IO::File::Copy(blockedpath, path, 1);
						}
					}
				}


			}
			catch (Exception^ ex)
			{
				MessageBox::Show("OnTimer(): " + ex->Message);
			}
		}

		private: System::Void inputToSeconds()
		{
			try
			{
				int minutes = 0;
				int	hours = 0;

				hours = dateTimePicker2->Value.Hour;
				minutes = dateTimePicker2->Value.Minute;

				this->alarmTime += minutes * 60;
				this->alarmTime += (hours * 60) * 60;
			}
			catch (Exception^ e)
			{
				MessageBox::Show(e->Message);
			}
		}

		private: System::Int32 currentTimeToSeconds()
		{
			int startTimeInSeconds = 0;
			int hour;
			int minutes;
			this->clockTime = 0;

			hour = DateTime::Now.Hour;
			minutes = DateTime::Now.Minute;

			startTimeInSeconds += minutes * 60;
			startTimeInSeconds += (hour * 60) * 60;

			return (startTimeInSeconds);
		}
	};
}
