// https://codeforces.com/contest/1850/problem/E
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool check(vector<long long>& pictures, long long w, long long c)
{
	long long tmp = 0;
	for (int pic : pictures)
	{
		tmp += (pic + w) * (pic + w);
		if (tmp >= c)
		{
			return true;
		}
	}
	return tmp >= c;
}
void solve()
{
	long long n;
	long long c;
	cin >> n >> c;
	vector<long long> pictures(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> pictures[i];
	}
	long long left = 1, right = sqrt(c) + 1;
	while (left < right)
	{
		long long mid = (left + right) >> 1;
		if (check(pictures, mid, c))
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << left / 2 << endl;
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
