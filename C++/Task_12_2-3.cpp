#include<iostream>
#include<Windows.h>
#include <stdlib.h>
#include <conio.h>


using namespace std;
struct RGB {
	int Red = 0;
	int Green = 0;
	int Blue = 0;
};
class rect {
private:
	COORD Left_Down;
	COORD Right_Top;
	COLORREF Color = RGB(0, 0, 0);
	RECT rectal;
public:
	void draw() {

		ShowCursor(FALSE);
		HPEN hPen;
		HWND hWindow = GetConsoleWindow();
		HDC hDeviceContext = GetDC(hWindow);
		HBRUSH hBrush = CreateSolidBrush(Color);
		SelectObject(hDeviceContext, hBrush);
		Rectangle(hDeviceContext, Left_Down.X, Right_Top.Y, Right_Top.X, Left_Down.Y);
	}
	void Set_Parametrs(COORD Le_Do,COORD Ri_To,int Red,int Green,int Blue) {
		this->Left_Down = Le_Do;
		this->Right_Top = Ri_To;
		this->Color = RGB(Red, Green, Blue);
	}
	rect(CONSOLE_SCREEN_BUFFER_INFO csbiInfo) {
		Left_Down.Y = 16 * (csbiInfo.srWindow.Bottom - csbiInfo.srWindow.Top + 1)-20;
		Right_Top.X = 2 * 4 * (0 + csbiInfo.srWindow.Right - csbiInfo.srWindow.Left + 1)-20;
		Left_Down.X = 20;
		Right_Top.Y = 20;
	}
};
int main() {
	int key;
	cout << "Enter 1 to 12.2 and 2 to 12.3" << endl;
	cin >> key;

	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hout, &csbiInfo);
	rect Rectal(csbiInfo);
		int Red, Green, Blue, Left, Down, Top, Right, amount;

	if (key == 1) {
		rect RectalOne(csbiInfo);
		rect RectalTwo(csbiInfo);
		rect RectalThree(csbiInfo);
		rect RectalFourth(csbiInfo);
		rect RectalFifth(csbiInfo);
		cout << "Enter amount of Rects(<=5)" << endl;
		cin >> amount;
		COORD LD, RT;
		rect Rect_Array[5] = { RectalOne ,RectalTwo , RectalThree , RectalFourth, RectalFifth };
		for (int i = 0; i < amount; i++) {
			cout << "Enter Coords: Left Down Right Top= ";
			cin >> Left >> Down >> Right >> Top;
			LD.X = Left * 10;
			LD.Y = Down * 10;
			RT.X = Right * 10;
			RT.Y = Top * 10;
			cout << "\nEnter Red Green Blue ";
			cin >> Red >> Green >> Blue;
			system("cls");
			Rect_Array[i].Set_Parametrs(LD, RT, Red, Green, Blue);
			//Rect_Array[i].draw();
		}
		CONSOLE_CURSOR_INFO curs;
		GetConsoleCursorInfo(hin, &curs);
		curs.bVisible = 0;
		for (int i = 0; i < amount; i++) {
			Rect_Array[i].draw();
		}
	}else{
			CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
			GetConsoleScreenBufferInfo(hout, &csbiInfo);
			COORD Left_Down, Right_Top,LDnow,RTnow,Center;
			
			Left_Down.Y = 14 * (csbiInfo.srWindow.Bottom - csbiInfo.srWindow.Top + 1);
			Right_Top.X = 8 * (csbiInfo.srWindow.Right - csbiInfo.srWindow.Left + 1);
			Left_Down.X = 0;
			Right_Top.Y = 0;
			LDnow.X =  Right_Top.X / 2;
			LDnow.Y =  Left_Down.Y / 2 ;
			RTnow.X =  Right_Top.X / 2 ;
			RTnow.Y =  Left_Down.Y / 2 ;
			int n = 0,indT=15,IntR=10;

		for (;;) {

			system("cls");
			if (n == 0) {
				Red = 255;
				Blue = 0;
				Green = 0;
			}
			if (n == 1) {
				Red = 0;
				Blue = 255;
				Green = 0;
			}
			if (n == 2) {
				Red = 0;
				Blue = 0;
				Green = 255;
			}
			n++;
			rect* Rectal=new rect(csbiInfo);
			Rectal->Set_Parametrs(LDnow, RTnow, Red, Green, Blue);
			Rectal->draw();
			Sleep(600);
			delete Rectal;
			LDnow.X -= indT;
			LDnow.Y += IntR;
			RTnow.X += indT;
			RTnow.Y -= IntR;
			if (LDnow.X <= 0) {
				LDnow.X = Right_Top.X / 2 - 30;
				LDnow.Y = Left_Down.Y / 2 + 20;
				RTnow.X = Right_Top.X / 2 + 30;
				RTnow.Y = Left_Down.Y / 2 - 20;
			}
			if (LDnow.Y >= Left_Down.Y) {
				LDnow.X = Right_Top.X / 2 - 30;
				LDnow.Y = Left_Down.Y / 2 + 20;
				RTnow.X = Right_Top.X / 2 + 30;
				RTnow.Y = Left_Down.Y / 2 - 20;
			}
			if (RTnow.X >= Right_Top.X) {
				LDnow.X = Right_Top.X / 2 - 30;
				LDnow.Y = Left_Down.Y / 2 + 20;
				RTnow.X = Right_Top.X / 2 + 30;
				RTnow.Y = Left_Down.Y / 2 - 20;
			}
			if (RTnow.Y <= Right_Top.Y) {
				LDnow.X = Right_Top.X / 2 - 30;
				LDnow.Y = Left_Down.Y / 2 + 20;
				RTnow.X = Right_Top.X / 2 + 30;
				RTnow.Y = Left_Down.Y / 2 - 20;
			}
			
			n =n% 3;
		}
	}
	_getche();
	return 0;
}