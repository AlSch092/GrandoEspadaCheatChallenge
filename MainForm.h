#pragma once
#include "Hooks.hpp"
#include "Packets/Packets.hpp"
#include <queue>

extern std::queue<PacketWriter*> SendPacketQueue;

namespace GEPacketSender {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Runtime::InteropServices;

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
		}
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_LogPackets;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^  copySelectedToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clearLogToolStripMenuItem;
	private: System::Windows::Forms::CheckBox^  checkBox_HookSend;
	private: System::Windows::Forms::TextBox^  textBox_StealGifts;
	private: System::Windows::Forms::CheckBox^  checkBox_StealCashItems;

		Thread^ SendLogThread;

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
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::ListView^  listView_PacketLog;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_PacketLength;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_PacketData;
	private: System::Windows::Forms::TextBox^  textBox_SendPacket;
	private: System::Windows::Forms::Button^  button_SendPacket;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Button^  button_RecvPacket;
	private: System::Windows::Forms::TextBox^  textBox_RecvPacket;
	private: System::Windows::Forms::ListView^  listView_RecvPacketLog;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Button^  button_EndScript;
	private: System::Windows::Forms::Button^  button_RunScript;
	private: System::Windows::Forms::TextBox^  textBox_ScriptText;
	private: System::Windows::Forms::TabPage^  tabPage4;

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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->listView_PacketLog = (gcnew System::Windows::Forms::ListView());
			this->columnHeader_PacketLength = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_PacketData = (gcnew System::Windows::Forms::ColumnHeader());
			this->contextMenuStrip_LogPackets = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->copySelectedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearLogToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox_SendPacket = (gcnew System::Windows::Forms::TextBox());
			this->button_SendPacket = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button_RecvPacket = (gcnew System::Windows::Forms::Button());
			this->textBox_RecvPacket = (gcnew System::Windows::Forms::TextBox());
			this->listView_RecvPacketLog = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->button_EndScript = (gcnew System::Windows::Forms::Button());
			this->button_RunScript = (gcnew System::Windows::Forms::Button());
			this->textBox_ScriptText = (gcnew System::Windows::Forms::TextBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->checkBox_StealCashItems = (gcnew System::Windows::Forms::CheckBox());
			this->textBox_StealGifts = (gcnew System::Windows::Forms::TextBox());
			this->checkBox_HookSend = (gcnew System::Windows::Forms::CheckBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->contextMenuStrip_LogPackets->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(667, 347);
			this->tabControl1->TabIndex = 9;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage1->Controls->Add(this->checkBox_HookSend);
			this->tabPage1->Controls->Add(this->listView_PacketLog);
			this->tabPage1->Controls->Add(this->textBox_SendPacket);
			this->tabPage1->Controls->Add(this->button_SendPacket);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(659, 321);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Send";
			// 
			// listView_PacketLog
			// 
			this->listView_PacketLog->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listView_PacketLog->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->columnHeader_PacketLength,
					this->columnHeader_PacketData
			});
			this->listView_PacketLog->ContextMenuStrip = this->contextMenuStrip_LogPackets;
			this->listView_PacketLog->FullRowSelect = true;
			this->listView_PacketLog->GridLines = true;
			this->listView_PacketLog->Location = System::Drawing::Point(6, 6);
			this->listView_PacketLog->Name = L"listView_PacketLog";
			this->listView_PacketLog->Size = System::Drawing::Size(647, 283);
			this->listView_PacketLog->TabIndex = 1;
			this->listView_PacketLog->UseCompatibleStateImageBehavior = false;
			this->listView_PacketLog->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader_PacketLength
			// 
			this->columnHeader_PacketLength->Text = L"Length";
			// 
			// columnHeader_PacketData
			// 
			this->columnHeader_PacketData->Text = L"Data";
			this->columnHeader_PacketData->Width = 854;
			// 
			// contextMenuStrip_LogPackets
			// 
			this->contextMenuStrip_LogPackets->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->copySelectedToolStripMenuItem,
					this->clearLogToolStripMenuItem
			});
			this->contextMenuStrip_LogPackets->Name = L"contextMenuStrip_LogPackets";
			this->contextMenuStrip_LogPackets->Size = System::Drawing::Size(150, 48);
			// 
			// copySelectedToolStripMenuItem
			// 
			this->copySelectedToolStripMenuItem->Name = L"copySelectedToolStripMenuItem";
			this->copySelectedToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->copySelectedToolStripMenuItem->Text = L"Copy Selected";
			this->copySelectedToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::copySelectedToolStripMenuItem_Click);
			// 
			// clearLogToolStripMenuItem
			// 
			this->clearLogToolStripMenuItem->Name = L"clearLogToolStripMenuItem";
			this->clearLogToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->clearLogToolStripMenuItem->Text = L"Clear Log";
			this->clearLogToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::clearLogToolStripMenuItem_Click);
			// 
			// textBox_SendPacket
			// 
			this->textBox_SendPacket->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_SendPacket->Location = System::Drawing::Point(6, 295);
			this->textBox_SendPacket->Name = L"textBox_SendPacket";
			this->textBox_SendPacket->Size = System::Drawing::Size(504, 20);
			this->textBox_SendPacket->TabIndex = 2;
			this->textBox_SendPacket->Text = L"Enter Packet...";
			// 
			// button_SendPacket
			// 
			this->button_SendPacket->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_SendPacket->Location = System::Drawing::Point(598, 295);
			this->button_SendPacket->Name = L"button_SendPacket";
			this->button_SendPacket->Size = System::Drawing::Size(55, 22);
			this->button_SendPacket->TabIndex = 6;
			this->button_SendPacket->Text = L"Send";
			this->button_SendPacket->UseVisualStyleBackColor = true;
			this->button_SendPacket->Click += gcnew System::EventHandler(this, &MainForm::button_SendPacket_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage2->Controls->Add(this->button_RecvPacket);
			this->tabPage2->Controls->Add(this->textBox_RecvPacket);
			this->tabPage2->Controls->Add(this->listView_RecvPacketLog);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(659, 321);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Recv";
			// 
			// button_RecvPacket
			// 
			this->button_RecvPacket->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_RecvPacket->Location = System::Drawing::Point(598, 295);
			this->button_RecvPacket->Name = L"button_RecvPacket";
			this->button_RecvPacket->Size = System::Drawing::Size(55, 22);
			this->button_RecvPacket->TabIndex = 7;
			this->button_RecvPacket->Text = L"Recv";
			this->button_RecvPacket->UseVisualStyleBackColor = true;
			// 
			// textBox_RecvPacket
			// 
			this->textBox_RecvPacket->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_RecvPacket->Location = System::Drawing::Point(7, 295);
			this->textBox_RecvPacket->Name = L"textBox_RecvPacket";
			this->textBox_RecvPacket->Size = System::Drawing::Size(585, 20);
			this->textBox_RecvPacket->TabIndex = 3;
			this->textBox_RecvPacket->Text = L"Enter Packet...";
			// 
			// listView_RecvPacketLog
			// 
			this->listView_RecvPacketLog->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listView_RecvPacketLog->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->columnHeader1,
					this->columnHeader2
			});
			this->listView_RecvPacketLog->FullRowSelect = true;
			this->listView_RecvPacketLog->GridLines = true;
			this->listView_RecvPacketLog->Location = System::Drawing::Point(6, 5);
			this->listView_RecvPacketLog->Name = L"listView_RecvPacketLog";
			this->listView_RecvPacketLog->Size = System::Drawing::Size(647, 284);
			this->listView_RecvPacketLog->TabIndex = 2;
			this->listView_RecvPacketLog->UseCompatibleStateImageBehavior = false;
			this->listView_RecvPacketLog->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Length";
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Data";
			this->columnHeader2->Width = 854;
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage3->Controls->Add(this->button_EndScript);
			this->tabPage3->Controls->Add(this->button_RunScript);
			this->tabPage3->Controls->Add(this->textBox_ScriptText);
			this->tabPage3->ForeColor = System::Drawing::SystemColors::Control;
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(659, 321);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"LUA Scripting";
			// 
			// button_EndScript
			// 
			this->button_EndScript->BackColor = System::Drawing::Color::Chocolate;
			this->button_EndScript->Location = System::Drawing::Point(343, 293);
			this->button_EndScript->Name = L"button_EndScript";
			this->button_EndScript->Size = System::Drawing::Size(104, 23);
			this->button_EndScript->TabIndex = 4;
			this->button_EndScript->Text = L"End Script";
			this->button_EndScript->UseVisualStyleBackColor = false;
			// 
			// button_RunScript
			// 
			this->button_RunScript->BackColor = System::Drawing::Color::YellowGreen;
			this->button_RunScript->Location = System::Drawing::Point(3, 293);
			this->button_RunScript->Name = L"button_RunScript";
			this->button_RunScript->Size = System::Drawing::Size(336, 23);
			this->button_RunScript->TabIndex = 3;
			this->button_RunScript->Text = L"Run Script";
			this->button_RunScript->UseVisualStyleBackColor = false;
			// 
			// textBox_ScriptText
			// 
			this->textBox_ScriptText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_ScriptText->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_ScriptText->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_ScriptText->Location = System::Drawing::Point(2, 0);
			this->textBox_ScriptText->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox_ScriptText->Multiline = true;
			this->textBox_ScriptText->Name = L"textBox_ScriptText";
			this->textBox_ScriptText->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_ScriptText->Size = System::Drawing::Size(448, 287);
			this->textBox_ScriptText->TabIndex = 2;
			this->textBox_ScriptText->Text = L"Enter script here (or Download Script)\r\n";
			// 
			// tabPage4
			// 
			this->tabPage4->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage4->Controls->Add(this->textBox_StealGifts);
			this->tabPage4->Controls->Add(this->checkBox_StealCashItems);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(659, 321);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Hacks";
			// 
			// checkBox_StealCashItems
			// 
			this->checkBox_StealCashItems->AutoSize = true;
			this->checkBox_StealCashItems->Location = System::Drawing::Point(118, 14);
			this->checkBox_StealCashItems->Name = L"checkBox_StealCashItems";
			this->checkBox_StealCashItems->Size = System::Drawing::Size(77, 17);
			this->checkBox_StealCashItems->TabIndex = 5;
			this->checkBox_StealCashItems->Text = L"Steal Gifts!";
			this->checkBox_StealCashItems->UseVisualStyleBackColor = true;
			this->checkBox_StealCashItems->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox_StealCashItems_CheckedChanged);
			// 
			// textBox_StealGifts
			// 
			this->textBox_StealGifts->Location = System::Drawing::Point(12, 12);
			this->textBox_StealGifts->Name = L"textBox_StealGifts";
			this->textBox_StealGifts->Size = System::Drawing::Size(100, 20);
			this->textBox_StealGifts->TabIndex = 6;
			this->textBox_StealGifts->Text = L"Seed..";
			// 
			// checkBox_HookSend
			// 
			this->checkBox_HookSend->AutoSize = true;
			this->checkBox_HookSend->Location = System::Drawing::Point(516, 298);
			this->checkBox_HookSend->Name = L"checkBox_HookSend";
			this->checkBox_HookSend->Size = System::Drawing::Size(80, 17);
			this->checkBox_HookSend->TabIndex = 7;
			this->checkBox_HookSend->Text = L"Hook Send";
			this->checkBox_HookSend->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(691, 371);
			this->Controls->Add(this->tabControl1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->Text = L"GE Packet Sender";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->contextMenuStrip_LogPackets->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	public: System::Void ProcessSendQueue() {

		while (this->checkBox_HookSend->Checked == TRUE) {

			if (SendPacketQueue.size() > 0) {

				PacketWriter* sendPacket = SendPacketQueue.front();

				wchar_t *pwDataText;
				wchar_t pwLengthText[10];

				CHAR* packetString = convertPacketFormatToString((unsigned char*)sendPacket->GetBuffer(), sendPacket->GetSize());

				DWORD dwNum = MultiByteToWideChar(CP_UTF8, 0, packetString, -1, NULL, 0);
				_itow_s(sendPacket->GetSize(), pwLengthText, 10);

				pwDataText = new wchar_t[dwNum];
				MultiByteToWideChar(CP_UTF8, 0, packetString, -1, pwDataText, dwNum);

				String ^dataString = gcnew String(pwDataText);
				String ^lengthString = gcnew String(pwLengthText);

				array<String^>^ subItems = gcnew array<String^>(2);
				subItems[0] = gcnew String(lengthString);
				subItems[1] = gcnew String(dataString);

				ListViewItem^ itm = gcnew ListViewItem(subItems);
				this->listView_PacketLog->Items->Add(itm);

				SendPacketQueue.pop();
				delete sendPacket;
				delete[] pwDataText;
				free(packetString);
			}
			else
				Thread::Sleep(300);
		}
	}
	private: System::Void checkBox_HookSend_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

		if (this->checkBox_HookSend->Checked)
		{
			WriteHookBytes(Hooks::hPacketOut, Hooks::_CallbackSendHook, true);
			SendLogThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::ProcessSendQueue));
			SendLogThread->Start();
		}
		else
		{
			WriteHookBytes(Hooks::hPacketOut, Hooks::_CallbackSendHook, false);
		}
	}
private: System::Void button_SendPacket_Click(System::Object^  sender, System::EventArgs^  e) {

	Functions::SendPacket outPacket;
	outPacket = (Functions::SendPacket)Constants::_SendPacket;

	String^ Pocket = gcnew String(this->textBox_SendPacket->Text);
	char* string_packet = (char*)(void*)Marshal::StringToHGlobalAnsi(Pocket);
	LPBYTE buffer = convertStringToPacketFormat(string_packet);

	SendPacket(getPacketLength(string_packet), buffer);
	//outPacket(getPacketLength(string_packet), (LPBYTE)string_packet, (LPBYTE)0x00C0FE50);
}
private: System::Void clearLogToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->listView_PacketLog->Items->Clear();
}

private: System::Void copySelectedToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	
	Thread^ newThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::copySendPacket));
	newThread->SetApartmentState(System::Threading::ApartmentState::STA);
	newThread->Start();
}

private: System::Void copySendPacket() {

	ListViewItem^ selectedItem;

	for (int i = 0; i < listView_PacketLog->Items->Count; i++) {
		selectedItem = listView_PacketLog->Items[i];
		if (selectedItem->Selected == true) {
			String^ packetString = selectedItem->SubItems[1]->Text;
			Clipboard::SetDataObject(packetString, true);
		}
	}
}
private: System::Void checkBox_StealCashItems_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_StealCashItems->Checked)
	{

	}
	else
	{

	}
}
};
}
