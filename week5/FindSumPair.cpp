#include <bits/stdc++.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int> &arr)
{
     int range = *max_element(arr.begin(), arr.end());
	int temp[arr.size()];
	int count[range + 1], i;
	memset(count, 0, sizeof(count));

	for (i = 0; i<arr.size(); ++i)
		++count[arr[i]];

	for (i = 1; i <= range; ++i)
		count[i] += count[i - 1];

	for (i = 0; i<arr.size(); ++i) {
		temp[count[arr[i]] - 1] = arr[i];
		--count[arr[i]];
	}
	for (i = 0; i<arr.size(); ++i)
        arr[i] = temp[i];
}


void findPair(vector<int> arr  , int key )
{
    int i=0,left=0,right=arr.size()-1;
    bool flag=false;
    while (left < right)
    {
        if(arr[left]+arr[right]==key)
            {
                cout << arr[left] << " " << arr[right] << ", ";
                right--;
                flag=true;  
            }
        else if(arr[left]+arr[right]>key)
                right--;
        else if(arr[left]+arr[right]<key)
                left++;
            
    }
    if(!flag)
        cout<<"No Such pair Exist";
    cout<<endl;
}
int main()
{
    int t ;
    cin >> t;
    while (t--)
    { 
        int n ,i,k;
        cin>>n;
        vector <int> arr;
        for(i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        cin>>k;
        countSort(arr);
        findPair(arr,k);
    }
	return 0;
}



