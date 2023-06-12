// https://codeforces.com/contest/1840/problem/B
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int K = 32;
// count of selection
vector<long long> sigma(K, 0);
// preCost of pre k
vector<long long> preCost(K, 0);

long long dfs(long long n, long long k)
{
	auto iter = upper_bound(preCost.begin(), preCost.end(), n);
	int index = min(iter - preCost.begin(), k);
	if (index == 0)
	{
		// if not enough for min preCost, return 1 means empty selection
		return 1;
	}
	// first we can buy all from 0 ~ index - 1, add the count of selection
	long long ans = sigma[index - 1];
	if (n > preCost[index - 1])
	{
		// if still left money after buy index, dfs to solve it.
		// remind that the cost of index is preCost[index - 1] + 1
		ans += dfs(n - preCost[index - 1] - 1, k);
	}
	return ans;
}

void solve()
{
	long long n, k;
	cin >> n >> k;
	if (k <= K && n > preCost[k - 1])
	{
		n = preCost[k - 1];
	}
	cout << dfs(n, k) << endl;
}

int main()
{
	sigma[0] = 2;
	preCost[0] = 1;
	for (int i = 1; i < K; ++i)
	{
		sigma[i] = sigma[i - 1] * 2;
		preCost[i] = preCost[i - 1] * 2 + 1;
	}
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
