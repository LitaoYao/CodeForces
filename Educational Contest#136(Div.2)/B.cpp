// https://codeforces.com/contests/1739/problem/B
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> d(n);
	bool valid = true;
	for (int i = 0; i < n; ++i)
	{
		cin >> d[i];
		if (i > 0 && d[i] != 0 && d[i - 1] - d[i] >= 0)
		{
			valid = false;
		}
		if (i > 0)
		{
			d[i] = d[i - 1] + d[i];
		}
	}
	if (valid)
	{
		for (int i = 0; i < n; ++i)
		{
			cout << d[i] << " \n"[i == n - 1];
		}
	}
	else
	{
		cout << -1 << endl;
	}
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
