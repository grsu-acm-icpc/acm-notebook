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

template <typename T>
T gcd (T a, T b) {
    return b ? gcd(b, a % b) : a;
}

const int MAXN = 100500;

char memory[MAXN * 300], *pointer = memory;

void *operator new (size_t c) {
    void *ans = pointer;
    pointer += c;
    return ans;
}

void operator delete (void *p) {
}

struct sparse_table {
    vector<vector<int> > table;
    vector<int> pows;

    int getSize(int size) {
        int res = 0;
        while((1 << res) < size) res++;
        return res;
    }

    sparse_table(vector<int> &arr, int inf) {
        int n = sz(arr);
        int lg2 = getSize(sz(arr));

        table = vector<vector<int> > (lg2 + 1, vector<int>(sz(arr), inf));
        pows = vector<int> (1 << (lg2 + 1));

        forn(i, sz(arr)) table[0][i] = arr[i];

        for(int i = 0; i < lg2 - 1; ++i) {
            for(int j = 0; j < n; ++j) {
                int l = j, r = j + (1 << i);
                if (r >= n) r = l;
                table[i + 1][j] = max(table[i][l], table[i][r]);
            }
        }

        for(int i = 1; i < sz(pows); ++i) {
            pows[i] = pows[i - 1];
            if ((1 << pows[i]) * 2 < i) pows[i]++;
        }
    }

    int query(int l, int r) {
        int lg2 = pows[r - l + 1];
        return max(table[lg2][l], table[lg2][r - (1 << lg2) + 1]);
    }
};

void solve () {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    forn(iter, n) scanf("%d", &arr[iter]);
    sparse_table table = sparse_table(arr, 0);
    ll m, r, R;
    cin >> m >> r >> R;
    ll ans = 0;
    forn(iter, m) {
        ll H = table.query(r, R);
        ans += H;
        r = (r * H + H * H);
        if (r >= n) r %= n;
        if (r > R) swap(r, R);
    }
    cout << ans << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
    freopen("mushrooms.in", "r", stdin);
    freopen("mushrooms.out", "w", stdout);
#endif
    solve();
#ifdef _DEBUG
    cout << fixed << setprecision(15) << clock() * 1. / CLOCKS_PER_SEC;
#endif
    return 0;
}
