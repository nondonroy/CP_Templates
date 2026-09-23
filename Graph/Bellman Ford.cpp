#define ll long long int
const ll INF = 1e9;

ll n;
vector<ll> dist(n + 1, INF);
vector<ll> par(n + 1, -1);
vector<ll> bellmanFord(ll source, vector<vector<ll>> &edges) {
    dist[source] = 0;

    for(ll i = 0; i < n - 1; i++) {
        for(auto it : edges) {
            ll u = it[0];
            ll v = it[1];
            ll wt = it[2];

            if(dist[u] == INF) continue;

            if(dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                par[v] = u;
            }
        }
    }
    return dist;
}
vector<ll> findPath(ll source, ll des) {
    vector<ll> path;
    
    if(dist[des] == INF) // no path
        return path;
    
    path.push_back(des);
    ll cur = des;
    while(cur != source) {
        path.push_back(par[cur]);
        cur = par[cur];
    }
    reverse(path.begin(), path.end());
    return path;
}
//SPSP - worked in negative edges
// O(VE)
/* in n'th iteration if the distance reduced then
there exist negative cycle */
