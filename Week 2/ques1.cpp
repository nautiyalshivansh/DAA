#include<iostream>
#include<vector>
using namespace std;
int main(){
	int temp,t,k,n;
	cin >> t;
	while(t--){
		vector<int> arr;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> k;
			arr.push_back(k);
		}
		cin >> k;
		int left = 0;
		int right = n-1;
		temp=0;
		int index;
		while(left<=right){
			int mid = left + ((right-left)/2);
			if(arr[mid]==k){
				index=mid;
				temp=1;
				break;
			}else if(arr[mid]>k){
				right = mid-1;
			}
			else{
				left = mid+1;
			}
		}
		if(temp==0){
			cout << "Key not Present";
		}
		else{
			int count=1;
			int left_side = index-1;
			while(left_side>=0 && arr[left_side]==k){
				count++;
				left_side--;
			}
			int right_side=index+1;
			while(right_side<n && arr[right_side]==k){
				count++;
				right_side++;
			}
			cout << k << " - " << count << endl; 
		}
	}
}
