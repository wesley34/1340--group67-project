#pragma once
//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <limits> 
//***************************************************************
//    	Used class
//****************************************************************
class data_template {
	int size = 0;

public:
	data_template(int length) :size(length) {};
	int* no = new int[size];
	std::string* name = new std::string[size];
	double* price = new double[size];
};
//***************************************************************
//    	function declaration
//****************************************************************
//***************************************************************
//   Check file_size
//****************************************************************
int length_check(std::string filename);
//***************************************************************
//    	function declaration
//****************************************************************
std::string filetxt(std::string name, std::string date, int mode);
//***************************************************************
//    	Initialization
//****************************************************************
void initialization(std::string filename);
//***************************************************************
//    	Double check 
//****************************************************************
int double_validation_double(double &num);
int double_validation_int(int &num);
//***************************************************************
//    copy temp to targeted file
//****************************************************************
void filecopy(std::string filename);
//***************************************************************
//    	write the data to temp
//****************************************************************
void add_write(int mode, data_template data, std::string filename, int iter);
void add(int mode, std::string filename);
void addmenu();
int add_main(std::string date, std::string name);

