#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,t;
    vector <int> arr;
    int flag;
    cin >> t;
    int ifinal,jfinal,kfinal;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> flag;
            arr.push_back(flag);
        }
        flag=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n-i-1;j++)
            {
                int sum=0;
                sum +=arr[i] + arr[j];
                for(int k=0;k<n;k++)
                {
                    if(sum==arr[k])
                    {
                        ifinal=i+1;
                        jfinal=j+1;
                        kfinal=k+1;
                        flag=1;
                    }
                }
            }
        }
    if(flag==1){
            cout << ifinal << "," << jfinal << "," << kfinal << endl;
        }
    else{
    cout << "No Sequence Found"<<endl;
    }
    }
}
