#include "add.h"
#include <fstream>
#include <string>
#include <iostream>
#include <regex>
#include<iomanip>

//#include"login.h"

using namespace std;

//***************************************************************
//    	Node declaration
//****************************************************************
struct Node {
	string info;
	double info_2;
	bool info_3;
	Node * next;
};

//***************************************************************
//    	function declaration
//****************************************************************

void assign_tasks(Node * & head, Node * & tail);
void tail_insert(Node * & head, Node * & tail, string task, double bonus, bool done);
void remove_tasks(Node * & head, Node * & tail);
void Sort_tasks(Node * & head);
void Initialize_task(Node * &head,string username);
void write_file(Node * &head,string username);
void read_task(Node *& head, Node * & tail,string username);
void MergeSort(Node** headRef);
Node* SortedMerge(Node* a, Node* b);
void split(Node* source, Node** frontRef, Node** backRef);
int print_list(Node * head);
void view_tasks(Node * & head, Node * & tail, string username);
bool confirm();
bool keep_going();
//void clrtask(string username);
/* sorts the linked list by changing next pointers (not data) */

//***************************************************************
//    	Task trigger for parents part
//****************************************************************
int  parents_task_main(string username) {
	char ch;
	string task = "";
	Node * head = NULL, *tail = NULL;
	read_task(head, tail,username);
	do {
		cout << "\033[2J\033[1;1H"; //system("cls");
		cout << "\n\n\n\tTasks Trigger";
		cout << "\n\n\n\t1. Assign Tasks";
		cout << "\n\n\t2. Remove Tasks";
		cout << "\n\n\t3. Sort Tasks";
		cout << "\n\n\t4. Initialize Tasks";
		cout << "\n\n\t0. Back to Main Menu";
		cout << "\n\n\n\tEnter Choice (0-4)? ";
		cin >> ch;
		switch (ch)
		{
		case '1':assign_tasks(head, tail); break;
		case '2':remove_tasks(head, tail); break;
		case '3':Sort_tasks(head);	 break;
		case '4':Initialize_task(head, username);	break;
		case '0':write_file(head,username); break;
		default:	cout << "\a"; //alert user
		}
	} while (ch != '0');
	return 0;
}

//assign the task
void assign_tasks(Node * & head, Node * & tail) {
	string task;
	char ch;
	double bonus;
	bool done;
	do {
		cout << "\n\n==========================================================\n";
		cout << "\n\tEnter enter the task : ";
		getline(cin >> ws, task);
		cout << "\n\tEnter bonus for completeing all tasks : $";
		cin >> bonus;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\n\tConfirm ? (y/n)";
		cin >> ch;
		if (ch == 'y')
			tail_insert(head, tail, task, bonus, done = false);
		cout << "\n\tContinue? (y/n)"; // doble validation
		cin >> ch;
		if (ch != 'y'&& ch != 'n')
			cout << '\a';
	} while (ch != 'n');

}

//remove the task or you can view here
void remove_tasks(Node * & head, Node * & tail) {
	int remove_line, count;
	char ch;
	if (head == NULL) {
		cout << "\n\n==========================================================\n";
		cout << "\n\tThere is no task.";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get(); // press button to leave
	}
	else {
		count = print_list(head);
		cout << "\n\n==========================================================\n";
		cout << "\n\tWhich line you wish to remove? (0-" << count - 1 << ")";
		cin >> remove_line;
		if (remove_line == 0)
			return;
		else if (remove_line == 1) {
			cout << "\n\n\tConfirm ? (y/n) ";
			cin >> ch;
			if (ch == 'y') {
				Node * current = head;
				head = head->next;
				delete current;
			}
		}
		else if (remove_line < count&&remove_line>1) {
			cout << "\n\n\tConfirm ? (y/n) ";
			cin >> ch;
			if (ch == 'y') {
				Node * current = head;
				for (int i = 0; i < remove_line - 2; i++) {
					current = current->next;
				}
				Node * p = current->next;
				current->next = p->next;
				delete p;
			}
		}
		if (ch == 'y') {
			if (head != NULL) {
				cout << "\n\n==========================================================\n";
				count = print_list(head);
				cout << "\n\n==========================================================\n";
				cout << "\n\n\tRemoved successfully ";
				cout << "\n\n\tContinue ? (y/n) ";
				cin >> ch;
				if (ch == 'y')
					remove_tasks(head, tail); // update the menu at once
				else
					return;
			}
			else {
				cout << "\n\n==========================================================\n";
				cout << "\n\n\tRemoved successfully ";
				count = print_list(head);
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.get();
				return;
			}
		}
	}
}

//clear all the tasks
void Initialize_task(Node *& head,string username) {
	string user_task_file = username + "tast.txt";
	cout << "\n\n==========================================================\n";
	cout << "\n\tConfirm ? (y/n) ";
	char ch;
	cin >> ch;
	if (ch == 'y') {
		ofstream fout(user_task_file);
		if (fout.fail()) {
			cout << " Error in file opening!" << endl;
			fout.close();
			return;
		}
		while (head != NULL) {
			Node * p = head;
			fout << p->info << "\n" << p->info_2 << "\n" << p->info_3 << endl;
			head = head->next;
			delete p;
		}
		fout.close();
		cout << "\n\tTasks are cleared."; // notice user
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
	}
	else
		return;
}

//***************************************************************
//    	Task trigger for kids part
//****************************************************************

int kids_task_main(string username) {
	char ch;
	string task = "";
	Node * head = NULL, *tail = NULL;
	read_task(head, tail,username);
	do {
		cout << "\033[2J\033[1;1H"; //system("cls");
		cout << "\n\n\n\tTasks Trigger";
		cout << "\n\n\n\t01. View Tasks";
		cout << "\n\n\t02. Sort Tasks";
		cout << "\n\n\t00. Back to Main Menu";
		cout << "\n\n\n\tPlease Select Your Option (0-2) ? ";
		cin >> ch;
		switch (ch)
		{
		case '1':view_tasks(head, tail,username); break;
		case '2':Sort_tasks(head);	 break;
		case '0':write_file(head, username); break;
		default:cout << "\a";
		}
	} while (ch != '0');
	return 0;
}

void view_tasks(Node * & head, Node * & tail,string username) {
	int done_line, count;
	string filename , name, Date;
	char ch;
	if (head == NULL) {
		cout << "\n\n==========================================================\n";
		cout << "\n\tThere is no task.";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();

	}
	else {
		count = print_list(head);
		cout << "\n\n==========================================================\n";
		cout << "\n\tWhich line of task you have done? (0-" << count - 1 << ")";
		cin >> done_line;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (done_line == 0)
			return;
		else {
			cout << "\n\tDATE (MMDD) : "; cin >> Date;
			cout << "\n\n\tConfirm ? (y/n) ";
			cin >> ch;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (ch == 'y') {
				Node * current = head;
				for (int i = 0; i<done_line - 1; i++) {
					current = current->next;
				}
				current->info_3 = true; // update the menu at once
				//update the income of the kid
				data_template * bonus = new data_template(1);
				bonus->no[0] = 1;
				bonus->name[0] = (current->info);
				bonus->price[0] = (current->info_2); // here you input the total removed moeny
				//		here require him to cin date
				filename = username + Date + "gains.txt";
				add_write(6, *bonus, filename, 1);
				//						end here
				delete bonus;
				count = print_list(head);
				cout << "\n\n==========================================================\n";
				cout << "\n\n\tGood job";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.get();
				return;
			}
		}
	}
}

//***************************************************************
//    	Task trigger general part
//****************************************************************

bool confirm() {
	char ch;
	cout << "\n\n\tConfirm ? (y/n) ";
	do {
		cin >> ch;
		switch (ch) {
		case 'y':return true; break;
		case 'n':return false;	 break;
		default:	cout << "\a";
		}
	} while (true);
}
bool keep_going() {
	char ch;
	cout << "\n\n\tContinue ? (y/n) ";
	do {
		cin >> ch;
		switch (ch) {
		case 'y':return true; break;
		case 'n':return false;	 break;
		default:	cout << "\a";
		}
	} while (true);
}

//out put to a txt file
void write_file(Node *& head, string username) {
	string user_task_file = username + "task.txt";
	ofstream fout(user_task_file);
	if (fout.fail()) {
		cout << " Error in file opening!" << endl;
		fout.close();
		return;
	}
	while (head != NULL) {
		Node * p = head;
		fout << p->info << "\n" << p->info_2 << "\n" << p->info_3 << endl;
		head = head->next;
		delete p;
	}
	fout.close();
	return;
}

//print all the tasks
int print_list(Node * head)
{
	int count = 1;
	if (head == NULL) {
		cout << "\n\tThere is no task.";
	}
	else {
		cout << "\033[2J\033[1;1H"; //system("cls");
		cout << "\n\n\n\tTasks\n\n";
		Node * current = head;
		while (current != NULL){
			cout << "\t" << count << ". " << current->info << " $" << current->info_2 << " " <<
				((current->info_3) ? "Done" : "Doing") << "\n\n";
			current = current->next;
			count++;
		}
		cout << "\t0. Back to last page";
		return count;
	}
	return 0;

}

//Sort by price only
void Sort_tasks(Node * &head) {
	char ch;
	cout << "\n\n==========================================================\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n\tConfirm(y) ? ";
	cin >> ch;
	if (ch == 'y') {
		MergeSort(&head);
		cout << "\n\n\tSorted by price successfully. ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
	}
}

// forward insert to create the linked list
void tail_insert(Node * & head, Node * & tail, string task, double bonus, bool done = false) {
	Node * p = new Node;
	p->info = task;
	p->info_2 = bonus;
	p->info_3 = done;
	p->next = NULL;
	if (head == NULL) {
		head = p;
		tail = p;
	}
	else {
		tail->next = p;
		tail = p;
	}
}

//input from the txt file to a linked list
void read_task(Node *& head, Node * & tail,string username) {
	string task,user_task_file= username+"task.txt";
	double bonus;
	bool done;
	ifstream fin(user_task_file);
	while (getline(fin >> ws, task)) {
		fin >> bonus >> done;
		tail_insert(head, tail, task, bonus, done);
	}
}

//***************************************************************
//    	Merge Sort - Better way to sort
//****************************************************************
void MergeSort(Node** headRef){
	Node* head = *headRef;
	Node* a;
	Node* b;
	// Base case -- size 0 or 1
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}
	// split head into 'a' and 'b' sublists
	split(head, &a, &b);
	// Recursively sort the sublists
	MergeSort(&a);
	MergeSort(&b);
	*headRef = SortedMerge(a, b);
}

Node* SortedMerge(Node* a, Node* b){
	Node* sort_list = NULL;
	//Base case
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->info_2 <= b->info_2) {
		sort_list = a;
		sort_list->next = SortedMerge(a->next, b);
	}
	else {
		sort_list = b;
		sort_list->next = SortedMerge(a, b->next);
	}
	return (sort_list);
}


void split(Node* source, Node** frontRef, Node** backRef){
	Node* a;
	Node* b;
	b = source;
	a = source->next;
	// Advance 'a' two nodes, and advance 'b' one node
	while (a != NULL) {
		a = a->next;
		if (a != NULL) {
			b = b->next;
			a = a->next;
		}
	}
	// 'b' is before the midpoint in the list
	*frontRef = source;
	*backRef = b->next;
	b->next = NULL;
}
