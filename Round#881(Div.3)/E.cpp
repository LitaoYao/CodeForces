// https://codeforces.com/contest/1843/problem/E
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> nums(n + 1);
	vector<int> preSum(n + 1);
	vector<pair<int, int>> pairs(m);
	int l, r;
	for (int i = 0; i < m; ++i)
	{
		cin >> l >> r;
		pairs[i] = make_pair(l, r);
	}
	int q;
	cin >> q;
	vector<int> changes(q + 1);
	for (int i = 1; i <= q; ++i)
	{
		cin >> changes[i];
	}
	bool hasValid = false;
	int left = 1, right = q;
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		bool valid = false;
		for (int i = 1; i <= n; ++i)
		{
			nums[i] = 0;
			preSum[i] = 0;
		}
		for (int i = 1; i <= mid; ++i)
		{
			nums[changes[i]] = 1;
		}
		for (int i = 1; i <= n; ++i)
		{
			preSum[i] = preSum[i - 1] + nums[i];
		}
		for (int i = 0; i < m; ++i)
		{
			l = pairs[i].first;
			r = pairs[i].second;
			if (preSum[r] - preSum[l - 1] > (r - l + 1) / 2)
			{
				valid = true;
				hasValid = true;
				break;
			}
		}
		if (valid)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << (hasValid ? left : -1) << endl;
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
