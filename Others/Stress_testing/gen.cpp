#include <bits/stdc++.h>
using namespace std;

#define ll long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll gen_random(ll l, ll r) { 
    return uniform_int_distribution<ll>(l, r)(rng);
}

// for real number
// inline double gen_random(double l, double r) {
//     return uniform_real_distribution<double>(l, r)(rng);
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

     freopen("in.txt", "w", stdout);  // the test case will be written on in.txt

   // && generating random array
    int n = gen_random(1, 5);
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << gen_random(-20, 20) << " ";
    }
    cout << endl;
  
    // **  generating permuation
    int n = gen_random(1, 5);
    cout << n << endl;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    shuffle(v.begin(), v.end(), rng);
  
    // ** string genertator
    int n = gen_random(1, 5);
    cout << n << endl;
    for(int i = 0; i < n; i++){
      char c = 'a' + gen_random(0, 25);
      cout << c;
    }
    cout << endl;

  // ** string genertator with specific char
   vector<char> x = {'p', 'q', 'x', 'z'};

   for(int i = 0; i < n; i++){
       cout << x[gen_random(0, x.size()-1)]
   }
   cout << endl;

  // tree generating
  // --> first generate the permutation


  for(int i = 1; i < n; i++){
      int indx = gen_random(0, i-1);
      cout << v[indx] << " " << v[i] << endl; // edge
  }

  // graph generating
  int n = gen_random(5, 10);
  int m = gen_random(1, n*(n-1)/2-1);

  set<pair<int, int>> st;

  while(st.size() < m){
      int u = gen_random(1, n);
      int v = gen_random(1, n);

      if(u==v) continue;
      st.insert({min(u, v), max(u, v)});
  }
    for(auto it : st) {
      cout << st.first << " " << st.second << endl;
    }


    return 0;
}
