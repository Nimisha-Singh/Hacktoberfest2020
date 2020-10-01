#include<bits/stdc++.h>

using namespace std;

#define pb push_back

void Dijkstra(int source, int n, vector<pair<int, int>> &v(1001),int &dis[1001],bool &vis[1001])
{
    for (int i = 0; i < 1001; i++)
        dis[i] = INT_MAX;
    class prioritize
    {
    public:
        bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
            return p1.second > p2.second; 
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, prioritize> pq;
    pq.push(make_pair(source, dis[source] = 0));
    while (!pq.empty())
    {
        pair<int, int> curr = pq.top();
        pq.pop();
        int cv = curr.first, cw = curr.second;
        if (vis[cv])
            continue;
        vis[cv] = true;
        for (int i = 0; i < v[cv].size(); i++)
            if (!vis[v[cv][i].first] && v[cv][i].second + cw < dis[v[cv][i].first])
                pq.push(make_pair(v[cv][i].first, (dis[v[cv][i].first] = v[cv][i].second + cw)));
    }
}


int main()
{
    vector<pair<int, int>> v(1001); 
    int dis[1001];                  
    bool vis[1001] = {0};
    int n, m, x, y, w;
    cout << "Enter number of vertices and edges in the graph\n";
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        v[x].pb(make_pair(y, w));
        v[y].pb(make_pair(x, w));
    }
    int s;
    cin >> s;
    Dijkstra(s, n,v,dis,vis);
    cout << "Source is: " << s << ". The shortest distance to every other vertex from here is: \n";
    for (int i = 1; i <= n; i++)
    {
        cout << "Vertex: " << i << " , Distance: ";
        dis[i] != INT_MAX ? cout << dis[i] << "\n" : cout << "-1\n";
    }
    return 0;
}
