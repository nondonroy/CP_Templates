int timer = 0;
vector<pair<int, int>> bridges;

void dfs(int v, int p, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &tin, vector<int> &low) {
    tin[v] = low[v] = ++timer;
    vis[v] = true;
    for(auto child: adj[v]) {
        if(child == p) continue;

        if (vis[child]){
            low[v] = min(low[v], tin[child]);
            continue;
        }
      
        dfs(child, v, vis, adj, tin, low);
      
        low[v] = min(low[v], low[child]);
        if (low[child] > tin[v]) {
            bridges.push_back({min(v, child), max(v, child)});
        }
    }
}
  
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<bool> vis(n + 1, false);
    vector<int> low(n + 1, 1e9);
    vector<int> tin(n + 1);
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i, -1, vis, adj, tin, low);
        }
    }

    cout << bridges.size() << endl;
    for(auto x: bridges) {
        cout << x.first << " " << x.second << endl;
    }
    timer = 0;
    bridges.clear();
}
