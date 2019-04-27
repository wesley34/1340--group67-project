#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include "delete.h"
std::vector<double> connector(std::string filename);
std::vector<double> predict_mean(std::string name, std::string Date);
double reporter(std::string filename, int mode);
double predict_main(std::string name, std::string Date);