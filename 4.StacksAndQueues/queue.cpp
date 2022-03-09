#include<bits/stdc++.h>
using namespace std;

int size = 100;
int arr[100] = {0};

int front = -1;
int rear = -1;

void queue_push(int value){
	if(rear == size-1){
		cout<<"QUEUE OVERFLOW"<<endl;
	}
	else{
		if(front == -1){
			front = 0;
		}
		rear++;
		arr[rear] = value;
	}
	cout<<"Front index :"<<front<<" Rear index :"<<rear<<endl;
	cout<<"Front value :"<<arr[front]<<" Rear value :"<<arr[rear]<<endl;
	cout<<endl;
	return ;
}

void queue_pop(){
	
	if (front == - 1 || front > rear) {
      cout<<"QUEUE UNDERFLOW ";
	  cout<<"Front index :"<<front<<" Rear index :"<<rear<<endl;
      cout<<"Front value :"<<" "<<" Rear value :"<<" "<<endl;
	  cout<<endl;
   } else {
      front++;
   }
   cout<<"Front index :"<<front<<" Rear index :"<<rear<<endl;
   cout<<"Front value :"<<arr[front]<<" Rear value :"<<arr[rear]<<endl;
   cout<<endl;
	
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
			queue_push(j);
			i++;
		}
		j++;
	}
	
	queue_pop();
	queue_pop();
	
	return 0;
	
}