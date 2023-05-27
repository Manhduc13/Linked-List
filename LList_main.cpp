#include "List.h"
#include<iostream>
using namespace std;

int main() {
    LList AL;
    for (int i = 0; i < 18; i++) { AL.addAtEnd(i); cout << AL; cout << "Size:" << AL.size(); }
    AL.addAtIndex(0, 8);
    cout << AL << endl;
    AL.addAtIndex(12, 8);
    cout << AL << endl;
    AL.addAtIndex(19, 8);
    cout << AL << endl;
    LList newL(AL);
    cout << endl << newL;
    cout << "Now erasing" << endl;
    for (int i = 0; i < 18; i++) { AL.eraseFirst(); cout << AL << endl; cout << "Size:" << AL.size(); }


    cout << endl;
    system("pause");
    return 0;
}