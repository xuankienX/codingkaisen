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
const int B=450;
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
ll block_val[B];
int ID[N], L[B], R[B], cntblock;
int A[N],n,q;
void update(int p,int val) {
    block_val[ID[p]]-=A[p];
    A[p]=val;
    block_val[ID[p]]+=A[p];
}
ll get(int l,int r) {
    ll res=0;
    for(int i=1;i<=cntblock;++i) {
        if (r<L[i]||R[i]<l) continue;
        if (l<=L[i]&&R[i]<=r) {
            res+=block_val[i];
        }
        else {
            for(int j=max(L[i],l);j<=min(R[i],r);++j) {
                res+=A[j];
            }
        }
    }
    return res;
}
void solve() {
    cin>>n>>q;
    for(int i=1;i<=n;++i) {
        cin>>A[i];
        if (i%B==1) {
            ++cntblock;
            L[cntblock]=i;
        }
        R[cntblock]=i;
        ID[i]=cntblock;
        block_val[cntblock]+=A[i];
    }
    while(q--) {
        int type;cin>>type;
        if (type==1) {
            int p,val;cin>>p>>val;
            update(p,val);
        }
        else {
            int l,r;cin>>l>>r;
            cout<<get(l,r)<<'\n';
        }
    }

}
signed main() {
    freopen("RANGE.INP","r",stdin);
    freopen("RANGE.OUT","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
}
