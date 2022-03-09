#include <bits/stdc++.h>
using namespace std;
 
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
	
	int arr[] = {45,10,20,80,30,60,50,110,100,170,90};
	int size= sizeof(arr) / sizeof(arr[0]);
	
	cout <<"Input is {";
	for(int i = 0; i < size-1; i++)
        cout<<arr[i]<<",";
	cout<<arr[size-1]<<"}"<<endl;
	
	insertionSort(arr, size);
	
	cout <<"Output is {";
	for(int i = 0; i < size-1; i++)
        cout<<arr[i]<<",";
	cout<<arr[size-1]<<"}"<<endl;
	
    return 0;
}