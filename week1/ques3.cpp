#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int jump(vector<int> arr,int key)
{
    int jump,prev,steps,n=arr.size();
    jump = sqrt(n);
    steps = jump;
    prev = 0;

    while(arr[min(steps, n)-1] < key)
    {
        prev = steps;
        steps+= jump;
        if(prev>=n)
            return -1;
    }
    while(arr[prev]<key)
    {
        prev+=1;
        if(prev==min(steps,n))
            return -1;
    }
    if(arr[prev]==key)
        return prev;
    return -1;
}
int main()
{
    int T,n,key,i;
    cin>>T;
    while(T-->0)
    {
        cin>>n;         
        vector<int> arr;
        for(i=0;i<n;i++)
        {       
            cin>>key;
            arr.push_back(key);
        }
        cin>>key;     
        if(jump(arr,key) > 0)
            cout<<"PRESENT"<<endl;
        else
            cout<<"NOT PRESENT"<<endl;
    }
    return 0;
}

