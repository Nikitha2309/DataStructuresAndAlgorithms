#include<bits/stdc++.h>
using namespace std;
 
int integer_knapsack(int n, int M, int w[], int p[])
{
    int i,j;
    int tempValue;    
 
    //create a vector of size M+1 to memoize calculated values
	//knapsack[i] denotes the maximum possible attainable value with capacity of knapsack being i
    int knapsack[M+1];
 
    //since no item can be put in a knapsack of capacity zero
    knapsack[0]=0;
 
    //the vector will be filled sequentially first calculating value of knapsack[1]
    //then using this value to calculate knapsack[2] and so on.
    for(i=1;i<=M;i++)
    {
        //the value of knapsack[i] will be greater than or equal to knapsack[i-1]
		knapsack[i]=knapsack[i-1];
 
        //try to put every item one by one 
        //and select the one that gives maximum value 
        for(j=0;j<n;j++)
        {
            //if this item can fit in the knapsack
            if(i>=w[j])
            {
                //this is a temporary value
                //if this value is greater than the current value of knapsack[i], this value will replace the value of knapsack[i]
                tempValue=p[j]+knapsack[i-w[j]];
 
                //replace the value of knapsack[i] with tempValue
                if(tempValue>knapsack[i])
                {
                    knapsack[i]=tempValue;
                }
            }
 
        }
	}
 
    //maximum attainable value with duplicate items permitted in knapsack of capacity M
    return knapsack[M];
}
 
int main()
{
    int n=4;  //number of items
    int M=10;  //capacity of knapsack
 
    int w[n] = {5,4,6,3};  //weight of items
    int p[n] = {10,40,30,50};  //value of items

    int result=integer_knapsack(n,M,w,p);
 
    cout<<"The maximum value of items that can be put into knapsack is "<<result;
 
    cout<<endl;
    return 0;
}