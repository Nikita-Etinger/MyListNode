
#include <iostream>
#include "ClassList.h"
using namespace std;

template <typename T>
class Stack {
private:
    T* array = nullptr;
    int maxSize = 0;
    int count = 0;


public:

    Stack(int size) {
        maxSize = size;
        array = new T[size];
    }
    ~Stack() {
        delete[]array;
    }
    T operator[](int index) {
        if (index < count && count != 0) {
            return array[index];
        }
    }
    void push(T newT) {
        if (count != maxSize - 1) {
            array[count++] = newT;
        }
    }
    T top() {
        return array[count];
    }
    void pop() {
        if (count != 0)count--;
    }
    bool empty() {
        if (count != 0)return 0;
        return 1;
    }
    int size() {
        return count;
    }
    void emplace(T newT) {
        if (count !=0) {
            array[count] = newT;
        }
    }

    bool operator==(Stack<T>& other) {
        if (other.count != count) return false;
        for (int i = 0; i < count; i++) {
            if (other[i] != array[i]) return false;
        }
        return true;
    }
    bool operator!=(Stack<T>& other) {
        return !(operator==(Stack & other));
    }

    bool operator<(Stack<T>& other) {
        int minLength;
        if (count < other.count) {
            return 1;
        }
        else return 0;

    }
    bool operator>=(Stack<T>& other) {
        return (*this == other) || (*this > other);
    }
    bool operator<=(Stack<T>& other) {
        return (*this == other) || (*this < other);
    }

    bool operator>(Stack<T>& other) {
        return !(*this <= other);
    }

    void swap(Stack& other) {
        swap(array, other.array);
        swap(count, other.array);
        swap(maxSize, other.maxSize);

    }




};

template <typename T>
class  Queue {
private:
    T* array = nullptr;
    int maxSize = 0;
    int count = 0;


public:

    Queue(int size) {
        maxSize = size;
        array = new T[size];
    }
    ~Queue() {
        delete[]array;
    }
    T operator[](int index) {
        return array[index];
    }
    void push(T newT) {
        if (count != maxSize - 1) {
            array[count++] = newT;
        }
    }
    T top() {
        return array[count];
    }
    void pop() {
        if (count != 0) {
            for (int i = 0; i < count; i++) {
                swap(array[i], array[i + 1]);
            }
            count--;
        }
    }
    bool empty() {
        if (count != 0)return 0;
        return 1;
    }
    int size() {
        return count;
    }
    void emplace(T newT) {
        if (count != 0) {
            array[count] = newT;
        }
    }

    bool operator==(Queue<T>& other) {
        if (other.count != count) return false;
        for (int i = 0; i < count; i++) {
            if (other[i] != array[i]) return false;
        }
        return true;
    }
    bool operator!=(Queue<T>& other) {
        return !(operator==(Queue & other));
    }

    bool operator<(Queue<T>& other) {
        int minLength;
        if (count < other.count) {
            return 1;
        }
        else return 0;

    }
    bool operator>=(Queue<T>& other) {
        return (*this == other) || (*this > other);
    }
    bool operator<=(Queue<T>& other) {
        return (*this == other) || (*this < other);
    }

    bool operator>(Queue<T>& other) {
        return !(*this <= other);
    }

    void swap(Queue<T>& other) {
        swap(array, other.array);
        swap(count, other.array);
        swap(maxSize, other.maxSize);

    }
    void front() {
        cout << array[0];
    }
    void back() {
        cout << array[count];
    }
    friend  ostream& operator<<(ostream& os, const Queue& other) {
        for (int i = 0; i < count; i++) {
            os << array[i];
        }
        return os;
    }

};




int main()
{
    //setlocale(LC_ALL, "ru");
    //Stack<int> betaStack(5);
    //Stack<int> betaStack2(5);
    //if (betaStack.empty())cout << "пусто"<<endl;
    //betaStack.push(1);
    //betaStack.push(2);
    //betaStack.push(3);
    //betaStack2.push(1);
    //betaStack2.push(2);
    //betaStack2.push(3);
    //cout << (betaStack == betaStack2)<<endl;
    //cout << (betaStack >= betaStack2) << endl;
    //cout << (betaStack <= betaStack2) << endl;
    //betaStack2.push(4);
    //cout << (betaStack < betaStack2) << endl;
    //cout << (betaStack > betaStack2) << endl;

    //cout << endl;
    //cout << betaStack[1]<<endl;

    //cout<<betaStack.size()<<endl;
    //cout << endl;
    //betaStack.emplace(8);
    //cout << endl;
    //cout << betaStack[2]<<endl;
    //betaStack = betaStack2;
    //cout << (betaStack == betaStack2) << endl;

    List<int> list;
    list.push(2);
    list.push(3);
    list.push(4);
    list.push(5);
    list.push(6);
    list.show();

};

