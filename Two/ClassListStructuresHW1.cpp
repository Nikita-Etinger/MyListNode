#include <iostream>
#include "ClassList.h"
using namespace std;





int main()
{
    //List<int> list;
    //list.show();
    //list.push_front(2);
    //list.push_front(4);
    //list.show();
    // cout <<  endl;
    //list.push_back(9);
    //list.show();
    // cout <<  endl;
    //list.insert(10, 1);
    //list.insert(12, 1);
    //list.insert(17, 1);
    //list.show();
    // cout <<  endl;
    //list.pop_back();
    //list.show();
    // cout <<  endl;
    //list.pop_front();
    //list.show();
    // cout <<  endl;
    //list.removeAt(4);
    //list.show();
    // cout <<  endl;
    //list.removeAt(1);
    //list.show();
    // cout <<  endl;
    //list.removeAt(0);
    //list.show();
    // cout <<  endl;
    //list.removeAt(0);
    //list.show();
    // cout <<  endl;
    //list.removeAt(0);
    //list.show();
    // cout <<  endl;
    //list.removeAt(0);
    //list.show();
    // cout <<  endl;
    //list.removeAt(0);
    //list.show();
    // cout <<  endl;
    //list.removeAt(0);
    //list.show();
    // cout <<  endl;


    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);

    myList.show(); 

    myList.insert(10, 2);
    myList.show();

    myList.push_front(5);
    myList.show(); 

    myList.pop_back();
    myList.show(); 

    myList.pop_front();
    myList.show(); 

    cout << "Front: " << myList.front() <<  endl;
    cout << "Back: " << myList.back() <<  endl;

    cout << "Size: " << myList.size() <<  endl;
    cout << "Is empty? " << (myList.empty() ? "Yes" : "No") <<  endl; 

    myList.removeAt(2);
    myList.show();

    List<int> otherList;
    otherList.push_back(100);
    otherList.push_back(200);
    otherList.push_back(300);

    myList.insertList(otherList, 1);
    myList.show(); 

    return 0;
};