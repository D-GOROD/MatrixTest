#include "MatrixTest.h"
int main()
{
	vector<int> X = { 0,1,2,3,4,5,6,7,8,9,10 };
	vector<int> Y = { 0,1,2,3,4,5,6,7,8,9,10 };
	Matrix source(X, Y);
	/*
		bool flag = true;
		while (flag)
	{
		flag = Matrix(X, Y).check_matrix();
		flag = erase_foo(X, 2);
		flag = Matrix(X, Y).check_matrix();
		flag = erase_foo(Y, 3);
	}
	cout << "_________________________" << endl;*/
	return 0;
}
Matrix Foo(Matrix mat) {

	return mat;
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