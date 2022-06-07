#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <clocale>
#include <Windows.h>
#include <algorithm>
#include <fstream>
#include "Martix.h"


#define D_MIN 0.7
#define SIZE_X 7
#define SIZE_Y 7
#define LENGHT_RESULT_VECTOR 0

using namespace std;
bool erase_foo(vector<int>& vec, int a);
void print_procent(int procent);