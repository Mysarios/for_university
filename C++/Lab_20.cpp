#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;




string Read_File(string Direct) {
	string line, Result;
	ifstream in(Direct);

	cout << "Read:  " << Direct << endl << endl;
	cout << "\tStart read:" << endl;
	if (in.is_open()) {
		while (getline(in, line)) {
			Result += line;
			Result += '\n';
			std::cout << line << std::endl;
		}
	}
	in.close();
	cout << "\tEnd read\n" << endl;


	return Result;
}
void   Clean_File(string Direct) {
	cout << "Clean:" << Direct << endl;
	ofstream out(Direct);

	if (out.is_open()) {
		out << " " << std::endl;
	}
	out.close();

	cout << "Was Clean:" << Direct << endl;
}
void   Write_File(string Direct, string Text_To_Write) {
	ofstream out(Direct, std::ios::app);

	if (out.is_open()) {
		out << Text_To_Write << std::endl;
	}
	out.close();

	cout << "Was Written:" << Direct << endl;
}
string Read_Line(string Direct, int num) {
	string line, Result;
	ifstream in(Direct);
	int i = 1;

	cout << "Read:  " << Direct << endl << endl;
	if (in.is_open()) {
		while (getline(in, line)) {
			if (i == num) {
				Result += line;
				std::cout << line << std::endl;
			}
			i++;
		}
	}
	if (i < num) {
		cout << "Wrong num! Size of lines less then num!!" << endl;
		return " ";
	}

	in.close();

	return Result;
}

int* Get_Array(string Massiv_In_String, int &size) {
	int* Array_Of_Nums = new int[1];
	int* Buffer = new int[1];
	int i = 0, check = 0;
	Array_Of_Nums[0] = 0;

	for (auto ch : Massiv_In_String) {
		if (ch >= '0' && ch <= '9') {
			cout << ch << "  -Write-  " << i << endl;
			Array_Of_Nums[i] *= pow(10, check++);
			Array_Of_Nums[i] += (int)ch - 48;
		}
		else {
			check = 0;
			i++;
			for (int j = 0; j < i; j++) {
				Buffer[j] = *(Array_Of_Nums + j);
			}
			Array_Of_Nums = new int[i + 1];

			for (int j = 0; j < i; j++) {
				Array_Of_Nums[j] = *(Buffer + j);
			}

			Array_Of_Nums[i] = 0;
			Buffer = new int[i + 1];

		}
	}
	size = i;

	return Array_Of_Nums;
}
void New_Massiv_For_Quest2(int F_size, int* F_Massiv, int* S_Massiv, int** Result)
{
	for (int j = 0; j < F_size; j++) {
		Result[0][j] = F_Massiv[j] + S_Massiv[j];
	}
	for (int j = 0; j < F_size; j++) {
		Result[1][j] = F_Massiv[j] - S_Massiv[j];
	}
	for (int j = 0; j < F_size; j++) {
		Result[2][j] = F_Massiv[j] * S_Massiv[j];
	}
}
void GetStr_FromMass(int F_size, std::string& Res, int** Result)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < F_size; j++) {
			Res += to_string(Result[i][j]) + ' ';
		}
		Res += '\n';
	}
}

struct names {
	std::string Name_B;
	double Regn;
	//names* names_ptr;
};
struct plan {
	std::string plan_n;
	std::string Num_SC;
	std::string Name;
	//plan* plan_ptr;
};
struct money_list {
	int Regn, VR, VV, VITG, ORA, OVE, OITGA, ORP, OVP, OITGP, IR, IV, IITG, PRIZ;
	std::string plan;
	std::string Num_SC;
	std::string DT;
	std::string A_P;
	//money_list* money_list_ptr;
};

bool Sort_Max(names A , names B) {
	return A.Regn < B.Regn;
}

void Sort_NamesTXT(string DIR) {
	vector < names > Names_V;
	string line, Result, Name = "", Regn = "";
	names Array_val;
	Array_val.Name_B = Name;
	Array_val.Regn = 0;

	ifstream in(DIR);
	int n = 0;
	if (in.is_open()) {
		while (getline(in, line)) {
			string Buffer[2];
			int  j = 0;
			n++;
			Result = line;
			int size = Result.size();
			for (int i = 0; i < size; i++) {
				if (Result[i] == ';') {
					j++;
				}
				else {
					Buffer[j] += Result[i];
				}
			}
			//names* Buffer = new names;
			Array_val.Name_B = Buffer[1];
			Array_val.Regn = atof(Buffer[0].c_str());

			//ptr_First = Buffer;
			Names_V.push_back(Array_val);
			Buffer[0] = "";
			Buffer[1] = "";
		}
	}

	for (int i = 0; i < Names_V.size(); i++) {
		cout << " Regn = " << Names_V[i].Regn << "  Name = " << Names_V[i].Name_B << endl;
	}

	sort(Names_V.begin(), Names_V.end(), Sort_Max);

	for (int i = 0; i < Names_V.size(); i++) {
		cout << " Regn = " << Names_V[i].Regn << "  Name = " << Names_V[i].Name_B << endl;
	}

	in.close();
}

class Names_c {
private:
	int size_Arr;
	vector < names > Names_V;
public:
	int Get_All_Values(string Dir) {

		string line, Result, Name = "", Regn = "";
		names Array_val;
		Array_val.Name_B = Name;
		Array_val.Regn = 0;
		//cout << Dir << endl;
		

		ifstream in(Dir);
		int n = 0;
		//cout << Dir << endl;

		if (in.is_open()) {
			//cout << "1" << endl;
			while (getline(in, line)) {
				//cout << "2" << endl;
				string Buffer[2];
				int  j = 0;
				n++;
				Result = line;
				int size = Result.size();
				for (int i = 0; i < size; i++) {
					if (Result[i] == ';') {
						j++;
					}
					else {
						Buffer[j] += Result[i];
					}
				}
				//names* Buffer = new names;
				Array_val.Name_B = Buffer[1];
				Array_val.Regn = atof(Buffer[0].c_str());
				
				//ptr_First = Buffer;
				Names_V.push_back(Array_val);
				Buffer[0] = "";
				Buffer[1] = "";
			}
		}
		in.close();
		size_Arr = n;
		cout << "GET" << endl;
		return n;
	}
	void Show() {
		for (int i = 0; i < size_Arr; i++) {
			cout << " Regn = " << Names_V[i].Regn << "  Name = " << Names_V[i].Name_B << endl;
		}
	}
	string Get_by_Id(double ID) {
		for (int i = 0; i < size_Arr-1; i++) {
			if (Names_V[i].Regn == ID) {
				cout << Names_V[i].Name_B << endl;
				return  Names_V[i].Name_B;
			}
		}
		return "";
	}

	Names_c() {}
};
class plan_c {
private:
	vector <plan> Plan_V;
	int size_Arr;

public:
	int Get_Info(string Dir) {
		string line, Result, Plan = "", Num_SC = "", Name = "";

		plan Buffer = { Plan, Num_SC , Name };
		string Array_Str[3];

		ifstream in(Dir);
		int n = 0;

		if (in.is_open()) {
			while (getline(in, line)) {
				int  j = 0;
				n++;
				Result = line;

				int size = Result.size();

				for (int i = 0; i < size; i++) {
					if (Result[i] == ';') {
						j++;
					}
					else {
						Array_Str[j] += Result[i];
					}
				}

				Buffer.Name = Array_Str[0];
				Buffer.Num_SC = Array_Str[1];
				Buffer.plan_n = Array_Str[2];
				Plan_V.push_back(Buffer);

				Array_Str[0] = "";
				Array_Str[1] = "";
				Array_Str[2] = "";
			}
		}
		in.close();
		
		size_Arr = n;
		//cout << size_Arr << endl;
		return n;
	}
	void Show() {
		int i;
		for ( i = 0; i < size_Arr - 1; i++) {
			cout << " Name = " << Plan_V[i].Name << " NameSC = " << Plan_V[i].Num_SC << " Plan_N= " << Plan_V[i].plan_n << endl;

		}
	
	}
	string Get_by_Id(int ID) {

		string ID_new = to_string(ID);

		for (int i = 0; i < size_Arr; i++) {
			if (Plan_V[i].Num_SC == ID_new) {
				cout << Plan_V[i].plan_n << endl;
				return  Plan_V[i].plan_n;
			}		
		}
		return "";
	}

	plan_c() {}
};
class money_list_c {
private:
	vector <money_list> Money_V;
	int size_Arr;
public:
	int Get_Info(string Dir) {
		string line, Result, Regn = "", VR = "", VV = "", VITG = "", ORA = "", OVE = "", OITGA = "", ORP = "", OVP = "", OITGP = "",
			IR = "", IV = "", IITG = "", PRIZ = "", A_P = "", DT = "", Num_SC = "", plan = "";
		string Buffer[] = { Regn, VR, VV, VITG, ORA, OVE, OITGA, ORP, OVP, OITGP, IR, IV, IITG, PRIZ , A_P, DT, Num_SC, plan };

		money_list Array_Buf;
		ifstream in(Dir);
		int n = 0;

		if (in.is_open()) {
			while (getline(in, line)) {
				int  j = 0;
				n++;

				Result = line;
				int size = Result.size();
				for (int i = 0; i < size; i++) {
					if (Result[i] == ';') {
						j++;
					}
					else {
						Buffer[j] += Result[i];
					}
				}
				
				Array_Buf.Regn = atof(Buffer[0].c_str());
				Array_Buf.plan = Buffer[1];
				Array_Buf.Num_SC = Buffer[2];
				Array_Buf.A_P = Buffer[3];
				Array_Buf.VR = atof(Buffer[4].c_str());
				Array_Buf.VV = atof(Buffer[5].c_str());
				Array_Buf.VITG = atof(Buffer[6].c_str());
				Array_Buf.ORA = atof(Buffer[7].c_str());
				Array_Buf.OVE = atof(Buffer[8].c_str());
				Array_Buf.OITGA = atof(Buffer[9].c_str());
				Array_Buf.ORP = atof(Buffer[10].c_str());
				Array_Buf.OVP = atof(Buffer[11].c_str());
				Array_Buf.OITGP = atof(Buffer[12].c_str());
				Array_Buf.IR = atof(Buffer[13].c_str());
				Array_Buf.IV = atof(Buffer[14].c_str());
				Array_Buf.IITG = atof(Buffer[15].c_str());

				string data = "";
				for (int y = 0; y < 11; y++) {
					data += Buffer[16][y];
				}

				Array_Buf.DT = data;

				Array_Buf.PRIZ = atof(Buffer[17].c_str());
				Money_V.push_back(Array_Buf);
				for (int j = 0; j < 18; j++) {
					Buffer[j] = "";
					
				}
				
			}
		}
		in.close();
		size_Arr = n;

		return n;
	}
	void Show() {
		for (int i = 0; i < size_Arr - 1; i++) {
			 cout << " Regn= " << Money_V[i].Regn << " NameSC= " << Money_V[i].Num_SC << " Plan= " << Money_V[i].plan << " Data= "<< Money_V[i].DT<< endl;
		}
	}
	vector<string> Get_by_Id(int ID) {
		string Id_new = to_string(ID);
		string Result = "";
		vector<string> Result_vector;

		for (int i = 0; i < size_Arr - 1; i++) {
			if (Money_V[i].Num_SC == Id_new) {
				Result = "";
				//cout << Money_V[i].IITG << " By data-> " << Money_V[i].DT << endl;
				Result += " By data-> " + Money_V[i].DT + "Money= "+ to_string(Money_V[i].IITG) ;
				Result_vector.push_back(Result);
			}

		}
		//cout << Result << endl;
		//Write_File("Res_Money.txt", Result);
		return Result_vector;
	}
	money_list_c() {}
};


int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	string Read_string, Write_string, Res, Dir;
	string DIR = "F:\\My Files\\Git Files\\for_university\\C++\\TXT";

	int key;
	int** Result;

	Names_c Names_class;
	plan_c Plan_class;
	money_list_c Money_class;
	vector<string> Result_Vec;

	COORD First_Values[4];
	stack <COORD> Point_stack;

	cout << "Choouse number of Programm" << endl;
	cin >> key;
	system("cls");

	switch (key) {
	case 1:
		Names_class.Get_All_Values(DIR + "\\NAMES.txt");
		//Names_class.Show();

		Plan_class.Get_Info(DIR + "\\PLAN.txt");
		//Plan_class.Show();

		Money_class.Get_Info(DIR + "\\101F.txt");
		//Money_class.Show();
		Result_Vec = Money_class.Get_by_Id(60322);

		for (int i = 0; i < Result_Vec.size(); i++) {
			cout << Result_Vec[i] << endl;
		}

		break;

	case 2:
		Sort_NamesTXT(DIR + "\\NAMES.txt");
		break;
	case 3:
		int point_f,point_s;
		COORD buf;

			for (int i = 0; i < 4; i++) {
				cout << " Enter " << i << " points =  ";
				cin >> point_f >> point_s;

				First_Values[i].X = point_f;
				First_Values[i].Y = point_s;
			}
		
			for (int i = 0; i < 4; i++) {
				Point_stack.push(First_Values[i]);
				cout << " Point= " << First_Values[i].X <<";"<< First_Values[i].Y<<" placed in stack!"<<endl;
			}
		cout << endl;
		cout << "Stack has " << Point_stack.size() << endl;

			buf = Point_stack.top();
			Point_stack.pop();
			cout << " Point= " << buf.X << ";" << buf.Y << " get from stack!" << endl;

			buf = Point_stack.top();
			Point_stack.pop();
			cout << " Point= " << buf.X << ";" << buf.Y << " get from stack!" << endl;
		cout << endl;
		cout << "Stack has " << Point_stack.size() << endl;

			for (int i = 0; i < 4; i++) {
				Point_stack.push(First_Values[i]);
				cout << " Point= " << First_Values[i].X << ";" << First_Values[i].Y << " placed in stack!" << endl;
			}
		cout << endl;
		cout << "Stack has " << Point_stack.size() << endl;

		int n = Point_stack.size();

		   for (int i = 0; i < n; i++) {
				buf = Point_stack.top();
				Point_stack.pop();
				cout << " Point= " << buf.X << ";" << buf.Y << " get from stack!" << endl;
		   }
	    cout << endl;
		cout << "Stack has " << Point_stack.size() << endl;

		break;
	}

	return 0;
}