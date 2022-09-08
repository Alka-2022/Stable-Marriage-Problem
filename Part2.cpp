#include <vector>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstdio>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <stack>
#include <sstream>
using namespace std;
struct diary
{
    string name;
    string gender;
    int age;
    int salary;
    string religion;
    int contact;
};
void clrscr()
{
    system("cls");
}
class file
{
private:
    diary d;

public:
    void getdata();
    void showdata();
    void setdata(string name, string gender, int age, int salary, string religion);
    void religions(string Religion);
    void preference_list();
    bool preference(int x, string gender, string religion, int age)
    {
        if (d.gender == gender && d.religion == religion)
        {
            if (d.age < age + x && d.age > age - x)
                return true;
        }
        return false;
    }
    void readFile();
    void writeFile(int);
    bool salary_access()
    {
        if (d.salary == 0)
            return true;
        return false;
    }
};
file obj[100];
int cnt = 0;
// This will take user input to shake of matching
void file::getdata()
{
    cout << "Enter your name: ";
    cin >> d.name;
    cout << "\n";
    cout << "Enter your gender(Male = M & Female = F): ";
    cin >> d.gender;
    cout << "\n";
    cout << "Enter your age: ";
    cin >> d.age;
    cout << "\n";
    cout << "Enter your salary: ";
    cin >> d.salary;
    cout << "\n";
    cout << "Enter your religion: ";
    cin >> d.religion;
    cout << "\n";
}
void file::writeFile(int apnd)
{
    int c = 1;
    ofstream fout;
    string name;
    string gender;
    int age;
    int salary;
    string religion;
    int temp = 0;
    if (apnd == 2)
    {
        fout.open("Myfile.dat");
    }
    else
        fout.open("Myfile.dat", ios::app);
    cout << "enter Name gender Age salary Religion";
    cin >> name;
    cin >> gender;
    // cout<<"Enter your age: ";
    cin >> age;
    // cout<<"Enter your salary: ";
    cin >> salary;
    // cout<<"Enter your religion: ";
    cin >> religion;
    fout << endl
         << name << " " << gender << " " << age << " " << salary << " " << religion;
    temp++;
    fout.close();
    cnt += temp;
}
// This function will read the data from the file
void file::readFile()
{
    std::ifstream infile("Myfile.dat");
    std::string line;
    int age, sal;
    string name, gen, rel;
    int i = 0;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        if (!(iss >> name >> gen >> age >> sal >> rel))
        {
            break;
        } // error
        obj[i].setdata(name, gen, age, sal, rel);
        i++;
    }
    cnt = i;
}
// this is a constructor that takes input from the user or file to set data in
sata structure.void file::setdata(string name, string gender, int age, int salary, string religion)
{
    d.name = name;
    d.gender = gender;
    d.age = age;
    d.salary = salary;
    d.religion = religion;
}
// This function is to show list as per
// the requirement of different function.
void file::showdata()
{
    cout << d.name;
    cout << "\t";
    cout << d.gender;
    cout << "\t";
    cout << d.age;
    cout << "\t";
    cout << d.salary;
    cout << "\t";
    cout << d.religion;
    // cout<<"\n";
}
// This list shows all the registered user according to religion
void file::religions(string Religion)
{
    for (int i = 0; i < cnt; i++)
    {
        if (obj[i].d.religion == Religion)
        {
            obj[i].showdata();
            cout << endl;
        }
    }
}
// Function to find the advanced searching
// This will search according to preferred
// Gender, age, Age_gap, religion
void file::preference_list()
{
    int a, x;
    string rel, gen;
    bool flag = true;
    cout << "Enter your preference. We will search the best for you" << endl;
    cout << "Gender(M/F): ";
    cin >> gen;
    cout << "Age: ";
    cin >> a;
    cout << "Age_gap between you and you partener: ";
    cin >> x;
    cout << "Religion(Hindu||Sikh||Muslim): ";
    cin >> rel;
    for (int i = 0; i < cnt; ++i)
    {
        if (obj[i].preference(x, gen, rel, a))
        {
            obj[i].showdata();
            cout << endl;
            flag = false;
        }
    }
    if (flag)
        cout << "!! Match not Found !!" << endl;
}
// Driver main function
int main()
{
    file fileop;
    int choice = 0;
    int first = 0;
    fileop.readFile();
    bool admin = false;
    string type;
    cout << "For Admin Login, Enter 'A' |" << endl
         << "For User Login, Entere 'L'
        | "<<endl;
              cout
              << "Enter A/L: ";
    cin >> type;
    if (type == "A")
    {
        cout << "Welcome Ma'am as an admin" << endl;
        int choice = 0;
        while (choice != 6)
        {
            cout << "Choose the key which you want from me" << endl
                 << endl;
            cout << " " << endl;
            cout << "1. Create a fresh register" << endl;
            cout << "2. Display datalist from file" << endl;
            cout << "3. Display persons list of prefered religion" << endl;
            cout << "4. Display list with advance sorting" << endl;
            cout << "5. Add new entry to the register" << endl;
            cout << "6. Quit" << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                fileop.writeFile(1);
                fileop.readFile();
            }
            break;
            case 2:
            {
                for (int i = 0; i < 19; i++)
                {
                    obj[i].showdata();
                    cout << endl;
                }
            }
            break;
}