#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef long long ll;
const int mod = 1e9 + 7;

void solve() {
  int n, temp;
  cin >> n;
  map<int, int> m;
  vector<int> v;
  for (int i = 0;  i <n ; i++){
      cin >> temp;
      m[temp]++;
      v.push_back(temp);
  }
  
  for (int i = 0; i<n; i++){
      if ( m[v[i]] == 1){
          cout << i+1 << endl;
          break;
      }
  }

}

int main() {
    fastIO;
    int t = 1;
    cin >> t; // Comment if only 1 testcase.
    while(t--) {
      solve();
    }

    return 0;
}