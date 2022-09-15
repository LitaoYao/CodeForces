// https://codeforces.com/contest/1681/problem/C
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> sortedA(n);
	vector<int> sortedB(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sortedA[i] = a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
		sortedB[i] = b[i];
	}
	sort(sortedA.begin(), sortedA.end());
	sort(sortedB.begin(), sortedB.end());
	bool possible = true;
	vector<int> operations;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] != sortedA[i] || b[i] != sortedB[i])
		{
			bool swappable = false;
			for (int j = i + 1; j < n; ++j)
			{
				if (a[j] == sortedA[i] && b[j] == sortedB[i])
				{
					operations.push_back(j * 1000 + i);
					swap(a[i], a[j]);
					swap(b[i], b[j]);
					swappable = true;
					break;
				}
			}
			if (!swappable)
			{
				possible = false;
				break;
			}
		}
	}
	if (!possible)
	{
		cout << -1 << endl;
	}
	else
	{
		int operationSize = operations.size();
		cout << operationSize << endl;
		for (int i = 0; i < operationSize; ++i)
		{
			cout << operations[i] / 1000 + 1 << " " << operations[i] % 1000 + 1 << endl;
		}
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
