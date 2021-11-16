// C++ Program for counting sort
#include <bits/stdc++.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int> &arr)
{
     int range = *max_element(arr.begin(), arr.end());;
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

int main()
{
	vector <int> arr;
    int i,n;
    cin>>n;
    for (i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

	countSort(arr);

	cout << "Sorted character array is " ;
    for (i=0;i<n;i++)
        cout << arr[i]<<" ";
	return 0;
}

