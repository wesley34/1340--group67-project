#include "add.h"
#include "search.h"
#include "edit.h"
#include "delete.h"
#include "sort.h"
#include "menu_kid.h"
#include "tasks_trigger.h"
#include <sstream>
#include<limits>
#include <fstream>
//#include <conio.h>
#include <string>
#include <iostream>
#include <regex>
#include<iomanip>
using namespace std;

//***************************************************************
//    	function declaration
//****************************************************************

bool user_check(string &username);
void sign_up();
void forget();
bool email_valid(string email);
bool fileExists(string fileName);
string setPass();
void headers();
bool pwd_valid(string password);
void login_main(string &username);

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

int main() {
	string username;
	string confirm;
	our_group();
	login_main(username);
	cout << "\n\n\n\t01. PARENT";
	cout << "\n\n\t02. KID";
	cout << "\n\n\tYou are (1/2) : ";
	cin >> confirm;//default kids, becoz kids love enter string
	if (confirm == "1") {
		parents_task_main(username);
	}
	else {
		menu_main(username);
	}
	return 0;
}



//***************************************************************
//    	Greet
//****************************************************************

void headers() {
	cout << "\033[2J\033[1;1H";
	cout << "     ***************************************" << endl;
	cout << "     * Welcome to Your Financial Majordomo *" << endl;
	cout << "     ***************************************" << endl;
	cout << "\n\n\tLogin/Register";
	cout << "\n\n\t01. LOGIN";
	cout << "\n\n\t02. REGISTER";
	cout << "\n\n\t03. FORGET USERNAME OR PASSWORD";
	cout << "\n\n\t00. EXIT";
	cout << "\n\n\tPlease Select Your Option (0-3) ";

}
//***************************************************************
//    	THE Login FUNCTION OF PROGRAM
//****************************************************************

void login_main(string &username) {
	char a;
	bool check = false;
	do {
		headers();
		cin >> a;
		switch (a) {
		case '1': check = user_check(username);
			break;
		case '2': sign_up();
			cout << "\n\n\tReturn to menu . . . ";
			cin.get();
			break;
		case '3': forget();
			cout << "\n\n\tReturn to menu . . . ";
			cin.get();
			break;
		case '0': break;
		default:
			cout << "\a"; // alert users if a != 1 or 2 or 3 or 0
		}
	} while (a != '0' && !check);
	if (a == '0') {
		cout << "\n\n==========================================================\n";
		cout << "\n\tSee you next time!\n\n\t";
		exit(1);
	}
}

bool user_check(string &username) {
	string password_check, username_file, password;
	cout << "\n\n==========================================================\n";
	cout << "\n\tUsername: ";
	cin >> username;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	username_file = username + ".txt";
	if (fileExists(username_file)) {
		cout << "\n\tPassword: ";
		password = setPass();
		ifstream fin;
		fin.open(username_file);
		if (fin.fail()) {
			cout << "Error opening file";
			exit(1);
		}
		fin >> password_check;
		fin.close();
		for (int i = 0; i<5; i++) {
			if (password_check == password) {
				cout << "\n==========================================================\n";
				cout << "\n\tWelcome " << username << endl;
				cin.get();
				return true;
			}
			else {
				cout << "\n==========================================================\n";
				cout << "\n\tInvalid password. Please enter again \n";
				cout << "\n\tPassword: ";
				password = setPass();
			}
		}
		cout << "\n==========================================================\n";
		cout << "\nToo many trails. " << endl;
		cin.get();
		return false;
	}
	else {
		cout << "\n\n==========================================================\n";
		cout << "\n\tUser does not exit." << endl;
		cout << "\nReturn to menu . . . ";
		cin.get();
		return false;
	}
}

void sign_up() {
	string username_file, password_check, password;
	cout << "\n\n==========================================================\n";
	cout << "\n\tCreate username: ";
	cin >> username_file;
	username_file += ".txt";
	ofstream fi;

	for (int i = 0; fileExists(username_file); i++) {
		if (i == 5) {
			cout << "\tToo many trails. " << endl; // too many trials
			return;
		}
		cout << "\n\tUsername exists. Please enter another one: ";
		cin >> username_file;
		username_file += ".txt";
	}
	cout << "\n\tEnter your password: ";
	password = setPass();
	while (!pwd_valid(password)) {
		cout << "\tInvalid password. It should be 6 - 20 characters including both letters and numbers. \n\n\tEnter your password: "; // alert user for invalid pw
		password = setPass();
	}
	cout << "\tEnter your password again: ";
	password_check = setPass();
	cout << "\n==========================================================\n";
	while (password != password_check) {
		cout << "\n\tPasswords do not match\n\n\tEnter your password: ";
		password = setPass();
		while (!pwd_valid(password)) {
			cout << "\tInvalid password. It should be 6 - 20 characters including both letters and numbers. \n\n==========================================================\n\n\tEnter your password: ";
			password = setPass();
		}
		cout << "\n\tEnter your password again: ";
		password_check = setPass();
		cout << "\n==========================================================\n";
	}
	cout << "\tThank you\n";
	fi.open(username_file);
	if (fi.fail()) {
		cout << "Error opening file";
		exit(1);
	}
	fi << password;
	fi.close();
}

void forget() {
	string user_email;
	cout << "\n==========================================================\n";
	cout << "\n\tPlease enter your email address: ";
	cin >> user_email;
	cout << "\n==========================================================\n\n\t";
	cout << (email_valid(user_email) ? "Check your email" : "Invalid email address") << endl; //depends the bool return true or false.
}
//check if file exist.
bool fileExists(string fileName) {
	ifstream infile(fileName);
	return infile.good();
}
//email format check.
bool email_valid(string email) {
	const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	return regex_match(email, pattern);
}
// can mask the password if neccessary.Not works in Linux
string setPass() {
	string pass = "";
	string line;
	char c = ' ';
	getline(cin>>ws, line);
	istringstream iss(line);
	while (iss >> c) { pass.push_back(c); }
	cout << endl;
	return pass;
}


bool pwd_valid(string password) {
	if (password.length()<6 || password.length()>20) {//check if the password within 6 -20 chars
		return false;
	}
	else {
		return ((password.find_first_of("0123456789") != string::npos) && (password.find_first_of("abcdefghijklmnopqrstuvwxyz") != string::npos));//return true if have char and numbers
	}
}
