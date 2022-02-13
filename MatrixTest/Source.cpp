#include "MatrixTest.h"
int main()
{
	setlocale(LC_ALL, "RU");
	auto start = chrono::high_resolution_clock::now();
	int size = 11;
	unsigned int N = pow(2, ((size - 2) * 2)) - 1;
	unsigned int procent100 = N / 100;
	unsigned int procent = N - procent100;
	int proc = 1;
	int M = (size - 2) * 2;
	int M2 = size - 2;
	for (N; N > 0; N--)
	{
		vector<int> X = { 0,1,2,3,4,5,6,7,8,9,10 };
		vector<int> Y = { 0,1,2,3,4,5,6,7,8,9,10 };
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
		if (N == procent)
		{
			system("cls");
			cout << proc << " %" << endl;
			proc++;
			procent -= procent100;
		}
		Matrix(X, Y).check_matrix(false);
		//print_vector(X);
		//print_vector(Y);
	}
	system("cls");
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout << "Time = " << duration.count() << "s" << endl;
	cout << "Total - " << Vec.size() << endl;
	cout << "Index min_K - " << min_I << endl;
	Vec[min_I].print_matrix();
	_getch();
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
void print_vector(std::vector<int> const& input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
	std::cout << std::endl << std::endl;
}