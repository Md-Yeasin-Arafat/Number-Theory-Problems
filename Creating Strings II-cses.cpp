#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define N 1000006
#define all(x) (x).begin(), (x).end()
#define LL_INF (1LL << 62)
#define INF (1 << 30)
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x >> k) & 1)
// cout<<fixed<<setprecession(8)<<ans<<endl;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
    typedef tree<
    ll,
    null_type,
    less<ll>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
 
ll fact[N+5],inv[N+5],mod=1e9+7;
const int mx = 2e6 + 12;
 
ll powerMod(ll a, ll b){
    if(b==0)return 1;
    if(b%2==0){
        ll x=powerMod(a,b/2);
        return (x*x)%mod;
    }
    else{
        ll x=powerMod(a,b/2);
        return ((x*x)%mod * a)%mod;
    }
 
    return 0;
}
 
ll inverseMod(ll n){
    return powerMod(n,mod-2);
}
 
ll nCrMod(ll n, ll r){
    if(r==0)return 1;
    if(r>n)return 0;
 
    return (fact[n] * inverseMod((fact[r] * fact[n-r])%mod))%mod;
}
 
void factorial(){
    fact[0]=inv[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=(fact[i-1]*i)%mod;
        inv[i]=inverseMod(fact[i]);
    }
}
// Coding starts from here...
 
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    factorial();
    
    string s;cin>>s;
    int sz=s.size();
    int frq[30]={0};
    for(int i=0;i<sz;i++){
        frq[s[i]-'a']++;
    }
 
 
    ll ans=fact[sz];
    for(int i=0;i<26;i++)ans=(ans*inv[frq[i]])%mod;
    cout<<ans<<endl;

 
    return 0;
}