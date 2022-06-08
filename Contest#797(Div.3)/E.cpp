#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solve()
{
	long long n, k;
	cin >> n >> k;
	vector<int> a(n);
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		ans += a[i] / k;
		a[i] %= k;
	}
	sort(a.begin(), a.end());
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
	    while (left < right && a[left] + a[right] < k) ++left;
	    if (left < right && a[left] + a[right] >= k)
	    {
	        ++ans;
	    }
	    ++left;
	    --right;
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
