#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll>	vl;
typedef vector<pi>	vpi;
typedef vector<pl>	vpl;
typedef vector<vi>	vvi;
typedef vector<vl>	vvl;
typedef priority_queue<ll> prq;  // Max priority Queue.
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define sz(x) (ll)(x).size()
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define decimal(x) cout << fixed << setprecision(x)
#define fr(i,a,b) for(ll (i)=(a) ; (i) <= (b) ; ++(i))
#define frr(i,a,b) for(ll (i)=(a) ; (i) >= (b) ; --(i))
#define trav(ele,container) for(auto (ele): (container)) // Just gives a copy of the elements.
#define tra(ele,container) for(auto& (ele): (container)) // Gives the reference to the elements.
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << " = " << x << "  ,  " << #y << "=" << y << "  ,  " << #z << "=" << z << endl
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
const int M = 1e9 + 7;
const ll INF = 1e18;
template <typename T> using min_prq = priority_queue<T, vector<T>, greater<T>>;   // Min priority queue
template <typename T> T pw(T a,T p=M-2,T MOD=M){
	int result = 1;
	while (p > 0) {
		if (p & 1)
			result = a * result % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return result;
}

ll count_paths(vector<vector<char>> &grid, ll n){

     vvl dp(n, vl(n,-1));

     
     if (grid[0][0] != '*')
        dp[0][0] =  1;
     else
        return 0;
     

     ll stop1 = -1;
     fr(i,1,n-1){
         if (grid[0][i] != '*' )
            { dp[0][i] = 1; }
         else
            { stop1 = i; break;
            
            }
    }

    if (stop1 != -1){
        fr(i,stop1,n-1){
            dp[0][i] = 0; 
        }
    }

    ll stop2 = -1;
     fr(i,1,n-1){
         if (grid[i][0] != '*' )
            { dp[i][0] = 1; }
         else
            { stop2 = i; break;
            
            }
    }

    if (stop2 != -1){
        fr(i,stop2,n-1){
            dp[i][0] = 0; 
        }
    }

     fr(i,1,n-1){
         fr(j,1,n-1){

             if (grid[i][j] != '*')
                dp[i][j] = ( dp[i-1][j] +  dp[i][j-1] )%M;
             else  
                dp[i][j] = 0;
         }
     }

     return dp[n-1][n-1];
}

void solve() {
  ll n; cin >> n;
  vector<vector<char>> grid(n, vector<char>(n)); 
  fr(i,0,n-1) 
    fr(j,0,n-1)
        cin >> grid[i][j];

  cout << count_paths(grid,n);


}

signed main() {

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1;

    //cin >>  t;  // Comment this line if only 1 testcase exists.

    fr(T,1,t){

        //cout << "Case #" << T << ": ";

        solve();
        cout << "\n";
    }
    return 0;
}