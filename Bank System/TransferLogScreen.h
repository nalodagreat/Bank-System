#pragma once
#include <fstream>
#include<iomanip>
#include <vector>
#include "Screen.h"
#include "BankClient.h"
class TransferLogScreen:protected Screen
{
	
	static void printtransferInfoLine(BankClient::stTransferInfo transferInfo)
    {
        string dateTime =
            transferInfo.dateAndTime + 
            transferInfo.idClientFrom + 
            transferInfo.IdClientTo + 
            to_string(transferInfo.amountTransfered)+
            to_string(transferInfo.BalanceOfClientTranferdFrom) +
            to_string(transferInfo.BalanceOfClientTranferdTo) +
            transferInfo.usernameOfAdminWhoMadeOp;

        cout << setw(8) << left << ""
            << "| " << setw(35) << left << dateTime
            << "| " << setw(20) << left << transferInfo.dateAndTime
            << "| " << setw(20) << left << transferInfo.idClientFrom
            << "| " << setw(10) << left << transferInfo.IdClientTo
            << "| " << setw(20) << left << transferInfo.amountTransfered
            << "| " << setw(20) << left << transferInfo.BalanceOfClientTranferdFrom
            << "| " << setw(20) << left << transferInfo.BalanceOfClientTranferdTo
            << "| " << setw(20) << left << transferInfo.usernameOfAdminWhoMadeOp
            << endl;
    }
public:
	static void showTransferLogScreen()
	{
		drawScreenHeader("\tTransferLogScreen\n");
		//read info from  TransferLogHistory
		vector <BankClient::stTransferInfo> vTransferList = BankClient::getTransferList();

        string title = "\tTransfer List Screen";
        string subTitle = "\t\t(" + to_string(vTransferList.size()) + ") Record(s).";

        drawScreenHeader(title, subTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time"
            << "| " << left << setw(20) << "From Client"
            << "| " << left << setw(20) << "To Client"
            << "| " << left << setw(20) << "Amount"
            << "| " << left << setw(20) << "BalanceFromClient"
            << "| " << left << setw(20) << "BalanceToClient"
            << "| " << left << setw(20) << "Admin" << endl;
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;


        if (vTransferList.size() == 0)
        {
            cout << "\t\t\t\tNo Transfers Available In the System!";
        }
        else
        {
            for (BankClient::stTransferInfo record : vTransferList)
            {
                printtransferInfoLine(record);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

	}
};

