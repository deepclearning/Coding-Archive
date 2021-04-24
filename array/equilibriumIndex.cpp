#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
    	// two pointer solution is not working
	int equillibriumPoint2pointers(long long a[], int n) {
		int i = 0;
		int j = n - 1;

		if (n == 1) return n;

		long long suml = a[i];
		long long sumr = a[j];

		while (i < j) {
			if (sumr == suml) {
				if (j - i == 2) {
					return i + 2;
				}
			}
			else {
				if (suml < sumr) {
					i++;
					suml += a[i];
				}
				else {
					j--;
					sumr += a[j];
				}
			}
		}
	}

	int equillibriumPoint(long long a[], int n) {
		long long total_cost = 0;

		for (int i = 0; i < n; i++) {
			total_cost += a[i];
		}

		long long left_sum = 0;
		long long right_sum = 0;

		for (int i = 0; i < n; i++) {
			total_cost -= a[i];

			right_sum = total_cost;
			if (left_sum == right_sum) {
				return i+1;
			}
			left_sum += a[i];
		}

		return -1;
	}
};

int main() {
	long long t;

	cin >> t;

	while (t--) {
		long long n;

		cin >> n;

		long long a[n];

		for (long long i = 0; i < n; i++) {
			cin >> a[i];
		}

		Solution ob;

		cout << ob.equillibriumPoint(a,n) << endl;
	}

	return 0;
}