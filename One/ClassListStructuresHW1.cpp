#include <iostream>
#include "ClassList.h"
using namespace std;





int main()
{
    List<int> myList;
    myList.push(1);
    myList.push(2);
    myList.push(3);
    myList.push(4);

    myList.show(); 

    myList.insert(10, 2);
    myList.show(); 

    myList.removeHead();
    myList.show(); 

    myList.removeAt(2);
    myList.show();

     cout << "Size: " << myList.size() <<  endl;
     cout << "Is empty? " << (myList.empty() ? "Yes" : "No") <<  endl;

    return 0;

};