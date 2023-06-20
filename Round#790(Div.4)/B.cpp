// https://codeforces.com/contest/1676/problem/B
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
		vector<int> candies(n);
		int minCount = INT_MAX;
		for (int i = 0; i < n; ++i)
		{
			cin >> candies[i];
			minCount = min(candies[i], minCount);
		}
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			ans += candies[i] - minCount;
		}
		cout << ans << endl;
	}
	return 0;
}
