import java.io.*; 
import java.util.*;
import java.lang.*;
  
class MaxSumPath { 
//int mat[][]; 
  
// function to find the maximum  
// sum path in a matrix 
    static void maxSum(int[][] mat, int n) 
    { 
        // if there is a single element only 
    
        // dp[][] matrix to store the results 
        // of each iteration 
        int dp[][] = new int[n][n]; 
        int ways[][] = new int[n][n];
    
        // base case, copying elements of 
        // last row 

        for (int j = n - 1; j >= 0; j--) {
            //last 
            if (j == n - 1) {
                dp[n-1][j] = 0;
                ways[n-1][j] = 1;
            }
            else {
                if (mat[n-1][j] == -1) {
                    dp[n-1][j] = 0;
                    ways[n-1][j] = 0;
                }
                else {
                    if (ways[n-1][j+1] == 0) {
                        dp[n-1][j] = 0;
                        ways[n-1][j] = 0;
                    }
                    else {
                        dp[n-1][j] = dp[n-1][j+1] + mat[n-1][j];
                        ways[n-1][j] = ways[n-1][j+1];
                    }
                }
            }
        }
            
    
        // building up the dp[][] matrix  
        // from bottom to the top row 
        for (int i = n - 2; i >= 0; i--) { 
            for (int j = n - 1; j >= 0; j--) { 

                if (mat[i][j] == -1) {
                    dp[i][j] = 0;
                    ways[i][j] = 0;
                }

                else {
                    if (j == n - 1) {
                        if (ways[i+1][j] == 0) {
                            dp[i][j] = 0;
                            ways[i][j] = 0;
                        }
                        else {
                            dp[i][j] = mat[i][j] + dp[i+1][j];
                            ways[i][j] = ways[i+1][j];
                        }
                        
                    }

                    else {
                        int mx = Math.max(dp[i+1][j+1], Math.max(dp[i+1][j], dp[i][j+1]));
                        int cnt = 0;
                        if (mx == dp[i+1][j+1]) {
                            cnt += ways[i+1][j+1];
                        }

                        if (mx == dp[i+1][j]) {
                            cnt += ways[i+1][j];
                        }

                        if (mx == dp[i][j+1]) {
                            cnt += ways[i][j+1];
                        }
                        
                        if (cnt == 0) {
                            dp[i][j] = 0;
                            ways[i][j] = 0;    
                        }
                        else {
                            dp[i][j] = mat[i][j] + mx;
                            ways[i][j] = cnt;
                        }
                        
                    }
                }
            } 
        }
        /*  for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                System.out.print(dp[j][k] + " ");
            }
            System.out.println();
        } */ 

        //System.out.println("Jai Hind");
        System.out.println(dp[0][0] + " " + ways[0][0]);
    } 
    
        // Driver code 
    public static void main (String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            char [][] board = new char[n][n];
            int [][] mat = new int[n][n];

            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    board[j][k] = sc.next().charAt(0);
                    if ((j == 0 && k == 0) || (j == n - 1 && k == n - 1)) {
                        mat[j][k] = 0;
                    }
                    else if (board[j][k] == 'x') {
                        mat[j][k] = -1;
                    }
                    else if (board[j][k] != 'x') {
                        mat[j][k] = board[j][k] - '0';
                    }
                }
            }

             /* for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    System.out.print(mat[j][k] + " ");
                }
                System.out.println();
            }  */

            maxSum(mat, n);
        }

    } 
}