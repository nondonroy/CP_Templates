const int N = 1e5 + 5;

vector<int> rnk(N, 0);
vector<int> par(N);
vector<int> sz(N, 1);

int findpar(int node) {
    if (node == par[node]) return node;
    return par[node] = findpar(par[node]);
}

void unionByrank(int u, int v) {
    int ulp_u = findpar(u);
    int ulp_v = findpar(v);

    if (ulp_u == ulp_v) return;

    if (rnk[ulp_u] < rnk[ulp_v]) {
        par[ulp_u] = ulp_v;
    }
    else if (rnk[ulp_u] > rnk[ulp_v]) {
        par[ulp_v] = ulp_u;
    }
    else {
        par[ulp_v] = ulp_u;
        rnk[ulp_u]++;
    }
}

void unionBysize(int u, int v) {
    int ulp_u = findpar(u);
    int ulp_v = findpar(v);

    if (ulp_u == ulp_v) return;

    if (sz[ulp_u] < sz[ulp_v]) {
        par[ulp_u] = ulp_v;
        sz[ulp_v] += sz[ulp_u];
    }
    else {
        par[ulp_v] = ulp_u;
        sz[ulp_u] += sz[ulp_v];
    }
}

void solve() {
    for (int i = 0; i < N; i++) par[i] = i; // initialize parent

    int n, m;
    cin >> m;

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        edges.pb({wt, {u, v}});
    }

    sort(edges.begin(), edges.end());

    int tmst = 0;

    for (auto it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (findpar(u) != findpar(v)) {
            tmst += wt;
            unionBysize(u, v); // choose any way of union
        }
    }

    cout << tmst << endl;
}
