#include <bits/stdc++.h>
#define range(i, x, n) for(i = x; i < n; i++)
#define pii pair<long long, long long>
#define ll long long
#define oo LLONG_MAX

using namespace std;

typedef struct edge{
    ll target,
        weight;
    edge(ll t, ll w){
        target = t;
        weight = w;
    }
}edge;

typedef vector<pair<ll, vector<edge>>> graph;

vector<ll> dijkstra(graph& G, int s, int n){
    vector<ll> dist(n + 1, oo);
    priority_queue<pair<ll, int>> pq;
    ll count = 0;
    pq.push({0, s});
    while(!pq.empty() && count < n){
        ll shortest = -pq.top().first,
            u = pq.top().second;
        pq.pop();
        if(dist[u] < oo)
            continue;
        dist[u] = shortest + G[u].first;
        count++;
        for(edge adj: G[u].second){
            if(dist[adj.target] < oo)
                continue;
            ll d = dist[u] + adj.weight;
            pq.push({-d, adj.target});
        }

    }
    return dist;
}

int main(){
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    graph G(n + 1);
    int i;
    range(i, 1, n+1){
        cin >> G[i].first;
    }
    range(i, 0, m){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].second.emplace_back(v, w);
        G[v].second.emplace_back(u, w);
    }
    vector<ll> ans = dijkstra(G, 1, n);
    range(i, 2, n + 1)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}