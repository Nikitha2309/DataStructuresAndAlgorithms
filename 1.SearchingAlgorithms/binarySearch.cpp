#include <iostream>
using namespace std;

int binarySearch(int a[], int size, int n) {
  
  int low = 0, high = size-1;
  while(low<=high){
	  int mid = low + (high-low)/2;
	  if(a[mid] == n){
		  return mid;
	  }else if(a[mid] < n){
		  low = mid + 1;
	  }else{
		  high = mid - 1;
	  }
  }
  // If the element is not found, return -1
	return -1;

}

int main() {
	
	// Example 1	
	int arr1[] = { 10, 25, 30, 40, 70, 80, 100, 130, 170 };
	// Target Element.
	int x1 = 130;
	int n1= sizeof(arr1) / sizeof(arr1[0]);
	int index1 = binarySearch(arr1, n1, x1);
	if(index1 == -1){
		 cout<<-1<<endl;
		 cout << "Element "<<x1<<" is not present in arr1[]" << endl;
	}
	else{
		cout<<"Element "<<x1<<" is present at index "<<index1<<endl;
	} 
	cout<<endl;
	
	// Example 2 
	int arr2[] = {10,20,40,60,70,80,100,130,150};
	// Target Element.
	int x2=175;
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	int index2 = binarySearch(arr2, n2, x2);
	if(index2 == -1){
		 cout<<-1<<endl;
		 cout << "Element "<<x2<<" is not present in arr2[]" << endl;
	}
	else{
		cout<<"Element "<<x2<<" is present at index "<<index2<<endl;
	}
	
    return 0;
}
