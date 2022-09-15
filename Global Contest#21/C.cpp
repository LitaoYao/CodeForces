// https://codeforces.com/contest/1696/problem/C
#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;
void solve()
{
	int n, m, k;
	cin >> n >> m;
	vector<pair<int, long long>> aFinal;
	int x;
	long long suma = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		suma += x;
		int t = x;
		if (x % m == 0)
		{
			while (t % m == 0)
			{
				t /= m;
			}
		}
		aFinal.push_back({t, x / t});
	}
	cin >> k;
	vector<pair<int, long long>> bFinal;
	long long sumb = 0;
	for (int i = 0; i < k; ++i)
	{
		cin >> x;
		sumb += x;
		int t = x;
		if (x % m == 0)
		{
			while (t % m == 0)
			{
				t /= m;
			}
		}
		bFinal.push_back({t, x / t});
	}
	bool valid = true;
	if (suma != sumb)
	{
		valid = false;
	}
	else
	{
		int i = 0;
		int j = 0;
		int aSize = aFinal.size();
		int bSize = bFinal.size();
		while (i < aSize || j < bSize)
		{
			int numa = aFinal[i].first;
			long long counta = 0;
			while (i < aSize && aFinal[i].first == numa)
			{
				counta += aFinal[i].second;
				++i;
			}
			int numb = bFinal[j].first;
			long long countb = 0;
			while (j < bSize && bFinal[j].first == numb)
			{
				countb += bFinal[j].second;
				++j;
			}
			if (numa != numb || counta != countb)
			{
				valid = false;
				break;
			}
		}
	}
	if (valid)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
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

