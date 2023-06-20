// https://codeforces.com/contest/1691/problem/C
#include <iostream>
#include <string>
using namespace std;
void solve()
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int leftOne = INT_MAX;
	int rightOne = 0;
	bool hasOne = false;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '1')
		{
			leftOne = min(leftOne, i);
			rightOne = max(rightOne, i);
			hasOne = true;
		}
	}
	if (hasOne)
	{
		if (leftOne == rightOne)
		{
			if (n - rightOne - 1 <= k)
			{
				swap(s[n - 1], s[rightOne]);
			}
			else if (leftOne <= k)
			{
				swap(s[0], s[leftOne]);
			}
		}
		else
		{
			if (n - rightOne - 1 <= k)
			{
				swap(s[n - 1], s[rightOne]);
				k -= n - rightOne - 1;
			}
			if (leftOne <= k)
			{
				swap(s[0], s[leftOne]);
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		ans += (s[i] - '0') * 10 + (s[i + 1] - '0');
	}
	cout << ans << endl;
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
