// This task about finding first positive pair (X, Y), which satisfy conditions:
// A * X + B * Y = C, X >= 1, Y >= 1, A >= 2, B <= -2, C >= 1, C - is a multiple of gcd(A, B)

#include <bits/stdc++.h>
#include <ctime>
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef string str;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef set <int> si;
typedef map <int, int> mii;
typedef pair <double, double> pdd;
typedef pair <ll, ll> pll;

#define fi first
#define se second
#define space ' '
#define enter endl
#define forn(i, n) for(int i = 0; i < n; ++i)
#define INF 1e+9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define X first
#define Y second
#define ms(x) memset(x, 0, sizeof(x))
#define ms1(x) memset(x, -1, sizeof(x))
#define sz(x) ( (int) x.size() )
#define len(x) ( (int) x.length() )
#define ALL(x) x.begin(), x.end()

ll gcd(ll a, ll b) {
	while(b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

pll exgcd(ll a, ll b) {
	ll A = a, B = b;

	ll x1 = 1, y1 = 0, x2 = 0, y2 = 1;

	while(b) {
		ll q = a / b;
		a = a - q * b;
		swap(a, b);

		x1 = x1 - q * x2;
		swap(x1, x2);

		y1 = y1 - q * y2;
		swap(y1, y2);
	}

	if (x1 * A + y1 * B < 0) x1 *= -1, y1 *= -1;

	return mp(x1, y1);
}

void solve() {
	ll a, b, c;
	cin >> a >> b >> c;
	ll _gcd = gcd(abs(a), abs(b));

	pll cord = exgcd(a, b);

	cord.X *= c / _gcd;
	cord.Y *= c / _gcd;

	pll v = mp(-b / _gcd, a / _gcd);

	ll l = -2e+8, r = 2e+8;

	while(r - l > 1) {
		ll middle = (l + r) / 2;
		ll val1 = cord.X + middle * v.X;
		ll val2 = cord.Y + middle * v.Y;
		if (val1 >= 1 && val2 >= 1)
			r = middle;
		else
			l = middle;
	}

	pll ans = mp(cord.X + r * v.X, cord.Y + r * v.Y);

	cout << ans.X << " " << ans.Y << endl;
}

int main() {
	solve();
	return 0;
}

