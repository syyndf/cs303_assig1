
#pragma once
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;


char useroptions();


void modifyValue(int*& a, int s, int ind, int newValue);
//modifys the value


void addInteger(int*& a, int s, int newValue);
//a function that adds a new integer to the end of the array


int intakeIndex(const int*& array, int size, int value);
//A function that intakes an index of an array


void replaceValue(int*& a, int& s, int ind);
//replaces the value with either 0 or removes the integer altogether.
