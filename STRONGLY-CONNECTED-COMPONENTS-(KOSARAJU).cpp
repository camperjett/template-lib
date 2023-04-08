//Om Namah Shiva
#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define int                 long long
#define all(x)              (x).begin(), (x).end()
#define el                  '\n'
#define pb                  push_back
#define ff                  first
#define ss                  second
#define dbg(x)              cout << #x << " is " << x << el;
#define pii                 pair<int,int>
#define INF                 (1LL * 1e18)
template <typename A, typename B> ostream& operator<< (ostream &cout, pair<A, B> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> ostream& operator<< (ostream &cout, vector<A> const &v) {cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";}
template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin>>n>>m;
    vector<vector<int>> ad(n);
    vector<vector<int>> tad(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v; cin>>u>>v; u--, v--;
        ad[u].pb(v);
        tad[v].pb(u);
    }

    vector<pii> out(n, {0, 0});
    int t = 0;
    auto dfs = [&](int c, int p, auto&& dfs) -> void{
        out[c].ff = ++t; // if > 0, then in-time i.e., visited
        for(auto& I: ad[c]){
            if(I == p) continue;
            if(out[I].ff) continue;
            dfs(I, c, dfs);
        }
        out[c] = {-(++t), c}; // if < 0, then out-time i.e., call-stack pops it
    };
    // dbg(ad)
    for (int i = 0; i < n; ++i)
    {
        if(out[i].ff) continue;
        dfs(i, -1, dfs);
    }
    sort(all(out));
    
    vector<int> v(n);
    auto dfs2 = [&](int c, int p, auto&& dfs2) -> void{
        if(p == -1) cout<<"scc: ";
        cout<<c+1<<" ";
        v[c] = 1;
        for(auto& I: tad[c]){
            if(I == p || v[I]) continue;
            dfs2(I, c, dfs2);
        }
        if(p == -1) cout<<el;
    };
    

    for(auto&[x, y]: out){
        if(v[y]) continue;
        dfs2(y, -1, dfs2);
    }

    
    return 0;
      
}

/**
 * Possible Mistakes:
 * -    = instead of == in if(...) condition
 * -    n % k : take care of remainders especially when k divides n ikyk
 * -    question may ask, "AT LEAST k" NOT "equal to k". READ Carefully!!
 * -    stack/ queue/ priority_queue (empty)
 * -    INT overflow:
 *          1e9 * 1e9 > INT_MAX
 *          summation of element: 1e9 + 1e9 + .... > INT_MAX
 * -    auto I = my_set.erase(J) returns iterator to next element to *J in my_set !!!! 
 * -    use (ans + MOD) % MOD and not ans % MOD
 * -    never use LLONG_MAX or LLONG_MIN : USE 1e18 or -1e18
 * */