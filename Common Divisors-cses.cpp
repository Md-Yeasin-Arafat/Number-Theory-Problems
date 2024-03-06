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
 
ll mod =1e9+6;
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
 
 
// Coding starts from here...
 
 
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;cin>>n;
    int a[n+2],mx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    
 
    int divisor[mx+2]={0};
    for(int i=1;i<=n;i++)divisor[a[i]]++;
 
 
    int counter=0,ans=0;
    for(int i=mx;i>=1;i--){
        counter=0;
        int j=i;
 
        while(j<=mx){
            if(divisor[j]>=2){
                ans=max(ans,j);
                break;
            }
            else if(divisor[j]==1)counter++;
 
            j+=i;
            if(counter==2){
                ans=max(ans,i);
                break;
            }
        }
    }
    
    cout<<ans<<endl;
    
    
    
    
    // int t;cin>>t;
    // while(t--){
 
    // }
    
 
    return 0;
}