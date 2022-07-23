#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100010];
int vis[100010];
int level[100010];
int parent[100010];
int col[100010];
int dfsvis[100010];

void multisourcebfd(vector<int> vroot,int n){
    deque<int> dq;
    int i;
    for(i =0 ;i < vroot.size();i++){
        level[vroot[i]] = 0;
        dq.push_back(vroot[i]);
        vis[vroot[i]] = 1;
    }
    
    
    while(dq.size() != 0){
        int node = dq.front();
        vector<int> vec;
        while(dq.size() != 0 && level[dq.front()] == level[node]){
            vec.push_back(dq.front());
            dq.pop_front();
        }
        

        for(i =0 ; i < vec.size();i++){
            int node1 = vec[i];
            for(auto it : adj[node1]){
                if(vis[it] == 0){
                    vis[it] = 1 ;
                    level[it] = level[node1] +1 ;
                    dq.push_back(it);
                }                
            }
        }
    }

    for(i =0 ;i < n;i++){
        cout << level[i] << ' ';
    }
}

vector<int> cycle ;
bool dfscycledetc(int root,int parent){
    cycle.push_back(root);
    vis[root] = 1  ;
    for(auto it: adj[root]){
        if(it != parent && vis[it] == 1){
            cycle.push_back(it);
            return 1;
        }else if(it != parent){
            if(dfscycledetc(it,root))return 1;
        }
    }
    cycle.pop_back();
    return 0;
}

void bfscycle(int root){
    int i;
    parent[root] = -1;
    deque<int> dq;
    dq.push_back(root);
    vis[root] =1 ;
    while(dq.size() != 0){
        int node = dq.front();
        dq.pop_front();
        cout << node << ' ';
        int par = parent[node];
        for(auto it : adj[node]){
            if(it != par && vis[it] == 1){
                cout << "cycle detetcts";
                return ;
            }else if(it != par){
                dq.push_back(it);
                vis[it] = 1  ;
                parent[it] = node;
            }
        }

    }

}

void bfdbipartite(int root, int n){
    int i;
    for(i =0 ; i < n;i++)col[i] = -1;
    
    deque<int> dq;
    dq.push_back(root);
    vis[root] =1 ;
    col[root] = 0;
    while(dq.size() != 0){
        int node = dq.front();
        dq.pop_front();
        for(auto it : adj[node]){
            if(col[it] == col[node]){
                cout << "no bipartite";
                return ;
            }
            if(vis[it] == 0){
                vis[it] = 1;
                col[it] = col[node] ^ 1;
                dq.push_back(it);
            }
        }

    }

}

void dfscycle(int root){
    vis[root] = 1;
    dfsvis[root] = 1;
    for(auto it : adj[root]){
        if(vis[it] == 0 )dfscycle(it);
        else if(vis[it] && dfsvis[it]){
            cout << "cycle deteced";
            return ;
        }
    }

    dfsvis[root] = 0;
    
}

vector<int> toposort;
void toposort1(int root){
    vis[root] = 1;
    for(auto it : adj[root]){
        if(vis[it] == 0)toposort1(it);
    }
    toposort.push_back(root);
}

void kahns(int n){
    int i;
    int indegree[n];
    for(i = 0 ; i <n;i++){
       indegree[i] =0 ;
    }
    for(i =0 ;i <n;i++){
        int j;
        for(j =0 ; j < adj[i].size();j++)indegree[adj[i][j]]++;
    }

    deque<int> dq;
    for(i= 0;i< n;i++){
        if(indegree[i] == 0){dq.push_back(i);vis[i] = 1;}
    }
    vector<int> ans;

    while(dq.size() != 0){
        int node = dq.front();
        ans.push_back(node);
        
        dq.pop_front();
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0  && vis[it] == 0){
               dq.push_back(it);
               vis[it] = 1;
            }
        }
    }
    
    cout << ans.size() << endl;
    
}

void unweighted(){
    int n;
    cin >> n;
    int m;
    cin >> m;

    int i;
    for(i =0 ; i <m;i++){

        int x,y;
        
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // toposort1(0);
    // reverse(toposort.begin(),toposort.end());
    // for(i =0 ; i < toposort.size();i++){
    //     cout << toposort[i] + 1 << ' ';
    // }

    // kahns(n);
    //  bfscycle(0);
    // bfdbipartite(0,n);
    // dfscycle(0);
    

}



vector<pair<int,int>> adw[100010];
int dist[100010];
void djkstra(int root,int n){
    int i;
    for(i =0 ; i < n;i++)dist[i] = INT_MAX;
    
    dist[root] = 0;
    set<pair<int,int>> st;
    st.insert({0,root});

    while(st.size() != 0){
        auto pa = st.begin();
        pair<int,int> p =  *pa;
        int node = p.second;
        int noded = p.first;
        
        st.erase(st.begin());
        for(auto it: adw[node]){
            if(dist[it.first] > noded + it.second){
                st.erase({dist[it.first],it.first});
                dist[it.first] = it.second + noded;
                st.insert({dist[it.first],it.first});
            }
        }
    }

    for(i =0; i < n;i++)cout << dist[i] << " ";
  
}

vector<vector<int>> edges;

void bellmonford(long long  root,long long n){
    int i , j;
    for(i =0 ;i < n;i++)dist[i] = INT_MAX;
    dist[root] = 0;
    
    for(i =0 ;i < n - 1;i++){
        for(j =0 ; j < edges.size();j++){ 
            vector<int> v = edges[j];
            int s = v[0];
            int d = v[1];
            int w = v[2];
            if( dist[d] > dist[s] + w){
                dist[d] = dist[s] + w;
            }
        }

        for(j =0 ; j < n;j++){
            cout << dist[i] << ' ';
        }
        cout << endl;

        
    }

}

long long dis[1001][1001];
void floyydwarshal(long long n){
    long long i ,j;
    long long k;
    
    

    for(k =0 ; k < n;k++){
        for(i =0 ; i < n;i++){
            for(j =0 ; j < n;j++){
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
                
            }
        }
    }

    for(i =0 ; i < n;i++){
        for(j =0 ; j < n;j++){
            cout << dis[i][j] << ' ';
        }
        cout << endl;
    }
}


void weighted(){
    int n, m;
    cin >> n >> m;
    int i,j;
    for(i =0 ; i < n;i++){
        for(j =0 ; j < n;j++){
        if(i != j)dis[i][j] = INT_MAX;
        else dis[i][j] = 0;
    }
    }
    for(i =0 ;i < m;i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--; 
        int z;
        cin >> z;
        edges.push_back({x,y,z});
        edges.push_back({y,x,z});
        
        dis[x][y] = z;
        dis[y][x] = z;
    }

   
     
    // djkstra(0,n);
    // bellmonford(0,n);
    floyydwarshal(n);
}
int main(){
    
    //  unweighted();
    weighted();

    
   
    
    
    
    
    
    
    
    
    
    
    
}