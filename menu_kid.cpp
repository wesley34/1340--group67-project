#include "edit_menu.h"
#include "search.h"
#include "sort.h"
#include "add.h"
#include "predict.h"
#include "dl.h"
#include "tasks_trigger.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include <string>
#include <limits>
//#include"login.h"
using namespace std;
//***************************************************************
//    	function declaration
//****************************************************************
void our_group();
void no_of_tasks(string name);
void create_task(string name);

//***************************************************************
//    	Main menu
//****************************************************************
int menu_main(string name)
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	double acc = 0;
	string Filename;
	string Date;
	char ch;
	cout.setf(ios::fixed | ios::showpoint);
	cout << setprecision(2); // program outputs decimal number to two decimal places
	create_task(name);
	do
	{
		cout << "\033[2J\033[1;1H"; //system("cls");
		cout << "\n\n\n\tName: " << name << endl;
		cout << "\n\n\t01. EDIT YOUR WALLET";
		cout << "\n\n\t02. REPORT";
		cout << "\n\n\t03. SEARCH";
		cout << "\n\n\t04. TASKS";
		no_of_tasks(name); // real time to show how many tasks to do
		cout << "\n\n\t05. SORT";
		cout << "\n\n\t06. INITIALIZE";
		cout << "\n\n\t07. DEEP LEARNING";
		cout << "\n\n\t00. EXIT";
		cout << "\n\n\tPlease Select Your Option (0-7) : ";
		cin >> ch;
		cout << "\n\n==========================================================\n";
		switch (ch)
		{
		case '1':
			cout << "\033[2J\033[1;1H"; //system("cls");
			cout << "\nDATE (MMDD) : "; cin >> Date;
			edit_menu_main(name, Date);
			break;
		case '2':
			cout << "\033[2J\033[1;1H"; //system("cls");
			cout << "\nDATE (MMDD) : "; cin >> Date;
			predict_main(name, Date);
			break;
		case '3':
			search(name);
			break;
		case '4':
			kids_task_main(name);
			break;
		case '5':
			cout << "\033[2J\033[1;1H"; //system("cls");
			cout << "\nDATE (MMDD) : "; cin >> Date;
			sort(name, Date);
			break;
		case '6':
			cout << "\033[2J\033[1;1H"; //system("cls");
			cout << "\nDATE (MMDD) : "; cin >> Date;
			Filename = name + Date;
			initialization(Filename);
			break;
		case '7':
			cout << "\033[2J\033[1;1H"; //system("cls");
			deep_learning_main(name,acc);
			cout << "Accuracy: " << acc << endl;
			break;
		default:cout << "\a";
		}
	} while (ch != '0');
	return 0;
}

void our_group(){
	cout<<"\n\n\n\t  ENGG1340 Group Project";
	cout<<"\n\n\t    Accounting system";
	cout<<"\n\n\t Your Financial Majordomo";
	cout<<"\n\n\n\tGroup : 67";
	cout<<"\n\tMADE BY : Chu Wai Kit ";
	cout<<"\n\tMADE BY : Yam Chak Fung Wesley";
	cin.get();
}

// create an empty task file
void create_task(string name){
	string filename=name+"task.txt";
	ofstream fout;
	fout.open(filename);
	if (fout.fail()){
		cout << " Error in file opening!"<<endl;
		exit(1);
	}
	fout.close();
}

// real time to show tasks to do
void no_of_tasks(string name){
	int n=0;
	string line,user_task_file=name+"task.txt";
	ifstream fin(user_task_file);
	if (fin.fail()){
		cout<< " Error in file opening!"<<endl;
		exit(1);
	}
	while(getline(fin>>ws,line)){
		int x;
		bool y;
		fin >> x >> y;
		if (y == false)
			n++;
	}
	if (n >1)
		cout <<" - "<< n << " tasks waiting you to finish";
	else
		cout <<" - "<< n << " task waiting you to finish";
}
