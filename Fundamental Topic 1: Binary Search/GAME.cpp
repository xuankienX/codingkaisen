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
int n;
int A[N], B[N];
void solve() {
    cin>>n;
    for(int i=1;i<=n;++i) {
        cin>>A[i];
    }
    for(int i=1;i<=n;++i) {
        cin>>B[i];
    }
    sort(A+1,A+n+1);
    sort(B+1,B+n+1);
    int ans=INT_MAX;
    for(int i=1;i<=n;++i) {
        int l=1,r=n,pos=n+1;
        while(l<=r) {
            int mid=l+r >>1;
            if (B[mid]>=-A[i]) {
                pos=mid;
                r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        if (pos<=n&&pos>=1) minimize(ans,abs(B[pos]+A[i]));
        --pos;
        if (pos<=n&&pos>=1) minimize(ans,abs(B[pos]+A[i]));
    }
    cout<<ans;
}
signed main() {
    freopen("GAME.INP","r",stdin);
    freopen("GAME.OUT","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
}
