#include "MatrixTest.h"
vector<Matrix> Vec;
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

Matrix::Matrix(vector<int> X, vector<int> Y)
{
	this->X = X;
	this->Y = Y;
	this->Summ_count.resize(X.back() + Y.back() + 1);
	this->K = (X.size() + Y.size()) / (Summ_count.capacity());
	this->D = calculate_D(X, Y);
}
int Matrix::get_K()
{
	return K;
}
int Matrix::get_D()
{
	return D;
}
int Matrix::calculate_D(vector<int> X, vector<int> Y)
{
	int D;
	D = X.size() / Y.size();
	if (D > 1)
		return Y.size() / X.size();
	else
	{
		return D;
	}
}
void Matrix::print_matrix()
{
	for (int y : Y)
	{
		for (int x : X) {
			std::cout << x + y << "\t";
		}
		std::cout << endl;
	}
	cout << endl;
	for (int i = 0; i < Summ_count.size(); i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (int z : Summ_count)
	{
		cout << z << "\t";
	}
	std::cout << endl << endl;
}
bool Matrix::check_matrix()
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
		cout << "***Error!***" << endl;
		for (int x : X)
		{
			cout << x << "\t";
		}
		cout << endl;
		for (int y : Y)
		{
			cout << y << "\t";
		}
		cout << endl;;
		return false;
	}
	else
	{
		Vec.push_back(*this);
		print_matrix();
		return true;
	}
}

int main()
{
	vector<int> X = { 0,1,2,3,4,5,6,7,8,9,10 };
	vector<int> Y = { 0,1,2,3,4,5,6,7,8,9,10 };
	/*cout << Vec.size() << endl << endl;
	Matrix(X, Y).check_matrix();
	cout << Vec.size() << endl << endl;
	erase_foo(X, 2);
	erase_foo(X, 2);
	erase_foo(Y, 3);
	erase_foo(Y, 3);
	Matrix(X, Y).check_matrix();
	cout << Vec.size() << endl << endl;
	erase_foo(Y, 0);
	Matrix(X, Y).check_matrix();
	cout << Vec.size() << endl << endl;*/
	bool flag = true;
	while (flag)
	{
		flag = Matrix(X, Y).check_matrix();
		flag = erase_foo(X, 2);
		flag = Matrix(X, Y).check_matrix();
		flag = erase_foo(Y, 3);
	}
	cout << "_________________________" << endl;
	//Vec[3].print_matrix();
	return 0;
}

bool erase_foo(vector<int> &vec, int a)
{
	if (a > vec.size() - 2 || a == 0)
	{
		return false;
	}
	vector<int>::iterator it = vec.begin();
	advance(it, a);
	vec.erase(it);
	return true;
}