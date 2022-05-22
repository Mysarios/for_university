#include <iomanip>
#include <iostream>
#include <Windows.h>
using namespace std;
struct color
{
	int r, g, b;
};

class line {
private:
	COORD x, y; 
	color color;
	int Penstile;
	double Width;
	;
public:
	void lines();

	line() :x{ 10,20 }, y{ 80,69 }, color({ 60,179,113 }), Penstile(0), Width(0.9) {};
	line(COORD a, COORD b, int p, double w) : x(a), y(b), Penstile(p), Width(w) { };
};

void line::lines() {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO curs;
	GetConsoleCursorInfo(hStdout, &curs);
	curs.bVisible = FALSE;
	SetConsoleCursorInfo(hStdout, &curs);

	HWND hWindow = GetConsoleWindow();
	HDC hDeviceContext = GetDC(hWindow);
	HPEN pen;

	pen = CreatePen(Penstile, Width, (color.r, color.g, color.b));
	SelectObject(hDeviceContext, pen);
	MoveToEx(hDeviceContext, x.X, x.Y, NULL);
	LineTo(hDeviceContext, y.X, y.Y);
	DeleteObject(pen);
}

class shape {
protected:
	COORD point;
	color color_type;
public:
	virtual void draw() = 0;

	shape() :point({ 480,350 }), color_type({ (255, 255, 0) }) {};
	shape(COORD c, color col) :point(c), color_type(col) {};
};

class rect :public shape {
private:
	int height;
	int weight;
	color color_type;
public:
	void draw() {
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO curs;
		GetConsoleCursorInfo(hStdout, &curs);
		curs.bVisible = FALSE;
		SetConsoleCursorInfo(hStdout, &curs);

		HWND hWindow = GetConsoleWindow();
		HDC hDeviceContext = GetDC(hWindow);

		HBRUSH hbrush = CreateSolidBrush(RGB(color_type.r, color_type.g, color_type.b));
		SelectObject(hDeviceContext, hbrush);
		Rectangle(hDeviceContext, point.X, point.Y, point.X + weight, point.Y + height);
		DeleteObject(hbrush);
		SelectObject(hDeviceContext, hbrush);
		ReleaseDC(hWindow, hDeviceContext);
	}

	rect() :height(100), weight(200) {};
	rect(int h, int w) :height(h), weight(w) {};
	rect(int h, int w, color color_type) :height(h), weight(w), color_type(color_type) {};
};

class circle :public shape {
private:
	int Radius;
	color color_type;
public:

	void draw() {
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO curs;
		GetConsoleCursorInfo(hStdout, &curs);
		curs.bVisible = FALSE;
		SetConsoleCursorInfo(hStdout, &curs);
		//ïîäãîòîâêà
		HWND hWindow = GetConsoleWindow();
		HDC hDeviceContext = GetDC(hWindow);
		//ðèñóåì êðóã
		HBRUSH hbrush = CreateSolidBrush(RGB(color_type.r, color_type.g, color_type.b));//ÑÄÅËÀËÈ ÊÈÑÒÎ×ÊÓ
		SelectObject(hDeviceContext, hbrush);
		Ellipse(hDeviceContext, point.X - Radius, point.Y - Radius, point.X + Radius, point.Y + Radius);
		DeleteObject(hbrush);
		ReleaseDC(hWindow, hDeviceContext);
	}

	circle() : Radius(150) {};
	circle(int r) :Radius(r) {};
	circle(int r, color color_type) :Radius(r), color_type(color_type) {};


};
class ellips :public shape {
private:
	int Radius1;
	int Radius2; 
	color color_type;
public:
	void draw() {
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO curs;
		GetConsoleCursorInfo(hStdout, &curs);
		curs.bVisible = FALSE;
		SetConsoleCursorInfo(hStdout, &curs);

		HWND hWindow = GetConsoleWindow();
		HDC hDeviceContext = GetDC(hWindow);

		HBRUSH hbrush = CreateSolidBrush(RGB(color_type.r, color_type.g, color_type.b));//ÑÄÅËÀËÈ ÊÈÑÒÎ×ÊÓ
		SelectObject(hDeviceContext, hbrush);
		Ellipse(hDeviceContext, point.X - Radius1, point.Y - Radius2, point.X + Radius1, point.Y + Radius2);
		DeleteObject(hbrush);
		ReleaseDC(hWindow, hDeviceContext);
	}

	ellips() :Radius1(100), Radius2(200) {};
	ellips(int r1, int r2) :Radius1(r1), Radius2(r2) {};
	ellips(int r1, int r2, color color_type) :Radius1(r1), Radius2(r2), color_type(color_type) {};
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
		Time Result(0, (this->hours * 3600 + this->minutes * 60 + this->seconds) * (time.hours * 3600 + time.minutes * 60 + time.seconds) / 60 / 60 / 60, 0);
		return Result;
	}
	friend ostream& operator << (ostream& O_str, const Time& Time)
	{

		O_str << Time.hours << "h :" << Time.minutes << "m :" << Time.seconds<<"s";

		return O_str;
	}

	Time(int H, int M = 0, int S = 0) {
		this->hours = H;
		this->minutes = M;
		this->seconds = S;
	}
};
int main() {

	COORD point_mass[] = { { 480, 350 },{ 480, 500 } };
	color rgb[] = { {102,204,255},{60,179,113},{ 255,255,102 } };
	color white = { 238,232,232 };
	color Red = { 218,30,30 };
	color green[] = { {41,95,41},{61,139,61},{86,176,86} };
	color dop = { 166,233,224 };
	color skin = { 218,198,144 };
	color black = { 0,0,0 };

	ellips ellips_1(100, 65, skin);
	ellips ellips_2(95, 60, white);
	ellips ellips_3(50, 50, green[0]);
	ellips ellips_4(48, 48, green[1]);
	ellips ellips_5(45, 45, green[2]);
	ellips ellips_6(15, 43, black);

	rect rectangle_1(12, 8, white);

	Time t3(11, 5, 14), t1(6, 5, 15);
	Time t2(0);
	
	
	shape* Arr[7];
	int key;
	cout << "Enter key for 1 or 2 =";
	cin >> key;
	system("cls");

	switch (key){
	case 1:
		Arr[0] = &ellips_1;
		Arr[1] = &ellips_2;
		Arr[2] = &ellips_3;
		Arr[3] = &ellips_4;
		Arr[4] = &ellips_5;
		Arr[5] = &ellips_6;
		Arr[6] = &rectangle_1;


		for (int i = 0; i < 7; i++) {
			Arr[i]->draw();
		}

		break;
	case 2:
		cout << "Time 1 = ";
		cout << t1 << endl << endl;
		cout << "Time 2 = ";
		cout << t3 << endl << endl;

		t2 = t1 + t3;
		cout << "Result time = ";
		cout << t2 << endl << endl;

		break;
	}
}