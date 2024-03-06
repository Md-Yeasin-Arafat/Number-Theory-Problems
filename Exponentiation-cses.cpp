#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define N 10000006
#define all(x) (x).begin(), (x).end()
#define LL_INF (1LL << 62)
#define INF (1 << 30)
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x >> k) & 1)
// cout<<fixed<<setprecession(8)<<ans<<endl;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
// #include <ext/pb_ds/detail/standard_policies.hpp>
// using namespace __gnu_pbds;
// typedef tree<
// ll,
// null_type,
// less<ll>,
// rb_tree_tag,
// tree_order_statistics_node_update>
// ordered_set;
 
bool isPerfectSquare(long long n)
{
    double root = sqrt(n);
    return floor(root) == root;
}
const int mx = 2e6 + 12;
 
// Coding starts from here...
 
ll mod =1e9+7;
ll fact[N];
ll powerMod(ll a, ll b)
{
   if (b == 0)
       return 1;
 
 
   if (b % 2 == 0)
   {
       ll x = powerMod(a, b / 2);
       return (x * x) % mod;
   }
   else
   {
       ll x = powerMod(a, b / 2);
       return ((x * x) % mod * a) % mod;
   }
 
 
   return 0;
}
 
 
ll inverseMod(ll a)
{
   return powerMod(a, mod - 2);
}
 
 
ll nCrMod(ll n, ll r)
{
   if (r == 0)
       return 1;
   if (r > n)
       return 0;
 
 
   return (fact[n] * inverseMod((fact[r] * fact[n - r]) % mod)) % mod;
}
void factorial()
{
   fact[0] = 1;
   for (int i = 1; i < N; i++)
   {
       fact[i] = (fact[i - 1] * i) % mod;
   }
}
 
ll nCr(ll n, ll r)
{
 
    ll p = 1, k = 1;
 
    if (n - r < r)
        r = n - r;
 
    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
 
            ll m = __gcd(p, k);
 
            p /= m;
            k /= m;
 
            n--;
            r--;
        }
    }
 
    else
        p = 1;
    return p;
}
 
// Coading starts from here...
ll solve(ll a, ll b){
    ll res=1;
    while(b>0){
        if(b&1)res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
 
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t;cin>>t;
    while(t--){
        ll a,b;cin>>a>>b;
        cout<<solve(a,b)<<endl;
 
 
    }
    
 
    return 0;
}