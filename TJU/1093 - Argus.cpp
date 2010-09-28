#include<cstdio>
#include<queue>

using namespace std;

struct nodo{
    int ID,t;
    
    nodo(int _ID, int _t){
        ID=_ID;
        t=_t;
    }
    
    bool operator < (nodo X) const{
        if(t!=X.t) return t>X.t;
        return ID>X.ID;
    }
};

int main(){    
    char s[9];
    int ID,t,K;
    int P[3001];
    priority_queue<nodo> Q;
    
    while(1){
        scanf("%s",s);
        if(s[0]=='#') break;
        
        scanf("%d",&ID);
        scanf("%d",&P[ID]);
        
        Q.push(nodo(ID,P[ID]));
    }    
    
    scanf("%d",&K);
    
    for(int i=0;i<K;i++){
        printf("%d\n",Q.top().ID);
        Q.push(nodo(Q.top().ID,Q.top().t+P[Q.top().ID]));
        Q.pop();
    }
    
    return 0;
}
