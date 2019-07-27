#define size 1000
int dp[size+5];
#define mod 1000000007

int countBST( int n)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
    if (n == 1) {
        return 1;
    }
    
    if (n == 2) {
        return 2;
    }
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        long long sum = 0;
        for (int j = 1; j <= i; j++) {
            int left = j - 1;
            int right = i - j;
            
            sum = (sum % mod +  ((dp[left] % mod) * (dp[right] % mod)) % mod) % mod;
        }
        dp[i] = sum;
    }
    
    return dp[n];
}


