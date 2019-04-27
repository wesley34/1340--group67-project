#include "add.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include<limits>
using namespace std;
//***************************************************************
//    	function declaration
//****************************************************************
//***************************************************************
//    	print text of file
//****************************************************************
int print_filetext(string filename,int mode) {
	int length = -1;
	string line;
	ifstream fread(filename.c_str());
	if (!fread.is_open()) {
		cout << "cannot open fread in delete" << endl;
		exit(1);
	}
	else {
		cout << "\033[2J\033[1;1H"; //system("cls");
		while (getline(fread, line)) {
			if (mode == 1) {
				cout << line << endl;
				cout << endl;
			}
			length++;
		}
	}
	fread.close();
	return length;
}
//***************************************************************
//    	Delete structure
//****************************************************************
int delete_main(string Date,string name) {
	//variable used
	int scope, problem_line = 0;
	int length_txt = 0;
	int problem_array_count = 0;
	int num = 0;
	int first_num = 1;//must be initialize at 1
	double sum = 0;
	string filename;
	string line;
	string addmode[] = { "food","transportation","toy","stationary","others","gains" };
	//temp
	string last_line_iter, name_str;

	//major
	while (1) {
		cout << "\033[2J\033[1;1H"; //system("cls");
		//delete_menu
		cout << "\n\n\n\tRemove" << endl;
		addmenu();
		//scope
		cin >> scope;
		cout << endl;
		//check scope
		cout << "\033[2J\033[1;1H"; //system("cls"); 
		cout << "\n\nName : "<< name << "Date : " << Date<<endl;
		if (scope == 0) {
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
			cout << "You have nothing to delete !" << endl;
			return 0;
		}
		//waiting
		cout << "Deleting" << endl;
		//reusing iterator
		int size_of_array = iter;
		iter = 1;


		//file in
		ifstream fread(filename.c_str());
		if (fread.fail()) {
			cout << "error on fread in delete file in" << endl;
			exit(1);
		}
		ofstream fwrite("temp.txt");

		//-----------------------file out---------------------
		//first line
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(fread, line);
		fwrite << line << endl;
		//remaining
		while (getline(fread, line)) {
			//finding first num of line and then delete it
			istringstream iss(line);
			if (iter != problem[problem_array_count] and iter != length_txt) {
				iss >> num;
			}

			//logic check if it is problem line
			if (iter != problem[problem_array_count] and iter != length_txt) {
				line.erase(0, to_string(num).size());
				fwrite << first_num << " " << line << endl;
				first_num++;
			}
			else if (iter == problem[problem_array_count]) {
				//accesing the price 1+3
				iss >> num;
				iss >> name_str;
				iss >> num;
				iss >> num;
				//adding it to sum
				sum += num;
				problem_array_count++;
			}
			//check if the default 1 will be delete or not if no element inside
			else if (iter == length_txt) {
				if (length_txt  == size_of_array+1) {

					fwrite << "1" << endl;
				}
				//access iss num
				iss >> last_line_iter;
				iss >> last_line_iter;
				iss >> num;
				num -= sum;
				//final line
				fwrite << "Total " << addmode[scope - 1] << " " << num;
				break;
			}
			iter++;
		}
		fread.close();
		fwrite.close();
		//copy it to real file
		filecopy(filename.c_str());
	}
	return 0;
}
