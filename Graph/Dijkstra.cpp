#define ll long long int
const ll INF = 1e9;
ll n;
vector<ll> dist(n + 1, INF);
vector<ll> par(n + 1, -1);
vector<ll> dijkstra(ll n, vector<vector<pair<ll, ll>>> &adj, ll source){
  
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    dist[source] = 0;
    pq.push({0, source});
    vector<bool> vis(n + 1);

    while (!pq.empty()){

        ll d = pq.top().first;
        ll node = pq.top().second;

        pq.pop();

        if (vis[node]) continue;
        vis[node] = true;

        for (auto it : adj[node]){

            ll adjNode = it.first;
            ll edgeWeight = it.second;

            if (dist[node] + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dist[node] + edgeWeight;
                pq.push({dist[adjNode], adjNode});
                par[adjNode] = node;
            }
        }
    }

    return dist;
}

vector<ll> findPath(ll src, ll des) {
    vector<ll> path;
    if(dist[des] == INF) return path;

    ll cur = des;
    while(cur != -1) {
        path.push_back(cur);
        cur = par[cur];
    }
    reverse(path.begin(), path.end());
    return path;
}
// not worked in negative edge
