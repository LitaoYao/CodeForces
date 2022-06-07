#include <iostream>
#include <vector>
#include <string>
using namespace std;
void solve()
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> count(n, 0);
	for (int i = 0; i < k; ++i)
	{
		if (s[i] == 'B')
		{
			count[i] = 1;
		}
		if (i > 0)
		{
			count[i] += count[i - 1];
		}
	}
	for (int j = k; j < n; ++j)
	{
		if (s[j] == 'B')
		{
			count[j] = 1;
		}
		if (s[j - k] == 'B')
		{
			count[j] -= 1; 
		}
		count[j] += count[j - 1];
	}
	int ans = INT_MAX;
	for (int i = k - 1; i < n; ++i)
	{
		ans = min(ans, k - count[i]);
	}
	cout << ans << endl;
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

