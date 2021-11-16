#include<iostream>
#include <list>
#include <vector>
using namespace std;

class Graph
{
	int V; 
	vector <vector <int> > arr;
    bool isCyclicUtil(int v, bool visited[], bool *found);
public:
	Graph(int V);
	bool isCyclic();
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
bool Graph::isCyclicUtil(int v, bool visited[], bool *found)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        found[v] = true;
        for(int i = 0; i<arr[v].size(); i++)
        {
            if ( !visited[i] && arr[v][i] != 0 && isCyclicUtil(i, visited, found))
            {
                return true;
            }
            else if (found[i] && arr[v][i] != 0 )
            {
                return true;
            }
        }
 
    }
    found[v] = false;  
    return false;
}
 
bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    bool *found = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        found[i] = false;
    }

    for(int i = 0; i < V; i++)
    {
        if (isCyclicUtil(i, visited, found))
        {
            return true;
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
	flag=g.isCyclic();
    if(flag)
        cout<<"Yes is Cyclic";
    else
        cout<<"No Cycle";
	return 0;
}
