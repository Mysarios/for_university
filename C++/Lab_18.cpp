#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Source.h"

using namespace std;
string Read_File(  string Direct) {
    string line,Result;
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
    ofstream out(Direct);

    if (out.is_open()) {
        out << " " << std::endl;
    }
    out.close();

    cout << "Was Clean:" << Direct << endl;
}
void   Write_File( string Direct, string Text_To_Write) {
    ofstream out(Direct, std::ios::app);
    
    if (out.is_open()){
        out << Text_To_Write << std::endl;
    }
    out.close();

    cout<<"Was Written:"<< Direct <<endl;
}
string Read_Line(string Direct,int num) {
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

    for (auto ch:Massiv_In_String) {
        if (ch >= '0' && ch <= '9') {
            cout << ch <<"  -Write-  "<<i<< endl;
            Array_Of_Nums[i] *= pow(10, check++);
            Array_Of_Nums[i] += (int)ch - 48;
        }
        else {
            check = 0;
            i++;
            for (int j = 0; j < i; j++) {
                Buffer[j] = *(Array_Of_Nums+j);
            }
            Array_Of_Nums = new int[i+1];
            
            for (int j = 0; j < i; j++) {
                Array_Of_Nums[j] = *(Buffer+j);               
            }

            Array_Of_Nums[i] = 0;
            Buffer = new int[i+1];

        }
    }
    size = i;

    return Array_Of_Nums;
}
void New_Massiv_For_Quest2(int F_size, int* F_Massiv, int* S_Massiv,int** Result)
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

int main(){
    string Read_string, Write_string,Res;
    int key;
    int** Result;

    cout << "Switch number of Prog" << endl;
    cin >> key;
    system("cls");

    switch (key) {
    case 1:
        Clean_File("F:\\My Files\\Programming\\C++\\Trash\\Res.txt");
        Write_string = Read_string = Read_File("F:\\My Files\\Programming\\C++\\Trash\\F.txt");
        Write_File("F:\\My Files\\Programming\\C++\\Trash\\Res.txt", Write_string);

        Write_string = Read_string = Read_File("F:\\My Files\\Programming\\C++\\Trash\\S.txt");
        Write_File("F:\\My Files\\Programming\\C++\\Trash\\Res.txt", Write_string);

        Read_string = Read_File("F:\\My Files\\Programming\\C++\\Trash\\Res.txt");

        break;
    case 2:
        int F_size, S_size;
        int* F_Massiv;
        int* S_Massiv;

        F_Massiv=Get_Array(Read_File("F:\\My Files\\Programming\\C++\\Trash\\F_Arr.txt"), F_size);
        S_Massiv=Get_Array(Read_File("F:\\My Files\\Programming\\C++\\Trash\\S_Arr.txt"), S_size);

        if (F_size != S_size) { cout << "Frong Size!" << endl; return 0; }

         Result = new int* [3];
        for (int i = 0; i < 3; i++) {
            Result[i] = new int[F_size];
        }

        New_Massiv_For_Quest2(F_size, F_Massiv, S_Massiv,Result);
        GetStr_FromMass(F_size, Res, Result);

        Clean_File("F:\\My Files\\Programming\\C++\\Trash\\Res_Arr.txt");
        Write_File("F:\\My Files\\Programming\\C++\\Trash\\Res_Arr.txt", Res);
        Read_File("F:\\My Files\\Programming\\C++\\Trash\\Res_Arr.txt");

        break;
    case 3:
        //???
        break;
    case 4:
        Clean_File("F:\\My Files\\Programming\\C++\\Trash\\Res.txt");
        Write_string = Read_string = Read_File("F:\\My Files\\Programming\\C++\\Trash\\F.txt");
        Write_File("F:\\My Files\\Programming\\C++\\Trash\\Res.txt", Write_string);

        Write_string = Read_string = Read_File("F:\\My Files\\Programming\\C++\\Trash\\S.txt");
        Write_File("F:\\My Files\\Programming\\C++\\Trash\\Res.txt", Write_string);
        for (;;) {
            cout << "Enter 5 to EXIT!, 0 to Read res.File!, 1 to write New info and 2 to write file with new info!  =  ";
            cin >> key;

            switch (key) {
            case 0:
                Read_File("F:\\My Files\\Programming\\C++\\Trash\\Res.txt");
                break;
            case 1:
                cout << "Write new info!" << endl;
                cin.ignore(7777, '\n');
                getline(cin, Read_string);

                //cin.ignore(7777, '\n');
                Write_File("F:\\My Files\\Programming\\C++\\Trash\\Res.txt", Read_string);
                break;
            case 2:
                cout << "Write Name of new file!" << endl;
                cin >> Write_string;

                Res = Read_File("F:\\My Files\\Programming\\C++\\Trash\\" + Write_string + ".txt");
                Write_File("F:\\My Files\\Programming\\C++\\Trash\\Res.txt", Res);
                break;
            case 5:
                return 0;
                break;
            }
        }
        break;

    case 5:
        for (;;) {
            cout << "Enter num of line! = ";
            cin >> key;
            Read_Line("F:\\My Files\\Programming\\C++\\Trash\\Res.txt", key);
        }
        break;
    }
    return 0;
}