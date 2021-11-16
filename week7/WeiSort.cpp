#include<bits/stdc++.h> 

#define V 100 
#define INF INT_MAX 
using namespace std;
int arr[100][100]; 
 
int shortestpath(int arr[][V],int u,int v,int k, int n) 
{ 
 	if(k==0 && u==v)  
        return 0;  	
    if(k==1 && arr[u][v] != INF) 
        return arr[u][v]; 
 	if(k<=0)  	 	
        return INF; 
    int res = INF;  
    for(int i=0;i<n;i++) 
 	{ 
 	 	if(arr[u][i] != INF && u!=i && v!=i) 
 	 	{ 
 	 	 	int rec_res = shortestpath(arr, i,v,k-1, n); 
 	 	 	if(rec_res != INF)
            res = min(res, arr[u][i]+rec_res); 
 	 	} 
 	} 
 	return res; 
} 
 
int main() { 
 	int n;  
 	cin>>n; 
    int a; 
 	for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        { 
 	        cin>>a; 
 	        if(a<0)
           	arr[i][j] = INF; 
 	        else 
 	        arr[i][j] = a; 
 	    } 
 	} 
 	int u,v,k;
    cin>>u>>v>>k; 
    int sp=shortestpath(arr,u-1,v-1,k,n);
    if(sp>0){
    printf("weight of the shortest path from (%d %d) with %d edges :",u,v,k);
 	cout<<sp<<endl;
    }
    else
    printf("no path of  %d edges :",k);
 	return 0; 
} 
