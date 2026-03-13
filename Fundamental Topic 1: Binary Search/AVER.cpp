//Author: XuanKien
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define fi first
#define se second
#define il inline
using namespace std;
using namespace __gnu_pbds;
template< class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x>y) {
            x=y;
            return true;
        }
        return false;
    }
template< class X,class Y>
    bool maximize(X &x,const Y &y) {
        if (x<y) {
            x=y;
            return true;
        }
        return false;
    }
const int M1=1e9+9009;
const int M2=1e9+9013;
const int base1=1e6+33;
const int base2=1e6+37;
const int N=1e5+5;
ll f1(ll x) {
    x=x%M1+0x9eb779b9%M1;
    x%=M1;
    x=x*91138233%M1;
    x^=(x>>16);
    x=x*972663749%M1;
    x^=(x>>15);
    return x;
}
ll f2(ll x) {
    x=x%M2+0x7f4a7c15%M2;
    x%=M2;
    x=x*972663749%M2;
    x^=(x>>13);
    x=x*91138233%M2;
    x^=(x>>16);
    return x;
}
struct int_hash{
    size_t operator()(const int &x) const {
        return f1(x);
    }
};
struct pair_hash{
    size_t operator()(const pair<int,int> &p) const {
        return (f1(p.fi) ^ (f2(p.se)<<1ll));
    }
};
// ACTUAL CODE HERE
//Nhan xet: TBC lon nhat cua mang luon = max cua mang
int n;
void solve() {
    cin>>n;
    int ans=INT_MIN;
    for(int i=1;i<=n;++i) {
        int x;cin>>x;
        maximize(ans,x);
    }
    cout<<ans;
}
signed main() {
    freopen("AVER.INP","r",stdin);
    freopen("AVER.OUT","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
}
