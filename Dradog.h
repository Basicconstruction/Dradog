#ifndef DRADOG_H
#define DRADOG_H
#include <string>
#include <fstream>
using namespace std;
template <typename T>
class Dradog
{
public:
    int age;
    Dradog();
    Dradog(int);
    ~Dradog();
    static void getRidOfStrLine(string);
    static void replaceStr(string,string);
    T pow(T,int);
    //如何声明模板函数？
private:
    
};
#endif
    
    