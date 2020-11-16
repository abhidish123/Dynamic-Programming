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
	int n, a, b, c;
	cin >> n;
	int p[n][3];
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> c;
		p[i][0] = a;
		p[i][1] = b;
		p[i][2] = c;
	}

	// dp[i][j] -> tells max points upto ith row and selecting jth task
	int dp[n][3];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = p[0][0], dp[0][1] = p[0][1], dp[0][2] = p[0][2]; // base cases

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (j == 0) dp[i][j] = p[i][j] + max(dp[i - 1][1], dp[i - 1][2]);
			else if (j == 1) dp[i][j] = p[i][j] + max(dp[i - 1][0], dp[i - 1][2]);
			else dp[i][j] = p[i][j] + max(dp[i - 1][0], dp[i - 1][1]);
		}
	}

	int max = 0;
	for (int j = 0; j < 3; ++j) {
		if (dp[n - 1][j] > max) max = dp[n - 1][j];
	}

	cout << max << endl;
}



int main() {

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
}
