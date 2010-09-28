#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n,m,d;
char map1[20][21];
char map2[20][21];

int flow[802][802];
int cap[802][802];
vector< vector<int> > L;
int prev[802];

bool escape(int i, int j){
    if(i+1<=d || j+1<=d || n-i<=d || m-j<=d) return true;
    return false;
}

bool augmenting(int &N){
    fill(prev,prev+N,-1);
    queue<int> Q;
    Q.push(0);
    prev[0]=-2;
    
    int aux;
    
    while(!Q.empty()){
        aux=Q.front();
        Q.pop();
        
        for(int i=0;i<L[aux].size();i++)
            if(flow[aux][L[aux][i]]<cap[aux][L[aux][i]] && prev[L[aux][i]]==-1){
                prev[L[aux][i]]=aux;
                if(L[aux][i]==N-1) goto found;
                Q.push(L[aux][i]);
            }
    }
    
    return false;
    
    found:
    
    int cur=N-1,next;
    
    while(cur!=0){
        next=prev[cur];
        flow[next][cur]++;
        flow[cur][next]--;
        cur=next;
    }
    
    return true;
}

int main(){    
    int T,f,cont;
    int N1=1,N2,N;
    int I,J;
    
    scanf("%d",&T);
    
    for(int caso=1;caso<=T;caso++){
        scanf("%d %d",&n,&d);
        
        for(int i=0;i<n;i++) scanf("%s",map1[i]);
        
        m=strlen(map1[0]);
        
        for(int i=0;i<n;i++) scanf("%s",map2[i]);
        
        N2=1+n*m;
        N=N2+n*m+1;
        
        L.clear();
        L.resize(N);
        
        for(int i=0;i<N;i++){
            fill(cap[i],cap[i]+N,0);
            fill(flow[i],flow[i]+N,0);
        }
        
        cont=0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(map2[i][j]=='L'){
                    cont++;
                    L[0].push_back(N1+i*m+j);
                    L[N1+i*m+j].push_back(0);
                    cap[0][N1+i*m+j]=1;
                }
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                cap[N1+i*m+j][N2+i*m+j]=map1[i][j]-'0';
                L[N1+i*m+j].push_back(N2+i*m+j);
                L[N2+i*m+j].push_back(N1+i*m+j);
                if(escape(i,j)){
                    cap[N2+i*m+j][N-1]=INT_MAX;
                    L[N2+i*m+j].push_back(N-1);
                    L[N-1].push_back(N2+i*m+j);
                }
            }
        
        for(int i1=0;i1<n;i1++)
            for(int j1=0;j1<m;j1++)
                for(int i2=max(0,i1-3);i2<=min(n-1,i1+3);i2++)
                    for(int j2=max(0,j1-3);j2<=min(m-1,j1+3);j2++)
                        if(abs(i1-i2)+abs(j1-j2)<=d && abs(i1-i2)+abs(j1-j2)>0){
                            cap[N2+i1*m+j1][N1+i2*m+j2]=INT_MAX;
                            L[N2+i2*m+j2].push_back(N1+i1*m+j1);
                            L[N1+i1*m+j1].push_back(N2+i2*m+j2);
                        }
        
        f=0;
        
        while(augmenting(N)) f++;
        
        printf("Case #%d: ",caso);
        
        if(f==cont) printf("no lizard was left behind.\n");
        else if(cont-f==1) printf("1 lizard was left behind.\n");
        else printf("%d lizards were left behind.\n",cont-f);
    }
    
    return 0;
}
