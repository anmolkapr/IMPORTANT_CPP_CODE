#include<bits/stdc++.h>
using namespace std;

//PRIMS
vector<int> adj[200010];
int key[200010];
int parent[200010];
int mst[200010];
map<pair<int,int>,int> weight;

int prims(int n){
    multiset<pair<int,int>> st;
    int i;
    for(i =0 ; i < n;i++){
        parent[i] = -1;
        mst[i] = 0;
        key[i] = INT_MAX;
    }

    key[0] =0 ;
    for(i =0 ;i < n;i++){
        st.insert({key[i],i});
    }
    while(st.size() != 0){
        pair<int,int> p = *st.begin();
        int y = p.second;

        mst[y] = 1;
        st.erase(st.begin());

        int i;
        for(i =0 ; i < adj[y].size();i++){
            int val = adj[y][i];
            if(key[val] > weight[{val,y}] && mst[val] == 0){
                st.erase(st.find({key[val],val}));
                key[val] = weight[{val,y}];
                parent[val] = y;
                st.insert({key[val],val});               
            }
        }
    }

    int cost = 0;
    for(i= 1; i < n;i++){
        cost = cost + weight[{parent[i],i}];
    }
    cout << cost;
    return cost;
}


int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    int i;
    for(i =0 ;i < m;i++){
       int x, y;
       cin >> x >> y;
       adj[x].push_back(y);
       adj[y].push_back(x);
       int z;
       cin >> z;
       weight[{x,y}] = z;
       weight[{y,x}] = z;
    }

    prims(n);





}