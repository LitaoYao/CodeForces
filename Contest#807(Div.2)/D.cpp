// https://codeforces.com/contest/1705/problem/D
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	char x;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		a[i] = x - '0';
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		b[i] = x - '0';
	}
	if (a[0] != b[0] || a[n - 1] != b[n - 1])
	{
		cout << -1 << endl;
		return;
	}
	for (int i = n - 1; i > 0; --i)
	{
		a[i] = a[i] ^ a[i - 1];
		b[i] = b[i] ^ b[i - 1];
	}
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == 1)
		{
			++count;
		}
		if (b[i] == 1)
		{
			--count;
		}
	}
	if (count != 0)
	{
		cout << -1 << endl;
	}
	else
	{
		int index1 = 1;
		int index2 = 1;
		long long ans = 0;
		while (index1 < n && index2 < n)
		{
			while (index1 < n && a[index1] == 0)
			{
				++index1;
			}
			while (index2 < n && b[index2] == 0)
			{
				++index2;
			}
			if (index1 < n && index2 < n)
			{
				ans += abs(index1 - index2);
			}
			++index1;
			++index2;
		}
		cout << ans << endl;
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
