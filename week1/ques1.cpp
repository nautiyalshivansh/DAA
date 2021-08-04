#include <iostream>
#include <vector>

using namespace std;
 
int linearSearch(vector<int> arr, int x)
{
    int i,n=arr.size();
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main()
{
    int t,n,x;
    cin>>t;
    while(t-- > 0)
        {
         vector<int> arr;
         cin>>n;
         for(int i=0;i<n;i++)
         {
           cin>>x;
           arr.push_back(x);
         }
          cin>>x;
          int result = linearSearch(arr, x);
          if(result == -1)
              cout << "Not Present"<<endl;
         else
               cout << "Present" << x<< endl;
        }
    return 0;
}
