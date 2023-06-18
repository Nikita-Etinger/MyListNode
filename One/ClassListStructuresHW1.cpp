#include <iostream>
#include "ClassList.h"
using namespace std;





int main()
{
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

    myList.clear();
    myList.show(); 

     cout << "Size: " << myList.size() <<  endl;
     cout << "Is empty? " << (myList.empty() ? "Yes" : "No") <<  endl; 


};