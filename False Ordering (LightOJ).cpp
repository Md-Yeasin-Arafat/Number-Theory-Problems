#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define mod 1e9 + 7
#define N 1000
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

bool isPerfectSquare(long long n)
{
    double root = sqrt(n);
    return floor(root) == root;
}
const int mx = 2e6 + 12;
// Coding starts from here...


vector<int>prime;
vector<pair<int,int>>divisor;
int vis[N];

bool cmp(pair<int,int>x,pair<int,int>y){
  if(x.second<y.second)return true;
  else if(x.second==y.second && x>y)return true;
  else return false; 
}


void findDivisor(int n){
  int ans=1,tmp=n;
  for(auto u:prime){
    int cnt=1;
    
    if(tmp%u==0){
      while(tmp%u==0){
        tmp/=u;
        cnt++;
      }
    }
    ans*=cnt;
  }
  if(tmp>1)ans*=2;
  divisor.push_back({n,ans});
}

void seive(){
  for(int i=3;i*i<=N;i+=2){
    for(int j=i*i;j<=N;j+=i*2){
      vis[j]=1;
    }
  }

  prime.push_back(2);
  for(int i=3;i<=N;i+=2){
    if(!vis[i])prime.push_back(i);
  }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    seive();
    // int t;cin>>t;
    // while(t--){
      for(int i=1;i<=N;i++)findDivisor(i);

      sort(divisor.begin(),divisor.end(),cmp);
      int n;cin>>n;
      for(int i=1;i<=n;i++){
        int x;cin>>x;

        cout<<"Case "<<i<<": "<<divisor[x-1].first<<endl;
      }

    //}


    return 0;
}