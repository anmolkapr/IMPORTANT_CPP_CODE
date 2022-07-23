#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll BIT[1000010];

void update(ll index, ll val,ll n){
   ll i;
   for(i = index ; i <= n;i = i + (i & (-i))){
       BIT[i] ^= val;
   } 
}

ll query(ll r, ll n ){
    ll i;
    ll sum = 0;
    for(i = r; i >= 1; i = i - (i & (-i))){
       sum = sum ^ BIT[i];
    }

    return sum;
}

int main(){
    ll n;
    cin >> n;
    ll q;
    cin >> q;
    ll arr[n + 1];
    ll i;
    for(i = 1; i <= n;i++){
        cin >> arr[i];
           update(i,arr[i],n);
    }
    for(i =0 ; i < q;i++){        
        ll x, y;
        cin >> x >> y;
        ll diff = 0;
        if(x != 1)diff = query(x - 1, n);
        ll g = query(y,n) ^ diff;
        cout <<g << endl;
        
    }

   

}