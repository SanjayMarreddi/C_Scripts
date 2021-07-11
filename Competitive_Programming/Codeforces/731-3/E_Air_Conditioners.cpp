#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long                                  
#define pb push_back
#define pob pop_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define decimal(x) cout << fixed << setprecision(x)
#define fr(i,a,b) for(int (i)=(a) ; (i) <= (b) ; ++(i))
#define frr(i,a,b) for(int (i)=(a) ; (i) >= (b) ; --(i))
#define trav(ele,container) for(auto (ele): (container)) // Just gives a copy of the elements.
#define tra(ele,container) for(auto& (ele): (container)) // Gives the reference to the elements.
#define lbd(a,x) lower_bound(all((a)),(x)) - (a).begin()
#define ubd(a,x) upper_bound(all((a)),(x)) - (a).begin()
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<pi>	vpi;
typedef vector<int> vi;
typedef vector<vi>	vvi;
typedef priority_queue<int> prq;                          
const int M = 1e9 + 7;
const int INF = 1e18;
//-------------------------------------------------------- DebugHelp--------------------------------------------------
vector<string> vec_splitter(string s) {s += ','; vector<string> res; while(!s.empty()) { res.push_back(s.substr(0, s.find(','))); s = s.substr(s.find(',') + 1);} return res;}
void debug_out( vector<string> __attribute__ ((unused)) args, __attribute__ ((unused)) int idx,  __attribute__ ((unused)) int LINE_NUM) { cout << endl; } 
template <typename Head, typename... Tail> void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) { if(idx > 0) cout << ", "; else cout << "Line(" << LINE_NUM << ") ";stringstream ss; ss << H;cout << args[idx] << " = " << ss.str();debug_out(args, idx + 1, LINE_NUM, T...); }
#define dbg(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
//-------------------------------------------------------- OperatorOverload --------------------------------------------------
template <typename T> using min_prq = priority_queue<T, vector<T>, greater<T>>;   
template <typename T> ostream& operator<< (ostream& os, const vector<T>& v) 
{ os << "[ "; for (int i = 0; i < v.size(); ++i) { os << v[i]; if (i != v.size() - 1) os << ", "; } os << " ]\n"; return os; } 
template <typename T> ostream& operator<< (ostream& os, const set<T>& v) 
{ os << "[ "; for (auto it : v) { os << it; if (it != *v.rbegin()) os << ", "; } os << " ]\n"; return os; } 
template <typename T> ostream& operator<< (ostream& os, const multiset<T>& v) 
{ os << "[ "; for (auto it : v) os << it << ", "; os << " ]\n"; return os; }
template <typename T, typename S> ostream& operator<< (ostream& os, const map<T, S>& v) 
{ os << "{ "; for (auto it : v) os << it.first << " : " << it.second << ", "; os << " }\n"; return os; }
template <typename T, typename S> ostream& operator<< (ostream& os, const multimap<T, S>& v) 
{ os << "{ "; for (auto it : v) os << it.first << " : " << it.second << ", "; os << " }\n"; return os; }
template <typename T, typename S> ostream& operator<< (ostream& os, const pair<T, S>& v) 
{ os << "("; os << v.first << ", " << v.second << ")"; return os; }
template <typename T> ostream& operator<< (ostream& os, priority_queue<T> p)
{ os << "[ "; while(!p.empty()){ os << p.top() << " ,"; p.pop(); } os << " ]\n"; return os; }
//-------------------------------------------------------- Basic Number Theory --------------------------------------------------
namespace number_theory{
    int gcd(int a, int b)   { int c;  while (b){c = b; b = a % b; a = c;} return a; }
    int lcm(int a, int b)   { return (a*(b/gcd(a,b)));}
    int modpow(int a, int p = M-2, int MOD = M )   { int result = 1; while (p > 0) { if (p & 1) { result = a * result % MOD; } a = a * a % MOD; p >>= 1; } return result; }
    int ncr (int n,int k)    { int ans = 1; if (k>n-k) {k=n-k;} fr(i,1,k) {ans*=(n-i+1); ans/=i; } return ans; }
}
using namespace number_theory;
// ----------------------------------------------------------------------------------------------------------------------//
// int dp[n][n]; 

void solve() {

  int n, k; cin >> n >> k;
  vi a(k); fr(i,0,k-1) { cin >> a[i]; }
  vi t(k); fr(i,0,k-1) { cin >> t[i]; }

  // ci is the temperature of air conditioner in cell i (or infinity if there is no air conditioner in this cell).
  vi c(n, INT_MAX);
  fr(i,0,k-1){
      c[a[i]-1] = t[i];
  }

  // Left_i is the temperature in cell i if we take only air conditioners with numbers less than or equal to i;
  vi left(n, INT_MAX);
  int previous = INT_MAX;
  fr(i, 0, n-1){
     previous = min(previous+1, c[i]);
     left[i] = previous;
  }

  // Right_i is the temperature in cell i if we take only air conditioners with numbers greater than or equal to i;
  vi right(n, INT_MAX);
  previous = INT_MAX;
  frr(i,n-1,0){
     previous = min(previous+1, c[i]);
     right[i] = previous;
  }

  fr(i,0,n-1){
      cout << min(left[i], right[i]) << " ";
  }

}

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1;
    cin >>  t; 
    fr(T,1,t){
        //cout << "Case #" << T << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}
