#include <iostream>
#include <sstream>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct flow_graph{
    int MAX_V,E,s,t,head,tail;
    int *cap,*to,*next,*last,*dist,*q,*now;
    
    flow_graph(){}
    
    flow_graph(int V, int MAX_E){
        MAX_V = V; E = 0;
        cap = new int[2*MAX_E], to = new int[2*MAX_E], next = new int[2*MAX_E];
        last = new int[MAX_V], q = new int[MAX_V];
        dist = new int[MAX_V], now = new int[MAX_V];
        fill(last,last+MAX_V,-1);
    }
    
    void clear(){
        fill(last,last+MAX_V,-1);
        E = 0;
    }
    
    void add_edge(int u, int v, int uv, int vu = 0){
        to[E] = v, cap[E] = uv, next[E] = last[u]; last[u] = E++;
        to[E] = u, cap[E] = vu, next[E] = last[v]; last[v] = E++;
    }
	
    bool bfs(){
        fill(dist,dist+MAX_V,-1);
        head = tail = 0;
		
        q[tail] = t; ++tail;
        dist[t] = 0;
		
        while(head<tail){
            int v = q[head]; ++head;
            
            for(int e = last[v];e!=-1;e = next[e]){
                if(cap[e^1]>0 && dist[to[e]]==-1){
                    q[tail] = to[e]; ++tail;
                    dist[to[e]] = dist[v]+1;
                }
            }
        }
        
        return dist[s]!=-1;
    }
	
    int dfs(int v, int f){
        if(v==t) return f;
		
        for(int &e = now[v];e!=-1;e = next[e]){
            if(cap[e]>0 && dist[to[e]]==dist[v]-1){
                int ret = dfs(to[e],min(f,cap[e]));
				
                if(ret>0){
                    cap[e] -= ret;
                    cap[e^1] += ret;
                    return ret;
                }
            }
        }
		
        return 0;
    }
	
    long long max_flow(int source, int sink){
        s = source; t = sink;
        long long f = 0,df;
		
        while(bfs()){
            for(int i = 0;i<MAX_V;++i) now[i] = last[i];
			
            while(true){
                df = dfs(s,INT_MAX);
                if(df==0) break;
                f += df;
            }
        }
		
        return f;
    }
}G(10000+2,8000+38000+1000+1000);

int main(){
    int T,N1,N2,N3,p[1000];
    vector<int> L[1000];
    string personName[1000],clubName[8000];
    map<string, int> partyID,clubID;
    string line,name,party,club;
    bool first = true;
    
    cin>>T;
    getline(cin,line);
    getline(cin,line);
    
    while(T--){
        N1 = N2 = N3 = 0;
        
        partyID.clear();
        clubID.clear();
        G.clear();
        
        while(getline(cin,line)){
            if(line.empty()) break;
            
            istringstream is(line);
            
            is>>name>>party;
            personName[N1] = name;
            
            if(partyID.find(party)==partyID.end())
                partyID[party] = N2++;
            
            p[N1] = partyID[party];
            
            while(is>>club){
                if(clubID.find(club)==clubID.end()){
                    clubID[club] = N3;
                    clubName[N3] = club;
                    ++N3;
                }
                
                L[N1].push_back(clubID[club]);
            }
            
            ++N1;
        }
        
        for(int i = 0;i<N3;++i) G.add_edge(0,1+i,1);
        for(int i = 0;i<N1;++i) G.add_edge(1+N3+i,1+N3+N1+p[i],1);
        for(int i = 0;i<N2;++i) G.add_edge(1+N3+N1+i,1+N3+N1+N2,(N3-1)/2);
        
        for(int i = 0;i<N1;++i){
            for(int j = L[i].size()-1;j>=0;--j){
                int c = L[i][j];
                G.add_edge(1+c,1+N3+i,1);
            }
        }
        
        if(!first) cout<<endl;
        first = false;
        
        if(G.max_flow(0,1+N3+N1+N2)!=N3) cout<<"Impossible."<<endl;
        else{
            int E = G.E;
            
            for(int e = 0;e<E;e += 2){
                int u = G.to[e^1]-1, v = G.to[e]-1-N3;
                
                if(G.cap[e]==0 && u>=0 && u<N3 && v>=0 && v<N1)
                    cout<<personName[v]<<" "<<clubName[u]<<endl;
            }
        }
        
        for(int i = 0;i<N1;++i) L[i].clear();
    }
    
    return 0;
}
