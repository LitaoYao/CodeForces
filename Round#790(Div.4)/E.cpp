// https://codeforces.com/contest/1676/problem/E
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
		if (array[mid] < x)
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
		int n, q;
		cin >> n;
		cin >> q;
		vector<int> candies(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> candies[i];
		}
		sort(candies.begin(), candies.end());
		vector<int> sum(n, 0);
		sum[0] = candies[n - 1];
		for (int i = n - 2; i >= 0; --i)
		{
			sum[n - i - 1] = sum[n - i - 2] + candies[i];
		}
		for (int j = 0; j < q; ++j)
		{
			int x;
			cin >> x;
			int index = findIndex(sum, x);
			if (index >= n)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << index + 1 << endl;
			}
		}
	}
	return 0;
}
