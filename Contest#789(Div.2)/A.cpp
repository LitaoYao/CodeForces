// https://codeforces.com/contest/1678/problem/A
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> nums(n);
		vector<int> counts(101, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> nums[i];
			++counts[nums[i]];
		}
		int ans = 0;
		if (counts[0] > 0)
		{
			for (int i = 1; i <= 100; ++i)
			{
				ans += counts[i];
			}
		}
		else
		{
			int hasDup = false;
			for (int i = 1; i <= 100; ++i)
			{
				if (counts[i] > 1)
				{
					hasDup = true;
				}
				ans += counts[i];
			}
			if (!hasDup)
			{
				ans += 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
