#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	
	vector<int> multiply(vector<int> res, int x) {
		long long temp = 0;
		long long carry = 0;

		vector<int> result;
		for (int i = res.size() - 1; i >= 0; i--) {
			temp = res[i] * x;
			temp += carry;
			carry = temp / 10;
			result.push_back(temp % 10);
		}

		/// carry should be handled with care.
		if (carry) {
			while (carry) {
				result.push_back(carry%10);
				carry /= 10;
			}
		}

		reverse(result.begin(), result.end());
		return result;
	}

	vector<int> factorial(int N) {
		vector<int> res;
		
		res.push_back(1);
		if (N == 0 || N == 1) return res;

		for (int i = 2; i <= N; i++) {
			res = multiply(res, i);
		}

		return res;
	}


};


int main() {
	int t;
	cin >> t;

	while (t--) {
		int N;
		cin >> N;

		Solution ob;
		std::vector<int> result = ob.factorial(N);
		for (int i = 0; i < result.size(); ++i) {
			cout << result[i];
		}

		cout << endl;
	}

	return 0;
}