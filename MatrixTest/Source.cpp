#include "MatrixTest.h"
int main()
{
	auto start = chrono::high_resolution_clock::now();
	setlocale(LC_ALL, "RU");
	long long N = (pow(2, ((SIZE_X - 2) + (SIZE_Y - 2))))-1;
	long long oneProcent = N / 100;
	long long procentPosition = N;
	int procent = 0;
	int M = (SIZE_X - 2) + (SIZE_Y - 2);
	int halfM = SIZE_Y-2;
	vector<int> X, Y;
	vector<int> X_min, Y_min;
	vector<int> Summ_count, Summ_count_min;;
	vector<Matrix> Result;
	float K_min = 100;
	float D_max = 0;
	bool flag = true;
		for (N; N > 0; N--)
		{
			if (N == procentPosition)
			{
				print_procent(procent);
				procent++;
				procentPosition -= oneProcent;
			}
		X.clear();
		Y.clear();
		Summ_count.clear();
		for (int i = 0; i < SIZE_X; i++) {
			X.push_back(i);
		}
		for (int i = 0; i < SIZE_Y; i++) {
			Y.push_back(i);
		}
		Summ_count.resize(X.back() + Y.back() + 1);
		for (int i = 0; i < M; i++) {
			if (N & (static_cast<long long>(1) << i)) {
				if (i < halfM)
					erase_foo(Y, (SIZE_Y - i - 2));
				else
				{
					erase_foo(X, (SIZE_X + SIZE_Y - i - 4));
				}
			}
		}
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
		if (multi != 0)
		{
			float D;
			D = static_cast<float>(X.size()) / Y.size();
			if (D > 1)
				D = static_cast<float>(Y.size()) / X.size();
			if (D >= D_MIN)
			{
				if (LENGHT_RESULT_VECTOR != 0)
				{
					Matrix matrix(X, Y, Summ_count, D);
					Result.push_back(matrix);
					sort(Result.begin(), Result.end());
					if (Result.size() > LENGHT_RESULT_VECTOR) Result.pop_back();
				}
				else
				{
					float K = K = static_cast<float>(X.size() * Y.size()) / static_cast<float>(Summ_count.capacity());
					if (K < K_min)
					{
						K_min = K;
						D_max = D;
						X_min = X;
						Y_min = Y;
						Summ_count_min = Summ_count;
					}
				}
			}
		}
	}
	if (LENGHT_RESULT_VECTOR == 0)
	{
		Result.push_back(Matrix(X_min, Y_min, Summ_count_min, D_max));
	}
	Result[0].print_matrix_to_console();
	ofstream fout;
	fout.open("Result.txt");
	int i = 1;
	for (Matrix mat : Result)
	{
		fout << "/*" << i << "*\\" << endl;
		mat.print_matrix_to_file(fout);
		fout << endl;
		i++;
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout << "Time - " << duration.count() << endl;
	fout << "Time - " << duration.count() << endl;
	fout.close();
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
void print_procent(int procent)
{
	system("cls");
	cout << procent << " %" << endl;
}