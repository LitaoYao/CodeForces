#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
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
		for (int i = 0; i < n; ++i)
		{
			cin >> nums[i];
		}
		int ans = 0;
		vector<int> bigger;
		vector<int> smaller;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (nums[j] > nums[i])
				{
					bigger.push_back(i * 10000 + j);
				}
				else if (nums[j] < nums[i])
				{
					smaller.push_back(i * 10000 + j);
				}
			}
		}
		int biggerSize = bigger.size();
		int smallerSize = smaller.size();
		map<int, int> endIndex;
		for (int i = 0; i < smallerSize; ++i)
		{
			int x = smaller[i] / 10000;
			endIndex[x] = i;
		}
		for (int i = 0; i < biggerSize; ++i)
		{
			int a = bigger[i] / 10000;
			int c = bigger[i] % 10000;
			int left = 0;
			int right = smallerSize;
			while(left < right)
			{
				int mid = (left + right) >> 1;
				if (smaller[mid] / 10000 <= a)
				{
					left = mid + 1;
				}
				else
				{
					right = mid;
				}
			}
			int begin = left;
			while (begin < smallerSize && smaller[begin] / 10000 < c)
			{
				left = begin;
				right = endIndex[smaller[begin] / 10000] + 1;
				while (left < right)
				{
					int mid = (left + right) >> 1;
					if (smaller[mid] % 10000 <= c)
					{
						left = mid + 1;
					}
					else
					{
						right = mid;
					}
				}
				ans += endIndex[smaller[begin] / 10000] - left + 1;
				begin = endIndex[smaller[begin] / 10000] + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
