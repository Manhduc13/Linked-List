#pragma once
#include<iostream>
using namespace std;

class LList {
private:
    class node {
    public:
        int value;
        node* next;
        node() :value(0), next(0) {}
        node(int item) : value(item), next(0) {}
    };
    node* myfirst;
    int mysize;
    node* pos2ptr(int);
public:
    LList() :myfirst(0), mysize(0) {}
    LList(LList&);
    ~LList();
    bool isEmpty();
    void addAtEnd(int);
    void addAtBeginning(int);
    void addAtIndex(int, int);
    void eraseAtIndex(int);
    void eraseFirst();
    void eraseEnd();// 
    bool find(int);
    int size();
    LList operator=(LList&); //overload
    friend ostream& operator<<(ostream&, LList&);
};

