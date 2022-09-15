// https://codeforces.com/contest/1690/problem/B
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	int maxDiff = 0;
	bool valid = true;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
		int diff = a[i] - b[i];
		maxDiff = max(diff, maxDiff);
	}
	for (int i = 0; i < n; ++i)
	{
		a[i] = max(0, a[i] - maxDiff);
		if (a[i] != b[i])
		{
			valid = false;
			break;
		}
	}
	if (valid)
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
