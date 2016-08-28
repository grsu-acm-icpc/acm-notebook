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

double sqr(double x) {
    return x * x;
}

struct point {
    double x, y;

    point(double x = 0, double y = 0) {
        this->x = x;
        this->y = y;
    }

    point operator + (const point &o) const {
        return point(x + o.x, y + o.y);
    }

    point operator - (const point &o) const {
        return point(x - o.x, y - o.y);
    }

    point operator * (const double &o) const {
        return point(x * o, y * o);
    }

    double operator * (const point &o) const {
        return x * o.y - o.x * y;
    }

    double operator % (const point &o) const {
        return x * o.x + y * o.y;
    }

    double length() {
        return sqrt(sqr(x) + sqr(y));
    }

    point setLength(double l) {
        double _l = length();
        return point(x * l / _l, y * l / _l);
    }

    point rotate(double angle) {
        double _x = x * cos(angle) - y * sin(angle);
        double _y = x * sin(angle) + y * cos(angle);
        return point(_x, _y);
    }

    void read() {
        scanf("%lf%lf", &x, &y);
    }

    void print() {
        printf("%.15lf %.15lf", x, y);
    }
};

const double eps = 1e-9;
int cmp(double a, double b) {
    if (fabs(a - b) < eps) return 0;
    if (a > b) return 1;
    return -1;
}

void doh(int ans = 0) {
    printf("%d\n", ans);
    exit(0);
}

int calc(vector<point> pts, point origin, double R) {
    int ans = 0;
    forn(iter, sz(pts)) {
        point current = pts[iter];
        ans += cmp((current - origin).length(), R) <= 0;
    }
    return ans;
}

void solve () {
    int n;
    cin >> n;
    vector<point> pts(n);
    forn(iter, n) pts[iter].read();
    double r, R;
    cin >> R >> r;
    if (cmp(R, r) < 0) doh(0);
    R -= r;
    int ans = 1;
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j) {
            double d = (pts[i] - pts[j]).length();
            if (cmp(d, 2 * R) == 1) continue;
            r = d / 2;
            double h = sqrt(sqr(R) - sqr(r));
            point ab = pts[i] - pts[j];
            point nab1 = ab.rotate(PI / 2);
            point nab2 = ab.rotate(-PI / 2);
            point m = pts[j] + ab.setLength(r);

            point cand1 = m + nab1.setLength(h);
            point cand2 = m + nab2.setLength(h);

            int curans1 = calc(pts, cand1, R);
            int curans2 = calc(pts, cand2, R);

            ans = max(ans, curans1);
            ans = max(ans, curans2);
        }
    doh(ans);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();
#ifdef _DEBUG
    cout << fixed << setprecision(15) << clock() * 1. / CLOCKS_PER_SEC;
#endif
    return 0;
}
