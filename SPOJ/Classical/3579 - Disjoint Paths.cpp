#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

#define SZ 1000

int flow[SZ][SZ],cap[SZ][SZ],prev[SZ],f;
//inicializar cap y flow en 0

void init(){
	f = 0;
	memset(flow,0,sizeof(flow));
	memset(cap,0,sizeof(cap));
}

int Q[SZ],head,tail;

bool augmenting(int N, int t){
    fill(prev,prev+N,-1);
    head = tail = 0;
    Q[tail] = 1; ++tail;
    prev[1] = -2;
    
    int aux;
    
    while(head<tail){
        aux = Q[head]; ++head;
        
        for(int i = 0;i<N;++i){
            if(flow[aux][i]<cap[aux][i] && prev[i]==-1){
                prev[i] = aux;
                if(i==t) goto found;
                Q[tail] = i; ++tail;
            }
        }
    }
    
    return false;
    
    found:
    
    int cur = t,next;
    ++f;
    
    while(cur!=1){
        next = prev[cur];
        ++flow[next][cur];
        --flow[cur][next];
        cur = next;
    }
    
    return true;
}

int main(){
	int tc = 1,N,K,v;
	bool used[SZ];
	string s;
	
	while(true){
		cin>>K>>N;
		if(N==0) break;
		
		init();
		getline(cin,s);
		
		for(int i = 2;i<N;++i) cap[2*i][2*i+1] = 1;
		
		for(int i = 0;i<N;++i){
			getline(cin,s);
			istringstream is(s);
			fill(used,used+N,false);
			
			while(is>>v){
				--v;
				if(used[v]) continue;
				used[v] = true;
				cap[2*i+1][2*v] = 1;
			}
		}
		
		for(int i = 0;i<K;++i) augmenting(2*N,2);
		
		cout<<"Case "<<tc<<":"<<endl;
		++tc;
		
		if(f<K) cout<<"Impossible"<<endl;
		else{
			fill(used,used+(2*N),false);
			
			for(int i = 0;i<2*N;++i){
				if(flow[1][i]==0) continue;
				flow[i][1] = 0;
				int pos = i;
				cout<<1<<" "<<1+i/2;
				
				while(pos!=2){
					for(int j = 0;j<2*N;++j){
						if(flow[pos][j]==1){
							flow[pos][j] = 0;
							pos = j;
							if(pos%2==0) cout<<" "<<1+pos/2;
							break;
						}
					}
					
				}
				
				cout<<endl;
			}
		}
		
		cout<<endl;
	}
	
	return 0;
}
