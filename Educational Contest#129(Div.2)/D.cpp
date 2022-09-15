// https://codeforces.com/contest/1681/problem/D
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;
vector<int> getDigits(unsigned long long x, int& length)
{
	vector<int> allDigits(10, 0);
	while (x != 0)
	{
		++allDigits[x % 10];
		x /= 10;
		++length;
	}
	return allDigits;
}
void solve()
{
	int n;
	unsigned long long x;
	cin >> n >> x;
	if (x == 1 && n > 1)
	{
		cout << -1 << endl;
	}
	else
	{
		priority_queue<unsigned long long> q;
		q.push(x);
		int ans = 0;
		while (!q.empty())
		{
			int qSize = q.size();
			set<unsigned long long> nexts;
			while(qSize--)
			{
				unsigned long long now = q.top();
				q.pop();
				int digitLength = 0;
				vector<int> allDigits = getDigits(now, digitLength);
				if (digitLength == n)
				{
					cout << ans << endl;
					return;
				}
				for (unsigned long long digit = 9; digit >= 2; --digit)
				{
					if (allDigits[digit] <= 0)
					{
						continue;
					}
					unsigned long long next = now * digit;
					int nextDigitLength = 0;
					getDigits(next, nextDigitLength);
					if (nextDigitLength == n)
					{
						cout << ans + 1 << endl;
						return;
					}
					nexts.insert(next);
				}
			}
			for (unsigned long long next : nexts)
			{
				q.push(next);
			}
			++ans;
		}
		cout << -1 << endl;
	}
	return;
}
int main()
{
	int t;
	t = 1;
	while (t--)
	{
		solve();
	}
	return 0;
}
