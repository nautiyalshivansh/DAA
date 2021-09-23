#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> ar;
    int i,t,n,r,key,com,shift;
    cin>>t;
    while(t--)
    {
        com=shift=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>r;
            ar.push_back(r);
        }
        for(i=1;i<n;i++)
        {
            key=ar[i];
            r=i-1;
            while(r>=0 &&ar[r]>key)
            {
                com++;
                shift++;
                ar[r+1]=ar[r];
                r--;
            }
            shift++;
            ar[r+1]=key;
        }
        for(i=0;i<n;i++)
        cout<<ar[i]<<" ";
        cout<<endl;
        cout<<"comparisions  "<<com<<endl;
        cout<<"shiftts  "<<shift<<endl;
    }
}
