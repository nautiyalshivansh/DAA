#include <bits/stdc++.h>
using namespace std;

int findParent(vector<int> parent, int u)
{
    if (parent[u] < 0)
        return u;
    return findParent(parent, parent[u]);
}

bool UnionByWeight(vector<int> &parent, int u, int v)
{
    int pu = findParent(parent, u);
    int pv = findParent(parent, v);
    if (pu != pv)
    {
        if (parent[pu] <= parent[pv])
        {
            parent[pu] += parent[pv];
            parent[pv] = pu;
        }
        else
        {
            parent[pv] += parent[pu];
            parent[pu] = pv;
        }
        return true;
    }
    return false;
}

int kruskals(vector <vector <int>> graph)
{
    int n =graph.size();
    vector<pair<int, pair<int, int>>> G;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (graph[i][j] != 0)
                G.push_back(make_pair(graph[i][j], make_pair(i, j)));
    sort(G.begin(), G.end());
    vector<int> parent(n,-1);
    int s = 0;
    for (auto i : G)
    {
        int u = i.second.first;
        int v = i.second.second;
        int w = i.first;
        if (UnionByWeight(parent, u, v))
            s += w;
    }
    return s;
}

int main()
{
	int v;
    cin>>v;
    vector <vector <int>> graph;
    vector <int> arrT;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            int temp;
            cin>>temp;
            arrT.push_back(temp);
        }
        graph.push_back(arrT);
        arrT.clear(); 
    }
    cout << "Minimum spanning weight : " << kruskals(graph) << endl;
    return 0;
}