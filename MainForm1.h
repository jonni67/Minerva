#pragma once

namespace Minerva {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
            formInstance = this;
        }

        // Delegate to log packets
        delegate void LogPacketDelegate(String^ packet, bool isSend);
        void LogPacket(String^ packet, bool isSend);

        // Method to log messages to the home page log
        void LogMessage(String^ message);

        // Static property to access the form instance
        static property Form1^ Instance
        {
            Form1^ get()
            {
                return formInstance;
            }
        }

    private: static Form1^ formInstance = nullptr;

    private: System::Windows::Forms::TabControl^ tabControl;
    private: System::Windows::Forms::TabPage^ packetsTabPage;
    private: System::Windows::Forms::TabPage^ homeTabPage;
    private: System::Windows::Forms::TabPage^ autoLoginTabPage;

           // Packet editor controls
    private: System::Windows::Forms::TextBox^ packetLogTextBox;
    private: System::Windows::Forms::TextBox^ packetTextBox;
    private: System::Windows::Forms::Button^ sendPacketButton;
    private: System::Windows::Forms::Button^ recvPacketButton;
    private: System::Windows::Forms::Button^ clearPacketLogButton;
    private: System::Windows::Forms::Button^ blockButton;
    private: System::Windows::Forms::Button^ ignoreButton;
    private: System::Windows::Forms::ListBox^ blockedHeadersListBox;
    private: System::Windows::Forms::ListBox^ ignoredHeadersListBox;
    private: System::Windows::Forms::Label^ blockedHeadersLabel;
    private: System::Windows::Forms::Label^ ignoredHeadersLabel;
    private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
    private: System::Windows::Forms::Button^ clearLogButton;
    private: System::Windows::Forms::Label^ logLabel;
    private: System::Windows::Forms::TextBox^ logTextBox;
    private: System::Windows::Forms::ListBox^ profileListBox;
    private: System::Windows::Forms::Panel^ buttonPanel;
    private: System::Windows::Forms::TextBox^ macTextBox;
    private: System::Windows::Forms::Label^ macLabel;
    private: System::Windows::Forms::TextBox^ hwidTextBox;
    private: System::Windows::Forms::Label^ hwidLabel;
    private: System::Windows::Forms::TextBox^ picTextBox;
    private: System::Windows::Forms::Label^ picLabel;
    private: System::Windows::Forms::TextBox^ pinTextBox;
    private: System::Windows::Forms::Label^ pinLabel;
    private: System::Windows::Forms::TextBox^ passwordTextBox;
    private: System::Windows::Forms::Label^ passwordLabel;
    private: System::Windows::Forms::TextBox^ usernameTextBox;
    private: System::Windows::Forms::Label^ usernameLabel;
    private: System::Windows::Forms::Button^ generateRandomButton;
    private: System::Windows::Forms::Button^ deleteButton;
    private: System::Windows::Forms::Button^ saveButton;
    private: System::Windows::Forms::Button^ loginButton;
    private: System::Windows::Forms::CheckBox^ rememberMeCheckBox;
    private: System::Windows::Forms::CheckBox^ autoLoginCheckBox;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->tabControl = (gcnew System::Windows::Forms::TabControl());
            this->packetsTabPage = (gcnew System::Windows::Forms::TabPage());
            this->clearPacketLogButton = (gcnew System::Windows::Forms::Button());
            this->packetLogTextBox = (gcnew System::Windows::Forms::TextBox());
            this->packetTextBox = (gcnew System::Windows::Forms::TextBox());
            this->sendPacketButton = (gcnew System::Windows::Forms::Button());
            this->recvPacketButton = (gcnew System::Windows::Forms::Button());
            this->blockButton = (gcnew System::Windows::Forms::Button());
            this->ignoreButton = (gcnew System::Windows::Forms::Button());
            this->blockedHeadersListBox = (gcnew System::Windows::Forms::ListBox());
            this->ignoredHeadersListBox = (gcnew System::Windows::Forms::ListBox());
            this->blockedHeadersLabel = (gcnew System::Windows::Forms::Label());
            this->ignoredHeadersLabel = (gcnew System::Windows::Forms::Label());
            this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
            this->buttonPanel = (gcnew System::Windows::Forms::Panel());
            this->macTextBox = (gcnew System::Windows::Forms::TextBox());
            this->macLabel = (gcnew System::Windows::Forms::Label());
            this->hwidTextBox = (gcnew System::Windows::Forms::TextBox());
            this->hwidLabel = (gcnew System::Windows::Forms::Label());
            this->picTextBox = (gcnew System::Windows::Forms::TextBox());
            this->picLabel = (gcnew System::Windows::Forms::Label());
            this->pinTextBox = (gcnew System::Windows::Forms::TextBox());
            this->pinLabel = (gcnew System::Windows::Forms::Label());
            this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
            this->passwordLabel = (gcnew System::Windows::Forms::Label());
            this->usernameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->usernameLabel = (gcnew System::Windows::Forms::Label());
            this->generateRandomButton = (gcnew System::Windows::Forms::Button());
            this->deleteButton = (gcnew System::Windows::Forms::Button());
            this->saveButton = (gcnew System::Windows::Forms::Button());
            this->loginButton = (gcnew System::Windows::Forms::Button());
            this->rememberMeCheckBox = (gcnew System::Windows::Forms::CheckBox());
            this->autoLoginCheckBox = (gcnew System::Windows::Forms::CheckBox());
            this->profileListBox = (gcnew System::Windows::Forms::ListBox());
            this->logTextBox = (gcnew System::Windows::Forms::TextBox());
            this->logLabel = (gcnew System::Windows::Forms::Label());
            this->clearLogButton = (gcnew System::Windows::Forms::Button());
            this->homeTabPage = (gcnew System::Windows::Forms::TabPage());
            this->autoLoginTabPage = (gcnew System::Windows::Forms::TabPage());
            this->tabControl->SuspendLayout();
            this->packetsTabPage->SuspendLayout();
            this->homeTabPage->SuspendLayout();
            this->autoLoginTabPage->SuspendLayout();
            this->SuspendLayout();
            // 
            // tabControl
            // 
            this->tabControl->Controls->Add(this->homeTabPage);
            this->tabControl->Controls->Add(this->packetsTabPage);
            this->tabControl->Controls->Add(this->autoLoginTabPage);
            this->tabControl->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tabControl->Location = System::Drawing::Point(0, 0);
            this->tabControl->Name = L"tabControl";
            this->tabControl->SelectedIndex = 0;
            this->tabControl->Size = System::Drawing::Size(800, 450);
            this->tabControl->TabIndex = 0;
            // 
            // packetsTabPage
            // 
            this->packetsTabPage->Controls->Add(this->clearPacketLogButton);
            this->packetsTabPage->Controls->Add(this->packetLogTextBox);
            this->packetsTabPage->Controls->Add(this->packetTextBox);
            this->packetsTabPage->Controls->Add(this->sendPacketButton);
            this->packetsTabPage->Controls->Add(this->recvPacketButton);
            this->packetsTabPage->Controls->Add(this->blockButton);
            this->packetsTabPage->Controls->Add(this->ignoreButton);
            this->packetsTabPage->Controls->Add(this->blockedHeadersListBox);
            this->packetsTabPage->Controls->Add(this->ignoredHeadersListBox);
            this->packetsTabPage->Controls->Add(this->blockedHeadersLabel);
            this->packetsTabPage->Controls->Add(this->ignoredHeadersLabel);
            this->packetsTabPage->Location = System::Drawing::Point(4, 22);
            this->packetsTabPage->Name = L"packetsTabPage";
            this->packetsTabPage->Padding = System::Windows::Forms::Padding(3);
            this->packetsTabPage->Size = System::Drawing::Size(792, 424);
            this->packetsTabPage->TabIndex = 1;
            this->packetsTabPage->Text = L"Packets";
            this->packetsTabPage->UseVisualStyleBackColor = true;
            // 
            // clearPacketLogButton
            // 
            this->clearPacketLogButton->Location = System::Drawing::Point(695, 6);
            this->clearPacketLogButton->Name = L"clearPacketLogButton";
            this->clearPacketLogButton->Size = System::Drawing::Size(75, 23);
            this->clearPacketLogButton->TabIndex = 1;
            this->clearPacketLogButton->Text = L"Clear Packet Log";
            this->clearPacketLogButton->Click += gcnew System::EventHandler(this, &Form1::clearPacketLogButton_Click);
            // 
            // packetLogTextBox
            // 
            this->packetLogTextBox->Location = System::Drawing::Point(10, 35);
            this->packetLogTextBox->Multiline = true;
            this->packetLogTextBox->Name = L"packetLogTextBox";
            this->packetLogTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->packetLogTextBox->Size = System::Drawing::Size(550, 275);
            this->packetLogTextBox->TabIndex = 0;
            // 
            // packetTextBox
            // 
            this->packetTextBox->Location = System::Drawing::Point(10, 365);
            this->packetTextBox->Name = L"packetTextBox";
            this->packetTextBox->Size = System::Drawing::Size(550, 20);
            this->packetTextBox->TabIndex = 1;
            // 
            // sendPacketButton
            // 
            this->sendPacketButton->Location = System::Drawing::Point(570, 365);
            this->sendPacketButton->Name = L"sendPacketButton";
            this->sendPacketButton->Size = System::Drawing::Size(100, 23);
            this->sendPacketButton->TabIndex = 2;
            this->sendPacketButton->Text = L"Send Packet";
            this->sendPacketButton->Click += gcnew System::EventHandler(this, &Form1::sendPacketButton_Click);
            // 
            // recvPacketButton
            // 
            this->recvPacketButton->Location = System::Drawing::Point(570, 390);
            this->recvPacketButton->Name = L"recvPacketButton";
            this->recvPacketButton->Size = System::Drawing::Size(100, 23);
            this->recvPacketButton->TabIndex = 3;
            this->recvPacketButton->Text = L"Recv Packet";
            this->recvPacketButton->Click += gcnew System::EventHandler(this, &Form1::recvPacketButton_Click);
            // 
            // blockButton
            // 
            this->blockButton->Location = System::Drawing::Point(570, 335);
            this->blockButton->Name = L"blockButton";
            this->blockButton->Size = System::Drawing::Size(100, 23);
            this->blockButton->TabIndex = 4;
            this->blockButton->Text = L"Block";
            this->blockButton->Click += gcnew System::EventHandler(this, &Form1::blockButton_Click);
            // 
            // ignoreButton
            // 
            this->ignoreButton->Location = System::Drawing::Point(680, 335);
            this->ignoreButton->Name = L"ignoreButton";
            this->ignoreButton->Size = System::Drawing::Size(100, 23);
            this->ignoreButton->TabIndex = 5;
            this->ignoreButton->Text = L"Ignore";
            this->ignoreButton->Click += gcnew System::EventHandler(this, &Form1::ignoreButton_Click);
            // 
            // blockedHeadersListBox
            // 
            this->blockedHeadersListBox->Location = System::Drawing::Point(570, 35);
            this->blockedHeadersListBox->Name = L"blockedHeadersListBox";
            this->blockedHeadersListBox->Size = System::Drawing::Size(210, 150);
            this->blockedHeadersListBox->TabIndex = 6;
            // 
            // ignoredHeadersListBox
            // 
            this->ignoredHeadersListBox->Location = System::Drawing::Point(570, 200);
            this->ignoredHeadersListBox->Name = L"ignoredHeadersListBox";
            this->ignoredHeadersListBox->Size = System::Drawing::Size(210, 150);
            this->ignoredHeadersListBox->TabIndex = 7;
            // 
            // blockedHeadersLabel
            // 
            this->blockedHeadersLabel->Location = System::Drawing::Point(570, 20);
            this->blockedHeadersLabel->Name = L"blockedHeadersLabel";
            this->blockedHeadersLabel->Size = System::Drawing::Size(100, 15);
            this->blockedHeadersLabel->TabIndex = 8;
            this->blockedHeadersLabel->Text = L"Blocked Headers";
            // 
            // ignoredHeadersLabel
            // 
            this->ignoredHeadersLabel->Location = System::Drawing::Point(570, 185);
            this->ignoredHeadersLabel->Name = L"ignoredHeadersLabel";
            this->ignoredHeadersLabel->Size = System::Drawing::Size(100, 15);
            this->ignoredHeadersLabel->TabIndex = 9;
            this->ignoredHeadersLabel->Text = L"Ignored Headers";
            // 
            // backgroundWorker1
            // 
            // 
            // buttonPanel
            // 
            this->buttonPanel->Dock = System::Windows::Forms::DockStyle::Left;
            this->buttonPanel->Location = System::Drawing::Point(3, 3);
            this->buttonPanel->Name = L"buttonPanel";
            this->buttonPanel->Size = System::Drawing::Size(200, 418);
            this->buttonPanel->TabIndex = 3;
            // 
            // macTextBox
            // 
            this->macTextBox->Location = System::Drawing::Point(10, 280);
            this->macTextBox->Name = L"macTextBox";
            this->macTextBox->Size = System::Drawing::Size(160, 20);
            this->macTextBox->TabIndex = 15;
            // 
            // macLabel
            // 
            this->macLabel->Location = System::Drawing::Point(10, 260);
            this->macLabel->Name = L"macLabel";
            this->macLabel->Size = System::Drawing::Size(100, 23);
            this->macLabel->TabIndex = 14;
            this->macLabel->Text = L"MAC Address";
            // 
            // hwidTextBox
            // 
            this->hwidTextBox->Location = System::Drawing::Point(10, 230);
            this->hwidTextBox->Name = L"hwidTextBox";
            this->hwidTextBox->Size = System::Drawing::Size(160, 20);
            this->hwidTextBox->TabIndex = 13;
            // 
            // hwidLabel
            // 
            this->hwidLabel->Location = System::Drawing::Point(10, 210);
            this->hwidLabel->Name = L"hwidLabel";
            this->hwidLabel->Size = System::Drawing::Size(100, 23);
            this->hwidLabel->TabIndex = 12;
            this->hwidLabel->Text = L"HWID";
            // 
            // picTextBox
            // 
            this->picTextBox->Location = System::Drawing::Point(10, 180);
            this->picTextBox->MaxLength = 6;
            this->picTextBox->Name = L"picTextBox";
            this->picTextBox->Size = System::Drawing::Size(160, 20);
            this->picTextBox->TabIndex = 11;
            // 
            // picLabel
            // 
            this->picLabel->Location = System::Drawing::Point(10, 160);
            this->picLabel->Name = L"picLabel";
            this->picLabel->Size = System::Drawing::Size(100, 23);
            this->picLabel->TabIndex = 10;
            this->picLabel->Text = L"PIC";
            // 
            // pinTextBox
            // 
            this->pinTextBox->Location = System::Drawing::Point(10, 130);
            this->pinTextBox->MaxLength = 4;
            this->pinTextBox->Name = L"pinTextBox";
            this->pinTextBox->Size = System::Drawing::Size(160, 20);
            this->pinTextBox->TabIndex = 9;
            // 
            // pinLabel
            // 
            this->pinLabel->Location = System::Drawing::Point(10, 110);
            this->pinLabel->Name = L"pinLabel";
            this->pinLabel->Size = System::Drawing::Size(100, 23);
            this->pinLabel->TabIndex = 8;
            this->pinLabel->Text = L"PIN";
            // 
            // passwordTextBox
            // 
            this->passwordTextBox->Location = System::Drawing::Point(10, 80);
            this->passwordTextBox->Name = L"passwordTextBox";
            this->passwordTextBox->Size = System::Drawing::Size(160, 20);
            this->passwordTextBox->TabIndex = 7;
            this->passwordTextBox->UseSystemPasswordChar = true;
            // 
            // passwordLabel
            // 
            this->passwordLabel->Location = System::Drawing::Point(10, 60);
            this->passwordLabel->Name = L"passwordLabel";
            this->passwordLabel->Size = System::Drawing::Size(100, 23);
            this->passwordLabel->TabIndex = 6;
            this->passwordLabel->Text = L"Password";
            // 
            // usernameTextBox
            // 
            this->usernameTextBox->Location = System::Drawing::Point(10, 30);
            this->usernameTextBox->Name = L"usernameTextBox";
            this->usernameTextBox->Size = System::Drawing::Size(160, 20);
            this->usernameTextBox->TabIndex = 5;
            // 
            // usernameLabel
            // 
            this->usernameLabel->Location = System::Drawing::Point(10, 10);
            this->usernameLabel->Name = L"usernameLabel";
            this->usernameLabel->Size = System::Drawing::Size(100, 23);
            this->usernameLabel->TabIndex = 4;
            this->usernameLabel->Text = L"Username";
            // 
            // generateRandomButton
            // 
            this->generateRandomButton->Location = System::Drawing::Point(10, 306);
            this->generateRandomButton->Name = L"generateRandomButton";
            this->generateRandomButton->Size = System::Drawing::Size(160, 23);
            this->generateRandomButton->TabIndex = 3;
            this->generateRandomButton->Text = L"Generate Random";
            this->generateRandomButton->Click += gcnew System::EventHandler(this, &Form1::generateRandomButton_Click);
            // 
            // deleteButton
            // 
            this->deleteButton->Location = System::Drawing::Point(91, 335);
            this->deleteButton->Name = L"deleteButton";
            this->deleteButton->Size = System::Drawing::Size(79, 23);
            this->deleteButton->TabIndex = 2;
            this->deleteButton->Text = L"Delete";
            this->deleteButton->Click += gcnew System::EventHandler(this, &Form1::deleteButton_Click);
            // 
            // saveButton
            // 
            this->saveButton->Location = System::Drawing::Point(10, 335);
            this->saveButton->Name = L"saveButton";
            this->saveButton->Size = System::Drawing::Size(75, 23);
            this->saveButton->TabIndex = 1;
            this->saveButton->Text = L"Save";
            this->saveButton->Click += gcnew System::EventHandler(this, &Form1::saveButton_Click);
            // 
            // loginButton
            // 
            this->loginButton->Location = System::Drawing::Point(50, 373);
            this->loginButton->Name = L"loginButton";
            this->loginButton->Size = System::Drawing::Size(75, 23);
            this->loginButton->TabIndex = 0;
            this->loginButton->Text = L"Login";
            this->loginButton->Click += gcnew System::EventHandler(this, &Form1::loginButton_Click);
            // 
            // rememberMeCheckBox
            // 
            this->rememberMeCheckBox->Location = System::Drawing::Point(10, 400);
            this->rememberMeCheckBox->Name = L"rememberMeCheckBox";
            this->rememberMeCheckBox->Size = System::Drawing::Size(120, 24);
            this->rememberMeCheckBox->TabIndex = 16;
            this->rememberMeCheckBox->Text = L"Remember Me";
            // 
            // autoLoginCheckBox
            // 
            this->autoLoginCheckBox->Location = System::Drawing::Point(140, 400);
            this->autoLoginCheckBox->Name = L"autoLoginCheckBox";
            this->autoLoginCheckBox->Size = System::Drawing::Size(120, 24);
            this->autoLoginCheckBox->TabIndex = 17;
            this->autoLoginCheckBox->Text = L"Auto Login";
            // 
            // profileListBox
            // 
            this->profileListBox->Location = System::Drawing::Point(220, 21);
            this->profileListBox->Name = L"profileListBox";
            this->profileListBox->Size = System::Drawing::Size(200, 394);
            this->profileListBox->TabIndex = 2;
            // 
            // logTextBox
            // 
            this->logTextBox->Location = System::Drawing::Point(3, 29);
            this->logTextBox->Multiline = true;
            this->logTextBox->Name = L"logTextBox";
            this->logTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->logTextBox->Size = System::Drawing::Size(780, 392);
            this->logTextBox->TabIndex = 1;
            // 
            // logLabel
            // 
            this->logLabel->Location = System::Drawing::Point(3, 6);
            this->logLabel->Name = L"logLabel";
            this->logLabel->Size = System::Drawing::Size(100, 15);
            this->logLabel->TabIndex = 0;
            this->logLabel->Text = L"Log";
            // 
            // clearLogButton
            // 
            this->clearLogButton->Location = System::Drawing::Point(708, 3);
            this->clearLogButton->Name = L"clearLogButton";
            this->clearLogButton->Size = System::Drawing::Size(75, 23);
            this->clearLogButton->TabIndex = 1;
            this->clearLogButton->Text = L"Clear Log";
            this->clearLogButton->Click += gcnew System::EventHandler(this, &Form1::clearLogButton_Click);
            // 
            // homeTabPage
            // 
            this->homeTabPage->Controls->Add(this->clearLogButton);
            this->homeTabPage->Controls->Add(this->logLabel);
            this->homeTabPage->Controls->Add(this->logTextBox);
            this->homeTabPage->Location = System::Drawing::Point(4, 22);
            this->homeTabPage->Name = L"homeTabPage";
            this->homeTabPage->Padding = System::Windows::Forms::Padding(3);
            this->homeTabPage->Size = System::Drawing::Size(792, 424);
            this->homeTabPage->TabIndex = 0;
            this->homeTabPage->Text = L"Home";
            this->homeTabPage->UseVisualStyleBackColor = true;
            // 
            // autoLoginTabPage
            // 
            this->autoLoginTabPage->Controls->Add(this->rememberMeCheckBox);
            this->autoLoginTabPage->Controls->Add(this->autoLoginCheckBox);
            this->autoLoginTabPage->Controls->Add(this->profileListBox);
            this->autoLoginTabPage->Controls->Add(this->usernameLabel);
            this->autoLoginTabPage->Controls->Add(this->usernameTextBox);
            this->autoLoginTabPage->Controls->Add(this->passwordLabel);
            this->autoLoginTabPage->Controls->Add(this->passwordTextBox);
            this->autoLoginTabPage->Controls->Add(this->pinLabel);
            this->autoLoginTabPage->Controls->Add(this->pinTextBox);
            this->autoLoginTabPage->Controls->Add(this->picLabel);
            this->autoLoginTabPage->Controls->Add(this->picTextBox);
            this->autoLoginTabPage->Controls->Add(this->hwidLabel);
            this->autoLoginTabPage->Controls->Add(this->hwidTextBox);
            this->autoLoginTabPage->Controls->Add(this->macLabel);
            this->autoLoginTabPage->Controls->Add(this->macTextBox);
            this->autoLoginTabPage->Controls->Add(this->generateRandomButton);
            this->autoLoginTabPage->Controls->Add(this->deleteButton);
            this->autoLoginTabPage->Controls->Add(this->saveButton);
            this->autoLoginTabPage->Controls->Add(this->loginButton);
            this->autoLoginTabPage->Location = System::Drawing::Point(4, 22);
            this->autoLoginTabPage->Name = L"autoLoginTabPage";
            this->autoLoginTabPage->Padding = System::Windows::Forms::Padding(3);
            this->autoLoginTabPage->Size = System::Drawing::Size(792, 424);
            this->autoLoginTabPage->TabIndex = 2;
            this->autoLoginTabPage->Text = L"Auto Login";
            this->autoLoginTabPage->UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(800, 450);
            this->Controls->Add(this->tabControl);
            this->Name = L"Form1";
            this->Text = L"Minerva";
            this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
            this->tabControl->ResumeLayout(false);
            this->packetsTabPage->ResumeLayout(false);
            this->packetsTabPage->PerformLayout();
            this->homeTabPage->ResumeLayout(false);
            this->homeTabPage->PerformLayout();
            this->autoLoginTabPage->ResumeLayout(false);
            this->autoLoginTabPage->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion

    private: System::Void clearPacketLogButton_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void sendPacketButton_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void recvPacketButton_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void blockButton_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void ignoreButton_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void generateRandomButton_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void loginButton_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void clearLogButton_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void Form1_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
    };
}
