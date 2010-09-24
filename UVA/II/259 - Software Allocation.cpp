#include<iostream>
#include<string>
#include<queue>

using namespace std;

int flow[38][38];
int cap[38][38];

bool augmenting(){
    int prev[38];
    fill(prev,prev+38,-1);
    
    queue<int> Q;
    Q.push(0);
    prev[0]=-2;
    
    int aux;
    
    while(!Q.empty()){
        aux=Q.front();
        Q.pop();
        
        for(int i=0;i<38;i++){
            if(flow[aux][i]<cap[aux][i] && prev[i]==-1){
                prev[i]=aux;
                if(i==37) goto found;
                Q.push(i);
            }
        }
    }
    
    return false;
    
    found:
    
    int cur=37,next;
    
    while(cur!=0){
        next=prev[cur];
        flow[next][cur]++;
        flow[cur][next]--;
        cur=next;
    }
    
    return true;
}

int main(){
    string s;
    int N1=1;
    int N2=N1+10;
    int a,b,n,total,f;
    bool found;
    
    while(getline(cin,s)){
        memset(cap,0,sizeof(cap));
        total=0;
        
        do{
            a=N2+s[0]-'A';
            n=s[1]-'0';
            
            for(int i=3;;i++){
                if(s[i]==';') break;
                
                b=N1+s[i]-'0';
                cap[b][a]=1;
            }
            
            cap[a][37]=n;
            total+=n;
            
            getline(cin,s);
        }while(!s.empty());
        
        for(int i=0;i<10;i++) cap[0][N1+i]=1;
        
        memset(flow,0,sizeof(flow));
        f=0;
        
        while(augmenting()) f++;
        
        if(f!=total){
            cout<<'!'<<endl;
            continue;
        }
        
        for(int i=0;i<10;i++){
            found=false;
            
            for(int j=0;j<26;j++){
                if(flow[N1+i][N2+j]==1){
                    found=true;
                    cout<<(char)('A'+j);
                    break;
                }
            }
            
            if(!found) cout<<'_';
        }
        
        cout<<endl;
    }
    
    return 0;
}
