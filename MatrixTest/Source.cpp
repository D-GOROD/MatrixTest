#include "MatrixTest.h"
int a = 1;
int b = 0;
int c = 0;
bool flag = true;
bool flag2 = false;
int main()
{
	setlocale(LC_ALL, "RU");
	vector<int> X = { 0,1,2,3,4,5 };
	vector<int> Y = { 0,1,2,3,4,5 };
	//Matrix source(X, Y);
	Foo(X, Y);
	b = 3;
	a = 2;
	Foo(X, Y);
	b = 3;
	a = 2;
	Foo(X, Y);
	//testFOO(X, Y);
	return 0;
}
void Foo(vector<int> X, vector<int> Y) {
	//Matrix(X, Y).check_matrix();
	if (b == 3)
	{
		//a = 2;
		flag = erase_foo(X, a);
		b = 1;
		//a = 0;
	}
	print_vector(X);
	flag = erase_foo(X, a);
	if (flag)
	{
		//b = 0;
		//a = 1;
		Foo(X, Y);
	}
	if (b == 3)
	{
		a = 2;
		c += 1;
		Foo(X, Y);
		if (c == 2) {
			b = 3;
			a = 3;
			Foo(X, Y);
		}
	}
	cout << "ELSE - ";
	print_vector(X);
	b++;
}
bool erase_foo(vector<int> &vec, int a)
{
	if (a == 0 || a >= vec.size() - 1)
	{
		//cout << "erase_foo: - Выход за границы" << endl;
		//cout << "\t" << "Попытка ислючить " << a << " элемент" << endl << endl;

		return false;
	}
	vector<int>::iterator it = vec.begin();
	advance(it, a);
	vec.erase(it);
	return true;
}
void print_vector(std::vector<int> const& input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
	std::cout << std::endl << std::endl;
}
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