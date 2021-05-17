#include <iostream>
#include <string>
#include <cstddef>
#include <cassert>
using namespace std;
class MyString{
public:
    string str;
    size_t length{};
    size_t size{};
    bool wave{};
    bool changed = false;
    class MyCharList{
    public:
        char* char_list;
        size_t v_l;
        explicit MyCharList(const string& s){
            this->char_list = new char[s.length()];
            generate(s);
            this->v_l = s.length();
        }
        explicit MyCharList(const MyString& myString){
            this->char_list = new char[myString.length];
            this->v_l = myString.length;
        }
        MyCharList(){
            v_l = 0;
            this->char_list = new char[1];
            char_list[0] = char('0');//aim at finished a initialization! with emphasize!
        };
        void generate(const MyString& myString) const{
            generate(myString.str);
        }
        void generate(const string _str) const{
            for(int i = 0; i < _str.length();i++){
                this->char_list[i] = _str[i];
            }
        }
    };
    MyCharList* x;
    MyString(){
        this->str = "";
        this->length = 0;
        this->size = this->length;
        this->wave = true;
    }
    explicit MyString(const string _s){
        this->str = _s;
        this->length = _s.length();
        this->size = this->length;
        this->wave = true;
    }
    MyString(const MyString &_mystr){
        this->str = _mystr.str;
        this->length = _mystr.length;
        this->size = this->length;
        this->wave = true;
    }
    MyString(const MyString& _mystr, int pre, int end){
        this->str = string(_mystr.str, pre, end-pre);
        this->length = end - pre;
        this->size = this->length;
        this->wave = true;
    }
    MyString(const char c, int len){
        this->str = string(len, c);
        this->length = len;
        this->size = this->length;
        this->wave = true;
    }
    MyString(const string s, int pre, int end){
        this->str = string(s, pre, end-pre);
        this->length = end - pre;
        this->size = this->length;
        this->wave = true;
    }
    void change_l_s(){
        this->length = this->str.length();
        this->size = this->length;
    }
    void tackleWaveString(){
        if(this->wave){
            this->x = new MyCharList(this->str);
        }
    }
    static string getString(const string s, int pre, int length){
        return string(s,pre,length);
    }
    static string getStringWithIndex(const string s, int pre, int end){
        //contains string[end]
        return string(s,pre,end-pre+1);
    }
    static string getString(const char c, int len){
        return string(len, c);
    }
    string reNewStr(){
        if(changed){
            this->str = "";
            for(int k = 0; k< x->v_l;k++){
                this->str += this->x->char_list[k];
            }
            this->length = this->x->v_l;
            this->size = this->length;
            changed = false;
        }
        return this->str;
    }
    string substr(int index=0, int _str_l=0) const{
        if(_str_l==0){
            _str_l = int(this->length);
        }
        assert(_str_l <= this->length - index);
        return string(this->str, index, _str_l);
    }
    string substrWithIndex(int pre=0, int end=0) const{
        if(end==0){
            end = int(this->length - 1);
        }
        assert(end <= this->length-1);
        return string(this->str, 0, end - pre + 1);
    }
    string append(char c){
        this->str += 'c';
//        changed = true;  no need, cause this->str will change with along with the chars!
        change_l_s();
        return this->str;
    }
    string append(string _s){
        this->str += _s;
//        changed = true;  no need, cause this->str will change with along with the chars!
        change_l_s();
        return this->str;
    }
    char& operator[](int index){
        this->x = new MyCharList(this->str);
        if(index<0||index>=this->x->v_l){
            throw runtime_error("error, index out of range");// casually choose a Exception()
        }
        changed = true;
        return this->x->char_list[index];
        //attention here! if use this function for change the string, 
        // you need to use reNewStr() before use this->str(also use the reNewStr for this->str is Ok!)
    }
    MyString& operator=(const string _str){
        this->str = _str;
        this->length = _str.length();
        this->size = this->length;
        changed = false;
        return *this;
    }
};

int main() {
    MyString s(MyString("hello world"));
    s[0] = 'p';
    cout<<s.reNewStr()<<endl;
    s[5] = 'u';
    cout<<s.reNewStr()<<endl;
    s = "jkl";
    s[0] = 'p';
    s.wave = true;
    cout<<s.reNewStr()<<endl;
    s = "ooops";
    s[4] = 'i';
    cout<<s.reNewStr()<<endl;
    s = "what";
    cout<<s.str<<endl;
    MyString k;
    k = "jslkd";
    cout<<k.str<<endl;
    cout<<k.substr(1,10);
}
/*
 * int* getArray(int l){
    int* arr = new int[l+1];
    arr[0] = l;
    for(int i = 1; i < l+1;i++){
        arr[i] = i;
    }
    return arr;
}*/
//    cout<<MyString::getString("hello world", 2,4);
//    int* s = getArray(10);
//    for(int j = 0; j < *(s);j++){
//        cout<<*(s+j+1)<<" ";
//    }
//    return 0;
//    MyString c("hello");
//    c.wave = true;
//    c.tackleWaveString();
//    for(int i = 0; i < c.x->v_l;i++){
//        cout<<c.x->char_list[i]<<" ";
//    }
//    cout<<c.length<<endl;
//    c[0] = 'k';
//    c.reNewStr();
//    cout<<c.str<<endl;
//    c[2] = 'p';
//    cout<<c.reNewStr();