#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve()
{
	long long n, m;
	cin >> n >> m;
	long long x, p;
	map<long long, long long> rains;
	vector<pair<long long, long long> > allRains;  
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> p;
		allRains.push_back({x, p});
		rains[x - p] += 1;
		rains[x] -= 2;
		rains[x + p] += 1;
	}
	long long x1, p1 = LLONG_MIN;
	long long x2, p2 = LLONG_MIN;
	long long nowRain = 0;
	long long lastRain = 0;
	long long lastPos = rains.begin()->first;
	for (auto& iter : rains)
	{
		x = iter.first;
		p = iter.second;
		nowRain = nowRain + (x - lastPos) * lastRain;
		lastRain = lastRain + p;
		lastPos = x;
		if (nowRain > m)
		{
			if (nowRain - m - x > p1)
			{
				x1 = x;
				p1 = nowRain - m - x;
			}
			if (nowRain - m + x >= p2)
			{
				x2 = x;
				p2 = nowRain - m + x;
			}
		}
	}
	string ans = "";
	for (int i = 0; i < n; ++i)
	{
		x = allRains[i].first;
		p = allRains[i].second;
		if (x >= x1 && p - x < p1)
		{
			ans += "0";
		}
		else if (x <= x2 && p + x < p2)
		{
			ans += "0";
		}
		else
		{
			ans += "1";
		}
	}
	cout << ans << endl;
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
