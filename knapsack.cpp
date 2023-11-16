// this is an exercise to help understand the Knapsack problem using DP

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

const int n = 4; //amount of items to choose from
const int capacity = 10; //capacity of the knapsack

int weights[n+1] = {0, 2, 3, 5, 7}; //wheigts of each item (1-based)
int values[n+1] = {0, 10, 5, 15, 7}; //values of each item (1-based)

int dpVector[n+1][capacity+1] = {0}; //matrix to store the values for the DP (1-based)
vector<int> itemsAdded;

void findAddedItems(){
    // tracks what items were added to the knapsack in the process
    int i = n;
    int j = capacity;

    while(i > 0 && j > 0){
        if(dpVector[i][j] != dpVector[i-1][j]){
            // i item has been put in the knapsack
            itemsAdded.push_back(i);
            j -= weights[i];
        }
        i--; // i item was not added to the knapsack, skip
    }
}

int main(){
    // i = current item
    // j = current capacity of the knapsack
    // dpVector[i][j] = maximum value possible to a knapsack with the i first items and j capacity
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= capacity; j++){
            if(weights[i] <= j){  // can add i item to the knapsack
                // take best option between:
                // dpVector[i - 1][j] --> not adding the item to the knapsack
                // values[i] + dpVector[i-1][j-weights[i]] --> add item to the knapsack (+ value, - capacity)
                dpVector[i][j] = max(dpVector[i-1][j], values[i] + dpVector[i-1][j-weights[i]]);
            }else{  // cannot add item to the knapsack (overflows capacity)
                dpVector[i][j] = dpVector[i-1][j]; // just skip item and keep capacity
            }
        }
    }

    // we want to find the maximum value for a knapsack of capacity = capacity and items = n
    cout << "Max value for " << n << " items and " << capacity << " of capacity: " << dpVector[n][capacity] << endl;
    findAddedItems();
    cout << "Selected Items:" << endl;
    for (int i = 0; i < itemsAdded.size(); i++){
        cout << "Item: " << itemsAdded[i] << "\t\tValue: " << values[i+1] << endl;
    }
}
