#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int findIndex(vector<int>& array, int& x)
{
	int left = 0;
	int right = array.size();
	while (left < right)
	{
		int mid = (left + right) >> 1;
		if (array[mid] <= x)
		{
			left = mid + 1;
		}
		else 
		{
			right = mid;
		}
	}
	return left;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> nums[i];
		}
		vector<vector<int>> bigger(n, vector<int>());
		vector<vector<int>> smaller(n, vector<int>());
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (nums[j] > nums[i])
				{
					bigger[i].push_back(j);
				}
				else if (nums[j] < nums[i])
				{
					smaller[i].push_back(j);
				}
			}
		}
		int ans = 0;
		for (int a = 0; a < n; ++a)
		{
			for (int b = a + 1; b < n; ++b)
			{
				int cIndex = findIndex(bigger[a], b);
				if (cIndex >= bigger[a].size())
				{
					continue;
				}
				for (int i = cIndex; i < bigger[a].size(); ++i)
				{
					int c = bigger[a][i];
					int dIndex = findIndex(smaller[b], c);
					if (dIndex >= smaller[b].size())
					{
						continue;
					}
					ans += (smaller[b].size() - dIndex);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
