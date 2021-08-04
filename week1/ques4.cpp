#include <iostream>
#include <vector>
using namespace std;

int linear(vector<int> arr,int index,int key)
{
    int i,n=arr.size();
    for(i= index;i<n;i++)
    {
        if(key==arr[i])
            return i;
    }
    return -1;
}

int binary(int arr[],int low,int high,int key)
{
    if(low<=high)
    {
        int mid=low+(high-low)/2;

        if(key==arr[mid])
            return mid;
        else if(key>arr[mid])
            return binary(arr,mid+1,high,key);
        else
            return binary(arr,low,mid-1,key);
    }
    else
        return -1;
}

int exponential(vector<int> arr,int key)
{
    int i,n=arr.size();
    if(arr[0]==key)
        return 0;
    i=1;
    while(i<n && arr[i]<key)
    {
        i=i*2;
    }
    return linear(arr,(int)i/2,key);
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
        if(exponential(arr,key) > 0)
            cout<<"PRESENT"<<endl;
        else
            cout<<"NOT PRESENT"<<endl;
        }
    return 0;
}
