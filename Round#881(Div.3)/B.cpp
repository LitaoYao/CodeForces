// https://codeforces.com/contest/1843/problem/B
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<long long> a(n);
	long long sum = 0;
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum += abs(a[i]);
	}
	bool nowPositive = true;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] < 0)
		{
			if (nowPositive)
			{
				++count;
			}
			nowPositive = false;
		}
		else if(a[i] > 0)
		{
			nowPositive = true;
		}
	}
	cout << sum << " " << count << endl;
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
