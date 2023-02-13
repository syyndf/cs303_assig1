#include "Functions.h"
using namespace std;

#include <fstream>

int main() {
    int* array = new int[150];
  
    int arraySize = 0;
  
    ifstream file("input.txt");
    if (file.fail()) {
        cout << "Input file opening failed" << endl;
        exit(1);
    }
    int value;
    while (file >> value) {
        array[arraySize++] = value;
    }
    char choice;
    do {
        choice = useroptions();
        switch (choice) {
        case 'a': 
        case 'A': {
            int searchValue;
            cout << "Enter a value to search for: ";
            cin >> searchValue;
            int index = -1;
            for (int i = 0; i < arraySize; i++) {
                if (array[i] == searchValue) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                cout << "Value not found." << endl;
            }
            else {
                cout << "Value found at index " << index << endl;
            }
            cout << endl;
            break;
        }
        
         //to modify 
        case 'b':        
        case 'B': {
            int modifyIndex, ValueToModify;
            cout << "Enter the index to modify: ";
            cin >> modifyIndex;
        
            if (modifyIndex >= 0 && modifyIndex < arraySize) {
                cout << "Enter the new value: ";
                cin >> ValueToModify;
                array[modifyIndex] = ValueToModify;
            }
            
            else {
                cout << "Invalid index." << endl;
            }
            modifyValue(array, arraySize, modifyIndex, ValueToModify);
            cout << endl;
            break;
        }
        
        //add to the end of the array 
        case 'c':        
        case 'C': {
            int newValue;
            cout << "Enter a value to add to the end of the array: ";
            cin >> newValue;
            addInteger(array, arraySize, newValue);
            
            arraySize++;
            cout << endl;
            break;
        }
        
        // Remove a value at index  
        case 'd':       
        case 'D': {
            int removeIndex;
            cout << "Enter the index to remove: ";
            cin >> removeIndex;
            replaceValue(array, arraySize, removeIndex);        
            cout << endl;
            break;
          }
        }
    } while (choice != 'q');
  
    file.close(); 
    return 0;
}
