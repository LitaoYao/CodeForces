#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<long long> a(n);
	vector<long long> b(n);
	vector<long long> dmin(n);
	vector<long long> dmax(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}
	for (int i = 0; i < n; ++i)
	{
		int index = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		dmin[i] = b[index] - a[i];
	}
	int index = 0;
	for (int i = 0; i < n; ++i)
	{
		while (index < n && (index <= i || b[index - 1] >= a[index]))
		{
			++index;
		}
		dmax[i] = b[index - 1] - a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cout << dmin[i] << " \n"[i == n - 1];
	}
	for (int i = 0; i < n; ++i)
	{
		cout << dmax[i] << " \n"[i == n - 1];
	}
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
