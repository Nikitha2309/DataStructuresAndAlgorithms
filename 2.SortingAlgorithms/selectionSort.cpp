#include <bits/stdc++.h>
using namespace std;
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

int main() {
	
	int arr[] = {45,10,20,80,30,60,50,110,100,170,90};
	int size= sizeof(arr) / sizeof(arr[0]);
	
	cout <<"Input is {";
	for(int i = 0; i < size-1; i++)
        cout<<arr[i]<<",";
	cout<<arr[size-1]<<"}"<<endl;
	
	selectionSort(arr, size);
	
	cout <<"Output is {";
	for(int i = 0; i < size-1; i++)
        cout<<arr[i]<<",";
	cout<<arr[size-1]<<"}"<<endl;
	
    return 0;
}
