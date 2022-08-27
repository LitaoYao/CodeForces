#include <iostream>
#include <vector>
#include <map>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<long long> a(n);
	vector<long long> b(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}
	long long ans = 0;
	for (int bit = 31; bit >= 0; --bit)
	{
		long long tmp = ans | (1 << bit);
		map<long long, int> counts;
		for (int i = 0; i < n; ++i)
		{
			counts[b[i] & tmp]++;
		}
		bool valid = true;
		for (int i = 0; i < n; ++i)
		{
			long long x = (a[i] & tmp) ^ tmp;
			if (counts.count(x) && counts[x] > 0)
			{
				--counts[x];
			}
			else
			{
				valid = false;
				break;
			}
		}
		if (valid)
		{
			ans = tmp;
		}
	}
	cout << ans << endl;
	return;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
