#pragma once
#include "predict.h"
#include <vector>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <numeric>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <sstream>
#include<fstream>
#include <assert.h>
using namespace std;
template<typename T>
void pop_front(std::vector<T>& vec)
{
	assert(!vec.empty());
	vec.front() = std::move(vec.back());
	vec.pop_back();
}
//affine->relu->affine->relu->softmax
//backward propagation, i want convolution layer + adam oringinally
//no xaiver , only standard libaray,
// what can i say
// hardcore
//function use
/*void initialize(vector<vector<double>> &params_1, vector<double> &const_1,
vector<vector<double>>& params_2, vector<double>& const_2);*/
//struct used
struct Grad {
	vector<vector<double>> dw2; vector<double> db2; vector<vector<double>> dw1; vector<double> db1;
	Grad(vector<vector<double>> dw2, vector<double> db2, vector<vector<double>> dw1, vector<double> db1);
};
//Class used, affine layer
class affine {
	vector<vector<double>>  params;
	vector<double> constant;
	std::vector<double> input;
	vector<double> sum;
	vector<vector<double>> dweight;
	vector<double> dconst;
public:
	affine(vector<vector<double>>  params_1, vector<double> const_1);
	vector<double> forward(vector<double>input1);
	vector<double> backward(vector<double>dout);
	vector<double> getdb();
	vector<vector<double>> getdw();
};
//Class relu
class Relu {
private:
	vector<double> save;
public:
	vector<double> forward(vector<double> x);
	vector<double> backward(vector<double> dout);
};
//class entrophy
vector<double> entrophy(vector<double> y, vector<double>target);
//class softmax
vector<double>softmax(vector<double> a);
//Class used, softmax
class Softmaxloss {
private:
	vector<double>loss;
	vector<double> y;
	vector<double> target;
	vector<double> reply;
public:
	vector<double> forward(vector<double>input, vector<double> target1);
	vector<double> backward(vector<double>input);

};
//major class
class two_layer_network {
public:
	//constructor
	two_layer_network(
		vector<vector<double>>  params_1, vector<double> const_1,
		vector<vector<double>> params_2, vector<double>  const_2);
	//create layer
	void layer();
	//predict
	vector<double> predict(vector<double> x);
	// find loss under softmass and cross entrophy
	vector<double> loss(vector<double> x, vector<double> target);
	// indeed no use, just small datas tbh.
	double accuracy(vector<double> x, vector<double> target);
	// gradient
	Grad gradient(vector<double> x, vector<double> target, double acc);

private:
	vector<double> input;//6
	vector<double>  hidden;//6
	vector<double>  output;//6
	vector<vector<double>>  params_1;//6 6
	vector<double> const_1;// 6 
	vector<vector<double>> params_2;//6 6
	vector<double>  const_2;// 6
	vector<vector<double>> layer_1;//6 6
	vector<vector<double>> relu_1;// 6 6
	vector<vector<double>> layer_2;// 6 6
	vector<vector<double>> relu_2; // 6 6
	vector<double>  fin_layer;// 6
	vector<vector<double>>  dw1;//6 6
	vector<double> db1;// 6 
	vector<vector<double>> dw2;//6 6
	vector<double>  db2;// 6
	affine A1;
	Relu R1;
	affine A2;
	Relu R2;
	Softmaxloss final_layer;

};
void deep_initialize();
Grad DL_main(vector<vector<double>> params_1, vector<double> const_1,
	vector<vector<double>> params_2, vector<double> const_2, vector<vector<double>> x, vector<vector<double>> y,double acc);
vector<double> DL_forward(vector<vector<double>> params_1, vector<double> const_1,//forward
	vector<vector<double>> params_2, vector<double> const_2, vector<double> x);
vector<vector<double>> get_data(string name, string from, string to);
vector<double> DL(std::string name);
vector<double> deep_learning_main(string name,double acc);
