#include<bits/stdc++.h>
using namespace std;

int partition (int arr[], int low, int high){
    int pivot = arr[high];   
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++; 
			swap(arr[i],arr[j]);
        }
    }
	swap(arr[i+1],arr[high]);
    return (i + 1);
}
 
void quickSort(int arr[], int low, int high){
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
	quickSort(arr, 0, size - 1);
	
	// Print the output array.
	cout <<"Output is {";
	for(int i = 0; i < size-1; i++)
        cout<<arr[i]<<",";
	cout<<arr[size-1]<<"}"<<endl;
	
    return 0;
}