#include "Includes.h"

namespace Minerva {

    void Form1::clearPacketLogButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->packetLogTextBox->Clear();
    }

    void Form1::sendPacketButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // Add functionality to send packet
    }

    void Form1::recvPacketButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // Add functionality to receive packet
    }

    void Form1::blockButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // Add functionality to block packet
    }

    void Form1::ignoreButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // Add functionality to ignore packet
    }

    void Form1::saveButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // Save profile
    }

    void Form1::deleteButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // Delete profile
    }

    void Form1::generateRandomButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Random^ rand = gcnew Random();
        array<Byte>^ hwidBytes = gcnew array<Byte>(4);
        array<Byte>^ macBytes = gcnew array<Byte>(6);
        rand->NextBytes(hwidBytes);
        rand->NextBytes(macBytes);
        hwidTextBox->Text = BitConverter::ToString(hwidBytes)->Replace("-", "");
        macTextBox->Text = BitConverter::ToString(macBytes)->Replace("-", "");
    }

    void Form1::loginButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // Perform login
    }

    void Form1::clearLogButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->logTextBox->Clear();
    }

    void Form1::Form1_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
    {
        // Handle form closing
    }

    void Form1::LogPacket(String^ packet, bool isSend)
    {
        if (isSend)
        {
            this->packetLogTextBox->AppendText("Send: " + packet + Environment::NewLine);
        }
        else
        {
            this->packetLogTextBox->AppendText("Recv: " + packet + Environment::NewLine);
        }
    }

    void Form1::LogMessage(String^ message)
    {
        this->logTextBox->AppendText(message + Environment::NewLine);
    }
}
