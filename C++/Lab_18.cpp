#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;




string Read_File(string Direct) {
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
    cout << "Clean:" << Direct << endl;
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

struct names {
    std::string Name_B;
    double Regn;
    names* names_ptr;
};
struct plan {
    std::string plan_n;
    std::string Num_SC;
    std::string Name;
    plan* plan_ptr;
};
struct money_list {
    int Regn, VR, VV, VITG, ORA, OVE, OITGA, ORP, OVP, OITGP, IR, IV, IITG, PRIZ;
    std::string plan;
    std::string Num_SC;
    std::string DT;
    std::string A_P;
    money_list* money_list_ptr;
};

class Names_c {
private:
    names* ptr_First;
    int size_Arr;
public:
    int Get_Info(string Dir) {
        string line, Result,Name="", Regn="";
        string Arr_Val[] = { Name, Regn};
        ifstream in(Dir);
        int n=0;

        if (in.is_open()) {
            while (getline(in, line)) {
                int  j = 0;
                n++;
                Result = line;
                int size = Result.size();
                for (int i = 0; i < size;i++) {
                    if (Result[i] == ';') { 
                        j++; 
                    }
                    else {
                        Arr_Val[j] += Result[i];
                    }
                }
                names* Buffer= new names;
                (* ptr_First).Name_B = Arr_Val[1];
                (*ptr_First).Regn = atof(Arr_Val[0].c_str());
                (*Buffer).names_ptr = ptr_First;
                ptr_First = Buffer;
                Arr_Val[0] = "";
                Arr_Val[1] = "";
            }
        }
        in.close();
        size_Arr = n;
        return n;
    }
    void Show() {
        names* Buffer;
        int size = 0;
        Buffer = ptr_First;
        do {
            cout << Buffer->Name_B << "  " << Buffer->Regn << endl;
            Buffer = Buffer->names_ptr;
            size++;
        } while (size != size_Arr);
        return;
    }
    void Get() {
        cout<<ptr_First->names_ptr->Name_B << endl;
    }
    string Get_by_Id(double ID) {
        names Buff=*ptr_First;
        for (int i = 0; i < size_Arr; i++) {
            if (Buff.Regn == ID) {
                cout << Buff.Name_B << endl;
                return  Buff.Name_B;
            }
            Buff = *(Buff.names_ptr);
        }
        return "";
    }
    Names_c() {
        ptr_First = new names;
    }
};
class plan_c {
private:
    plan* ptr_First;
    int size_Arr;
public:
    int Get_Info(string Dir) {
        string line, Result, Plan = "", Num_SC = "", Name = "";
        string Arr_Val[] = { Plan, Num_SC , Name };
        ifstream in(Dir);
        int n = 0;

        if (in.is_open()) {
            while (getline(in, line)) {
                int  j = 0;
                n++;
                Result = line;
               // cout << line << endl;
                int size = Result.size();
                for (int i = 0; i < size; i++) {
                    if (Result[i] == ';') {
                        j++;
                    }
                    else {
                        Arr_Val[j] += Result[i];
                    }
                }
                plan* Buffer = new plan;
                (*ptr_First).Name = Arr_Val[0];
                (*ptr_First).Num_SC = Arr_Val[1];
                (*ptr_First).plan_n = Arr_Val[2];
                (*Buffer).plan_ptr = ptr_First;
                ptr_First = Buffer;
                Arr_Val[0] = "";
                Arr_Val[1] = "";
                Arr_Val[2] = "";
            }
        }
        in.close();
        size_Arr = n;
        return n;
    }
    void Show() {
        plan* Buffer;
        int size = 0;
        Buffer = ptr_First;
        do {
            cout << Buffer->Name << "  " << Buffer->Num_SC<<"  "<< Buffer->plan_n << endl;
            Buffer = Buffer->plan_ptr;
            size++;
        } while (size != size_Arr);
        return;
    }
    void Get() {
        cout << ptr_First->plan_ptr->plan_n << endl;
    }
    string Get_by_Id(int ID) {
        plan Buff = *ptr_First;
        string Id_new = to_string(ID);
        for (int i = 0; i < size_Arr; i++) {
            if (Buff.Num_SC == Id_new) {
                cout << Buff.plan_n << endl;
                return  Buff.plan_n;
            }
            Buff = *(Buff.plan_ptr);
        }
        return "";
    }
    plan_c() { 
        ptr_First = new plan;
    }
};
class money_list_c {
private:
    money_list* ptr_First;
    int size_Arr;
public:
    int Get_Info(string Dir) {
        string line, Result, Regn="", VR = "", VV = "", VITG = "", ORA = "", OVE = "", OITGA = "", ORP = "", OVP = "", OITGP = "", IR = "", IV = "", IITG = "", PRIZ = "", A_P = "", DT = "", Num_SC = "", plan = "";
        string Arr_Val[] = { Regn, VR, VV, VITG, ORA, OVE, OITGA, ORP, OVP, OITGP, IR, IV, IITG, PRIZ , A_P, DT, Num_SC, plan };
        ifstream in(Dir);
        int n = 0;
        money_list* Buf = ptr_First;

        if (in.is_open()) {
            while (getline(in, line)) {
                int  j = 0;
                
                Result = line;
                // cout << line << endl;
                int size = Result.size();
                for (int i = 0; i < size; i++) {
                    if (Result[i] == ';') {
                        j++;
                    }
                    else {
                        Arr_Val[j] += Result[i];
                    }
                }
                //money_list* Buffer = new money_list;
                (*Buf).Regn = atof(Arr_Val[0].c_str());
                (*Buf).plan = Arr_Val[1];
                (*Buf).Num_SC = Arr_Val[2];
                (*Buf).A_P = Arr_Val[3];
                (*Buf).VR = atof(Arr_Val[4].c_str());
                (*Buf).VV = atof(Arr_Val[5].c_str());
                (*Buf).VITG = atof(Arr_Val[6].c_str());
                (*Buf).ORA = atof(Arr_Val[7].c_str());
                (*Buf).OVE = atof(Arr_Val[8].c_str());
                (*Buf).OITGA = atof(Arr_Val[9].c_str());
                (*Buf).ORP = atof(Arr_Val[10].c_str());
                (*Buf).OVP = atof(Arr_Val[11].c_str());
                (*Buf).OITGP = atof(Arr_Val[12].c_str());
                (*Buf).IR = atof(Arr_Val[13].c_str());
                (*Buf).IV = atof(Arr_Val[14].c_str());
                (*Buf).IITG = atof(Arr_Val[15].c_str());
                string data = "";
                for (int y = 0; y < 11; y++) {
                    data += Arr_Val[16][y];
                }
                (*Buf).DT = data;
               // (*Buf).DT = Arr_Val[16];
                (*Buf).PRIZ = atof(Arr_Val[17].c_str());

                //Buf = Buffer;
                Buf->money_list_ptr = new money_list;
                Buf = Buf->money_list_ptr;

                //ptr_First = Buffer;
                Arr_Val[0] = "";
                Arr_Val[1] = "";
                Arr_Val[2] = "";
                Arr_Val[3] = "";
                Arr_Val[4] = "";
                Arr_Val[5] = "";
                Arr_Val[6] = "";
                Arr_Val[7] = "";
                Arr_Val[8] = "";
                Arr_Val[9] = "";
                Arr_Val[10] = "";
                Arr_Val[11] = "";
                Arr_Val[12] = "";
                Arr_Val[13] = "";
                Arr_Val[14] = "";
                Arr_Val[15] = "";
                Arr_Val[16] = "";
                Arr_Val[17] = "";
                n++;
            }
        }
        in.close();
        size_Arr = n;
        return n;
    }
   /* void Show() {
        plan* Buffer;
        int size = 0;
        Buffer = ptr_First;
        do {
            cout << Buffer->Name << "  " << Buffer->Num_SC << "  " << Buffer->plan_n << endl;
            Buffer = Buffer->plan_ptr;
            size++;
        } while (size != size_Arr);
        return;
    }*/
    void Get() {
        cout << ptr_First->money_list_ptr->DT << endl;
    }
    void Get_by_Id(int ID) {
        money_list Buff = *ptr_First;
        string Id_new = to_string(ID);
        string Result = "";
        for (int i = 0; i < size_Arr-1; i++) {
            if (Buff.Num_SC == Id_new) {
                cout << Buff.IITG <<" By data-> "<< Buff.DT<< endl;
                Result += to_string(Buff.IITG) + " By data-> " + Buff.DT + '\n';
            }
            //cout << i << endl;
            Buff = *Buff.money_list_ptr;
        }
        cout << Result << endl;
        Write_File("F:\\My Files\\Git Files\\for_university\\C++\\TXT\\Res_Money.txt", Result);
    }
    money_list_c() {
        ptr_First = new money_list;
    }
};


int main(){
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string Read_string, Write_string,Res,Dir;
    Dir = "F:\\My Files\\Git Files\\for_university\\C++\\TXT";
    int key;
    int** Result;

    cout << "Switch number of Prog" << endl;
    cin >> key;
    system("cls");

    switch (key) {
    case 1:
        Clean_File(Dir + "\\Res.txt");
        Write_string = Read_string = Read_File(Dir + "\\F.txt");
        Write_File(Dir + "\\Res.txt", Write_string);

        Write_string = Read_string = Read_File(Dir + "\\S.txt");
        Write_File(Dir + "\\Res.txt", Write_string);

        Read_string = Read_File(Dir + "\\Res.txt");

        break;
    case 2:
        int F_size, S_size;
        int* F_Massiv;
        int* S_Massiv;

        F_Massiv=Get_Array(Read_File(Dir + "\\F_Arr.txt"), F_size);
        S_Massiv=Get_Array(Read_File(Dir + "\\S_Arr.txt"), S_size);

        if (F_size != S_size) { cout << "Frong Size!" << endl; return 0; }

         Result = new int* [3];
        for (int i = 0; i < 3; i++) {
            Result[i] = new int[F_size];
        }

        New_Massiv_For_Quest2(F_size, F_Massiv, S_Massiv,Result);
        GetStr_FromMass(F_size, Res, Result);

        Clean_File(Dir + "\\Res_Arr.txt");
        Write_File(Dir + "\\Res_Arr.txt", Res);
        Read_File(Dir + "\\Res_Arr.txt");

        break;
    case 3:
        //???
        break;
    case 4:
        Clean_File(Dir + "\\Res.txt");
        Write_string = Read_string = Read_File(Dir + "\\F.txt");
        Write_File(Dir + "\\Res.txt", Write_string);

        Write_string = Read_string = Read_File(Dir + "\\S.txt");
        Write_File(Dir + "\\Res.txt", Write_string);
        for (;;) {
            cout << "Enter 5 to EXIT!, 0 to Read res.File!, 1 to write New info and 2 to write file with new info!  =  ";
            cin >> key;

            switch (key) {
            case 0:
                Read_File(Dir + "\\Res.txt");
                break;
            case 1:
                cout << "Write new info!" << endl;
                cin.ignore(7777, '\n');
                getline(cin, Read_string);

                //cin.ignore(7777, '\n');
                Write_File(Dir + "\\Res.txt", Read_string);
                break;
            case 2:
                cout << "Write Name of new file!" << endl;
                cin >> Write_string;

                Res = Read_File(Dir + Write_string + ".txt");
                Write_File(Dir + "\\Res.txt", Res);
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
            Read_Line(Dir + "\\Res.txt", key);
        }
        break;
    case 6:
        Names_c Names_class;
        cout<< Names_class.Get_Info(Dir + "\\NAMES.txt") << endl;
        Names_class.Get_by_Id(1139.00);

        plan_c Plan_class;
        cout << Plan_class.Get_Info(Dir + "\\PLAN.txt") << endl;
        Plan_class.Get_by_Id(103);

        money_list_c Money_class;
        cout << Money_class.Get_Info(Dir + "\\101F.txt") << endl;
        Money_class.Get_by_Id(47901);
        //Money_class.Get();

        break;
    }
    return 0;
}