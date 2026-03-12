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
int n;
ll x;
int A[25][2];
void sub1() {
    ll res=0;
    res+=A[1][0];
    --x;
    res+=1ll * A[1][1]*x;
    cout<<res;
}
bool f(ll mid) {
    ll cnt=0;
    for(int i=1;i<=n;++i) {
        ll temp=mid;
        if (temp<A[i][0]) continue;
        temp-=A[i][0];
        if (cnt>LLONG_MAX-1-temp/A[i][1]) return true;
        cnt+=temp/A[i][1] + 1;
    }
    return (cnt>=x);
}
void sub3() {
    ll l=0,r=5e17+1e3,ans=0;
    while(l<=r) {
        ll mid=l+r >>1;
        if (f(mid)) {
            ans=mid;
            r=mid-1;
        }
        else {
            l=mid+1;
        }
    }
    cout<<ans;
}
void solve() {
    cin>>n>>x;
    for(int i=1;i<=n;++i) {
        cin>>A[i][0]>>A[i][1];
    }
    if (n==1) sub1();
    else sub3();
}
signed main() {
    freopen("CHICKEN.INP","r",stdin);
    freopen("CHICKEN.OUT","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
}
