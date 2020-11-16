#pragma GCC optimize "trapv"
#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define sz(s) (ll)(s.size())
#define vvi vector<vector<ll>>
#define vi vector<ll>
#define all(a) (a).begin(),(a).end()
#define pii pair<ll,ll>
#define trace(x,y) cout<<"Value of "<< x << " = " << y <<endl
#define endl '\n'
#define M 1000000007
const ll INF = 1ll << 60;

using namespace std;
//-----------------------------------------//

// in dp must use iterative approach instead of recursive approach

void solve() {
	int n, k;
	cin >> n >> k;
	ll h[n];
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	// dp[i] = min(abs(a[i]-a[i-1])+dp[i-1], abs(a[i]-a[i-2])+dp[i-2],
	//                abs(a[i]-a[i-3])+dp[i-3])

	ll dp[n];
	for (int i = 0; i < n; ++i) {
		dp[i] = INF;
	}
	dp[0] = 0;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < min(i + k + 1, n); ++j) {
			dp[j] = min(dp[j], dp[i] + abs(h[j] - h[i]));
		}
	}
	// for (auto &x : dp) cout << x << " ";
	// cout << endl;
	cout << dp[n - 1];
}



int main() {

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
}
