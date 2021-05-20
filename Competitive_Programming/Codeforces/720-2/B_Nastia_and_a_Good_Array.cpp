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
template <typename T> using min_prq = priority_queue<T, vector<T>, greater<T>>;   // Min priority queue

inline ll pmod(ll i, ll n) { return (i % n + n) % n; }
const int mod = 1e9 + 7;
const long long INF = 1e18;


void solve() {

  int n;
  cin >> n;
  vi v(n);
  vvi results;
  fr(i,0,n-1) cin >> v[i];

  ll miny =  *min_element(all(v));
  ll miny_ind =  min_element(all(v)) - v.begin();



    fr(i,0,n-1) {


            vi temp;

            if (i != miny_ind){
            temp.pb(miny_ind+1);
            temp.pb(i+1);

            temp.pb(miny);
            temp.pb(miny+abs(miny_ind-i));

            v[i]  = miny + abs(miny_ind-i);
            results.pb(temp);
            }
    }
    

   
    int s = results.size();
    if (s != 0){
        cout << s << "\n";
        fr(i, 0, s-1){
            fr(j,0,3){
                cout << results[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else{
         cout << s << "\n";
    }

    // fr(i,0,n-1){
    //     cout << v[i] << " ";
    // }

    // cout << endl;


}

signed main() {

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1;

    cin >>  t;  // Comment this line if only 1 testcase exists.

    fr(T,1,t){

        //cout << "Case #" << T << ": ";

        solve();
    }
    return 0;
}