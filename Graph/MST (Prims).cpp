int prims(int n, vector<vector<pair<int, int>>> &adj) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(n + 1, 0);

    pq.push({0, 1});
    int tmst = 0;

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int wt = it.first;

        if (vis[node]) continue;

        vis[node] = 1;
        tmst += wt;

        for (auto it : adj[node]) {
            if (!vis[it.first]) {
                pq.push({it.second, it.first});
            }
        }
      
    }

    return tmst;
}
// adj: first -> node , second -> wt
// pq: first -> wt , seconf -> node
