#include<iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void findComm(vector<int> arr1,vector<int> arr2){
	int n=arr1.size(),m=arr2.size();
	int i=0,j=0;
	int flag=0;
	for(int it=0;it<m+n;it++){
		if(arr1[i]==arr2[j]){
			cout << arr1[i] << " ";
			i++;
			j++;
			flag=1;
		}
		else if(arr1[i]>arr2[j]){
			j++;
		}
		else if(arr1[i]<arr2[j]){
			i++;
		}
	}
	if(flag==0)
		cout << "No Common\n";
}
int main()
{
    int t=1 ;
    // cin >> t;
    while (t--)
    { 
        int n,n2,i,k;
        cin>>n;
        vector <int> arr,arr2;
        for(i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            arr.push_back(temp);
        } 
        cin>>n2;
        for(i=0;i<n2;i++)
        {
            int temp;
            cin>>temp;
            arr2.push_back(temp);
        }
        findComm(arr,arr2);
    }
	return 0;
}

