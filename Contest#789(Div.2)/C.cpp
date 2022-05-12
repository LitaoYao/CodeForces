#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int lowbit(int x)
{
	return x & -x;
}
void add(vector<long long>& t, int x)
{
	int n = t.size() - 1;
	while(x <= n)
	{
		++t[x];
		x += lowbit(x);
	}
}
long long sum(vector<long long>& t, int x)
{
	long long ans = 0;
	while(x >= 1)
	{
		ans += t[x];
		x -= lowbit(x);
	}
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> nums(n + 1);
		vector<long long> pairs(n + 1, 0);
		vector<long long> t(n + 1, 0);
		for (int i = 1; i <= n; ++i)
		{
			cin >> nums[i];
			add(t, nums[i]);
			pairs[i] = sum(t, nums[i] - 1);
			pairs[i] += pairs[i - 1];
		}
		long long ans = 0;
		for (int b = n - 2; b >= 1; --b)
		{
			int modify = 0;
			for (int c = b + 1; c < n; ++c)
			{
				if (nums[b] < nums[c])
				{
					++modify;
				}
				pairs[c] -= modify;
				int d = c + 1;
				if (nums[b] > nums[d])
				{
					ans += pairs[c] - pairs[b];
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
