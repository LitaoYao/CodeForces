// https://codeforces.com/contest/1843/problem/C
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve()
{
	long long n;
	cin >> n;
	long long sum = 0;
	while(n > 0)
	{
		sum += n;
		n /= 2;
	}
	cout << sum << endl;
	return;
}
void fastRead()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
int main()
{
	fastRead();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
