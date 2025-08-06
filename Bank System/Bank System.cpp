#include "BankClient.h"
#include <iostream>
using namespace std;
int main()
{
    BankClient client1 = BankClient::find("B456", "789");
    client1.print();
}
