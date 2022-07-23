#include<bits/stdc++.h>
using namespace std;


int dp[200000][24];

int query(int x, int y){
    int len = y - x + 1;
    x--;
    int ans = INT_MAX;

    int numlen = log2(len) +1 ;
    int steps = 0;
    int x1= 1;
    int index = x;

    while(steps < numlen){
        if(len & 1){
            
            ans = min(ans,dp[index][steps]);
            index = index + x1;
        }
       
        len = len >> 1;
        steps++;
    }

    return ans;

}

int main(){
    int n;
    cin >> n;

    int arr[n];
     int q;
    cin >> q;
    
     int i , j;
    for(i = 0 ; i < n;i++){
        cin >> arr[i];
    }
    int x  = log2(n);
    
    
    for(i =0 ; i <= x;i++){
        for(j =0 ; j <= n;j++)dp[i][j] = INT_MAX;
    }
    
   
    for(i =0 ;i < n;i++)dp[i][0] = arr[i];
    
    for(j =1 ; j<= x;j++){

        for(i =0 ;i + pow(2,j ) <= n ;i++){
            int x = pow(2,j-1);
            dp[i][j] = min(dp[i + x ][j-1],dp[i][j-1]);
        }
    }

    // for(j =0 ; j <= x;j++){
    //     cout << pow(2,j) << "->\n";
    //    for(i =0 ; i < n;i++){
    //        cout << i << ' ' << dp[i][j] << endl;
    //    }
    //    cout << endl;
    // }

   
    for(i =0 ; i < q;i++){
        int x, y;
        cin >> x >> y;
        cout << query(x,y) << endl;
    }
}