
#include <bits/stdc++.h>
using namespace std;


int mindis(int key[], bool mstSet[],int V)
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void printMST(int parent[], vector < vector <int> > graph)
{
     int V = graph[0].size();
	cout<<"Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}
void printMinD(int parent[], vector < vector <int> > graph){
    int V = graph[0].size();
    int distance=0;
    for (int i = 1; i < V; i++)
        distance+=graph[i][parent[i]];
    cout<<"Minimum spanning weight :"<<distance<<endl;
}

void prim(vector < vector <int> > graph)
{
    int V = graph[0].size();
	int parent[V];
	int dis[V];
	bool mstSet[V];

	for (int i = 0; i < V; i++)
		dis[i] = INT_MAX, mstSet[i] = false;

	dis[0] = 0;
	parent[0] = -1;
	for (int count = 0; count < V - 1; count++)
	{
		int u = mindis(dis, mstSet,V);

		mstSet[u] = true;

		for (int v = 0; v < V; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < dis[v])
				parent[v] = u, dis[v] = graph[u][v];
	}

	printMinD(parent, graph);
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
	prim(graph);

	return 0;
}

