#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
void txt_produce(int mode, string namedate) {
	bool break_confirm = 0;
	string filename;
	string line;
	string confirm;
	string addmenu[] = { "food.txt","transportation.txt","toy.txt","stationary.txt","others.txt","income.txt" };
	if (mode != 7) {
		cout << "Name : " << namedate.substr(0,namedate.size()-4) << " Date : " << namedate.substr(namedate.size()-4,4)<<endl<< endl;
		filename = namedate + addmenu[mode - 1];
		ifstream fread(filename.c_str());
		if (fread.fail()) {
			cout << "error on reading " << filename << endl;
			fread.close();
			return ;
		}
		while (getline(fread, line)) {
			cout << line << "\n" << endl;
		}
		while (1) {
				cout << "Quit (y/n): "; cin >> confirm;
				if (confirm == "y") {
					cout << "\033[2J\033[1;1H"; //system("cls");
					break;
				}
				else if (confirm == "n") {
				}
			}

		fread.close();
	}
	else {
		for (int i = 1; i < 7; i++) {
			filename = namedate + addmenu[i - 1];
			ifstream fread(filename.c_str());
			if (fread.fail()) {
				cout << "error on reading " << filename << endl;
				fread.close();
			}
			while (getline(fread, line)) {
				cout << line << endl << endl;
			}
			fread.close();
			while (1) {
				cout << "Next file(y/n): "; cin >> confirm;
				if (confirm == "y") {
					cout << "\033[2J\033[1;1H"; //system("cls");
					break;
				}
				else if (confirm == "n") {
					cout << "\033[2J\033[1;1H"; //system("cls");
					break_confirm = 1;
					break;
				}
			}
			if (break_confirm == 1) {
				break;
			}
		}
	}
}
int search(string name) {
	string Date;
	int scope = 0;
	cout << "\033[2J\033[1;1H"; //system("cls");
	cout << "\nDATE (MMDD) : "; cin >> Date;
	cout << "\n\n\tSearch" << endl;
	cout << "\n\t01. Food" << endl;
	cout << "\n\t02. Transportation" << endl;
	cout << "\n\t03. Toy" << endl;
	cout << "\n\t04. Stationary" << endl;
	cout << "\n\t05. Others" << endl;
	cout << "\n\t06. Income" << endl;
	cout << "\n\t07. All" << endl;
	cout << "\n\t00. Back to Main Menu" << endl;
	cout << "\n\n\tPlease Select Your Option (0-7)  ";
	cin >> scope;
	cout << "\033[2J\033[1;1H"; //system("cls");
	txt_produce(scope,name+Date);
	return 0;
}
