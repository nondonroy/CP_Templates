#define ll long long int
const ll INF = 1e15;

vector<ll> bellmanFord(ll source, vector<vector<ll>> &edges) {
    vector<ll> dist(n + 1, INF);

    dist[source] = 0;

    for(ll i = 0; i < n - 1; i++) {
        for(auto it : edges) {
            ll u = it[0];
            ll v = it[1];
            ll wt = it[2];

            if(dist[u] == INF) continue;

            if(dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    return dist;
}
//SPSP - worked in negative edges
// O(VE)
/* in n'th iteration if the distance reduced then
there exist negative cycle */
