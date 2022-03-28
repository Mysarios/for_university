#include<iostream>
class Fraction {
private:
	int Numerator;
	int Denominator;
public:
	void reduction() {
		int MainNum;

		if (Numerator == Denominator) {
			Numerator = 1;
			Denominator = 1;
		}

		abs(Numerator) > abs(Denominator) ? MainNum = abs(Denominator) : MainNum = abs(Numerator);

		for (int i = 2; i < MainNum; i++) {
			if (Numerator % i == 0 && Denominator % i == 0) {
				Numerator /= i;
				Denominator /= i;
				reduction();
			}
		}

		return;
	}
	void show() {
		reduction();
		std::cout << Numerator << " / " << Denominator << std::endl;
	}
	Fraction operator+(Fraction F) {
		std::cout << this->Numerator << " / " << this->Denominator <<"  +  ";
		std::cout << F.Numerator << " / " << F.Denominator << "  =  ";

		if (this->Denominator == F.Denominator) {
			Fraction Result(this->Numerator+F.Numerator,this->Denominator);
			//Result.show();
			return Result;
		}
		else {
			Fraction Result(this->Numerator * F.Denominator + F.Numerator * this->Denominator, F.Denominator * this->Denominator);
			//Result.show();
			return Result;
		}

		Fraction Result(1);
		return Result;
	}
	Fraction operator-(Fraction F) {
		std::cout << this->Numerator << " / " << this->Denominator << "  -  ";
		std::cout << F.Numerator << " / " << F.Denominator << "  =  ";

		if (this->Denominator == F.Denominator) {
			Fraction Result(this->Numerator - F.Numerator, this->Denominator);
			return Result;
		}
		else {
			Fraction Result(this->Numerator * F.Denominator - F.Numerator * this->Denominator, F.Denominator * this->Denominator);
			return Result;
		}

		Fraction Result(1);
		return Result;
	}
	Fraction operator*(Fraction F) {
		std::cout << this->Numerator << " / " << this->Denominator << "  *  ";
		std::cout << F.Numerator << " / " << F.Denominator << "  =  ";

		Fraction Result(this->Numerator * F.Numerator, this->Denominator * F.Denominator);
		return Result;
	}
	Fraction operator/(Fraction F) {
		std::cout << this->Numerator << " / " << this->Denominator << "  /  ";
		std::cout << F.Numerator << " / " << F.Denominator << "  =  ";

		Fraction Result(this->Numerator * F.Denominator, this->Denominator * F.Numerator);
		return Result;
	}
	Fraction operator=(Fraction F) {
		this->Numerator = F.Numerator;
		this->Denominator = F.Denominator;
		return *this;
	}
	Fraction(int N, int D=1) {
		Numerator = N;
		Denominator = D;
		this->show();
		std::cout << std::endl;
	}

};
class Distance {
private:
	int meters;
	int centimeters;
public:
	void show() {
		while (centimeters >= 100) {
			centimeters -= 100;
			meters++;
		}
		while (centimeters < 0) {
			centimeters += 100;
			meters--;
		}

		std::cout << " " << meters << " m, " << centimeters << " cm" << std::endl;
	}
	Distance operator+(Distance D) {
		Distance Result(this->meters + D.meters, this->centimeters + D.centimeters);
		Result.show();

		return Result;
	}
	Distance operator-(Distance D) {
		if (this->centimeters + this->meters * 100 < D.centimeters + D.meters * 100) {
			std::cout << "U can't do this!" << std::endl;
			Distance Res(0,0);
			return Res;
		}

		Distance Result(this->meters - D.meters, this->centimeters - D.centimeters);
		Result.show();

		return Result;
	}
	Distance operator*(Distance D) {
		Distance Result(0, (this->meters * 100 + this->centimeters) * (D.centimeters + D.meters * 100)/100);
		Result.show();

		return Result;
	}
	Distance operator+=(Distance D) {
		this->meters += D.meters;
		this->centimeters += D.centimeters;
		Distance Result(this->meters, this->centimeters);

		return Result;
	}
	bool operator>(Distance D) {
		if (this->centimeters + this->meters * 100 > D.centimeters + D.meters * 100) {
			//std::cout << "U can't do this!" << std::endl;
			//Distance Res(0, 0);
			return 1;
		}
		else {
			return 0;
		}
	}
	bool operator==(Distance D) {
		if (this->centimeters + this->meters * 100 == D.centimeters + D.meters * 100) {
			//std::cout << "U can't do this!" << std::endl;
			//Distance Res(0, 0);
			return 1;
		}
		else {
			return 0;
		}
	}
	Distance(int m, int cm ) {
		meters = m;
		centimeters = cm;
	}
};
class Time {
private:
	int hours;
	int minutes;
	int seconds;
public:
	void show() {

		while (seconds >= 60) {
			seconds -= 60;
			minutes++;
		}
		while (minutes >= 60) {
			minutes -= 60;
			hours++;
		}

		while (seconds < 0) {
			seconds += 60;
			minutes--;
		}
		while (minutes < 0) {
			minutes += 60;
			hours--;
		}
		if (hours < 0) { std::cout << "Time is over!" << std::endl; return; }

		std::cout << hours << " h " << minutes << " m " << seconds << " s " << std::endl;
	}
	Time operator+(Time time) {
		Time Result(this->hours + time.hours, this->minutes + time.minutes, this->seconds + time.seconds);
		return Result;
	}
	Time operator-(Time time) {
		Time Result(this->hours - time.hours, this->minutes - time.minutes, this->seconds - time.seconds);
		return Result;
	}
	Time operator*(Time time) {
		Time Result(0 ,(this->hours*3600+this->minutes*60+this->seconds)*(time.hours*3600+time.minutes*60+time.seconds)/60/60/60, 0);
		return Result;
	}

	Time(int H, int M = 0, int S = 0) {
		this->hours = H;
		this->minutes = M;
		this->seconds = S;
	}
};
class Time24{
private:
	int hours;
	int minutes;
public:
	void show() {

		/*while (seconds >= 60) {
			seconds -= 60;
			minutes++;
		}
		while (seconds < 0) {
			seconds += 60;
			minutes--;
		}*/

		while (minutes >= 60) {
			minutes -= 60;
			hours++;
		}

		while (minutes < 0) {
			minutes += 60;
			hours--;
		}
		//if (hours < 0) { std::cout << "Time is over!" << std::endl; return; }
		hours = hours % 24;
		std::cout << hours << " h " << minutes << " m    24h format"<< std::endl;
	}
	void GetTIme(int& H, int& M) {
		H = hours;
		M = minutes;
	}
	Time24(int H, int M, int type=12) {
		hours = H;
		minutes = M;

		if (type == 24) {
			hours += 12;
		}
	}
};
class Time12 {
private:
	int hours;
	int minutes;
	int type;
public:
	void show() {
		char Type;
		while (minutes >= 60) {
			minutes -= 60;
			hours++;
		}
		while (minutes < 0) {
			minutes += 60;
			hours--;
		}
		hours = hours % 24;
		if (hours < 0) { std::cout << "Time is over!" << std::endl; return; }

		if (hours >= 12 ) {
			hours -= 12;
			type = 24;
		}
		if (hours < 12 && type != 24) {
			type = 12;
		}

		switch (type) {
		case 12:
			Type = 'a';
			break;
		case 24:
			Type = 'p';
			break;
		}

		std::cout << hours << " h " << minutes << " m  " << Type << ".m" << std::endl;
	}
	Time24 convertTo24() {

		std::cout << std::endl;
		this->show();
		std::cout << "Has been converted to =>";

		Time24 Result(hours, minutes, type);
		return Result;
	}
	Time12 convertFrom24(Time24 time) {
		time.GetTIme(hours, minutes);
		Time12 Result(hours, minutes);

		std::cout << std::endl;
		Result.show();
		std::cout << "Has been converted from =>";
		time.show();
		std::cout << std::endl;

		return Result;
	}
	Time12(int H, int M) {
		hours = H;
		minutes = M;
	}
};
int main() {
	int key;

	std::cout << "Enter 1 for First(Frac) Question, 2 for Second(Dist),3 for third(time),4 for quest with 2 formats of time." << std::endl;
	std::cin >> key;

	switch (key) {
		case 1:
			for (; ; ) {
				int num1, num2, dem1, dem2;
				char ch1, ch;

				std::cout << "Enter 2 Fractions and operations\n" << std::endl;
				std::cin >> num1 >> ch1 >> dem1 >> ch >> num2 >> ch1 >> dem2;
				std::cout<<std::endl;

				Fraction First(num1, dem1);
				Fraction Second(num2, dem2);
				Fraction Result(1);

				switch (ch) {
					case '+':
					    Result = First + Second;
					break;

					case '-':
						Result = First - Second;
						break;

					case '*':
						Result = First * Second;
						break;

					case '/':
						Result = First / Second;
						break;
				}

			}
			break;
		case 2:
			for (; ; ) {
				int m1, m2, cm1, cm2;
				char ch1,ch;

				std::cout << "Enter 2 Dist( m.cm char m.cm) and operations" << std::endl;
				std::cin >> m1 >> ch1 >> cm1 >> ch;

				if (ch == '=') {
					 std::cin >> ch1;
					 ch += ch1;
				}

				if (ch == '+') {
					std::cin >> ch1;

					if (ch1 == '=') {
						ch += ch1;
						std::cin >> m2 >> ch1 >> cm2;
					}else {
						m2 = ch1 - '0';
						std::cin>> ch1 >> cm2;
					}
				}else {
					std::cin >> m2 >> ch1 >> cm2;
					std::cout << std::endl;
				}

				if (cm1 / 10 == 0) {
					cm1 *= 10;
				}
				if (cm2 / 10 == 0) {
					cm2 *= 10;
				}

				Distance First(m1, cm1);
				Distance Second(m2, cm2);
				Distance Result(0, 0);

				switch (ch) {
				case '+':
					Result = First + Second;
					break;

				case '-':
					Result = First - Second;
					break;

				case '*':
					Result = First * Second;
					break;

				case '>':
					First > Second ? std::cout << "True" << std::endl : std::cout << "False" << std::endl;
					break;

				case 122:
					First == Second ? std::cout << "True" << std::endl : std::cout << "False" << std::endl;
					break;

				case 104:
					Result=First += Second;
					//Result.show();                                   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
					std::cout << "\nFor exapmle we add to resulting dist 10 m. 55cm.   \n\nFirst= ";
					First.show();
					std::cout << "Result= ";
					Distance Add(10, 55);
					Result = First + Add;
					std::cout << std::endl;
					break;
				}

			}
			break;
		case 3:
			for (; ; ) {
				int h1,h2,m1, m2, s1, s2;
				char ch1, ch;

				std::cout << "Enter 2 Times(hour:minute:seconds) and operation" << std::endl;
				std::cin >> h1 >> ch1 >> m1 >> ch1 >> s1 >> ch >> h2 >> ch1 >> m2 >> ch1 >> s2;
				std::cout << "Result = ";

				Time First(h1,m1,s1);
				Time Second(h2,m2,s2);
				Time Result(0);

				switch (ch) {
				case '+':
					Result = First + Second;
					Result.show();
					break;

				case '-':
					Result = First - Second;
					Result.show();
					break;

				case '*':
					Result = First * Second;
					Result.show();
					break;
				}
			}
			break;
		case 4:
			std::cout << std::endl;

			Time12 one(23, 90);
			Time12 two(26, 55);
			Time24 tree(60, 50);
			Time12 fourth(16, 49);
			one.show();
			two.show();
			tree.show();
			fourth.show();

			Time24 Buffer= fourth.convertTo24();
			Buffer.show();

			two.convertFrom24(Buffer);
			two.show();
			two.show();

			std::cout << "\n\nEnter time in 24 format!"<<std::endl;
			int h1, m1;
			char ch;

			std::cin >> h1 >> ch >> m1;
			std::cout << std::endl;

			Time24 First(h1, m1);
			First.show();

			std::cout << "Create Empty time12 : ";
			Time12 Second(0, 0);
			Second.show();
			Second.convertFrom24(First);
			Time24 Third = Second.convertTo24();
			Third.show();
	}
}