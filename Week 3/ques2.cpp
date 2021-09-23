#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> ar;
    int i,mini,t,n,r,key,com,swa,temp;
    cin>>t;
   while(t--)
    {
        com=swa=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>temp;
            ar.push_back(temp);
        }
        for(i=0;i<n-1;i++)
        {
            mini=i;
            for(int j=i+1;j<n;j++)
            {
                com++;
                if(ar[j]<ar[mini])
                mini=j;
            }
            temp=ar[mini];
            ar[mini]=ar[i];
            ar[i]=temp;
            swa++;
        }
        for(i=0;i<n;i++)
        cout<<ar[i]<<" ";
        cout<<endl;
        cout<<"comparisions  "<<com<<endl;
        cout<<"swaps  "<<swa<<endl;
}
}
