#include <iostream>
#include "Functions.h"
#include <fstream>
#include <sstream>
#include <iostream>
using  namespace std;

int main() {
	int arr[100];
	string filename;
	cout << "Enter a file name" << endl;
	cin >> filename;
	// Open up the file with the users filename, if incorrect ask again
	ifstream file(filename);
	while (file.fail()) {
		file.clear();
		cout << "Incorrect filename, please enter again" << endl;
		cin >> filename;
		file.open(filename.c_str());
	}
	if (file.is_open()) {
		for (int i = 0; i < 100; i++) {
			file >> arr[i];
			cout << arr[i] << " ";


		}
		cout << endl;
	}
	file.close();
	char choice;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	do
	{
		choice = userchoice();
		if (choice != '1' && choice != '2' && choice != '3' && choice != '4' &&
			choice != '5') {
			cout << "Invalid choice, please try again" << endl;
			continue;
		}
		switch (choice) {
		case '1':
			// checks for the integer in the Array
			cout << "Enter integer to see if it exists in the array: " << endl;
			cin >> a;
			findindex(arr, 100, a);
			break;
		case '2':
			// modifys a integer at a certain index
			cout << "Enter index to be modified: ";
			cin >> b;
			try {
				if (0 <= b && b <= 100) {
					modify(arr, b, 100);
				}
				else
				{
					throw(b);
				}
			}
			catch (...) {
				cout << "The index does not exist in the range of the array " << endl;
			}
			break;
		case '3':
			//  appends an integer to the array
			cout << "Enter new integer to add to the end of the array:  " << endl;
			cin >> c;
			try {
				if (c > 0) {
					add(arr, 100, c);
				}
				else {
					throw(c);
				}
			}
			catch (...) {
				cout << "Please try again with a integer above 0" << endl;

			}
			break;
		case '4':
			// removes a integer at certain index
			cout << "Enter index to remove integer: " << endl;
			cin >> d;
			remove(arr, d, 100);
			break;

		}
	} while (choice != '5');

}
