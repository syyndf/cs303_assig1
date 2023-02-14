#include "Functions.h"

#include <iostream>

#include <string>

using namespace std;

char useroptions() {
    cout << "a Search value " << endl;
    cout << "b Modify value " << endl;
    cout << "c Add a value " << endl;
    cout << "d Remove value" << endl; 
    cout << "q Quit" << endl;
    cout << "Enter your choice: ";
    cout << endl;
    char choice;
    string menu = "abcdeq";
    while (true) {
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            continue;
        }
        cin.ignore(256, '\n');
        return tolower(choice);
    }
}

void modifyValue(int*& a, int s, int ind, int newValue) {
    
  if (ind < 0 or ind >= s) {
        cout << "Index out of range" << endl;
        return;
    }
    a[ind] = newValue;
    cout << " The new value is" << a[ind] << endl;
    cout << endl;
}

void addInteger(int*& a, int s, int newValue) {
    a[s] = newValue;
    cout << newValue << " was added." << endl;
}

int intakeIndex(const int*& a, int s, int value) {
    for (int i = 0; i < s; i++) {
        if (a[i] == value) {
            return i;
        }
    }
    return -1;
}

void replaceValue(int*& a, int& s, int ind) {
    for (int i = ind; i < s - 1; i++) {
        a[i] = a[i + 1];
    }
    s--;
}
