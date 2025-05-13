#include <bits/stdc++.h>

#define range(i, x, n) for(i = x; i < n; i++)
#define piii pair<size_t,pair<int,int>>
#define oo 410'000'000'000
#define MAX 1'000'000'000'000

using namespace std;

typedef struct edge{
    int target,
        weight;
        edge(int t, int w){
            target = t;
            weight = w;
        }
}edge;

typedef vector<vector<edge>> graph;

int cantor(int xx, int yy){
    int x, y;
    (xx > yy) ? x = xx : x = yy;
    (x == xx) ? y = yy : y = xx;
    return (x + y)*(x + y + 1)/2 + y;
}

void dijkstra(graph& G, int s, unordered_map<int,size_t>& path_found, int n, priority_queue<size_t>& all_paths, int& size){
    vector<size_t> dist(G.size(), oo);
    vector<bool> prev_known(n + 1, false);
    priority_queue<pair<long long, int>> pq;
    int count = n, pathc = 0;
    int i;
     range(i, 1, n + 1){
         auto it = path_found.find(cantor(s, i));
         if(it != path_found.end()){
             dist[i] = (*it).second;
             pq.push({-(*it).second, i});
             count--;
             prev_known[i] = true;
         }
     }
    pq.push({0, s});
    while(!pq.empty() && count > 0){
        size_t shortest = -pq.top().first,
            u = pq.top().second;

        pq.pop();
        if(size >= 400 && all_paths.top() < shortest)
            continue;
        if(dist[u] < oo && !prev_known[u] && u != s)
            continue;
        if(prev_known[u] && !(dist[u] == shortest)){
            continue;
        }
        dist[u] = shortest;
        pathc++;
        if(!prev_known[u]){
            count--;
        }
        if(path_found.find(cantor(s, u)) == path_found.end()){
            path_found[cantor(s, u)] = shortest;
            all_paths.push(shortest);
            size++;
            if(size > 400){
                all_paths.pop();
                size--;
            }
        }
        for(edge adj: G[u]){
            if(dist[adj.target] < oo)
                continue;

            size_t d;
            if(dist[u] + adj.weight > oo)
                continue;
            d = dist[u] + adj.weight;
            if(dist[adj.target] > d)
                pq.push({-d, adj.target});
        }
    }
}

size_t kth_smallest_path(graph& G, int n, int k){
    priority_queue<size_t> all_dist;
    int i, size = 0;
    unordered_map<int,size_t> path_found;
    range(i, 1, n + 1)
        path_found[cantor(i,i)] = 0;
    range(i, 1, n + 1){
        dijkstra(G, i, path_found, n, all_dist, size);
    }
    range(i, 0, size - k){
        all_dist.pop();
    }
    size_t x = all_dist.top();
    return x;
}

int main(){
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    graph G(n + 1);
    int i;
    range(i, 0, m){
        int x, y, w;
        cin >> x >> y >> w;
        G[x].emplace_back(y, w);
        G[y].emplace_back(x, w);
    }
    cout << kth_smallest_path(G, n, k) << '\n';

    return 0;
}