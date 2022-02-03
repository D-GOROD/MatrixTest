#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Matrix
{
public:
	Matrix(vector<int> X, vector<int> Y);
	void print_matrix();
	bool check_matrix();
	int get_K();
	int get_D();
private:
	vector<int> X;
	vector<int> Y;
	vector<int> Summ_count;
	int K;
	int D;
	int calculate_D(vector<int> X, vector<int> Y);
};
extern vector<Matrix> Vec;