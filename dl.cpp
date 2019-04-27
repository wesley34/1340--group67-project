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
#include <algorithm>
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
	Grad(vector<vector<double>> dw2, vector<double> db2, vector<vector<double>> dw1, vector<double> db1) :dw2(dw2), db2(db2), dw1(dw1), db1(db1) {}
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
	affine(vector<vector<double>>  params_1, vector<double> const_1) :
		params(params_1), constant(const_1) {}
	vector<double> forward(vector<double>input1) {// no cross product in stl
		input = input1;//we need this for backward propagation
		for (int i = 0; i < 6; i++) {
			sum.push_back(inner_product(input1.begin(), input1.end(), (params[i]).begin(), 0));
			sum[i] += constant[i];
		}
		return sum;
	}
	vector<double> backward(vector<double>dout) {// no cross product in stl
		vector<double> temp;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				//dout*dw.T give x
				sum.push_back(dout[i] * params[i][j]);
			}
		}
		// dw db not yet done
		//dw
		for (int i = 0; i < 6; i++) {
			for (int k = 0; k < 6; k++) {
				temp.push_back(inner_product(input.begin(), input.end(), dout.begin(), 0));
			}
			dweight.push_back(temp);
			temp.clear();
		}
		//db
		for (int i = 0; i < 6; i++) {
			dconst.push_back(dout[i]);
		}
		return sum;

	}
	vector<double> getdb() {
		return dconst;
	}
	vector<vector<double>> getdw() {
		return dweight;
	}
};
//Class relu
class Relu {
private:
	vector<double> save;
public:
	vector<double> forward(vector<double> x) {
		for (int i = 0; i < 6; i++) {
			if (x[i] <= 0) {
				x[i] = 0;
			}

			save.push_back(x[i]);

		}
		return x;
	}
	vector<double> backward(vector<double> dout) {
		for (int i = 0; i < 6; i++) {
			if (save[i] != 0) {
				save[i] = 1;
			}
		}
		return save;
	}
};
//class entrophy
vector<double> entrophy(vector<double> y, vector<double>target) {
	vector <double> reply;
	for (int i = 0; i < 6; i++) {
		reply.push_back(-target[i] * log(y[i] + 0.00001));
	}

	return reply;
}
//class softmax
vector<double>softmax(vector<double> a) {
	double sum = accumulate(a.begin(), a.end(), 0);
	for (int i = 0; i < 6; i++) {
		a[i] /= (sum+0.000001);
	}
	return a;
}
//Class used, softmax
class Softmaxloss {
private:
	vector<double>loss;
	vector<double> y;
	vector<double> target;
	vector<double> reply;
public:
	vector<double> forward(vector<double>input, vector<double> target1) {
		target = target1;
		y = softmax(input);
		loss = entrophy(y, target);
		return target;
	}
	vector<double> backward(vector<double>input) {
		vector<double> reply;
		for (int i = 0; i< 6; i++) {
			reply.push_back((y[i] - target[i]) / 6);
		}
		return reply;
	}

};
//major class
class two_layer_network {
public:
	//constructor
	two_layer_network(
		vector<vector<double>>  params_1, vector<double> const_1,
		vector<vector<double>> params_2, vector<double>  const_2) :
		params_1(params_1), const_1(const_1),
		params_2(params_2), const_2(const_2) {}
	//create layer
	void layer() {
		this->A1 = new affine(params_1, const_1);
		this->R1 = new Relu;
		this->A2 = new affine(params_2, const_2);
		this->final_layer = new Softmaxloss;
	}
	//predict
	vector<double> predict(vector<double> x) {
		x = A1->forward(x);
		x = R1->forward(x);
		x = A2->forward(x);
		return x;
	}
	// find loss under softmass and cross entrophy
	vector<double> loss(vector<double> x, vector<double> target) {
		x = predict(x);
		return final_layer->forward(x, target);
	}
	// indeed no use, just small datas tbh.
	double accuracy(vector<vector<double>> x, vector<vector<double>> target) {
		vector <double> save1 = { 0,0,0,0,0,0 };
		vector<double> save2;
		double acc = 0;
		for (int i = 0; i < x.size(); i++) {
			save2 = predict(x[i]);
			std::transform(save1.begin(), save1.end(), save2.begin(), save1.begin(), std::plus<int>());
			save2 = final_layer->forward(save2, target[i]);
			std::transform(save1.begin(), save1.end(), save2.begin(), save1.begin(), std::plus<int>());
		}

		for (int i = 0; i < 6; i++) {
			if (save1[i]/(x.size() != 1)) {
				acc += 1;
			}
		}
		return acc / 6;
	}
	// gradient
	Grad* gradient(vector<double> x, vector<double> target,double acc) {
		/*this->A1 = new affine(params_1, const_1);
		this->R1 = new Relu;
		this->A2 = new affine(params_2, const_2);
		this->final_layer = new Softmaxloss;*/
		layer();
		vector <double> lost = this->loss(x, target);
		for (int i = 0; i < 6; i++) {
			if (lost[i]) {//do forward and the help storing data
				acc += 1/6;
			}
		}

		vector<double> dout = { 1,1,1,1,1,1 };
		//cout << "start final" << endl;
		dout = final_layer->backward(dout);
		//cout << "pass final" << endl;
		dout = A2->backward(dout);
		//cout << "pass A2" << endl;
		dout = R1->backward(dout);
		//cout << "pass R1" << endl;
		dout = A1->backward(dout);
		//cout << "pass A1" << endl;

		dw2 = A2->getdw();
		db2 = A2->getdb();
		dw1 = A1->getdw();
		db1 = A1->getdb();

		Grad* grad = new Grad(dw2, db2, dw1, db1);
		return grad;
	}
	vector<double> getb(int mode) {
		if (mode == 2) {
			return const_2;
		}
		return const_1;
	}
	vector<vector<double>> getw(int mode) {
		if (mode == 2) {
			return  params_2;
		}
		return  params_1;
	}

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
	affine* A1 = NULL;
	Relu* R1 = NULL;
	affine* A2 = NULL;
	Relu* R2 = NULL;
	Softmaxloss* final_layer = NULL;

};
void deep_initialize() {
	vector<vector<double>> params_1; vector<double> const_1;
	vector<vector<double>> params_2; vector<double> const_2;
	vector<double> param1_size;//size of 2 then do what?
	vector<double> param2_size;//size of 2
	int r_num = 0;
	for (int i = 1; i <= 6; i++) {


		param1_size.push_back(0.31 / i);
		param1_size.push_back(3.2 / i);
		param2_size.push_back(1.2 / i);
		param2_size.push_back(0.99 / i);
		const_1.push_back(0.3 / i);
		const_2.push_back(0.12 / i);
	}

	for (int i = 0; i < 6; i++) {
		params_1.push_back(param1_size);
		params_2.push_back(param2_size);
	}
	ofstream fwrite("deeplearning.txt");
	for (int i = 0; i < 6; i++) {
		fwrite << const_1[i] << " ";
	}
	for (int i = 0; i < 6; i++) {
		fwrite << const_2[i] << " ";
	}
	for (int j = 0; j < 6; j++) {
		for (int k = 0; k < 6; k++) {
			fwrite << params_1[k][j] << " ";
		}
	}
	for (int j = 0; j < 6; j++) {
		for (int k = 0; k < 6; k++) {
			fwrite << params_2[k][j] << " ";
		}
	}
	fwrite.close();

}
Grad* DL_main(vector<vector<double>> params_1, vector<double> const_1,
	vector<vector<double>> params_2, vector<double> const_2, vector<vector<double>> x, vector<vector<double>> y,double& acc) {//backward
	double learning_rate = 0.05;
	int size_data = x.size();
	Grad* grad = new Grad(params_2, const_2, params_1, const_1);
	two_layer_network *mydl = new two_layer_network(params_1, const_1, params_2, const_2);
	//cout << "Warning!!" << endl;
	//cout << "At least 50 days to make it predict well" << endl;
	//cout << "(<1000/day,0.02)Perfer 0.05 (>1000/day,0.1)" << endl;
	//cout << "Please tune your best learning rate and have fun !!" << endl;
	//cout << "Learning Rate: ";
	//cin >> learning_rate;
	cout << "\n\n==========================================================\n";
	cout << "\n\tYour learning rate : " << learning_rate << endl;
	//double learning_rate = 0.047;//tbh, stl cannot use adam is hardcore,
							   //i mean i dun want to type from the beginning
							   //so i make it depends on users,

	for (int i = 0; i < size_data; i++) {
		//cout << "pass for loop" << endl;
		grad = mydl->gradient(x[i], y[i],acc);////important, input data area
		vector<vector<double>>w1 = mydl->getw(1);
		vector<vector<double>>w2 = mydl->getw(2);
		vector<double>b1 = mydl->getb(1);
		vector<double>b2 = mydl->getb(2);
		for (int j = 0; j < 6; j++) {
			const_2[j] -= learning_rate * (grad->db2)[j];
			const_1[j] -= learning_rate * grad->db1[j];
			for (int k = 0; k < 6; k++) {
				params_2[k][j] -= learning_rate * grad->dw2[k][j];
				params_1[k][j] -= learning_rate * grad->dw1[k][j];
			}
		}
	}

	acc /= size_data;
	delete mydl, grad;
	//store the updated params
	Grad* updated_grad = new Grad(params_2, const_2, params_1, const_1);
	// write to dl sheet
	ofstream fwrite("deeplearning.txt");
	for (int i = 0; i < 6; i++) {
		fwrite << const_1[i] << " ";
	}
	for (int i = 0; i < 6; i++) {
		fwrite << const_2[i] << " ";
	}
	for (int j = 0; j < 6; j++) {
		for (int k = 0; k < 6; k++) {
			fwrite << params_1[k][j] << " ";
		}
	}
	for (int j = 0; j < 6; j++) {
		for (int k = 0; k < 6; k++) {
			fwrite << params_2[k][j] << " ";
		}
	}
	fwrite.close();
	// end of training

	return updated_grad;
}
vector<double> DL_forward(vector<vector<double>> params_1, vector<double> const_1,vector<vector<double>> params_2, vector<double> const_2, vector<double> x) {
	two_layer_network *myforward = new two_layer_network(params_1, const_1, params_2, const_2);
	myforward->layer();
	vector<double>sum = myforward->predict(x);
	delete myforward;
	return sum;
}
vector<vector<double>> get_data(string name, string from, string to) {
	int month = 0; int day = 0;  int end_day = 0; int end_month = 0;
	string calander[32] = { "00","01","02","03","04","05","06","07","08","09","10","11","12","13" };
	for (int i = 14; i<32; i++) {
		calander[i] = to_string(i);
	}
	vector<double> temp;
	vector<vector<double>> ans;
	string filename;
	istringstream iss1(from.substr(0, 2));//month
	iss1 >> month;
	istringstream iss2(from.substr(2, 2));//day
	iss2 >> day;
	istringstream iss3(to.substr(0, 2));//month
	iss3 >> end_month;
	istringstream iss4(to.substr(2, 2));//day
	iss4 >> end_day;
	int diff = month - end_month;
	for (int i = month; i <= end_month; i++) {
		if (i == end_month and diff == 0) {
			for (int j = day; j <= end_day; j++) {
				filename = name + calander[i] + calander[j];
				for (int k = 0; k < 6; k++) {

					temp.push_back(reporter(filename, k));

				}
				ans.push_back(temp);
				temp.clear();
			}
		}
		else if (i == end_month and diff != 0) {
			for (int j = 1; j <= end_day; j++) {
				filename = name + calander[i] + calander[j];
				for (int k = 0; k < 6; k++) {
					temp.push_back(reporter(filename, k));

				}
				ans.push_back(temp);
			}
		}
		else {
			for (int j = day; j <= 31; j++) {
				filename = name + calander[i] + calander[j];
				for (int k = 0; k < 6; k++) {
					temp.push_back(reporter(filename, k));
				}
				ans.push_back(temp);
			}
		}
	}
	return ans;
}
vector<double> DL(string name,double acc) {//forward
	double temp_num = 0;
	vector<double> temp_vec;
	string from;
	string to;
	cout << "\tEnter the date start training." << endl;
	cout << "\tFrom (MMDD) : "; cin >> from; cout << endl;
	cout << "\tEnter the date end training." << endl;
	cout << "\tEnd (MMDD) : "; cin >> to; cout << endl;
	vector<vector<double>> w1; vector<double> b1;
	vector<vector<double>> w2; vector<double> b2;
	vector<vector<double>> x; vector<vector<double>> y;
	vector<double> ans;
	x = get_data(name, from, to);
	y = x;
	x.pop_back();
	pop_front(y);
	int size = x.size();
	ifstream fopen("deeplearning.txt");
	if (fopen.fail()) {
		fopen.close();
		cout << "No DL" << endl;
		exit(1);
	}
	for (int i = 0; i < 6; i++) {
		fopen >> temp_num;
		b1.push_back(temp_num);
	}
	for (int i = 0; i < 6; i++) {
		fopen >> temp_num;
		b2.push_back(temp_num);
	}
	for (int j = 0; j < 6; j++) {
		for (int k = 0; k < 6; k++) {
			fopen >> temp_num;
			temp_vec.push_back(temp_num);
		}
		w1.push_back(temp_vec);
		temp_vec.clear();
	}
	for (int j = 0; j < 6; j++) {
		for (int k = 0; k < 6; k++) {
			fopen >> temp_num;
			temp_vec.push_back(temp_num);
		}
		w2.push_back(temp_vec);
		temp_vec.clear();
	}
	Grad* grad = DL_main(w1, b1, w2, b2, x, y,acc);
	//cout << "grad end here" << endl;
	ans = DL_forward(grad->dw1, grad->db1, grad->dw2, grad->db2, x[x.size() - 1]);
	delete grad;
	cout << "\n\n==========================================================\n";
	cout << "\n\tThe training finished. ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return ans;
}
vector<double> deep_learning_main(string name,double acc) {
	char init = 'a';

	cout << "\n\n\n\tDeep Learning Initialize" << endl << endl;
	cout << "\tIf this is the first time you login, please enter yes. Otherwise, no. " << endl;
	cout << "\n\tConfirm (y/n) : ";
	cin >> init;
	cout << endl;
	if (init == 'y') {
		deep_initialize();
	}
	vector<double> mypredict = DL(name,acc);
	/*for (int i = 0; i < 6; i++) {
		cout << mypredict[i] << endl;
	}*/
	cout << "\033[2J\033[1;1H"; //system("cls"); 
	return mypredict;
}
