#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 4e18;         

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<ll>> dist(n, vector<ll>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }


    vector<int> x(n);
    for (int &v : x) {
        cin >> v;
        --v;          
    }

    vector<ll> answers;        
    vector<char> alive(n, 0);  

    for (int t = n - 1; t >= 0; --t) {
        int k = x[t];
        alive[k] = 1;
        
        //Floyd-Warshall
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        ll sum = 0;
        for (int i = 0; i < n; ++i) if (alive[i])
            for (int j = 0; j < n; ++j) if (alive[j])
                sum += dist[i][j];

        answers.push_back(sum);
    }

    for (int i = n - 1; i >= 0; --i) {
        cout << answers[i] << (i ? ' ' : '\n');
    }
    return 0;
}
