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
//Tom tat: Cho n tam van, moi tam van co chieu cao la hi
//Chon ra chieu cao g, sau do tai moi tam van co hi>=g
//Ta se dong dinh cac van nay
//TIm do cao g nho nhat sao cho so van bi dong <=k
//NHan xet: g cang lon -> so van bi dong cang it
//NHan xet: g cang be -> so van bi dong cang lon
//-> Tim g be nhat sao cho so van bi dong <=k
int n,k;
int H[N];
bool f(int mid) {
    int cnt=0;
    for(int i=1;i<=n;++i) {
        if (H[i]>=mid) ++cnt;
    }
    return (cnt<=k);
}
void solve() {
    cin>>n>>k;
    int mx=-1;
    for(int i=1;i<=n;++i) {
        cin>>H[i];
        mx=max(mx,H[i]);
    }
    int l=1,r=mx,ans=-1;
    while(l<=r) {
        int mid=l+r >>1;
        if (f(mid)) {
            ans=mid;
            r=mid-1;
        }
        else {
            l=mid+1;
        }
    }
    cout<<ans;
    cout<<'\n';
}
signed main() {
    freopen("PLANK.INP","r",stdin);
    freopen("PLANK.OUT","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
}
