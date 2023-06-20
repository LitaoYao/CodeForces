// https://codeforces.com/contest/1695/problem/C
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
const int N = 1000;
void modify(bitset<2 * N + 1>& group, int x)
{
	if (x == 1)
	{
		group >>= 1;
	}
	else
	{
		group <<= 1;
	}
}
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	vector<bitset<2 * N + 1>> sum(m, 0);
	bitset<2 * N + 1> zero = bitset<2 * N + 1>(1) << N;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> grid[i][j];
		}
	}
	sum[0] = zero;
	modify(sum[0], grid[0][0]);
	for (int j = 1; j < m; ++j)
	{
		sum[j] = sum[j - 1];
		modify(sum[j], grid[0][j]);
	}
	for (int i = 1; i < n; ++i)
	{
		modify(sum[0], grid[i][0]);
		for (int j = 1; j < m; ++j)
		{
			sum[j] = (sum[j] | sum[j - 1]);
			modify(sum[j], grid[i][j]);
		}
	}
	if ((sum[m - 1] & zero) == zero)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
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
