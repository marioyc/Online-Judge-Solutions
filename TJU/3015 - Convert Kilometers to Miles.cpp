#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct nodo{
    int n;
    int from;
    int mask;
    
    nodo(int a, int b, int c){
        n=a;
        from=b;
        mask=c;
    }
};

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    //Generando los numeros de fibonacci
    int a,cont;
    vector<int> F;
    
    F.push_back(1);
    F.push_back(2);
    cont=2;
    a=3;
    
    while(a<25000){
        F.push_back(a);
        cont++;
        
        a=F[cont-1]+F[cont-2];
    }
    
    //Generando las representaciones    
    int M[25000];
    
    memset(M,-1,sizeof(M));
    M[0]=0;
    
    queue<nodo> Q;
    for(int i=0;i<F.size();i++)
        Q.push(nodo(F[i],i,(1<<i)));
    nodo aux(nodo(0,0,0));
    
    while(!Q.empty()){
        aux=Q.front();
        Q.pop();
        
        if(aux.n>=25000 || M[aux.n]!=-1) continue;
        
        M[aux.n]=aux.mask;
        
        for(int i=2;aux.from+i<F.size();i++)
            Q.push(nodo(aux.n+F[aux.from+i],aux.from+i,aux.mask | (1<<(aux.from+i))));
    }
    
    int t,x,miles,fibo_base;
    
    cin>>t;
    
    for(int i=0;i<t;i++){
        cin>>x;
        
        fibo_base=M[x];
        
        miles=0;
        
        for(int j=1;j<F.size();j++)
            if((fibo_base & (1<<j)) != 0) miles+=F[j-1];
        
        cout<<miles<<endl;
    }
    
    return 0;
}
