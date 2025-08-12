#include "LoginScreen.h"




int main()
{

	while (true)
	{
		
		if(!LoginScreen::showLoginScreen())
			break; //if login failed then exit the program
		LoginScreen::showLoginScreen();
    }
	
	
    return 0;
}
