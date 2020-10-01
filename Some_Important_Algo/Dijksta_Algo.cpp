#include <bits/stdc++.h>
using namespace std;
#define forInc(i, a, b) for (ll i = a; i <= b; i++)
#define forDec(i, b, a) for (ll i = b; i >= a; i--)
#define inf LLONG_MAX
#define neginf LLONG_MIN
#define mod 1000000007
#define eps 1e-9
typedef long long ll;
typedef unsigned long long ull;

vector<ll> dis, parent;
vector<vector<ll>> graphedge, graphcost;
ll vertex, edges;
void dijkstra(ll source)
{
    dis[source] = 0;
    parent[source] = source;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({dis[source], source});
    while (!pq.empty())
    {
        pair<ll, ll> node = pq.top();
        pq.pop();
        if (graphedge[node.second].size())
        {
            forInc(i, 0, graphedge[node.second].size() - 1)
            {
                ll child = graphedge[node.second][i];
                ll edgecost = graphcost[node.second][i];
                if (edgecost + dis[node.second] < dis[child])
                {
                    dis[child] = edgecost + dis[node.second];
                    parent[child] = node.second;
                    pq.push(make_pair(dis[child], child));
                }
            }
        }
    }
}

int main()
{
    cout << "Enter number of vertex:\n";
    cin >> vertex;
    cout << "Enter number of edges\n";
    cin >> edges;
    ll node1, node2, weight;
    dis.clear();
    parent.clear();
    graphedge.clear();
    graphcost.clear();
    graphedge.resize(vertex + 5);
    graphcost.resize(vertex + 5);
    dis.resize(vertex + 5, inf);
    parent.resize(vertex + 5, -1);
    cout << "Enter vertex1,vertex2 and weight\n";
    forInc(i, 1, edges)
    {
        cout << "Edge " << i << endl;
        cin >> node1 >> node2 >> weight;
        graphedge[node1].push_back(node2);
        graphcost[node1].push_back(weight);
        graphedge[node2].push_back(node1);
        graphcost[node2].push_back(weight);
    }

    cout << "Source Vertex : " << endl;
    ll source;
    cin >> source;
    dijkstra(source);
    cout << "VERTEX\tCOST\tPARENT" << endl;
    forInc(i, 1, vertex) cout << i << " \t" << dis[i] << "\t" << parent[i] << endl;
    cout << endl;
    return 0;
}
