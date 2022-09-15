// https://codeforces.com/contest/1676/problem/H1
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
		vector<int> endPoints(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> endPoints[i];
		}
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (endPoints[i] >= endPoints[j])
				{
					++ans;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
