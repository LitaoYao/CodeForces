// https://codeforces.com/contest/1694/problem/A
#include <iostream>
#include <string>
using namespace std;
void fill(string& str, int a, int b, char A, char B)
{
	int maxScore = max(1, a - b);
	while (a >= maxScore && b >= maxScore)
	{
		for (int i = 0; i < maxScore; ++i)
		{
			str += B;
		}
		for (int i = 0; i < maxScore; ++i)
		{
			str += A;
		}
		a -= maxScore;
		b -= maxScore;
	}
	for (int i = 0; i < b; ++i)
	{
		str += B;
	}
	for (int i = 0; i < a; ++i)
	{
		str += A;
	}
}
void solve()
{
	int a, b;
	cin >> a >> b;
	string str = "";
	if (a > b)
	{
		fill(str, a, b, '0', '1');
	}
	else
	{
		fill(str, b, a, '1', '0');
	}
	cout << str << endl;
	return;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
