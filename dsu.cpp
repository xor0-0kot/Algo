#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), r.end();
#define srt(a) sort(a.begin(), a.end());
#define srtr(a) sort(a.rbegin(), a.rend());
 
constexpr int mXN = 2e5 + 5, inf = INT_MAX - 100, mod = 1e9 + 7;
constexpr double eps = 1e-8; 
 
struct dsu {
    vector<int> p, sz;
    dsu() {}
    dsu(int n) {
        p.resize(n), sz.resize(n);
        for(int i=0; i<n; ++i) {
            p[i] = i;
            sz[i] = 1;
        }
    }

    int get(int u) {
        if(p[u] == u) {
            return u;
        } else return p[u] = get(p[u]);
    }

    bool check(int u, int v) {
        return get(u) == get(v);
    }

    void upd(int u, int v) {
        u = get(u);
        v = get(v);
        if(u == v) {
            return;
        }
        if(sz[u] > sz[v]) {
            swap(u, v);
        }
        p[u] = p[v];
        sz[v] += sz[u];
    }
};

struct Edge{
    int u, v, w;
    Edge() {}
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
};

vector<Edge> gr;

inline bool operator<(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

int n, m;

void test_case() {
    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        gr.push_back(Edge(u-1, v-1, w));
    }
    dsu d(n);
    sort(all(gr));
    int res =  0;
    for(auto& e : gr) {
        if(!d.check(e.u, e.v)) {
            d.upd(e.u, e.v);
            res += e.w;
        }
    }
    cout << res << '\n';
}
 
signed main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_cases = 1;
//    cin >> test_cases;
    while(test_cases--) {
        test_case();    
    }
}