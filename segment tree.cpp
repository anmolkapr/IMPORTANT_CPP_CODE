#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double  
ll i,n;
ll mod = 139 + 7;
ll find_nth_root(ll X, int n)
{ll nth_root=std::trunc(std::pow(X,1.0/n));if(std::pow(nth_root+1,n)<=X){return nth_root + 1;}
return nth_root;} 
bool checkperfectsquare(ll n){ if (ceil((double)sqrt(n)) == floor((double)sqrt(n)))
{ return true; }else{ return false; } }
ll bexp(ll a, ll b){ ll res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } 
return res; }
ll bexpM(ll a, ll b, ll mod) { ll res = 1; while (b > 0) 
{ if (b & 1) res = (res * a) % mod; a = (a%mod * a%mod) % mod; b >>= 1; } return res; }
vector<ll> divisorsofanum(ll n){ vector<ll> v; for(i= 2; i < sqrt(n);i++){ if(n%i == 0)
{ v.push_back(i); v.push_back(n/i); } }
if(checkperfectsquare(n) == 1){ v.push_back(sqrt(n)); } return v; }
void precision(int a){ cout << setprecision(a) << fixed << endl; } 
ll modInverse(ll a, ll m){return bexpM(a,m - 2, m);}
ll gpsum(ll a, ll r, ll t){ll rpow = bexpM(r,t,mod);
ll ans = ((( rpow%mod + mod - 1)%mod)*(a%mod))%mod;
ans = ans%mod*(modInverse((r%mod - 1 + mod)%mod, mod)%mod);ans = ans%mod;return ans;}

const int P = 1e6;
bool prime[P + 1];

void SieveOfEratosthenes(int n)
{memset(prime, true, sizeof(prime));
for (int p = 2; p * p <= n; p++){if (prime[p] == true)
{for (int i = p * p; i <= n; i += p)prime[i] = false;}}}
vector<ll> adj[100010];bool visited[100010];vector<ll> graph;
void dfs(ll node){graph.push_back(node);visited[node]=true;
for(auto x: adj[node]){if(!visited[x]){dfs(x);}}}
 
 
 void buildtree(ll l , ll r, ll tree[], ll arr[] , ll treein){
     if(l == r){tree[treein] = arr[l];return ;}
     ll mid = (l + r)/2;
     buildtree(l,mid,tree,arr,2*treein);
     buildtree(mid + 1,r,tree,arr,2*treein + 1);
     tree[treein] = tree[2*treein] + tree[2*treein + 1];
 }

 void updatetree(ll l ,ll r, ll tree[],ll arr[],ll treein,ll in , ll val){
     if(l == r && l == in){arr[in] = val;tree[treein] = val;return ;}
     ll mid = (l + r)/2;
     if(mid < in){
         updatetree(mid + 1, r,tree,arr,2*treein + 1,in ,val);}
         else{
         updatetree(l, mid,tree,arr,2*treein ,in ,val);
     }
     tree[treein] = (tree[2*treein] + tree[2*treein + 1]);
 }
 ll sumquery(ll l ,ll r, ll tree[],ll arr[],ll treein,ll s , ll e){
     if(s > r || e < l)return 0;
     if(l >= s && r <= e)return tree[treein];
     ll mid = (l + r)/2;
     ll p1  = sumquery(l,mid,tree,arr,2*treein,s,e);
     ll p2  = sumquery(mid + 1,r,tree,arr,2*treein + 1,s,e);
     return p1 + p2;
 }

 void buildtreeformin(ll l , ll r, ll tree[], ll arr[] , ll treein){
     if(l == r){tree[treein] = arr[l];return ;}
     ll mid = (l + r)/2;
     buildtreeformin(l,mid,tree,arr,2*treein);
     buildtreeformin(mid + 1,r,tree,arr,2*treein + 1);
     tree[treein] = min(tree[2*treein],tree[2*treein + 1]);
 }

 ll minquery(ll l ,ll r, ll tree[],ll arr[],ll treein,ll s , ll e){
     if(s > r || e < l)return INT_MAX;
     if(l >= s && r <= e)return tree[treein];
     ll mid = (l + r)/2;
     ll p1  = minquery(l,mid,tree,arr,2*treein,s,e);
     ll p2  = minquery(mid + 1,r,tree,arr,2*treein + 1,s,e);
     return min(p1,p2);
 }
 
 void updatemintree(ll l ,ll r, ll tree[],ll arr[],ll treein,ll in , ll val){
     if(l == r && l == in){arr[in] = val;tree[treein] = val;return ;}
     ll mid = (l + r)/2;
     if(mid < in){
         updatemintree(mid + 1, r,tree,arr,2*treein + 1,in ,val);}
         else{
         updatemintree(l, mid,tree,arr,2*treein ,in ,val);
     }
     tree[treein] = min(tree[2*treein],tree[2*treein + 1]);
 }
 /////////////////////////////////////////////////////////////

 void buildtreeformax(ll l , ll r, ll tree[], ll arr[] , ll treein){
     if(l == r){tree[treein] = arr[l];return ;}
     ll mid = (l + r)/2;
     buildtreeformax(l,mid,tree,arr,2*treein);
     buildtreeformax(mid + 1,r,tree,arr,2*treein + 1);
     tree[treein] = max(tree[2*treein],tree[2*treein + 1]);
 }

//  ll maxquery(ll l ,ll r, ll tree[],ll arr[],ll treein,ll s , ll e){
//      if(s > r || e < l)return INT_MIN;
//      if(l >= s && r <= e)return tree[treein];
//      ll mid = (l + r)/2;
//      ll p1  = maxquery(l,mid,tree,arr,2*treein,s,e);
//      ll p2  = maxquery(mid + 1,r,tree,arr,2*treein + 1,s,e);
//      return max(p1,p2);
//  }
 
 void updatemaxtree(ll l ,ll r, ll tree[],ll arr[],ll treein,ll in , ll val){
     if(l == r && l == in){arr[in] = val;tree[treein] = val;return ;}
     ll mid = (l + r)/2;
     if(mid < in){
         updatemaxtree(mid + 1, r,tree,arr,2*treein + 1,in ,val);}
         else{
         updatemaxtree(l, mid,tree,arr,2*treein ,in ,val);
     }
     tree[treein] = max(tree[2*treein],tree[2*treein + 1]);
 }

 void buildtreeforpairmax(ll l , ll r, ll tree[],ll mtree[], ll arr[] , ll treein){
     if(l == r){tree[treein] = INT_MIN;return ;}
     ll mid = (l + r)/2;
     buildtreeforpairmax(l,mid,tree,mtree,arr,2*treein);
     buildtreeforpairmax(mid + 1,r,tree,mtree,arr,2*treein + 1);
     ll x = mtree[2*treein];
     ll y = mtree[2*treein + 1];
     
     tree[treein] = max(tree[2*treein],tree[2*treein + 1]);
     tree[treein] = max(tree[treein],x + y);
     
 }

  ll maxquery(ll l ,ll r, ll tree[],ll arr[],ll treein,ll s , ll e){
     if(s > r || e < l)return INT_MIN;
     
     if(l >= s && r <= e)return tree[treein];
     ll mid = (l + r)/2;
     ll p1  = maxquery(l,mid,tree,arr,2*treein,s,e);
     ll p2  = maxquery(mid + 1,r,tree,arr,2*treein + 1,s,e);
     
     return max(p1,p2);
 }
 
 void updatepmaxtree(ll l ,ll r, ll tree[],ll mtree[],ll arr[],ll treein,ll in , ll val){
     if(l == r && l == in){return ;}
     ll mid = (l + r)/2;
     if(mid < in){
         updatepmaxtree(mid + 1, r,tree,mtree,arr,2*treein + 1,in ,val);}
         else{
         updatepmaxtree(l, mid,tree,mtree,arr,2*treein ,in ,val);
     }
     
     tree[treein] = max(tree[2*treein],tree[2*treein + 1]);
   
     tree[treein] = max(tree[treein],mtree[2*treein] + mtree[2*treein + 1]);
 }

  
  ll maxpquery(ll l ,ll r,ll n, ll tree[],ll mtree[],ll arr[],ll treein,ll s , ll e){
      if(e < l || s >r ){
          return INT_MIN;
      }
      ll mid = (l + r)/2;
      if(l == s && r == e){
          return tree[treein];
      }
      if(s > mid){
          return maxpquery(mid + 1, r,n,tree,mtree,arr,2*treein + 1,s,e);
      }
       if(e <= mid){
          return maxpquery(l, mid,n,tree,mtree,arr,2*treein,s,e);
      }
      ll x = maxpquery(l, mid,n,tree,mtree,arr,2*treein,s,mid);
      ll y =  maxpquery(mid + 1, r,n,tree,mtree,arr,2*treein + 1,mid + 1,e);
     
      ll t1 = maxquery(0, n-1,mtree,arr,1,s,mid);
    
      ll t2 = maxquery(0, n-1,mtree,arr,1,mid + 1,e);
       
      ll f = max(x,y);
      return max(f,t1 + t2);
      
      }




 





 
 
 
 
void solve(){
   ll n;
   cin >> n;
   ll arr[n];
   for(i =0 ; i < n;i++)cin >> arr[i];
   ll q;
   cin >> q;
   ll tree[4*n];
   buildtreeformax(0,n-1,tree,arr,1);
   for(i =0 ; i < q;i++){
       ll l ,r;
       cin >> l >> r;
       
       cout << maxquery(0,n-1,tree,arr,1,l,r) <<  endl;

   }


 
   







    
}
 
 
 
 
int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int t=1;
//cin>>t;
while(t--){
    solve();
 cout << endl;
}
 
}


 