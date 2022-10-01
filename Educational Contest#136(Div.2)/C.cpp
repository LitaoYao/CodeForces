// https://codeforces.com/contest/1739/problem/C
#include <iostream>
#include <vector>
using namespace std;
const int MOD = 998244353;
void solve()
{
	int n;
	cin >> n;
	vector<vector<long long>> C(n + 1, vector<long long>(n + 1, 0));
	C[0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		C[i][0] = 1;
		C[i][i] = 1;
		for (int j = 1; j < i; ++j)
		{
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}
	long long A = 0;
	long long B = 0;
	int turn = 1;
	for (int i = n; i >= 2; i -= 2)
	{
		if (turn)
		{
			A += C[(i - 1)][i / 2 - 1];
			A %= MOD;
		}
		else
		{
			if (i > 2)
			{
				A += C[(i - 2)][(i - 2) / 2 - 1];
				A %= MOD;
			}
		}
		turn = 1 - turn;
	}
	B = (C[n][n / 2] - A - 1 + MOD) % MOD;
	cout << A << " " << B << " " << 1 << endl;
	return;
}
void fastRead()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
int main()
{
	fastRead();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
