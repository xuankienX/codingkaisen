//Author: Raine
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define il inline
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
template <class X,class Y>
    bool maximize(X &x, const Y &y) {
        if (x<y) {
            x=y;
            return true;
        }
        else return false;
    }
template <class X,class Y>
    bool minimize(X &x,const Y &y) {
        if (x>y) {
            x=y;
            return true;
        }
        return false;
    }
const int M1=1e9+9009;
const int M2=1e9+9013;
const int base1=1e6+33;
const int base2=1e6+37;
const int N=2e5+5;
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
    size_t operator()(const ll &x) const {
        return f1(x);
    }
};
struct pair_hash{
    size_t operator()(const pair<ll,ll> &p) const {
        return (f1(p.fi) ^ (f2(p.se)<<1));
    }
};

//ACTUAL CODE HERE

struct SegmentTree{
    vector<ll> st,lazy;
    SegmentTree(int n) : st(4*n), lazy(4*n) {}
    void propagate(int id,int l,int r) {
        int mid=l+r >>1;
        st[id*2]+=(mid-l+1)*lazy[id];
        st[id*2+1]+=(r-mid)*lazy[id];
        lazy[id*2]+=lazy[id];
        lazy[id*2+1]+=lazy[id];
        lazy[id]=0;
    }
    void update(int id,int l,int r,int u,int v,ll val) {
        if (r<u||v<l) return;
        if (u<=l&&r<=v) {
            st[id]+=(r-l+1)*val;
            lazy[id]+=val;
            return;
        }
        propagate(id,l,r);
        int mid=l+r >>1;
        update(id*2,l,mid,u,v,val);
        update(id*2+1,mid+1,r,u,v,val);
        st[id]=st[id*2]+st[id*2+1];
    }
    ll get(int id,int l,int r,int u,int v) {
        if (r<u||v<l) return 0;
        if (u<=l&&r<=v) {
            return st[id];
        }
        propagate(id,l,r);
        int mid=l+r >>1;
        return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
    }
};
int n;
int A[N];
vector<int> can;
void solve() {
    cin>>n;
    SegmentTree st1(2e5+5);
    for(int i=1;i<=n;++i) {
        cin>>A[i];
        can.push_back(A[i]);
    }
    sort(all(can));
    can.erase(unique(all(can)),can.end());
    for(int i=1;i<=n;++i) {
        A[i]=lower_bound(all(can),A[i])-can.begin()+1;
    }
    ll ans=0;
    for(int i=1;i<=n;++i) {
        ans+=st1.get(1,1,2e5,A[i]+1,2e5);
        st1.update(1,1,2e5,A[i],A[i],1);
    }
    cout<<ans;

}
signed main() {
    freopen("INVERSION.INP","r",stdin);
    freopen("INVERSION.OUT","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
}
