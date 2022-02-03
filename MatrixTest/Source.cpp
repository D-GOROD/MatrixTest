#include "MatrixTest.h"
void testFOO(vector<int> X, vector<int> Y)
{
	bool flag = true;
	while (flag)
	{
		flag = Matrix(X, Y).check_matrix();
		flag = erase_foo(Y, 2);
		flag = erase_foo(Y, 4);
		flag = erase_foo(X, 3);
	}
	cout << "Size = " << Vec.size() << endl << endl;
}
int main()
{
	setlocale(LC_ALL, "RU");
	vector<int> X = { 0,1,2,3,4,5,6,7,8,9,10 };
	vector<int> Y = { 0,1,2,3,4,5,6,7,8,9,10 };
	Matrix source(X, Y);
	Foo(source);
	//testFOO(X, Y);
	return 0;
}
Matrix Foo(Matrix mat) {

	return mat;
}
bool erase_foo(vector<int> &vec, int a)
{
	if (a == 0 || a >= vec.size() - 1)
	{
		cout << "erase_foo: - Выход за границы" << endl;
		cout << "\t" << "Попытка ислючить " << a << " элемент" << endl << endl;

		return false;
	}
	vector<int>::iterator it = vec.begin();
	advance(it, a);
	vec.erase(it);
	return true;
}