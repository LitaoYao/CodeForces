// https://codeforces.com/contest/1700/problem/B
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void deal(vector<int>& a, vector<int>&b, vector<int>& c)
{
	int aSize = a.size();
	for (int i = aSize - 1; i > 0; --i)
	{
		if (a[i] >= b[i - 1])
		{
			c[i - 1] = a[i] - b[i - 1];
		}
		else
		{
			a[i - 1] -= 1;
			c[i - 1] = a[i] + 10 - b[i - 1];
		}
	}
}
void solve()
{
	int n;
	cin >> n;
	string numStr;
	cin >> numStr;
	vector<int> num(n);
	vector<int> ans(n, 0);
	for (int i = 0; i < n; ++i)
	{
		num[i] = numStr[i] - '0';
	}
	vector<int> target(n + 1, 1);
	deal(target, num, ans);
	if (ans[0] == 0)
	{
		target[0] = target[n] = 1;
		for (int i = 1; i <= n - 1; ++i)
		{
			target[i] = 0;
		}
		deal(target, num, ans);
	}
	for (int i = 0; i < n; ++i)
	{
		cout << ans[i];
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
