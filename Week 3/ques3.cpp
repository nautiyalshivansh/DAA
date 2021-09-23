#include<iostream>
#include<vector>
using namespace std;
void qShort(vector<int> ar,int low,int high)
{
    if(low<high)
    {
   int pivot=ar[high];
   int i=low-1;
   int temp;
   for(int j=low;j<high;j++)
   {
       if(ar[j]<pivot)
       {
            i++;
           temp=ar[i];
           ar[i]=ar[j];
           ar[j]=temp;
          
       }
   }
     temp=ar[i+1];
           ar[i+1]=ar[high];
           ar[high]=temp;
   qShort(ar,low,i);
   qShort(ar,i+2,high);
    }
}
int main()
{
    vector<int> ar;
    int t,co,com,val;
    cin>>t;
    while(t--)
    {
        
        cin>>co;
        for(int j=0;j<co;j++)
        {
            cin>>val;
            ar.push_back(val);
        }
        qShort(ar,0,co-1);
        cout<<endl;

        com=0;
        for(int j=0;j<co-1;j++)
        {
            if(ar[j]==ar[j+1])
            {
                cout<<"YES"<<endl;
                com=1;
                break;
        }
        }
        if(com==0)
        cout<<"NO"<<endl;
    }
}
