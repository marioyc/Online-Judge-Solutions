#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<string, int> id;
vector<int> adj[300];
int dist[300];

void bfs(){
    int Q[300],head = 0,tail = 0;
    
    memset(dist,-1,sizeof(dist));
    
    if(id.find("Isenbaev") != id.end()){
        int s = id["Isenbaev"];
        
        dist[s] = 0;
        Q[tail] = s;
        ++tail;
        
        while(head < tail){
            int cur = Q[head];
            ++head;
            
            for(int i = adj[cur].size()-1;i >= 0;--i){
                int nxt = adj[cur][i];
                
                if(dist[nxt] == -1){
                    dist[nxt] = dist[cur] + 1;
                    Q[tail] = nxt;
                    ++tail;
                }
            }
        }
    }
}

int main(){
    int N;
    
    cin >> N;
    
    int V = 0;
    string s1,s2,s3;
    
    for(int i = 0;i < N;++i){
        cin >> s1 >> s2 >> s3;
        
        if(id.find(s1) == id.end()) id[s1] = V++;
        if(id.find(s2) == id.end()) id[s2] = V++;
        if(id.find(s3) == id.end()) id[s3] = V++;
        
        int a = id[s1],b = id[s2],c = id[s3];
        
        adj[a].push_back(b); adj[a].push_back(c);
        adj[b].push_back(a); adj[b].push_back(c);
        adj[c].push_back(a); adj[c].push_back(b);
    }
    
    bfs();
    
    for(map<string, int>::iterator it = id.begin();it != id.end();++it){
        cout << it->first << " ";
        
        if(dist[it->second] == -1) cout << "undefined" << endl;
        else cout << dist[it->second] << endl;
    }
    
    return 0;
}
