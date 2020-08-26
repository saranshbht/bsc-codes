#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long 
#define M (ll)(1e9 + 7)
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int m, n;
		cin >> n >> m;
		//int total = 1;
		int roads = n - m;
		//total += roads / 2;
		ll first = m;
		ll last = m + roads - 1;
		ll sum = first + last;
		if(sum & 1)
			roads >>= 1;
		else
			sum >>= 1;
		ll total = ((sum % M) * (roads % M) + 1) % M;
		cout << total << endl;
	}
	return 0;
}
