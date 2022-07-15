#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
void solve()
{
	int n, c, q;
	string str;
	cin >> n >> c >> q;
	cin >> str;
	vector<long long> curLen(c + 1);
	vector<long long> L(c + 1);
	curLen[0] = n;
	long long l, r;
	for (int i = 0; i < c; ++i)
	{
		cin >> l >> r;
		curLen[i + 1] = curLen[i] + r - l + 1;
		L[i + 1] = l - 1;
	}
	long long k;
	for (int i = 0; i < q; ++i)
	{
		cin >> k;
		k = k - 1;
		while (k >= n)
		{
			int index = upper_bound(curLen.begin(), curLen.end(), k) - curLen.begin();
			k = L[index] + k - curLen[index - 1];
		}
		cout << str[k] << endl;
	}
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
