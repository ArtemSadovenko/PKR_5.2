#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>


using namespace std;

enum Spec { CS, IT, ME, PhIT, TR };

string strSpec[] = { "Комп'ютернi науки", "Iнформатика", "Математика та економiка", "Фiзика та iнформатика", "Трудове навчання" };

void print(string name);
void create(string name);
void print_vidm(string name);
int percent(string name);
void ignore(ifstream& a);
void amount(string name, int*& q);
void ignore_one(ifstream& a);
bool ter(int a);

int main() {
    setlocale(LC_ALL, "Ukrainian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    bool e;
    
    cout << "Load(0)  Create(1)"; cin >> e;
    
    if (e) { 
        create("File.txt"); 
    }
    
    print("File.txt");
    print_vidm("File.txt");
    cout << "Percent: " << percent("File.txt");
}

bool ter(int a) {
    if (a == 3) {
        return true;
    }
    else {
        return false;
    }
}

void print(string name){
	ifstream f(name, ios::binary);
	int n;
    int Wn;
    char s[100];
    int spec_n;
	f.read((char*)&Wn, sizeof(Wn));
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| № |    Прiзвище   | Курс |      Спецiальнiсть     | Фiзика | Математика | Програмування | Чисельнi методи | Педагогiка |" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;


    for (int i = 0; i < Wn; i++) {

        cout << "| " << setw(2) << right << i + 1 << "";

        f.read((char*)&s, sizeof(s));
        cout << "| " << setw(14) << left << s;

        f.read((char*)&n, sizeof(n));
        cout << "| " << setw(5) << right << n;

        f.read((char*)&spec_n, sizeof(spec_n));
        cout << "| " << setw(23) << left << strSpec[spec_n]; ;//strSpec[s[i].spec]

        f.read((char*)&n, sizeof(n));
        cout << "| " << setw(7) << n;

        f.read((char*)&n, sizeof(n));
        cout << "| " << setw(11) << right << n;

        if (spec_n == 0) {
            f.read((char*)&n, sizeof(n));
            cout << "| " << setw(14) << right << n
                << "| " << setw(16) << right << " "
                << "| " << setw(11) << right << " " << "| ";
        }
        else if (spec_n == 1) {
            f.read((char*)&n, sizeof(n));
            cout << "| " << setw(14) << right << " "
                << "| " << setw(16) << right << n
                << "| " << setw(11) << right << " " << "| ";
        }
        else {
            f.read((char*)&n, sizeof(n));
            cout << "| " << setw(14) << right << " "
                << "| " << setw(16) << right << " "
                << "| " << setw(11) << right << n << "| ";
        }
        cout << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    
    
}

void create(string name){
    ofstream f(name, ios::binary | ios::trunc | ios::out);
    int Wn;
    int n;
    char s[100];
    int spec_n;


    cout << "n: "; cin >> Wn;
    f.write((char*)&Wn, sizeof(Wn));

    for (int i = 0; i < Wn; i++) {
        cout << "Student " << i + 1 << endl;

        cout << "Name: "; cin>> s;
        f.write((char*)&s, sizeof(s));

        cout << "Curs: "; cin >> n;
        f.write((char*)&n, sizeof(n));
        
        cout << "Spec: "; cin >> spec_n;
        f.write((char*)&spec_n, sizeof(spec_n));

        cout << "Fis: "; cin >> n;
        f.write((char*)&n, sizeof(n));

        cout << "Math: "; cin >> n;
        f.write((char*)&n, sizeof(n));

        if (spec_n == 0) {
            cout << "Prog: "; cin >> n;
            f.write((char*)&n, sizeof(n));
        }
        else if (spec_n == 1) {
            cout << "Numer: "; cin >> n;
            f.write((char*)&n, sizeof(n));
        }
        else {
            cout << "Pedag: "; cin >> n;
            f.write((char*)&n, sizeof(n));
        }
    }
}

void print_vidm(string name){
    
    ifstream f(name, ios::binary);
    int n;
    int Wn;
    int qn = 0;
    int* q = new int[100];
    amount(name, q);
    char s[100];
    int spec_n;
    f.read((char*)&Wn, sizeof(Wn));
    cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| № |    Прiзвище   | Курс |      Спецiальнiсть     | Фiзика | Математика | Програмування | Чисельнi методи | Педагогiка |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;


    for (int i = 0; i < Wn; i++) {
        if (i == q[qn]) {
            cout << "| " << setw(2) << right << i + 1 << "";

            f.read((char*)&s, sizeof(s));
            cout << "| " << setw(14) << left << s;

            f.read((char*)&n, sizeof(n));
            cout << "| " << setw(5) << right << n;

            f.read((char*)&spec_n, sizeof(spec_n));
            cout << "| " << setw(23) << left << strSpec[spec_n]; ;//strSpec[s[i].spec]

            f.read((char*)&n, sizeof(n));
            cout << "| " << setw(7) << n;

            f.read((char*)&n, sizeof(n));
            cout << "| " << setw(11) << right << n;

            if (spec_n == 0) {
                f.read((char*)&n, sizeof(n));
                cout << "| " << setw(14) << right << n
                    << "| " << setw(16) << right << " "
                    << "| " << setw(11) << right << " " << "| ";
            }
            else if (spec_n == 1) {
                f.read((char*)&n, sizeof(n));
                cout << "| " << setw(14) << right << " "
                    << "| " << setw(16) << right << n
                    << "| " << setw(11) << right << " " << "| ";
            }
            else {
                f.read((char*)&n, sizeof(n));
                cout << "| " << setw(14) << right << " "
                    << "| " << setw(16) << right << " "
                    << "| " << setw(11) << right << n << "| ";
            }
            cout << endl;
            qn++;
        }
        else {
            ignore_one(f);
        }

    }
    cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;


}

int percent(string name){
    ifstream f(name, ios::binary);
    int Wn;
    int tmp;
    double aver = 0;
    int k = 0;
    f.read((char*)&Wn, sizeof(Wn));
    for (int i = 0; i < Wn; i++) {
        ignore(f);
        for (int j = 0; j < 3; j++) {
            f.read((char*)&tmp, sizeof(tmp));
            aver += tmp;
        }
        if (aver/3 > 4.5) {
            k++;
        }
        aver = 0;
    }
    return ((double)k / (double)Wn)*100;
}

void ignore(ifstream& a){
    char s[100];
    int k;
    a.read((char*)&s, sizeof(s));
    a.read((char*)&k, sizeof(k));
    a.read((char*)&k, sizeof(k));
}

void ignore_one(ifstream& a) {
    char s[100];
    int k;
    a.read((char*)&s, sizeof(s));
    for (int j = 0; j < 5; j++) {
        a.read((char*)&k, sizeof(k));
    }
}

void amount(string name, int*&q) {
    ifstream f(name, ios::binary);
    int n = 0;
    int Wn;
    int qn = 0;
    int k = 0; 
    int tmp;
    f.read((char*)&Wn, sizeof(Wn));
    for (int i = 0; i < Wn; i++) {
        ignore(f);
        for (int j = 0; j < 3; j++) {
            f.read((char*)&tmp, sizeof(tmp));
            if (tmp == 5) {
                n++;
            }
        }
        if (n == 3) {
            q[qn] = i;
            qn++;
        }
        n = 0;
    }
}

