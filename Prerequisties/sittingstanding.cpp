#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("sitin.txt","r", stdin);
	freopen("sitout.txt", "w", stdout);
	int n, m;
	cin >> n >> m;

	int people;
	cin >> people;

	int total_capacity = n * m;
	int people_standing = people - total_capacity;

	if (people_standing < 0) {
		cout << people << " " << 0 << endl;
	}
	else {
		cout << total_capacity << " " << people_standing << endl;
	}

	return 0;
}
