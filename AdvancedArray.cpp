#include <iostream>

using namespace std;

class LocalArr {
public:
    int length;
    int totalStorageLength;
    int effectiveLength{};
    int *arr;
    int *arr2;
    bool *effectiveElements;
    bool *effectiveElements2;

    static int localMin(int a, int b) {
        if (a < b) {
            return a;
        }
        return b;
    }

    explicit LocalArr(int length) {
        this->totalStorageLength = length + 1;
        this->length = length;
        this->effectiveLength = 0;
        arr = new int[this->totalStorageLength];
        arr2 = new int[this->totalStorageLength];
        arr[0] = 1;
        arr2[0] = 0;
        effectiveElements = new bool[this->totalStorageLength];
        effectiveElements2 = new bool[this->totalStorageLength];
        effectiveElements[0] = true;
        effectiveElements2[0] = false;
        initEffectiveElements(false);
        effectiveLength = 0;
        /*初始化参数 length 为 对象数组长度
         * effectiveElements/2为 描述对象数组元素是否有效的数组
         * effectiveLength 是用来代表对象数组元素有效元素 的个数 的变量
         * 默认优先占用 arr和 initElements
         * */
    }

    LocalArr(int length, int initNumber) {
        this->totalStorageLength = length + 1;
        this->length = length;
        arr = new int[this->totalStorageLength];
        arr2 = new int[this->totalStorageLength];
        arr[0] = 1;
        arr2[0] = 0;
        effectiveElements = new bool(this->totalStorageLength);
        effectiveElements2 = new bool[this->totalStorageLength];
        effectiveElements[0] = true;
        effectiveElements2[0] = false;
        initEffectiveElements(true);
        initLocalArr(initNumber);
    }

    void printArray() const {
        if (effectiveElements[0]) {
            for (int u = 0; u < this->length; u++) {
                if (effectiveElements[u+1]) {
                    cout << arr[u+1] << " ";
                }
            }
        } else {
            for (int u = 0; u < this->length; u++) {
                if (effectiveElements2[u+1]) {
                    cout << arr2[u+1] << " ";
                }
            }
        }
    }

    int getCount() const {
        int count = 0;
        if (effectiveElements[0]) {
            for (int y = 0; y < this->length; y++) {
                if (effectiveElements[y+1]) {
                    count = count + 1;
                }
            }
        } else {
            for (int y = 0; y < this->length; y++) {
                if (effectiveElements2[y+1]) {
                    count = count + 1;
                }
            }
        }
        return count;
    }

    void initEffectiveElements(bool initBool) const {
        if (effectiveElements[0]) {
            for (int j = 0; j < this->length; j++) {
                effectiveElements[j+1] = initBool;
            }
        } else {
            for (int j = 0; j < this->length; j++) {
                effectiveElements2[j+1] = initBool;
            }
        }
    }

    void initLocalArr(int initValue) {
        if (arr[0]) {
            for (int k = 0; k < this->length; k++) {
                arr[k+1] = initValue;
            }
        } else {
            for (int k = 0; k < this->length; k++) {
                arr2[k+1] = initValue;
            }
        }
        initEffectiveElements(true);
        this->effectiveLength = this->length;
        //        printArray();
    }

    void setSize(int size) {
        if (!arr[0]) {
            this->totalStorageLength = size + 1;
            arr = new int[this->totalStorageLength];
            arr[0] = 1;
            effectiveElements = new bool[this->totalStorageLength];
            for (int h = 1; h < this->totalStorageLength; h++) {
                effectiveElements[h] = false;
            }
            for (int i = 1; i < localMin(this->totalStorageLength, this->length+1); i++) {
                if (effectiveElements2[i]) {
                    arr[i] = arr2[i];
                    effectiveElements[i] = effectiveElements2[i];
                }
            }
            arr2[0] = 0;
            effectiveElements[0] = true;
            effectiveElements2[0] = false;
            this->length = size;
            this->effectiveLength = this->getCount();
        } else {
            this->totalStorageLength = size + 1;
            arr2 = new int[this->totalStorageLength];
            arr2[0] = 1;
            effectiveElements2 = new bool[this->totalStorageLength];
            for (int h = 1; h < this->totalStorageLength; h++) {
                effectiveElements2[h] = false;
            }
            for (int i = 1; i < localMin(this->totalStorageLength, this->length+1); i++) {
                if (effectiveElements[i]) {
                    arr2[i] = arr[i];
                    effectiveElements2[i] = effectiveElements[i];
                }
            }
            arr[0] = 0;
            effectiveElements2[0] = true;
            effectiveElements[0] = false;
            this->length = size;
            this->effectiveLength = this->getCount();
        }
    }

    int elementAt(int index) const {
        if (index > this->length - 1 && index < 0) {
            throw (exception());
        }
        if (arr[0]) {
            return arr[index + 1];
        } else {
            return arr2[index + 1];
        }
    }

    int &operator[](int index) {
        if (index > this->length - 1 && index < 0) {
            throw (exception());
        }
        if (arr[0]) {
            effectiveElements[index + 1] = true;
            this->effectiveLength = this->getCount();
            return arr[index + 1];
        } else {
            effectiveElements2[index + 1] = true;
            this->effectiveLength = this->getCount();
            return arr2[index + 1];
        }
    }

    void setValueByIndex(int index, int value) {
        if (arr[0]) {
            arr[index + 1] = value;
            effectiveElements[index + 1] = true;
        } else {
            arr2[index + 1] = value;
            effectiveElements2[index + 1] = true;
        }
        this->effectiveLength = this->getCount();
    }
};

template<typename T>
void printBlankArray(T *arr, int length) {
    for (int h = 0; h < length; h++) {
        cout << arr[h] << " ";
    }
}

int main() {

    LocalArr b(10, 17);
    b.printArray();
    b[2] = 10;
    cout << "\n";
    b.printArray();
    cout << "\n";
    b.setSize(20);
    for (int h = 0; h < 20; h++) {
        b[h] = h * h;
    }
    b.printArray();
    cout << " \n";
    b.setSize(5);
    b.printArray();
    cout << "\n";
    b.setSize(20);
    b.printArray();
    cout<<"\n";
    b.setSize(100);
    for(int y = 0; y < 100;y++){
        b[y] = y * y;
    }
    b.printArray();
    return 0;
}
