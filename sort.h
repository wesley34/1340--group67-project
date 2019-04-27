#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "delete.h"
#include "add.h"
#include <limits> 
void swap(int &a, int &b);
data_template sort_by_name(data_template data, int size);
data_template sort_by_num(data_template data, int size);
data_template sort_by_price(data_template data, int size);
int sort(std::string name, std::string date);
