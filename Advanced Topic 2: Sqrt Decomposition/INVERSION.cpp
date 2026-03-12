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
const int B=325;
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
struct query{
    int l,r,id;
};
bool cmp(const query &a,const query &b) {
    int blocka=a.l/B;
    int blockb=b.l/B;
    if (blocka!=blockb) return (blocka<blockb);
    if (blocka&1) return (a.r>b.r);
    return (a.r<b.r);
}
int BIT[N];
void update(int p,int val) {
    for(;p<N;p+=(p&(-p))) BIT[p]+=val;
}
int get(int p) {
    int sum=0;
    for(;p>0;p-=(p&(-p))) sum+=BIT[p];
    return sum;
}
ll CUR;
int n,q;
int A[N];
query Q[N];
ll ANS[N];
int curl=1,curr=0;
vector<int> can;
void add(int p,bool side) {
    if (side) {
        CUR+=get(1e5)-get(A[p]);
    }
    else {
        CUR+=get(A[p]-1);
    }
    update(A[p],1);
}
void del(int p,bool side){
    if (side) {
        CUR-=get(1e5)-get(A[p]);
    }
    else {
        CUR-=get(A[p]-1);
    }
    update(A[p],-1);
}
void solve() {
    cin>>n>>q;
    for(int i=1;i<=n;++i) {
        cin>>A[i];
        can.push_back(A[i]);
    }
    sort(all(can));
    can.erase(unique(all(can)),can.end());
    for(int i=1;i<=n;++i) {
        A[i]=lower_bound(all(can),A[i])-can.begin()+1;
    }
    for(int i=1;i<=q;++i) {
        cin>>Q[i].l>>Q[i].r;
        Q[i].id=i;
    }
    sort(Q+1,Q+q+1,cmp);
    for(int i=1;i<=q;++i) {
        int l=Q[i].l,r=Q[i].r,id=Q[i].id;
        while(curl<l) del(curl++,0);
        while(curr<r) add(++curr,1);
        while(curl>l) add(--curl,0);
        while(curr>r) del(curr--,1);
        ANS[id]=CUR;
    }
    for(int i=1;i<=q;++i) {
        cout<<ANS[i]<<'\n';
    }
}
signed main() {
    freopen("INVERSION.INP","r",stdin);
    freopen("INVERSION.OUT","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
}
