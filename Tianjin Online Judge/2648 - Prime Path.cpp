#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

struct num{
    short a,b,c,d,dist;
    
    num(){
    }
    
    num(short _a, short _b, short _c, short _d, short _dist){
        a=_a;
        b=_b;
        c=_c;
        d=_d;
        dist=_dist;
    }
};

bool p[10000];
bool visited[10000];

int dist(int &p1, int &p2){
    queue<num> Q;
    Q.push(num(p1/1000,p1/100%10,p1/10%10,p1%10,0));
    
    fill(visited,visited+9000,false);
    visited[p1-1000]=true;
    
    num aux;
    int N,M;
    
    while(!Q.empty()){
        aux=Q.front();
        Q.pop();
        
        N=aux.a*1000+aux.b*100+aux.c*10+aux.d;
        if(N==p2) return aux.dist;
        
        for(int i=1;i<=9;i++){
            M=N-aux.a*1000+i*1000;
            if(!visited[M-1000] && p[M]){
                visited[M-1000]=true;
                Q.push(num(i,aux.b,aux.c,aux.d,aux.dist+1));
            }
        }
        
        for(int i=0;i<=9;i++){
            M=N-aux.b*100+i*100;
            if(!visited[M-1000] && p[M]){
                visited[M-1000]=true;
                Q.push(num(aux.a,i,aux.c,aux.d,aux.dist+1));
            }
        }
        
        for(int i=0;i<=9;i++){
            M=N-aux.c*10+i*10;
            if(!visited[M-1000] && p[M]){
                visited[M-1000]=true;
                Q.push(num(aux.a,aux.b,i,aux.d,aux.dist+1));
            }
        }
        
        for(int i=0;i<=9;i++){
            M=N-aux.d+i;
            if(!visited[M-1000] && p[M]){
                visited[M-1000]=true;
                Q.push(num(aux.a,aux.b,aux.c,i,aux.dist+1));
            }
        }
    }
    
    return -1;
}

int main(){    
    fill(p,p+10000,true);
    p[0]=p[1]=false;
    
    for(int i=2;i<10000;i++)
        if(p[i])
            for(int j=i*i;j<10000;j+=i) p[j]=false;
    
    int T,p1,p2,x;
    
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        scanf("%d %d",&p1,&p2);
        
        x=dist(p1,p2);
        
        if(x==-1) printf("Impossible\n");
        else printf("%d\n",x);
    }
    
    return 0;
}
