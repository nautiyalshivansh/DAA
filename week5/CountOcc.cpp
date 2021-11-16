#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define RANGE 255

void countSort(char arr[],int n )
{
    int maxOcc=0;
    char ch;
	char output[strlen(arr)];
	int count[RANGE + 1], i;
	memset(count, 0, sizeof(count));
	for (i = 0; i<n; i++)
		count[arr[i]]++;
    for (i = 0; i<n ; i++)
    {
        if (count[arr[i]]>maxOcc)
        {
            maxOcc=count[arr[i]];
            ch=arr[i];
        }
    }   
    if (maxOcc>1)
    cout << ch<<" - "<< maxOcc << endl ;
    else
    cout<<"No Duplicates Present"<<endl;
    // for counting sort of character
	/*for (i = 1; i <= RANGE; ++i)
		count[i] += count[i - 1];
	for (i = 0; arr[i]; ++i) {
		output[count[arr[i]] - 1] = arr[i];
		--count[arr[i]];
	}
	for (i = 0; arr[i]; ++i)
		arr[i] = output[i];*/
}

int main()
{
    int t ;
    cin >> t;
    while (t--)
    { 
        int n ,i;
        cin>>n;
        char arr[n];
        for(i=0;i<n;i++)
            cin>>arr[i];
        countSort(arr,n);
    }
	return 0;
}

