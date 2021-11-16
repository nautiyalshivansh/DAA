#include <limits.h>
#include <vector>
#include <iostream>
using namespace std;
int minDistance(int dist[],int V,bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}
void printPath(int parent[], int j)
{
	if (parent[j] == - 1)
    {
        cout<<j+1;
		return;
    }
	printf("%d ", j+1);
	printPath(parent, parent[j]);

}
void printSolution(int dist[], int n,int parent[] , int src)
{
    cout<<src+1<<" : "<<dist[src]<<endl;
	for (int i = 1; i < n; i++)
	{
		printPath(parent, i);
		printf(" :  %d \n",dist[i]);
	}
}
void dijkstra (vector <vector<int>> &graph,int V, int src)
{
	int dist[V];
	bool sptSet[V];
	int parent[V];
	for (int i = 0; i < V; i++)
	{
		parent[0] = -1;
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}
	dist[src] = 0;
	for (int count = 0; count < V - 1; count++)
	{
		int u = minDistance(dist,V,sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}
	printSolution(dist, V, parent,src);
}
int main()
{
    int v,s;
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
    cin >> s;
	dijkstra(graph,v,s-1);
	return 0;
}
