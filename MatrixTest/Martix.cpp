#include "Martix.h"

Matrix::Matrix(vector<int> X, vector<int> Y)
{
	this->X = X;
	this->Y = Y;
	this->Summ_count.resize(X.back() + Y.back() + 1);
	this->K = static_cast<float>(X.size() * Y.size()) / static_cast<float>(Summ_count.capacity());
	this->D = calculate_D(X, Y);
	static vector<Matrix> Vec;
}
float Matrix::get_K()
{
	return K;
}
float Matrix::get_D()
{
	return D;
}
float Matrix::calculate_D(vector<int> X, vector<int> Y)
{
	float D;
	D = static_cast<float>(X.size()) / Y.size();
	if (D > 1)
		return static_cast<float>(Y.size()) / X.size();
	else
	{
		return D;
	}
}
void Matrix::print_matrix()
{
	cout << START_FOO << endl;
	for (int y : Y)
	{
		for (int x : X) {
			printf("%3d", x + y);
		}
		std::cout << endl;
	}
	cout << endl;
	for (int i = 0; i < Summ_count.size(); i++)
	{
		printf("%2d |", i);
	}
	cout << endl;
	for (int z : Summ_count)
	{
		printf("%2d |", z);
	}
	std::cout << endl << endl;
	cout << "K = " << K << endl << "D = " << D << endl;
	cout << END_FOO << endl;

}
bool Matrix::check_matrix(bool print)
{
	int z;
	for (int x : X)
	{
		for (int y : Y)
		{
			z = x + y;
			Summ_count[z]++;
		}
	}
	int multi = 1;
	for (int z : Summ_count)
	{
		multi *= z;
	}
	if (multi == 0)
	{
		if (print) {
			cout << "Matrix.cpp: - Нарушена непрерывность" << endl;
			for (int x : X)
			{
				printf("\t%2d |", x);
			}
			cout << endl;
			for (int y : Y)
			{
				printf("\t%2d |", y);
			}
			cout << endl << endl;
		}
		return false;
	}
	else
	{
		if (D < 0.6)
			return false;
		Vec.push_back(*this);
		if (K < Vec[min_I].get_K())
		{
			min_I = Vec.size() - 1;
		}
		if(print)
			print_matrix();
		return true;
	}
}