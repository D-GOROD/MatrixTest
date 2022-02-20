#include "Martix.h"
#define END_FOO "\\-\\-\\-\\-\\-\\-\\-\\-\\-\\-\\-\\-\\-\\-\\-\\-\\-\\-\\-\\"
#define START_FOO "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/"

Matrix::Matrix(vector<int> X, vector<int> Y, vector<int> Summ_count, float D)
{
	this->X = X;
	this->Y = Y;
	this->Summ_count = Summ_count;
	this->D = D;
	this->K = static_cast<float>(X.size() * Y.size()) / static_cast<float>(Summ_count.capacity());
}

float Matrix::get_K()
{
	return K;
}
float Matrix::get_D()
{
	return D;
}
void Matrix::print_matrix_to_console()
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

void Matrix::print_matrix_to_file(ofstream& fout)
{
	fout << START_FOO << endl;
	for (int y : Y)
	{
		for (int x : X) {
			fout << x + y << "\t";
		}
		fout << endl;
	}
	fout << endl;
	for (int i = 0; i < Summ_count.size(); i++)
	{
		fout << i << "\t" << "|";
	}
	fout << endl;
	for (int z : Summ_count)
	{
		fout << z << "\t" << "|";
	}
	fout << endl << endl;
	fout << "K = " << K << endl << "D = " << D << endl;
	fout << END_FOO << endl;
}

bool operator>(const Matrix& m1, const Matrix& m2)
{
	return m1.K > m2.K;
}
bool operator<(const Matrix& m1, const Matrix& m2)
{
	return m1.K < m2.K;
}
bool operator>=(const Matrix& m1, const Matrix& m2)
{
	return m1.K >= m2.K;
}
bool operator<=(const Matrix& m1, const Matrix& m2)
{
	return m1.K <= m2.K;
}