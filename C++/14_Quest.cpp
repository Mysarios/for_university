#include <iostream>

using namespace std;
const short MAX = 10;

class   Queue {
 private:
	 int QueueArr[MAX];
	 int* HeadOfQueue;
	 int* EndOfQueue;
 public:
	 void PutInTail(int Element) {
	
		 if ((HeadOfQueue == QueueArr) && (HeadOfQueue == EndOfQueue)) {
			 *EndOfQueue = Element;
			 cout << "Element = " << Element << " Has been added in. :  " << EndOfQueue++ << " Queue has : " << this->GetCountElements() << endl;
			 return;
		 }
		 if ((EndOfQueue >= &QueueArr[MAX]) && (HeadOfQueue == QueueArr)) {
			 cout << "Queue is full!" << endl;
			 cout << "Wait while Queue will be free...." << endl;
			 return;
		 }
		 if (EndOfQueue >= &QueueArr[MAX]) {
			 EndOfQueue = QueueArr;
			 *EndOfQueue = Element;
			 cout << "Element = " << Element << " Has been added in :  " << EndOfQueue << endl;
			 return;
		 }
		
		 if ((++EndOfQueue == HeadOfQueue) && (HeadOfQueue !=QueueArr)) {
			 cout << "Queue is full!" << endl;
			 cout << "Wait while Queue will be free..." << endl;
			 EndOfQueue--;
			 return;
		 }


		 EndOfQueue--;
		 *EndOfQueue = Element;
		 cout << "Element = " << Element << " Has been added in :  " <<EndOfQueue++<<" Queue has : "<<this->GetCountElements() << endl;

	 };
	 void GetFromHead() {
		/* if ((HeadOfQueue >= &QueueArr[MAX]) && (EndOfQueue == QueueArr)) {
			 cout << "Queue is free!" << endl;
			 cout << "Wait People...." << endl;
			 return;
		 }*/
		 if (HeadOfQueue >= &QueueArr[MAX]) {
			 HeadOfQueue = QueueArr;
			 cout << "Element = " << *HeadOfQueue << " Has been Deleted from :  " << HeadOfQueue++ << " Queue has : " << this->GetCountElements() << endl;
			 return;
		 }
		 if (HeadOfQueue == EndOfQueue) {
			 cout << "Queue is free!" << endl;
			 cout << "Wait People..." << endl;
			return;
		 }

		 cout << "Element = " << *HeadOfQueue << " Has been Deleted from :  " << HeadOfQueue++ << " Queue has : " << this->GetCountElements() << endl;
		 return ;
	 };

	 int GetCountElements() {
		 int* Head = HeadOfQueue;
		 int* End = EndOfQueue;
		 int n=0;

		 if ((End == Head) && (Head ==QueueArr)) {
			 return n;
		 }
		 if ((End == Head)) {
			 return n;
		 }
		 if (End > &QueueArr[MAX]) {
			 End = QueueArr;
		 }

		 do{
			 Head++;
			 if (Head > &QueueArr[MAX]) {
				 Head = QueueArr;
			 }
			 n++;
		}while (Head != End);

		 return n;
	 };

	 Queue() {
		 HeadOfQueue = QueueArr;
		 EndOfQueue = QueueArr;
	 }
};

class   DynamicQueue {
private:
	int* HeadOfQueue;
	int* TailOfQueue;
public:
	DynamicQueue operator=(DynamicQueue mc) {
		this->HeadOfQueue = mc.HeadOfQueue;
		this->TailOfQueue = mc.TailOfQueue;
		return mc;

	}
	void show() {
		int* head = HeadOfQueue;
		if (this->check()) {
		do {
			cout << *head << endl;
			head++;
		} while (head != TailOfQueue);
			return;
		}
		else {
			cout << "EMPTY!" << endl;
		}
		return;
	}
	bool check() {
		if (HeadOfQueue != TailOfQueue) {
			return 1;
		}
		else {
			return 0;
		}
	}
	void PutNum(int Num) {
		*TailOfQueue = Num;
		TailOfQueue++;
		cout << "Num= " << Num << " has been added" << endl;
		return;
	}
	void IncTail() {
		this->TailOfQueue--;
		return;
	}
	void GetNum(int& Num) {
		if (HeadOfQueue != TailOfQueue) {
			Num = *HeadOfQueue;
			HeadOfQueue++;
			return;
		}
		else {
			cout << "Queue is free!" << endl;
			return;
		}
	}
	void Flip(DynamicQueue DQ,int& Num) {
		//int k;
		//int* Head = HeadOfQueue;
		//int* Tail = DQ.TailOfQueue;
		//Tail--;
		//cout << "Num= " << *(--DQ.TailOfQueue) << endl;
		////*DQ.TailOfQueue = NULL;
		//do {
		//	*Head = *DQ.TailOfQueue;
		//	Head++;
		//	DQ.TailOfQueue--;
		//} while (DQ.TailOfQueue!=DQ.HeadOfQueue);
		//TailOfQueue = HeadOfQueue;
		//HeadOfQueue = Head;
		//DQ.TailOfQueue = Tail;
		//Num = *HeadOfQueue;
		//this->GetNum(k);
		//if(DQ.check())
		int* head = this->HeadOfQueue;
		int* tail = DQ.TailOfQueue;
		TailOfQueue = head;
		if (DQ.HeadOfQueue == --DQ.TailOfQueue) {
			Num = *DQ.HeadOfQueue;
			*DQ.HeadOfQueue = NULL;
			DQ.HeadOfQueue++;
			return;
		}
		--tail;
		do {
			*head = *tail;
			head++;
			TailOfQueue++;
			tail--;
		} while (tail != DQ.HeadOfQueue);

		*head = *tail;
		//*(--DQ.TailOfQueue)=NULL;
		this->GetNum(Num);			
	}
	DynamicQueue() {
		HeadOfQueue = new int;
		TailOfQueue = HeadOfQueue;
	}
};

class   SStack {
private:
	DynamicQueue QueueForPut;
	DynamicQueue QueueForGet;
public:
	void PutInStack(int Num) {
		QueueForPut.PutNum(Num);
		return;
	}
	void GetFromStack() {
		int Num;
		if (QueueForPut.check()) {
			QueueForGet.Flip(QueueForPut, Num);
			QueueForPut.IncTail();
			cout << "Num= " << Num << " has been deleted" << endl;
		}
		else {
			cout << "EROR!" << endl;
		}
	}
	void Show() {
		QueueForPut.show();
	}
	SStack():QueueForGet(),QueueForPut(){ }
};

class   Stack {
	private:
		int* HeadOfStack;
		int* TailOfStack;
	public:
		bool check() {
			if (HeadOfStack != TailOfStack) {
				return 0;
			}
			else {
				return 1;
			}
		}
		void Show() {
			int* tail=TailOfStack;
			int* head = HeadOfStack;

			if (TailOfStack == HeadOfStack) {
				cout << *head << endl;
				return;
			}
			do {
				cout << *head << endl;
				head++;
			} while (TailOfStack != head);
			return;
		}
		void Input(int Num) {
			*TailOfStack = Num;
			TailOfStack++;
			return;
		}
		void Get() {
			this->HeadOfStack++;
			return;
		}
		void Flip(Stack stack,int &Num) {
			int* head = HeadOfStack;
			int* tail = stack.TailOfStack;
			if (stack.HeadOfStack == --stack.TailOfStack) {
				Num = *stack.HeadOfStack;
				*stack.HeadOfStack = NULL;
				stack.HeadOfStack++;
				return;
			}
			tail--;
			do {
				*head = *tail;
				head++;
				tail--;
			} while (tail != stack.HeadOfStack);

			TailOfStack = head;
			Num = *tail;
			return;
		}
		Stack() {
			HeadOfStack = new int;
			TailOfStack = HeadOfStack;
		}
};
class QueueFromTwo {
	private:
		Stack StackForGet;
		Stack StackForPut;
	public:
		void Show() {
			if (StackForPut.check()) {
				cout << "EMPTY!" << endl;
				return;
			}
			StackForPut.Show();
		}
		void PutNum(int Num) {
			StackForPut.Input(Num);
			cout << "Added " << Num << " to Queue" << endl;
			return;
		}
		void GetNum() {
			if (StackForPut.check()) {
				cout << "ERROR" << endl;
				return;
			}
			int Num;
			StackForGet.Flip(StackForPut,Num);
			StackForPut.Get();
			cout << "Get from Queue= " << Num << endl;
			return;
		}
		QueueFromTwo() :StackForGet(), StackForPut() {}
};
int main() {
	int key;
	Queue FQueue;
	SStack One;
	QueueFromTwo Two;

	int Element;

	cout << "Enter 2 or 3 or 4" << endl;
	cin >> key;
	switch (key) {
	case 2:
		for (;;) {

			cout << "Enter 0 to Del or 1 to Add" << endl;
			cin >> key;

			switch (key) {
			case 0:
				FQueue.GetFromHead();
				break;
			case 1:
				cout << "Enter *name* of Element (int)= ";
				cin >> Element;
				FQueue.PutInTail(Element);
				break;
			}
		}
		break;

	case 3:

		for (;;) {

			cout << "Enter 0 to Del or 1 to Add or 2 to show stack" << endl;
			cin >> key;
			cout << " " << endl;

			switch (key) {
			case 0:
				Two.GetNum();
				break;
			case 1:
				cout << "Enter *name* of Element (int)= ";
				cin >> Element;
				Two.PutNum(Element);
				break;
			case 2:
				Two.Show();
				break;
			}

		}
		break;

	case 4:
		for (;;) {
			cout << "Enter 0 to Del or 1 to Add or 2 to show stack" << endl;
			cin >> key;
			cout << " " << endl;
			switch (key) {
			case 0:
				One.GetFromStack();
				break;
			case 1:
				cout << "Enter *name* of Element (int)= ";
				cin >> Element;
				One.PutInStack(Element);
				break;
			case 2:
				One.Show();
				break;
			}
			break;
		}
	}
}