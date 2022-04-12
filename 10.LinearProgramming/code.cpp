#include<bits/stdc++.h>
using namespace std;

int main(){
    int st = 2;
    int rt = 3;
    int sp = 4;
    int rp = 5;

    int s = -1;
    int r = -1;
    int m = INT_MIN;

   // Run the loop to get the max value.
   for(int i=5;i<=22;i++){
     for(int j=5;j<=16;j++){
          if((i+j < 25) || ((2*i +  3*j) > 60)){
              continue; 
          }
          else if(m <= 4*i+5*j){
            m = 4*i+5*j;
            s = i;
            r = j;
          }
      }
     }
	 cout<<"Hence the max profit occurs at "<<endl;
     cout<<"square box : "<<s<<endl;
     cout<<"rectangle box : "<<r<<endl;
     cout<< "max profit : "<<m<<endl;
}