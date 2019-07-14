/*Our college team is going to the sports fest to play a football match with our coach. There are n players in our team, numbered from 1 to n.
The coach will know the position of another team hence create a winning strategy. He creates the position of every player in a specific order so that we will win and then he starts swapping two players at a time to form the positions.
He swaps payers in such a way that it can't be understood by another team:
1. Any player can swap with the player directly at front him
2. One player can swap at most with two other players
If the specific order is formed then our team will win otherwise we will lose */

#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int n;
    cin >> n;
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int cnt = 0;
    int flag = 0;
    
    for (int i = n - 1; i >= 0; i--) {
//         if (i >= 0 && arr[i] != i + 1) {
//             int j = i - 1;
//             while (j >= 0 && arr[j] != i + 1) {
//                 j--;
//             }
            
//             if (abs(i - j) > 2) {
//                 cout << "NO" << endl;
//                 flag = 1;
//                 break;
//             }
//             else {
//                 cnt += i - j;
//                 i = j - 1;
//             }
//         }
        if(arr[i]!=i+1) {
            if((i-1) >=0 && arr[i-1] == i+1){
                cnt++;
                swap(arr[i], arr[i-1]);
            } else if((i-2) >=0 &&arr[i-2] == i+1) {
                cnt +=2;
                arr[i-2] = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = i+1;
            } else {
                flag= 1;
                break;
            }
        }
    }
    
    if (!flag) {
        cout << "YES" << endl;
        cout << cnt << endl;
    } else {
        cout << "NO" << endl;
    }
}
