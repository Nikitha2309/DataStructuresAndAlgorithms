#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int x) {
	//Start from the leftmost element of arr[] and one by one compare x with each element of arr[]
  for (int i = 0; i < size; i++) {
    if (arr[i] == x) {
      return i; //If x matches with an element, return the index
    }
  }

  // If x doesn’t match with any of elements, return -1
  return -1;

}

int main() {
	
	// Example 1	
	int arr1[] = {60,20,80,230,160,50,110,100,130,170};
	int x1 = 160; // Target Element
	int n1= sizeof(arr1) / sizeof(arr1[0]);
	int index1 = linearSearch(arr1, n1, x1);
	if(index1 == -1){
		 cout<<-1<<endl;
		 cout << "Element "<<x1<<" is not present in arr1[]." << endl;
	}
	else{
		cout<<"Element "<<x1<<" is present at index "<<index1<<endl;
	} 
	cout<<endl;
	
	// Example 2 
	int arr2[] = {90,20,40,30,60,50,110,140,130,190};
	// Target Element.
	int x2=175;
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	int index2 = linearSearch(arr2, n2, x2);
	if(index2 == -1){
		 cout<<-1<<endl;
		 cout << "Element "<<x2<<" is not present in arr2[]." << endl;
	}
	else{
		cout<<"Element "<<x2<<" is present at index "<<index2<<endl;
	}
	
    return 0;
}