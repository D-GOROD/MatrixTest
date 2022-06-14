#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <clocale>
#include <Windows.h>
#include <algorithm>
#include <fstream>
#include "Martix.h"


#define D_MIN 0.9
#define SIZE_X 8
#define SIZE_Y 10
#define LENGHT_RESULT_VECTOR 2

using namespace std;
bool erase_foo(vector<int>& vec, int a);
void print_procent(int procent);