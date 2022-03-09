#include <bits/stdc++.h>
using namespace std;

void printArray(int* arr, int size)
{
	cout<<"Array = { ";
	for(int i=0;i<size-1;i++)
	 	cout<<arr[i]<<", ";
	cout<<arr[size-1]<<" }"<<endl;
}

void printElement(int* arr,int size,int index)
{
	if(index > size)
		cout<<"Invalid index !!"<<endl;
	else
    	cout << "Element at the index "<<index<<" in the given array is "<<arr[index-1]<<endl;
}

int searchElement(int* arr, int size, int target)
{
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

void insertElement(int* arr,int& size, int element, int position)
{
	if(position > size)
	{
		cout<<"Invalid index !!"<<endl;
		return;
	}
	
	size++;
    for (int i = size-1; i >= position; i--)
        arr[i] = arr[i - 1];
    arr[position - 1] = element;
	cout<<"Inserted element 7 at index 6."<<endl;
    return;
}

void deleteMinimumElement(int* arr, int& size)
{
	// Find the index of the minimum element.
    int min_element = INT_MAX;
    int min_index;
    for(int i=0;i<=size;i++){
        if(min_element > arr[i])
            min_index = i;
        min_element = min(min_element,arr[i]);
    }
	
    if (min_index < size)
	{
        size--;
        for (int j=min_index; j<=size; j++)
            arr[j] = arr[j+1];
    }
	cout<<"Deleted the minimum entry."<<endl;
    return;
}

int main()
{
	// 1. Create an integer array of size 8.
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	// Print the original array.
	printArray(arr,size);
	cout<<endl;
	
	
	// 2. Print the 3rd element.
    printElement(arr,size,3);
	cout<<endl;
	
	
	// 3. Search for 2 in the array.
	int index = searchElement(arr,size,2);
	if(index==-1)
		cout<<"Element 2 is not present in the given array."<<endl;
	else
		cout<<"Element 2 is at the index "<<index+1<<" in the given array."<<endl;
	cout<<endl;
   
	
	// 4. Insert 7 in the 6th position.
    insertElement(arr,size,7,6);
	// Print the array after element insertion.
	printArray(arr,size);
	cout<<endl;
	
	
	// 5. Delete the minimum entry.
    deleteMinimumElement(arr,size);
    // Print the array after deleting minimum entry.
	printArray(arr,size);
	cout<<endl;
	
    return 0;
}