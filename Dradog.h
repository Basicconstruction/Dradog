#ifndef DRADOG_H
#define DRADOG_H
#include <string>
#include <fstream>
using namespace std;
class Dradog
{
public:
    int age;
    Dradog();
    Dradog(int);
    ~Dradog();
    static void getRidOfStrLine(string);
    static void replaceStr(string,string);
    int pow(int,int);//function overloading, 
    long int pow(long int,int);//function overloading, 
    float pow(float,int);//function overloading, 
    double pow(double,int);//function overloading, 
private:
    
};
#endif
    
    