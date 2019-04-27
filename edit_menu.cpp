#include "add.h"
#include "edit.h"
#include "delete.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include<limits>

using namespace std;
int edit_menu_main(string name,string Date) {
	int options;
	while (1) {
		cout << "\033[2J\033[1;1H"; //system("cls");
		cout << "\nDATE (MMDD) : " << Date<<endl;
		cout << "\n\n\tEDIT YOUR WALLET " <<endl;
		cout << "\n\n\t01: Insert" << endl;
		cout << "\n\n\t02: Remove" << endl;
		cout << "\n\n\t03: Edit" << endl;
		cout << "\n\n\t00: Back to main memu" << endl;
		cout << "\n\n\tPlease Select Your Option (0-3) : ";
		cin >> options;
		if (options == 1) {
			add_main(Date, name);
		}
		else if (options == 2) {
			delete_main(Date, name);
		}
		else if (options == 3) {
			edit_main(Date, name);
		}
		else if (options == 0) {
			break;
		}
	}
	return 0;
}
