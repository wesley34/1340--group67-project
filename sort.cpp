#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "delete.h"
#include "add.h"
#include <limits>
using namespace std;
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
	return;
}

data_template sort_by_name(data_template data, int size) {
	data_template new_data(size);
	//greet
	int mode = 0;
	cout << "Sort by name\n" << endl;
	cout << "\n1->Ascending Order" << endl;
	cout << "2->Descending Order" << endl;
	cout << "Mode (1/2) : " ;
	cin >> mode;
	cout << endl;
	int* save = new int[size];

	int save_to_data = 0;
	//initialize the int list
	for (int i = 0; i < size; i++) {
		save[i] = i;
	}

	int i, j, idx;
	int min;
	string current;
	for (i = 0; i < size; ++i)
	{
		current = data.name[save[i]];
		min = save[i];
		idx = i;
		for (j = i + 1; j < size; ++j)
		{
			if (data.name[save[j]][0] == current[0]) {
				if (data.name[save[j]].length() < current.length() and mode == 1) {
					current = data.name[save[j]];
					min = save[j];
					idx = j;
				}
				else if (data.name[save[j]].length() > current.length() and mode == 2) {
					current = data.name[save[j]];
					min = save[j];
					idx = j;
				}
			}
			if (data.name[save[j]] < current and mode == 1)
			{
				current = data.name[save[j]];
				min = save[j];
				idx = j;
			}
			else if (data.name[save[j]] > current and mode == 2) {
				current = data.name[save[j]];
				min = save[j];
				idx = j;
			}
		}
		if (idx != i) {
			swap(save[i], save[idx]);
		}
	}
	///test
	cout << "\033[2J\033[1;1H"; //system("cls");
	for (int i = 0; i < size; i++) {
		save_to_data = save[i];
		new_data.name[i] = data.name[save_to_data];
		new_data.no[i] = data.no[save_to_data];
		new_data.price[i] = data.price[save_to_data];
	}
	delete [] data.name, data.no, data.price;
	return new_data;
}
data_template sort_by_num(data_template data, int size) {
	//greet
	cout << "\033[2J\033[1;1H"; //system("cls");
	cout << "Sort by item\n" << endl;
	int mode = 0;
	cout << "\n1->Ascending Order" << endl;
	cout << "2->Descending Order" << endl;
	cout << "Mode (1/2) : ";
	cin >> mode;
	cout << endl;


	data_template new_data(size);
	int* save = new int[size];
	int save_to_data = 0;
	//initialize the int list
	for (int i = 0; i < size; i++) {
		save[i] = i;
	}

	int i, j, idx;
	int min;
	int current;
	for (i = 0; i < size; ++i)
	{
		current = data.no[save[i]];
		min = save[i];
		idx = i;
		for (j = i + 1; j < size; ++j)
		{
			if (data.no[save[j]] < current and mode == 1)
			{
				current = data.no[save[j]];
				min = save[j];
				idx = j;
			}
			else if (data.no[save[j]] > current and mode == 2)
			{
				current = data.no[save[j]];
				min = save[j];
				idx = j;
			}
		}
		if (idx != i) {
			swap(save[i], save[idx]);
		}
	}
	//test

	for (int i = 0; i < size; i++) {
		save_to_data = save[i];
		new_data.name[i] = data.name[save_to_data];
		new_data.no[i] = data.no[save_to_data];
		new_data.price[i] = data.price[save_to_data];
	}
	delete[] data.name, data.no, data.price;
	return new_data;
}
data_template sort_by_price(data_template data, int size) {
	//greet
	cout << "\033[2J\033[1;1H"; //system("cls");
	cout << "Sort by price\n" << endl;
	int mode = 0;
	cout << "\n1->Ascending Order" << endl;
	cout << "2->Descending Order" << endl;
	cout << "Mode (1/2) : ";
	cin >> mode;
	cout << endl;


	data_template new_data(size);
	int* save = new int[size];
	int save_to_data = 0;
	//initialize the int list
	for (int i = 0; i < size; i++) {
		save[i] = i;
	}
	int i, j, idx;
	int min;
	double current;
	for (i = 0; i < size; ++i)
	{
		current = data.price[save[i]];
		min = save[i];
		idx = i;
		for (j = i + 1; j < size; ++j)
		{

			if (data.price[save[j]] < current and mode == 1)
			{
				current = data.price[save[j]];
				min = save[j];
				idx = j;
			}
			else if (data.price[save[j]] > current and mode == 2)
			{
				current = data.price[save[j]];
				min = save[j];
				idx = j;
			}
		}
		if (idx != i) {
			swap(save[i], save[idx]);
		}
	}
	//test

	for (int i = 0; i < size; i++) {
		save_to_data = save[i];
		new_data.name[i] = data.name[save_to_data];
		new_data.no[i] = data.no[save_to_data];
		new_data.price[i] = data.price[save_to_data];
	}
	delete[] data.name, data.no, data.price;
	return new_data;
}
void sortmenu() {
	cout << "\n\n\n\tSort" << endl;
	cout << "\n\t01. Food" << endl;
	cout << "\n\t02. Transportation" << endl;
	cout << "\n\t03. Toy" << endl;
	cout << "\n\t04. Stationary" << endl;
	cout << "\n\t05. Others" << endl;
	cout << "\n\t06. Income" << endl;
	cout << "\n\t00. Back to Main Menu";
	cout << "\n\n\tPlease Select Your Option (0-6) ? ";
}
int sort(string name, string date) {
	cout << "\033[2J\033[1;1H"; //system("cls");
	int scope = 0;
	string line;
	string confirm;
	string addmenu[] = { "food","transportation","toy","stationary","others","income" };
	string str[] = { "food.txt","transportation.txt","toy.txt","stationary.txt","others.txt","income.txt" };
	double sum = 0;
	int mode = 0;
	int iterator= 0;
	int no = 0;
	int filesize = 0;
	double price = 0;
	//greet
	//choice
	sortmenu();
	cin >> scope;
	cout << endl;
	//file
	string filename = name + date + str[scope - 1];
	ifstream fc(filename.c_str());
		if (fc.fail()){
			cout<<"Not this day file"<<endl;
			fc.close();
			return 0;
		}
	fc.close();
	filesize = print_filetext(filename,1);
	int length_of_text = length_check(filename);
	data_template data(filesize);
	data_template new_data(filesize);
	ifstream fread(filename.c_str());
	if(fread.fail()){
		cout << "Error no such a date" << endl;
		return 0;
	}
	getline(fread, line);
	while (1) {
		//getting the price information
		fread >> no;
		fread >> data.name[iterator];
		fread >> data.no[iterator];
		fread >> data.price[iterator];
		iterator++;
		if (iterator == filesize - 1) {
			break;
		}
	}
	fread.close();
	cout << "01 -> Sort by name" << endl;
	cout << "02 -> Sort by number of item" << endl;
	cout << "03 -> Sort by number of price" << endl;
	cout << "\nPlease enter your choice : ";
	cin >> mode;
	if (iterator == 1) {
		return 0;
	}
	if (mode == 1) {
		cout << " iterator " << iterator << endl;
		new_data = sort_by_name(data, iterator);
	}
	else if (mode == 2) {
		new_data = sort_by_num(data, iterator);
	}
	else {
		new_data = sort_by_price(data, iterator);
	}
	//file make and print
	cout << "Updataed Version" << endl << endl;
	string* passage = new string[filesize+1];
	passage[0] = "\tName\tNo\tPrice";
	cout << passage[0] << endl;
	for (int i = 1; i < filesize; i++) {
		passage[i] = to_string(i) + "\t" + new_data.name[i-1] + "\t" + to_string(new_data.no[i-1]) + "\t" + to_string(new_data.price[i - 1]) ;
		sum += new_data.price[i-1];
		cout << passage[i] << endl;
		cout << endl;
	}

	passage[filesize] = "total " + addmenu[scope-1] + " "  + to_string(sum);
	cout << passage[filesize] << endl;
	cout << endl;
	//greet

	cout << "Update it (y/n) ??";
	cin >> confirm;
	cout << endl;
	if (confirm == "y") {
		ofstream fwrite(filename.c_str());
		if (fwrite.fail()) {
			cout << "error" << endl;
			exit(1);
		}
		for (int i = 0; i < filesize; i++) {
			fwrite << passage[i] << endl;
		}
		fwrite.close();
	}
	delete[] passage, new_data.name, new_data.no, new_data.price;
	return 0;
}
