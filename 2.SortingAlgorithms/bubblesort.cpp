#include <bits/stdc++.h>
using namespace std;
  
void bubbleSort(int arr[], int n)
{
   bool swapped;
   for (int pass = 0; pass < n-1; pass++)
   {
     swapped = false;
     for (int i = 0; i < n-pass-1; i++)
     {
        if (arr[i] > arr[i+1])
        {
		   swap(arr[i], arr[i+1]);
           swapped = true;
        }
     }
  
     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
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
	bubbleSort(arr, size); 
	
	// Print the output array.
	cout <<"Output is {";
	for(int i = 0; i < size-1; i++)
        cout<<arr[i]<<",";
	cout<<arr[size-1]<<"}"<<endl;
	
    return 0;
}