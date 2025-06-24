#include <iostream>
using namespace std;
const long long mod = 1e9 + 7;
long long multiple(long long a, long long b)
{
	return (a * b) % mod;
}
long long add(long long a, long long b)
{
	return (a + b) % mod;
}
long long power(long long a, long long b)
{
	long long res = 1;
	while (b)
	{
		if (b & 1)
			res = multiple(res, a);
		a = multiple(a, a);
		b >>= 1;
	}
	return res;
}
void init()
{
	return;
}
void solve()
{
	long long a, b, k;
	cin >> a >> b >> k;
	// pigeonhole principle for n
	long long n = add(multiple(k, a - 1), 1);
	// pigeonhole principle for m
	// m = (b - 1) * k * C(n, a) + 1
	// Fermat's little theorem: a ^ (p - 1) % p = 1
	// modular inverse: a * a ^ (p - 2) % p = 1
	// then (1 / a) % p = a ^ (p - 2) % p
	// so C(n, a) % p = n! / (a! * (n - a)!) % p
	// C(n, a) % p = n * (n - 1) * ... * (n - a + 1) / (a * (a - 1) * ... * 1) % p
	// C(n, a) % p = n * (n - 1) * ... * (n - a + 1) * (a ^ (p - 2)) * ... * (1 ^ (p - 2)) % p
	long long m = multiple(b - 1, k);
	for (long long i = 0; i < a; ++i)
	{
		m = multiple(m, n - i);
		m = multiple(m, power(i + 1, mod - 2));
	}
	m = add(m, 1);
	cout << n << " " << m << endl;
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
	init();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
