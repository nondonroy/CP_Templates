#define pb push_back 
vector<int> topSort(int n, vector<vector<int>> &adj) { 
 
    vector<int> indegree(n + 1, 0); 
    for(int i = 1; i <= n; i++) { 
        for(auto it : adj[i]) { 
            indegree[it]++; 
        } 
    } 
 
    queue<int> q; 
    for(int i = 1; i <= n; i++) { 
        if(indegree[i] == 0) q.push(i); 
    } 
 
    vector<int> ans; 
    while(!q.empty()) { 
 
        int node = q.front(); 
        q.pop(); 
 
        ans.pb(node); 
 
        for(auto it : adj[node]) { 
 
            indegree[it]--; 
            if(indegree[it] == 0) { 
                q.push(it); 
            } 
        } 
    } 
 
    return ans; 
}??
