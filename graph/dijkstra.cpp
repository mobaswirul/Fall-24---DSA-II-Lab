#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];

    for(int i = 0; i < m; i++){
        int from, to, weight;
        cin >> from >> to >> weight;
        adj[from].push_back({to, weight});
        adj[to].push_back({from, weight});
    }

    int source;
    cin >> source;


    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    vector<bool> visited(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    int count = 0;

    while(count < n){
        auto pp = pq.top();
        pq.pop();
        int current_node = pp.second;
        int current_dist = pp.first;
        if(visited[current_node]) continue;

        int sz = adj[current_node].size();
        for(int i = 0; i < sz; i++){
            int next_node = adj[current_node][i].first;

            if(visited[next_node]) continue;

            int next_total_cost = current_dist + adj[current_node][i].second;

            if(next_total_cost < dist[next_node]){
                dist[next_node] = next_total_cost;
                pq.push({next_total_cost, next_node});
            }
        }
        
        visited[current_node] = true;
        count++;
    }

    for(int i = 0; i < n; i++){
        cout << "Distance from " << source << " to " << i << " is " << dist[i] << endl;
    }
}