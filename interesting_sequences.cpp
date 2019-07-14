/*Professor Jain has a class full of notorious students. To get anything done from them is a herculean task. Prof Jain wanted to organize a test. He gave this responsibility to Aahad. Aahad did an excellent job of organizing the test. As a reward, the professor gave him an sequence of numbers to play with. But Aahad likes playing with "interesting" sequence of numbers, which are sequences that have equal elements.
Now, the problem is - Prof Jain has a sequence with elements, and that sequence isn't always "interesting”. To ensure sequence has equal elements, Prof Jain has 2 options:
1) Choose two elements of sequence . DECREASE the first element by 1 and INCREASE the second element by 1. This operation costs 'k' coins.
2) Choose one element of array and INCREASE it by 1. This operation costs 'l' coins.
What’s the minimum number of coins Prof Jain needs to turn his sequence into a “interesting" sequence for Aahad? */

#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int n, k, l;
    cin >> n >> k >> l;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    int i = arr[0]; 
    int j = arr[n - 1];
    
    int val = 0;
    int mincost = INT_MAX;
    
    while (i <= j) {
        int mid = i;
        int inc = 0;
        int dec = 0;
        int cost = 0;
        for (int ii = 0; ii < n; ii++) {
            if (mid > arr[ii]) {
                inc += mid - arr[ii];
            }
            else {
                dec += arr[ii] - mid;
            }
        }
        
        if (inc >= dec) {
            cost = (dec * k) + (inc - dec) * l;
            mincost = min(mincost, cost);
        }
        i++;
    }
    
    cout << mincost << endl;
}
