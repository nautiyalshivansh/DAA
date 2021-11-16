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
	bool BFS(int s , int d);
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
bool Graph::BFS(int s,int d)
{
	bool *visited = new bool[V];
    int *status = new int[V];
	for(int i = 0; i < V; i++)
    {
		visited[i] = false;
        status[i]=0;
    }
    list<int> queue;
	visited[s] = true;
	queue.push_back(s);
	status[s]=1;

	while(!queue.empty())
	{
        s=queue.front();
		queue.pop_front();
        
		for (int i = 0; i < arr[s].size(); ++i)
		{
			if (!visited[i] && arr[s][i]!=0)
			{
				visited[i] = true;
                status[i]=2;
				queue.push_back(i);
                if(i == d)
                {
                    return true;
                }
			}
		}
	}
    return false;
}


int main()
{
	int v ,s ,d ;
    bool  flag;
    cin>> v;
    Graph g(v);
    cin>>s>>d;
	flag=g.BFS(s-1,d-1);
    if(flag)
        cout<<"Yes Path Exist";
    else
        cout<<"No path Exist";
	return 0;
}
