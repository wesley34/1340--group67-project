#include "add.h"
#include "delete.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include<limits>
using namespace std;
int edit_main(std::string Date, std::string name) {
	//variable used
	int scope, problem_line = 0;
	int length_txt = 0;
	int problem_array_count = 0;
	double num = 0;
	int first_num = 1;//must be initialize at 1
	double sum = 0;
	string filename;
	string line;
	string addmode[] = { "food","transportation","toy","stationary","others","income" };
	//temp
	string last_line_iter, name_str;

	//major
	while (1) {
		cout << "\033[2J\033[1;1H"; //system("cls");
		//edit_menu
		cout << "\n\n\n\tEdit" << endl;
		addmenu();
		//scope
		cin >> scope;
		cout << endl;
		//check scope
		if (scope == 0) {
			cout << "\033[2J\033[1;1H"; //system("cls");
			return 0;
		}
		else if (scope == 7) {
			initialization(name + Date);
			continue;
		}
		//create filetext
		filename = filetxt(name, Date, scope);
		ifstream fc(filename.c_str());
		if (fc.fail()){
			cout<<"Not this day file"<<endl;
			fc.close();
			return 0;
		}
		fc.close();
		//print filetext
		length_txt = print_filetext(filename,1);

		//creating array of problem
		int *problem = new int[length_txt];
		int iter = 0;

		//Delete Greeting
		cout << "Enter 0 to leave" << endl;
		cout << "Lines with Problem: ";
		while (problem_line != 0) {
			cin >> problem_line;
			//handler
			if (problem_line == 0) {
				break;
			}
			//assignment
			problem[iter] = problem_line;
			iter++;
		}
		//handler
		if (iter == 0) {
			cout << "You have nothing to edit !" << endl;
			return 0;
		}
		//waiting
		cout << "Editing" << endl;
		//reusing iterator
		int size_of_array = iter;
		iter = 1;

		//----------------------file edit---------------------
		data_template temp(size_of_array);


		for (int i = 0; i < size_of_array; i++) {
			cout << "Editing Line " << problem[i] << endl;
			cout << "Name " << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::getline(cin, temp.name[i]);
			cout << endl;

			//no
			cout << "No of item "; cin >> temp.no[i];    cout << endl;
			//check input
			while (1) {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Please enter a number" << endl;
					cin >> temp.no[i];
				}
				if (!cin.fail()) {
					break;
				}
			}

			//price
			cout << "Price: ";     cin >> temp.price[i]; cout << endl;
			//check input
			while (1) {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Please enter a number" << endl;
					cin >> temp.price[i];
				}
				if (!cin.fail()) {
					break;
				}
			}
		}
		//file in
		ifstream fread(filename.c_str());
		if (fread.fail()) {
			cout << "error on fread in edit file in" << endl;
			exit(1);
		}
		ofstream fwrite("temp.txt");

		//-----------------------file out---------------------
		//first line

		getline(fread, line);
		fwrite << line << endl;
		//remaining
		//
		int iter_of__class = 0;
		while (getline(fread, line)) {

			istringstream iss(line);


			//logic check if it is problem line

			if (iter == problem[problem_array_count]) {
				iss >> num;
				iss >> name_str;
				iss >> num;
				iss >> num;
				//accesing the price 1+3
				fwrite << first_num << "\t" << temp.name[problem_array_count] << "\t" << temp.no[problem_array_count] << "\t" << temp.price[problem_array_count] << endl;
				//adding it to sum
				sum += temp.price[problem_array_count]-num;
				problem_array_count++;
			}
			//check if the default 1 will be delete or not if no element inside
			else if (iter == length_txt) {
				if (length_txt == size_of_array - 1) {
					fwrite << "1" << endl;
				}
				//access iss num
				iss >> last_line_iter;
				iss >> last_line_iter;
				iss >> num;
				num += sum;
				//final line
				fwrite << "Total " << addmode[scope - 1] << " " << num;
				break;
			}
			first_num++;
			iter++;
		}
		fread.close();
		fwrite.close();
		//copy it to real file
		filecopy(filename.c_str());
	}

	return 0;
}
