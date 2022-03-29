#include <bits/stdc++.h>
using namespace std;
 
bool compare(pair <float, int> p1, pair <float, int> p2)
{
    return p1.first > p2.first;
}
 
float fractional_knapsack(vector <int> weights, vector <int> values, int capacity)
{
    int len = weights.size();
    float total_value = 0;
 
    // vector to store the items based on their value/weight ratios
    vector <pair <float, int>> ratio(len, make_pair(0.0, 0));
 
    for(int i = 0; i < len; i++)
        ratio[i] = make_pair(values[i]/weights[i], i);
 
    // now sort the ratios in non-increasing order
    // for this purpose, we will use our custom
    // comparator function
    sort(ratio.begin(), ratio.end(), compare);
 
    // start selecting the items
    for(int i = 0; i < len; i++)
    {
        if(capacity == 0)
            break;
 
        int index = ratio[i].second;
 
        if(weights[index] <= capacity)
        {
            // we item can fit into the knapsack
            // hence take the whole of it
            capacity -= weights[index];
 
            // add the value of this item to the
            // final answer
            total_value += values[index];
			cout<<"value = "<<values[index]<<" => weight = "<<weights[index]<<endl;
        }
        else
        {
            // this item doesn't fit into the bag
            // and thus we take a fraction of it
            float value_to_consider = values[index] * (float(capacity)/float(weights[index]));
            total_value += value_to_consider;
			cout<<"value = "<<value_to_consider<<" => weight = "<<(float(capacity))<<endl;
            capacity = 0;
        }
    }
 
    return total_value;
}
 
int main()
{
    vector <int> weights = {2,3,5,7,1,4,1};
    vector <int> values = {10,5,15,7,6,18,3};
    int capacity = 15;
	float ans = fractional_knapsack(weights, values, capacity);
    cout << "The maximum value possible based on current list is: " << ans << endl;
}