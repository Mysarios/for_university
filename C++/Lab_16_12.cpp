#include <iostream>
#include<string>

using namespace std;

struct Node {
	int number;
	Node* Iterator;
};
class List {
	protected:
		Node* first_node;
		Node* last_node;
	public:
		void push(int num) {

			cout << " Push " << num << endl;

			last_node->number = num;
			Node* new_node = new Node;

			last_node->Iterator = new_node;
			last_node = new_node;
		}
		int pop() {

			if (first_node->Iterator == NULL) {
				cout << "Queue is empty" << endl;
				return 0;
			}

			Node* Iter;
			Iter = first_node;

			while (Iter->Iterator != last_node) {
				Iter = Iter->Iterator;
			}

			int Result = Iter->number;
			delete Iter->Iterator;
			last_node = Iter;

			cout << " Pop " << Result << endl;

			return Result;
		}
		void show() {

			int i = 1;
			Node* Iter;
			Iter = first_node;

			cout << i++ << " = " << Iter->number << endl;

			while (Iter->Iterator != last_node) {
				Iter = Iter->Iterator;
				cout << i++ << " = " << Iter->number << endl;
			}

			return;
		}
		List() {
			first_node = new Node;
			last_node = first_node;
		}
};
class Queue_list : public List {
public:
	int pop() {

		if (first_node == last_node) {
			cout << "Queue is empty" << endl;
			return 0;
		}
		//cout << "Iter= " << first_node->Iterator;

		cout << " pop " << first_node->number << endl;

		int Result = first_node->number;
		Node* nd = first_node;
		first_node = first_node->Iterator;

		delete nd;

		return Result;
	}

	Queue_list():List() {};
};

class Publication {
	protected:
		string Title;
		double price;
	public:
		virtual void putdata() {
			cout << "Enter title and price = ";
			cin >> this->Title >> this->price;
		}
		virtual void getdata() {
			cout << " Title = " << Title << "   price = " << price;
		}
		Publication() {}
};
class Book : public Publication {
	private:
		int Page_Count;
	public:
		void putdata() {
			Publication::putdata();
			cout << "Enter Page_count = ";
			cin >>this->Page_Count;

			cout << endl;
		}
		 void getdata() {
			cout << endl;

			Publication::getdata();
			cout  << " Pages = "<< Page_Count <<  endl;

			cout << endl;
		}
		 Book():Publication(){}
};
class Tape : public Publication {
	private:
		double time;
	public:
		void putdata() {
			Publication::putdata();
			cout << "Enter Time = ";
			cin>> this->time;

			cout << endl;
		}
		void getdata() {
			cout << endl;

			Publication::getdata();
			cout  << " Time = " << time << endl;

			cout << endl;
		}
		Tape() :Publication() {}
};
int main() {

	int key;
		cout << " Enter 1/2" << endl;
	cin >> key;

	Queue_list Test2;
	Publication* Array[2];
	Book* book = new Book;
	Tape* tape = new Tape;

	switch (key) {
	case 1:
		
		Test2.push(1);
		Test2.push(2);
		Test2.push(3);
		Test2.push(7);
		Test2.push(5);
		Test2.show();
		Test2.pop();
		Test2.pop();
		Test2.pop();
		Test2.show();
		Test2.pop();
		Test2.pop();
		Test2.pop();
		Test2.push(1);
		Test2.push(2);
		Test2.push(3);
		Test2.pop();
		Test2.pop();
		Test2.pop();
		Test2.pop();
		Test2.pop();
		Test2.pop();
	break;

	case 2:
		Array[0] = book;
		Array[1] = tape;

		for (int i = 0; i < 2; i++) {
			Array[i]->putdata();
		}
		for (int i = 0; i < 2; i++) {
			Array[i]->getdata();
		}

	break;
	}
}