const int N = 1e5 + 5;

vector<int> adj[N];

bool vis[N];
int level[N];
int par[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    par[s] = -1;
    level[s] = 0;

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        for(auto u : adj[v]) {
            if(vis[u]) continue;

            vis[u] = true;
            q.push(u);

            level[u] = level[v] + 1;
            par[u] = v;
        }
    }
}
