#include <iostream>
#include "Libraries.h"
#include <ctime>

// Get information about the current username
// Don't worry, It's harmless, however
#include <Windows.h>
#include <lmcons.h>

using namespace std;

/* Functions */

// Sector: Grab the current name of the active Windows User

bool IsOKName() {
	// Check if username is ok
	// Borrowed from same StackOverflow thread

	TCHAR username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;

	return GetUserName((TCHAR*)username, &username_len)!=NULL;
}

// Sector 2: Unrelated arthimetic

// *S*econdsTo*M*illiseconds
int SM(int number) {
	
	return (number * 1000);
}

int main() {
	// Stolen from StackOverflow, credit link below:
	// https://stackoverflow.com/questions/11587426/get-current-username-in-c-on-windows

	TCHAR username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;

	/* Is this really the best way we could go about it? */

	// Ok I FINALLY Figured it out, you have to fetch the username in the same
	// function as you're trying to log it inside of.
    
	GetUserName((TCHAR*)username, &username_len);

	Sleep(SM(1));

	if (IsOKName() == true) {
		// example: "Good evening, keboard4."
		wcout << L"Hello, " << username << L"." << "\n";
	}
	else {
		cerr << "Unexpected Error; " << GetLastError() << ". Try again later.";
	}

	// 1 second: 1,000 milliseconds
	Sleep(SM(1));

	cout << "Thank you for trying my program..." << endl;

	return 0;
}