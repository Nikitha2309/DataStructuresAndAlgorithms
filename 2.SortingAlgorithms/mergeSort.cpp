#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int k,n1 = m - l + 1,n2 =  r - m;
    int L[n1], R[n2];
 
    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    int i = 0,j = 0;
	k = l;
     
    while (i < n1 && j < n2)
        L[i] <= R[j] ? arr[k++] = L[i++] : arr[k++] = R[j++];
 
    while (i < n1)
        arr[k++] = L[i++];
 
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r){
    if (l < r)
    {
        // int m = l + (r - l) / 2;
		int m = ((long)(l+r))/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
	
	// Declare array.
	int arr[] = {45,10,20,80,30,60,50,110,100,170,90};
	int size= sizeof(arr) / sizeof(arr[0]);
	
	// Print the input array.
	cout <<"Input is {";
	for(int i = 0; i < size-1; i++)
        cout<<arr[i]<<",";
	cout<<arr[size-1]<<"}"<<endl;
	
	// call a sorting function.
	mergeSort(arr, 0, size - 1);
	
	// Print the output array.
	cout <<"Output is {";
	for(int i = 0; i < size-1; i++)
        cout<<arr[i]<<",";
	cout<<arr[size-1]<<"}"<<endl;
	
    return 0;
}
