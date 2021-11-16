#include <limits.h>
#include <vector>
#include <iostream>
using namespace std;
vector< vector <int>> ArrToTre(vector <vector<int>> graph)
{
    int v=graph[0].size();
    vector <vector <int>> tree;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if (graph[i][j]!=0)
            {
                vector <int> arr;
                arr.push_back(i);
                arr.push_back(j);
                arr.push_back(graph[i][j]);
                tree.push_back(arr);
            } 
        }
    }
    return tree;
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
void bellmen (vector <vector<int>> graph,int V, int src)
{
	int dist[V];
	int parent[V];
    int e = graph.size();
	for (int i = 0; i < V; i++)
	{
		parent[0] = -1;
		dist[i] = INT_MAX;
	}
	dist[src] = 0;
	for (int i = 0; i < V ; i++)
	{
		for (int j = 0; j < e; j++)
        {
            int u = graph[j][0];
            int v = graph[j][1];
			if (dist[u] + graph[j][2] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[j][2];
			}
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
    vector <vector <int>> tree;
    tree = ArrToTre(graph);
    /*for(int i=0;i<v;i++)
    {
        cout<<tree[i][0]<<" "<<tree[i][1]<<" "<<tree[i][2]<<endl;
    }*/
	bellmen(tree,v,s-1);
	return 0;
}
