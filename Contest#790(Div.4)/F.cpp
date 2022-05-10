#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n;
		cin >> k;
		vector<int> nums(n);
		unordered_map<int, int> counts;
		for (int i = 0; i < n; ++i)
		{
			cin >> nums[i];
			if (!counts.count(nums[i]))
			{
				counts[nums[i]] = 0;
			}
			++counts[nums[i]];
		}
		vector<int> keys;
		for (auto& it : counts)
		{
			keys.push_back(it.first);
		}
		sort(keys.begin(), keys.end());
		int m = keys.size();
		vector<int> dp(m, 0);
		int r = -1;
		int r_l = 0;
		if (counts[keys[0]] >= k)
		{
			dp[0] = 1;
			r = keys[0];
			r_l = 1;
		}
		for (int i = 1; i < m; ++i)
		{
			if (counts[keys[i]] >= k)
			{
				if (keys[i] == keys[i - 1] + 1)
				{
					dp[i] = dp[i - 1] + 1;
				}
				else
				{
					dp[i] = 1;
				}
				if (dp[i] > r_l)
				{
					r_l = dp[i];
					r = keys[i];
				}
			}
		}
		if (r != -1)
		{
			cout << r - r_l + 1 << " " << r << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
