#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int diff(string a, string b, int m)
{
	int step = 0;
	for (int i = 0; i < m; ++i)
	{
		step += abs(a[i] - b[i]);
	}
	return step;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n;
		cin >> m;
		vector<string> words(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> words[i];
		}
		int ans = INT_MAX;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				ans = min(ans, diff(words[i], words[j], m));
			}
		}
		cout << ans << endl;
	}
	return 0;
}
