#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,t,k;
    vector<int> arr;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin>>k;
            arr.push_back(k);
        }
        cin >> k;
        int count =1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n-i-1;j++){
                if(abs(arr[i]-arr[j])==k){
                count++;
                }
            }
        }
        cout << count << endl;
    }
return 0;
}
