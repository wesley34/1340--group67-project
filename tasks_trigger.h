#pragma once
#include "add.h"
#include <fstream>
#include <string>
#include <iostream>
#include <regex>
#include<iomanip>

//#include"login.h"
using namespace std;
struct Node {
	string info;
	int info_2;
	bool info_3;
	Node * next;
};
int kids_task_main(string username);
int parents_task_main(string username);
void assign_tasks(Node * & head, Node * & tail);
void tail_insert(Node * & head, Node * & tail, string task, double bonus, bool done);
void Sort_tasks(Node * & head);
void Initialize_task(Node * &head,string username);
//string username;
void remove_tasks(Node * & head, Node * & tail);
void write_file(Node * &head,string username);
void read_task(Node *& head, Node * & tail, string username);
void MergeSort(Node** headRef);
Node* SortedMerge(Node* a, Node* b);
void split(Node* source, Node** frontRef, Node** backRef);
int print_list(Node * head);
void view_tasks(Node * & head, Node * & tail);
bool confirm();
bool keep_going();
