#include<bits/stdc++.h>
using namespace std;

int main() {
	int k, n, w;

	cin >> k >> n >> w;

	int total_cost = w * k * (w + 1);
	total_cost /= 2;
	
	int res = total_cost - n;
	
	if (res < 0) cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}