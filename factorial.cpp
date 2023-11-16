// this is an exercise to help understande dynamic programming logic (DP)

#include <iostream>

using namespace std;

int recursiveFactorial(int n){
    //regular recursive factorial implementation
    if (n==0 || n==1)
        return 1;
    
    return n * recursiveFactorial(n - 1);
}

int results[1000] = {0}; //storage vector used in dp

int dpIterativeFactorial(int n){
    // Bottom-Up iterative implementation of factorial using DP
    // Builds sub-problems iteratively up to the bigger problem
    if(n >= 0){
        results[0] = 1;
        for(int i = 1; i <= n; i++){
            results[i] = i * results[i - 1];
        }
        return results[n];
    }
    return 0;
}

int dpRecursiveFactorial(int n){
    // Top-Down recursive implementation of factorial using DP
    // Approaches bigger problem and divides into smaller sub-problems
    if(n>=0){
        if(results[n] != 0){
            // has been calculated
            return results[n];
        }

        if(n == 0){
            results[n] = 1;
        }
        else{
            results[n] = n * dpRecursiveFactorial(n - 1);
        }

        return results[n];
    }
    return 0;
}

int main(){

    cout << "Recursive standard: "<< recursiveFactorial(3) << endl;
    cout << "Top-Down DP: "<< dpRecursiveFactorial(3) << endl;
    cout << "Bottom-Up DP: "<< dpIterativeFactorial(3) << endl;

    return 0;
}