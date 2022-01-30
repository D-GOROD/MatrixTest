#include <iostream>
#include <vector>

using namespace std;
void print_matrix(vector<int> X, vector<int> Y, vector<int> Z);
void check_matrix(vector<int> X, vector<int> Y, vector<int> Z);
int main()
{
	vector<int> X = { 0,1,2,3,4,5,6,7,8,9,10 };
	vector<int> Y = { 0,1,2,3,4,5,6,7,8,9,10 };
	vector<int> Z;
	print_matrix(X, Y, Z);
	return 0;
}
void check_matrix(vector<int> X, vector<int> Y, vector<int> Z)
{
	int z;
	for (int x = 0; x < Y.size(); x++)
	{
		for (int y = 0; y < X.size(); y++)
		{
			z = X[x] + Y[y];
			Z[z]++;

		}
	}
}
void print_matrix(vector<int> X, vector<int> Y, vector<int> Z)
{
	int z;
	for (int x = 0; x < Y.size(); x++)
	{	
		for (int y = 0; y < X.size(); y++)
		{
			z = X[x] + Y[y];
			cout << z << "\t";
			Z[z]++;
			
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < Z.size(); i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (int i = 0; i < Z.size(); i++)
	{
		cout << Z[i] << "\t";
	}
}