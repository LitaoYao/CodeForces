// https://codeforces.com/contest/1690/problem/C
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> s(n);
	vector<int> f(n);
	vector<int> d(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> f[i];
	}
	int lastEndTime = 0;
	for (int i = 0; i < n; ++i)
	{
		int startTime = max(lastEndTime, s[i]);
		d[i] = f[i] - startTime;
		lastEndTime = f[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cout << d[i] << " ";
	}
	cout << endl;
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

