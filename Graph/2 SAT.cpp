#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'
#define pb push_back

int N;

vector<bool> vis, value;
vector<int> order, comp;
vector<vector<int>> adj, adjT;

void dfs1(int u) {
    vis[u] = true;

    for(auto v : adj[u]) {
        if(!vis[v]) {
            dfs1(v);
        }
    }

    order.push_back(u);
}

void dfs2(int u, int cnt) {
    comp[u] = cnt;

    for(auto v : adjT[u]) {
        if(!comp[v]) {
            dfs2(v, cnt);
        }
    }
}

void Kosaraju() {
    for(int i = 0; i < 2 * N; i++) {
        if(!vis[i]) {
            dfs1(i);
        }
    }

    reverse(order.begin(), order.end());

    int cnt = 1;

    for(auto u : order) {
        if(!comp[u]) {
            dfs2(u, cnt++);
        }
    }
}

bool assignment() {
    Kosaraju();

    for(int i = 0; i < N; i++) {

        // x and !x belong to same SCC -> impossible
        if(comp[i] == comp[i + N]) {
            return false;
        }

        value[i] = comp[i] < comp[i + N] ? 0 : 1;
    }

    return true;
}

void addDisjunction(int a, bool pos_a, int b, bool pos_b) {
    // (a V b)

    int neg_a = a + N;
    int neg_b = b + N;

    if(!pos_a) swap(a, neg_a);
    if(!pos_b) swap(b, neg_b);

    // (!a -> b)
    // (!b -> a)
    adj[neg_a].pb(b);
    adj[neg_b].pb(a);

    // Transpose graph
    adjT[b].pb(neg_a);
    adjT[a].pb(neg_b);
}

void init(int n) {
    N = n;

    vis.assign(2 * N, false);
    value.assign(N, false);

    order.clear();
    comp.assign(2 * N, 0);

    adj.assign(2 * N, {});
    adjT.assign(2 * N, {});
}

void solve() {
    int n, m;
    cin >> n >> m;

    init(n);
    // Example:
    // addDisjunction(0, true, 1, false);
    // means (x0 V !x1)

    for(int i = 0; i < m; i++) {
        int a, b;
        bool pos_a, pos_b;

        cin >> a >> pos_a >> b >> pos_b;

        addDisjunction(a, pos_a, b, pos_b);
    }

    if(!assignment()) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for(int i = 0; i < N; i++) {
        cout << value[i] << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
