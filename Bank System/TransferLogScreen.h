#pragma once
#include <fstream>
#include <iomanip>
#include <vector>
#include "Screen.h"
#include "BankClient.h"

class TransferLogScreen : protected Screen
{
private:
    static void printtransferInfoLine(BankClient::stTransferInfo transferInfo)
    {
        cout << setw(8) << left << "" << "| " << setw(23) << left << transferInfo.dateAndTime;
        cout << "| " << setw(8) << left << transferInfo.idClientFrom;
        cout << "| " << setw(8) << left << transferInfo.IdClientTo;
        cout << "| " << setw(8) << left << transferInfo.amountTransfered;
        cout << "| " << setw(10) << left << transferInfo.BalanceOfClientTranferdFrom;
        cout << "| " << setw(10) << left << transferInfo.BalanceOfClientTranferdTo;
        cout << "| " << setw(8) << left << transferInfo.usernameOfAdminWhoMadeOp << endl;
    }

public:
    static void showTransferLogScreen()
    {
        vector<BankClient::stTransferInfo> vTransferList = BankClient::getTransferList();

        string title = "\tTransfer Log List Screen";
        string subTitle = "\t    (" + to_string(vTransferList.size()) + ") Record(s).";

        drawScreenHeader(title, subTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User" << endl;

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferList.empty())
            cout << "\t\t\t\tNo Transfers Available In the System!\n";
        else
            for (const BankClient::stTransferInfo& record : vTransferList)
                printtransferInfoLine(record);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};
