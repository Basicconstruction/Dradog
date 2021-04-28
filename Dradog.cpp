#include <string>
#include <stdio.h>
#include "Dradog.h"
#include <fstream>
#include <iostream>
using namespace std;
Dradog::Dradog(){
    age = 1;
}
Dradog::Dradog(int age){
    this->age = age;
}
Dradog::~Dradog(){

}
void Dradog::replaceStr(string oldStr, string newStr){
    //function replaceStr
    //Parameters string string 
    //no return value
    //work: Replace the specific string in the file and output it to another file
    std::cout << "please input the Absolut filename(include path)" << '\n';
    string name;
    string newpath;
    std::cin >> name;
    ifstream in(name);
    while (in.fail()) {
        std::cout << "Error reading" << "\n";
        std::cout << "try again" << '\n';
        std::cin >> name;
        ifstream in(name);
    }
    unsigned int i = 0;
    while (i < name.length()) {
        //将路径改为双右滑线
        i = name.find('\\', i);
        name.insert(i+1,"\\");
        i = i + 2;
        if (name.find('\\', i) >= name.length()) {
            break;
        }
    }
    for (int j = name.length() - 1; j >= 0; j--) {
        if (name[j] == '\\') {
            for (int p = 0; p <= j; p++) {
                newpath = newpath + name[p];
            }
            j = -1;
        }
    }
    ofstream out(newpath+"transferred.txt");
    string estr;
    while (getline(in, estr, '\n'))
    {
        if (estr.find(oldStr) < 1000) {
            unsigned int j = 0;
            while(j<=oldStr.length()-1&&estr.find(oldStr,j)<10000){
                j = estr.find(oldStr,j);
                estr.replace(j,oldStr.length(),newStr);
                j = j + newStr.length();
            }
        }
        out << estr << "\n";
    }
    in.close();
    out.close();
    cout<<"Done"<<"\n";
}
void Dradog::getRidOfStrLine(string getstr) {
    //function replaceStr
    //Parameters string string 
    //no return value
    //work: delete the lines with the specific string and output it to another file
    std::cout << "please input the Absolut filename(include path)" << '\n';
    string name;
    string newpath;
    std::cin >> name;
    ifstream in(name);
    while (in.fail()) {
        std::cout << "Error reading" << "\n";
        std::cout << "try again" << '\n';
        std::cin >> name;
        ifstream in(name);
    }
    unsigned int i = 0;
    while (i < name.length()) {
        //将路径改为双右滑线
        i = name.find('\\', i);
        name.insert(i+1,"\\");
        i = i + 2;
        if (name.find('\\', i) >= name.length()) {
            break;
        }
    }
    for (int j = name.length() - 1; j >= 0; j--) {
        if (name[j] == '\\') {
            for (int p = 0; p <= j; p++) {
                newpath = newpath + name[p];
            }
            j = -1;
        }
    }
    ofstream out(newpath+"transferred.txt");
    string estr;
    while (getline(in, estr, '\n'))
    {
        if (estr.find(getstr) < 1000) {
            continue;
        }
        else {
            out << estr << "\n";
        }
    }
    in.close();
    out.close();
    cout<<"Done"<<"\n";
}
int Dradog::pow(int x,int y){
    //function overloading -- pow
    //work: pow
    int res = 1;
    for(int f = 0;f < y; f++){
        res = res * x;
    }
    return res;
}
long int Dradog::pow(long int x,int y){
    //function overloading -- pow
    //parameter long int ,int
    //return long int
    //work: pow
    long int res = 1;
    for(int f = 0;f < y; f++){
        res = res * x;
    }
    return res;
}
float Dradog::pow(float x,int y){
    //function overloading -- pow
    //parameter float ,int
    //return float
    //work: pow
    float res = 1.0f;
    for(int f = 0;f < y; f++){
        res = res * x;
    }
    return res;
}
double Dradog::pow(double x,int y){
    //function overloading -- pow
    //parameter double ,int
    //return double
    //work: pow
    double res = 1.0;
    for(int f = 0;f < y; f++){
        res = res * x;
    }
    return res;
}
