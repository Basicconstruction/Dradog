//#include <iostream>
//using namespace std;
//class Cat{
//private:
//    int age;
//public:
//    explicit Cat(string name = "cat 001", int age = 19){
//        this->name = name;
//        this->age = age;
//    }
//    string name;
//    void setAge(int age){
//        this->age = age;
//    }
//    int getAge() const{
//        return this->age;
//    }
//    void printInfo(){
//        cout<<this->name <<" "<<this->age<<"\n";
//    }
//};
//class People{
//private:
//    int age;
//    Cat cat;
//    int length;
//public:
//    string name;
//    People(string name, int age):cat("gk", 18),length(9999){
//        this->name = name;
//        this->age = age;
//    }
//    Cat getCat(){
//        return this->cat;
//    }
//    void setCatAge(int age){
//        this->cat.setAge(age);
//    }
//    void setAge(int age){
//        this->age = age;
//    }
//    int getLength(){
//        return this->length;
//    }
//};
//int main() {
//    Cat c;
//    c.setAge(20);
//    cout<<c.name<<" "<<c.getAge()<<"\n";
//    Cat c2("cat 002", 20);
//    c2.printInfo();
//    People p("Tom",10);
//    //p.setCatAge(100);
//    cout<<p.name<<" pet's age: "<<p.getCat().getAge()<<" "<<p.getCat().name<<" "<<p.getLength();
//    return 0;
//}
#include <iostream>
using namespace std;
class LocalArr {
public:
    int length;
    int effectiveLength{};
    int* arr;
    int* arr2;
    bool* effectiveElements;
    bool* effectiveElements2;
    static int localMin(int a, int b) {
        if (a < b) {
            return a;
        }
        return b;
    }
    explicit LocalArr(int length) {
        this->length = length;
        this->effectiveLength = 0;
        arr = new int(this->length);
        effectiveElements = new bool(this->length);
        initEffectiveElements(false);
        effectiveLength = 0;
        /*初始化参数 length 为 对象数组长度
         * effectiveElements/2为 描述对象数组元素是否有效的数组
         * effectiveLength 是用来代表对象数组元素有效元素 的个数 的变量
         * 默认优先占用 arr和 initElements
         * */
    }
    LocalArr(int length, int initNumber) {
        this->length = length;
        arr = new int(this->length);
        arr2 = new int(2);
        delete []arr2;
        effectiveElements = new bool(this->length);
        effectiveElements2 = new bool(2);
        delete []effectiveElements2;
        initEffectiveElements(true);
        initLocalArr(initNumber);
    }
    void printArray() const {
        if (effectiveElements) {
            for (int u = 0; u < this->length; u++) {
                if (effectiveElements[u]) {
                    cout << arr[u] << "*";
                }
            }
        }
        else {
            for (int u = 0; u < this->length; u++) {
                if (effectiveElements2[u]) {
                    cout << arr2[u] << " ";
                }
            }
        }
    }
    int getCount() const {
        int count = 0;
        if (effectiveElements) {
            for (int y = 0; y < this->length; y++) {
                if (effectiveElements[y]) {
                    count = count + 1;
                }
            }
        }
        else {
            for (int y = 0; y < this->length; y++) {
                if (effectiveElements2[y]) {
                    count = count + 1;
                }
            }
        }
        return count;
    }
    void initLocalArr(int initValue) {
        if (arr) {
            for (int k = 0; k < this->length; k++) {
                arr[k] = initValue;
            }
        }
        else {
            for (int k = 0; k < this->length; k++) {
                arr2[k] = initValue;
            }
        }
        initEffectiveElements(true);
        this->effectiveLength = this->length;
        printArray();
    }
    void initEffectiveElements(bool initBool) const {
        if (effectiveElements) {
            for (int j = 0; j < this->length; j++) {
                effectiveElements[j] = initBool;
            }
        }
        else {
            for (int j = 0; j < this->length; j++) {
                effectiveElements2[j] = initBool;
            }
        }
    }
    void setSize(int size) {
        if (!arr) {
            arr = new int(size);
            effectiveElements = new bool(size);
            for (int i = 0; i < localMin(size, this->length); i++) {
                if (effectiveElements2[i]) {
                    arr[i] = arr2[i];
                    effectiveElements[i] = effectiveElements2[i];
                }
            }
            delete []arr2;
            delete []effectiveElements2;
            this->length = size;
            this->effectiveLength = this->getCount();
        }
        if (!arr2) {
            arr2 = new int(size);
            effectiveElements2 = new bool(size);
            for (int i = 0; i < localMin(size, this->length); i++) {
                if (effectiveElements[i]) {
                    arr2[i] = arr[i];
                    effectiveElements2[i] = effectiveElements[i];
                }
            }
            delete []arr;
            delete []effectiveElements;
            this->length = size;
            this->effectiveLength = this->getCount();
        }
    }
    int elementAt(int index) const {
        if (index > length - 1 && index < 0) {
            throw(exception());
        }
        if (arr) {
            return arr[index];
        }
        else {
            return arr2[index];
        }
    }
    int& operator[](int index) {
        if (index > length - 1 && index < 0) {
            throw(exception());
        }
        if (arr) {
            effectiveElements[index] = true;
            this->effectiveLength = this->getCount();
            return arr[index];
        }
        else {
            effectiveElements2[index] = true;
            this->effectiveLength = this->getCount();
            return arr2[index];
        }
    }
    int setValueByIndex(int index, int value) {
        if (arr) {
            arr[index] = value;
            effectiveElements[index] = true;
        }
        else {
            arr2[index] = value;
            effectiveElements2[index] = true;
        }
        this->effectiveLength = this->getCount();
    }
};
template<typename T>
void printBlankArray(T* arr, int length) {
    for (int h = 0; h < length; h++) {
        cout << arr[h] << " ";
    }
}
int main() {
    //    LocalArr a(4);
    //    cout<<a.effectiveLength<<" "<<a.length<<" ";
    LocalArr b(10);
//    b[4] = 12;
    b.setValueByIndex(4,12);
    b.printArray();
    cout<<"\n";
    printBlankArray(b.arr?b.arr:b.arr2, 10);
    cout<<"\n";
    printBlankArray(b.effectiveElements?b.effectiveElements:b.effectiveElements2,10);
    return 0;
}


























