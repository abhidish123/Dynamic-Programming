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


void solve() {
	int n, w;
	cin >> n >> w;
	ll a, b;

	// dp[i] -> max val upto ith weight and each item can be carried only once
	ll dp[w + 1] = {0};
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		for (int j = w; j >= a; --j) {
			dp[j] = max(dp[j], b + dp[j - a]);
		}
	}

	cout << dp[w];
}



int main() {

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
}
