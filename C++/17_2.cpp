#include <iostream>

using namespace std;

class Bank {
private:
	int Deposit_interest;
public:
	class Banker{
	private:
		string password;
		int* Account;
	public:
		int Get_Money(string Pass,int count) {
			bool check = 0;
			if (Pass == password) {
				check = 1;
			}
			else {
				cout << "Access denied" << endl;
				return 0;
			}
			if (check) {
				if (*Account >= count) {
					*Account -= count;
					cout << "U get = " << count << " Money to u cash" << endl;
					return count;
				}
				else {
					cout << "you don't have so much money" << endl;
					return 0;
				}
			}
		}
		void Deposit_Money(int count) {
			cout << "U depos. =" << count << " money in this bank" << endl;
			*Account += count;
		}
		int Show_Count_Of_Money(string Pass) {
			if (Pass == password) {
				cout << "U have  = " << *Account <<"  in this bank"<< endl;
				return *Account;
			}
		}
		Banker(string pass) {
			this->password = pass;
			Account = new int;
			*Account = 0;
		}
	};
	Banker banker;
	void Info_About_Bank() {
		cout << "U can have " << Deposit_interest << " % per year" << endl;
	}
	Bank(string Pass):banker(Pass) {}
};
class Stock_market {
private:
	int Profitability;
	int price;
public:
	class Broker {
	private:
		string password;
		int Count_Of_Stocks;
		int price=10;
	public:
		int Sell_Stocks(string Pass, int count) {
			bool check = 0;
			if (Pass == password) {
				check = 1;
			}
			else {
				cout << "Access denied" << endl;
				return 0;
			}
			if (check) {
				if (Count_Of_Stocks >= count) {
					cout << "U get = " << count * price << " money when u sell = " << count << " Stocks" << endl;
					Count_Of_Stocks -= count;
					return count*price;
					return 0;
				}
				else {
					cout << "you don't have so much Stocks" << endl;
					return 0;
				}
			}
		}
		void Buy_Stocks(int &money) {
			cout << "U buy = " << money / price << " Stocks and get remains = " << money - (money / price) * price << " money" << endl;
			Count_Of_Stocks += money/price;
			money -= (money / price) * price;
			return;
		}
		int Show_wealth(string Pass) {
			if (Pass == password) {
				cout << "U have Stocks on = " << Count_Of_Stocks*price << endl;
				return Count_Of_Stocks;
			}
		}
		Broker(string pass,int price) {
			this->password = pass;
			this->price = price;
			Count_Of_Stocks = 0;
		}
	};
	Broker broker;
	void Info_About_Stock_Market() {
		cout << "Our Stocks has = " << Profitability <<"  Profitability" <<endl;
	}
	Stock_market(string Pass,int price) :broker(Pass,price){
		this->price = price;
	}
};

class Financier :protected Stock_market, protected Bank {
private:
	int Cash;
	string Password;
public:
	void Show_wealth() {
		cout << "\tU wealth" << endl;
		banker.Show_Count_Of_Money(Password);
		broker.Show_wealth(Password);
		cout << " And cash = " << Cash << endl;
		cout << "Thats all\n" << endl;
	}
	void Depos_money(int count) {
		if (count > Cash) {
			cout << "you don't have so much money" << endl;
			return;
		}
		banker.Deposit_Money(count);
		Cash -= count;
	}
	void Get_money(int count) {
		Cash+=banker.Get_Money(Password, count);
	}
	void Buy_Stocks(int money) {
		if (money <= Cash) {
			Cash -= money;
			broker.Buy_Stocks(money);
			Cash += money;
		}
		else {
			cout << "you don't have so much money" << endl;
			return;
		}
	}
	void Sell_Stocks(int count) {
		Cash+=broker.Sell_Stocks(Password, count);
	}
	Financier(string Password) :Stock_market(Password,10),Bank(Password) {
		this->Password = Password;
		Cash = 50000;
	}
};
int main() {
	Financier Fin("123");
	Fin.Buy_Stocks(10000);
	Fin.Show_wealth();
	Fin.Depos_money(15000);
	Fin.Show_wealth();
	Fin.Get_money(10000);
	Fin.Show_wealth();

	return 0;
}