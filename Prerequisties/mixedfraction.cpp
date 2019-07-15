#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("mixin.txt", "r", stdin);
	freopen("mixout.txt", "w", stdout);

	int n, d;
	cin >> n >> d;

	int rem = n % d;
	int q = n / d;
	
	if (rem) {
		cout << q << " " << rem << "/" << d << endl;
	}
	else {
		cout << q << endl;
	}

	return 0;
}
