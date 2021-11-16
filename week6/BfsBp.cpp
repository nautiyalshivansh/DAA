#include<iostream>
#include <list>
#include <vector>
using namespace std;

class Graph
{
	int V; 
	vector <vector <int> > arr; 
public:
	Graph(int V);
	bool BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
    
    for ( int i=0;i<V;i++)
    {
        vector <int>  arrT;
        for (int j=0;j<V;j++)
        {
            int temp;
            cin>>temp;
            arrT.push_back(temp);
        }
        arr.push_back(arrT);
        arrT.clear();    
    }
}
bool Graph::BFS(int s)
{
	bool *visited = new bool[V];
    int *status = new int[V];
    int *color = new int[V];
	for(int i = 0; i < V; i++)
    {
		visited[i] = false;
        status[i]=color[i]=0;
    }
    list<int> queue;
	visited[s] = true;
	queue.push_back(s);
	status[s]=1;
    if ( color[s]== 0 ) color[s]=1;
	while(!queue.empty())
	{
        s=queue.front();
		queue.pop_front();
        visited[s] = true;
		for (int i = 0; i < arr[s].size(); ++i)
		{
			if (!visited[i] && arr[s][i]!=0)
			{
                status[i]=2;
				queue.push_back(i);
                if(color[i] == color[s])
                    return false;
                else
                {
                    color[i]=color[s] * (-1);
                }
                    
			}
		}
	}
    return true;
}


int main()
{
	int v ,s ,d ;
    bool  flag;
cin>> v;
    Graph g(v);
	flag=g.BFS(0);
    if(flag)
        cout<<"Bipartite"<<endl;
    else
        cout<<"Not Bipartite"<<endl;
	return 0;
}
