#include<bits/stdc++.h>
using namespace std;
 
class Stack {
    int *arr;
    int temp[1000];
    int capacity, size;
 
public:
    Stack()
    {
        arr = new int[1000];
        capacity = 1000;
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    Stack(int cap) {
        arr = new int[cap];
        capacity = cap;
        size = 0;
    }
 
    void Push(int val) {
        if (capacity == size) {
            cout << "Stack is Already Full." << endl;
            return;
        }
        arr[size] = val;
        size++;
    }
 
    void Pop() {
        
        if (size == 0){
            cout << "Stack is Empty." << endl;
            return;
        }
        size--;
    }
 
    int Top() {
        if (size == 0)
            return -1;
        return arr[size - 1];
    }

    void display()
    {
        cout<<" TOP -> ";
        for(int i=size-1;i>=0;i--)
            cout<<arr[i]<<" -> ";
        cout<<" END "<<endl;
    }
};
 
class Queue {
    int *arr;
    int capacity, front, end, size;
public:
    Queue(int cap) {
        arr = new int[cap];
        front = 0;
        end = 0;
        capacity = cap;
        size = 0;
    }
 
    void Push(int val) {
        if (size == capacity) 
        {
            cout << "Queue is already full." << endl;
            return;
        }
        arr[end] = val;
        size++;
		end++;
        // end = (end + 1) % capacity;
    }
 
    void Pop() {
        if (size == 0) {
            cout << "Can't Pop. Queue is empty." << endl;
            return;
        }
        size--;
        front = (front + 1) % capacity;
        if (size == 0) {
            cout << "Queue has become empty." << endl;
            return;
        }
    }
 
    int Front() {
        if (size == 0) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }
 
    int End() {
        if (size == 0) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[(end - 1 + capacity) % capacity];
    }

    void display()
    {
        cout<<" FRONT -> ";
        for(int i=front;i<end;i++)
            cout<<arr[i]<<" -> ";
        cout<<" END "<<endl;
    }
};

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

int main() {
    cout<<"Stack using array implementation:"<<endl;
    
    Stack s(20);
    int i=1;
	int j=1;
	while(i<=5){
		if(isPrime(j)){
			s.Push(j);
			i++;
		}
		j++;
	}
    s.display();
    for(int i=0;i<2;i++)
    {
        s.Pop();
        s.display();
    }
	
	
    cout<<"Queue using array implementation:"<<endl;
    Queue q(20);
	i=1;
	j=1;
	while(i<=5){
		if(isPrime(j)){
			q.Push(j);
			i++;
		}
		j++;
	}
    q.display();
    for(int i=0;i<2;i++)
    {
        q.Pop();
        q.display();
    }
	return 0;
}
 