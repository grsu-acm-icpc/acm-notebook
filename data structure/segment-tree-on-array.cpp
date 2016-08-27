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

struct node {
    int val;
    int l, r;

    node(int val = 0, int l = -1, int r = -1) {
        this->l = l;
        this->r = r;
        this->val = val;
    }
};

struct segment_tree {
private:
    vector<int> arr;
    vector<node> tree;
    int ptr = -1;

    inline int recalc(int v) {
        tree[v].val = max(tree[tree[v].l].val, tree[tree[v].r].val);
        return v;
    }

    inline int addNode(int val, int l = -1, int r = -1) {
        tree[++ptr] = node(val, l, r);
        return ptr;
    }

    inline int build(int l, int r) {
        if (l == r) return addNode(arr[l]);
        int middle = (l + r) >> 1;
        return recalc(addNode(-1, build(l, middle), build(middle + 1, r)));
    }

    inline int _query(int v, int l, int r, int L, int R) {
        if (L <= l && r <= R) return tree[v].val;
        if (l > R || L > r) return 0;
        int middle = (l + r) >> 1;
        int valL = _query(tree[v].l, l, middle, L, R);
        int valR = _query(tree[v].r, middle + 1, r, L, R);
        return max(valL, valR);
    }

public:
    segment_tree(vector<int> &arr) {
        this->arr = arr;
        tree.resize(4 * sz(arr));
        build(0, sz(arr) - 1);
    }

    int query(int l, int r) {
        return _query(ptr, 0, sz(arr) - 1, l, r);
    }

};

void solve () {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    forn(iter, n) scanf("%d", &arr[iter]);
    segment_tree tree = segment_tree(arr);
    ll m, r, R;
    cin >> m >> r >> R;
    ll ans = 0;
    forn(iter, m) {
        ll H = tree.query(r, R);
        r = r * H + H * H;
        r %= n;
        if (r > R) swap(r, R);
        ans += H;
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
