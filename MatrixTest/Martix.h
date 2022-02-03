#pragma once
#include <iostream>
#include <vector>
#define END_FOO "\\-\\-\\-\\-\\-\\-\\-\\-\\-\\-\\-\\-\\-\\-\\-\\-\\-\\-\\-\\"
#define START_FOO "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/"
using namespace std;
class Matrix
{
public:
	Matrix(vector<int> X, vector<int> Y);
	void print_matrix();
	bool check_matrix();
	float get_K();
	float get_D();
private:
	vector<int> X;
	vector<int> Y;
	vector<int> Summ_count;
	float K;
	float D;
	float calculate_D(vector<int> X, vector<int> Y);
};
extern vector<Matrix> Vec;