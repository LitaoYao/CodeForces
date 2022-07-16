#include <iostream>
#include <vector>
#include <map>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<long long> nums;
	long long x;
	int zeroCount = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		if (x == 0)
		{
			++zeroCount;
		}
		else
		{
			nums.push_back(x);
		}
	}
	while ((n = nums.size()) > 1)
	{
		map<long long, long long> tmp;
		if (zeroCount)
		{
			++tmp[nums[0]];
			--zeroCount;
		}
		for (int j = 1; j < n; ++j)
		{
			x = nums[j] - nums[j - 1];
			++tmp[x];
		}
		nums.clear();
		for (auto& it : tmp)
		{
			if (it.first == 0)
			{
				zeroCount += it.second;
			}
			else
			{
				for (int i = 0; i < it.second; ++i)
				{
					nums.push_back(it.first);
				}
			}
		}
	}
	cout << (n == 0 ? 0 : nums[0]) << endl;
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
