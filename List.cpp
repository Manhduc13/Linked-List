#include "List.h"
#include<iostream>
using namespace std;

LList::LList(LList& L) {
    if (L.myfirst == 0) myfirst = 0;
    else {
        myfirst = new node(L.myfirst->value);
        node* tempL = myfirst;
        node* tempR = L.myfirst;
        while (tempR->next != 0) {
            tempL->next = new node(tempR->next->value);
            tempR = tempR->next;
            tempL = tempL->next;
        }
    }
    mysize = L.mysize;
}
LList::~LList() {
    node* temp;
    while (myfirst != 0) {//1
        temp = myfirst;
        //2 
        myfirst = myfirst->next;
        delete temp;
    }

}
bool LList::isEmpty() { return (myfirst == 0); }
void LList::addAtEnd(int item) {
    if (isEmpty()) { myfirst = new node(item); }
    else {
        node* temp = myfirst;
        while (temp->next != 0) temp = temp->next;
        temp->next = new node(item);
    }
    mysize++;

}
void LList::addAtBeginning(int item) { //add item at the beginning of list
    node* temp = new node(item);
    if (myfirst == 0) myfirst = temp;
    else { temp->next = myfirst; myfirst = temp; }
    mysize++;

}
void LList::addAtIndex(int pos, int item) {
    if (!(pos < mysize && pos >= 0))cout << "invalid position" << endl;
    else {
        if (pos == 0) addAtBeginning(item);
        else {
            node* ptr = pos2ptr(pos);
            node* temp = new node(item);
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }
    mysize++;
}
void LList::eraseFirst() {
    if (!isEmpty()) {
        node* temp = myfirst;
        myfirst = myfirst->next;
        delete temp;
        mysize--;
    }
}
void LList::eraseEnd() {
    if (myfirst != 0) {
        if (myfirst->next == 0) { delete myfirst; myfirst = 0; }
        else {
            node* temp = myfirst;
            while (temp->next->next != 0) { temp = temp->next; }
            delete temp->next;
            temp->next = 0;
        }
        mysize--;
    }
    else cout << "Can not erase, the list is empty" << endl;
}
void LList::eraseAtIndex(int pos) {
    if (pos<0 || pos>mysize) {
        cout << "Invalid position!";
        return;
    }
    mysize--;
    node* ptr;
    if (pos == 0) eraseFirst();
    else {
        node* prev = pos2ptr(pos);
        ptr = prev;
        prev = ptr->next;
        delete ptr;
    }
}
bool LList::find(int item) {
    node* temp = myfirst;
    bool found = false;
    while (temp != 0) {
        if (temp->value == item) { found = true; break; }
        temp = temp->next;
    }
    return found;
}
int LList::size() { return mysize; }
//helper function pos2ptr returns a pointer to node predecessor to the index node
LList::node* LList::pos2ptr(int pos) {
    node* temp = myfirst;
    int counter = 1;
    while (counter < pos) { temp = temp->next; counter++; }
    return temp;
}
LList LList::operator=(LList& L) {
    if (L.myfirst == 0) myfirst = 0;
    else {
        myfirst = new node(L.myfirst->value);
        node* tempL = myfirst;
        node* tempR = L.myfirst;
        while (tempR->next != 0) {
            tempL->next = new node(tempR->next->value);
            tempR = tempR->next;
            tempL = tempL->next;
        }
    }
    mysize = L.mysize;
    return *this;
}
ostream& operator<<(ostream& out, LList& L) {
    LList::node* temp = L.myfirst;
    while (temp != 0) {
        out << " " << temp->value;
        temp = temp->next;
    }
    cout << endl;
    return out;
}