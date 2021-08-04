#include <iostream>
#include <vector>

using namespace std;
 
int binarySearch(vector<int> arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
          if (arr[mid] == x)
            return mid;
          if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
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
          int result = binarySearch(arr,0,n-1,x);
          if(result == -1)
              cout << "Not Present"<<endl;
         else
               cout << "Present" << x<< endl;
        }
    return 0;
}
