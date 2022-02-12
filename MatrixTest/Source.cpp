#include "MatrixTest.h"
int main()
{
	setlocale(LC_ALL, "RU");
	int size = 6;
	int N = pow(2, ((size - 2) * 2)) - 1;
	int M = (size - 2) * 2;
	int M2 = size - 2;
	for (N; N >= 0; N--)
	{
		vector<int> X = { 0,1,2,3,4,5 };
		vector<int> Y = { 0,1,2,3,4,5 };
		for (int i = 0; i < M; i++) {
			if (N & (1 << i)) {
				if (i < M2)
					erase_foo(Y, (M2 - (i + 1)) + 1);
				else
				{
					erase_foo(X, (M2 * 2 - (i - 1)) - 1);
				}
			}
		}
		Matrix(X, Y).check_matrix(true);
	}
	cout << Vec.size();
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