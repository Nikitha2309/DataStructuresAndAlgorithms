#include<bits/stdc++.h>

using namespace std;
int size = 10;
int arr[10];
int top_index = -1;

void stack_push(int value){
	if(top_index >= (size-1)){
		cout<<"STACK OVERFLOW"<<endl;
	}
	else{
	top_index++;
	arr[top_index] = value;
	}
	cout<<"Top value :"<<arr[top_index]<<" Top index :"<<top_index<<endl;
	return;
	
}

void stack_pop(){
	if(top_index == -1){
		cout<<"STACK UNDERFLOW"<<endl;
		cout<<"Top value :"<<" "<<" Top index :"<<top_index<<endl;
		return ;
	}
	top_index--;
	if(top_index == -1){
		cout<<"Top value :  Top index :"<<top_index<<endl;

	}
	else{
		cout<<"Top value :"<<arr[top_index]<<" Top index :"<<top_index<<endl;
	}
	return;
	
}

bool isPrime(int num){
    bool flag=true;
	if(num==1){
		return false;
	}
    for(int i = 2; i <= sqrt(num); i++) {
       if(num % i == 0) {
          flag = false;
          break;
       }
    }
    return flag;
}

int main(){
	
	int i=1;
	int j=1;
	while(i<=5){
		if(isPrime(j)){
			stack_push(j);
			i++;
		}
		j++;
	}
	
	stack_pop();
	stack_pop();
	
	return 0;
	
	
}