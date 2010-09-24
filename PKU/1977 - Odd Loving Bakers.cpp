#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_SIZE 100

int size;

struct M{
    int X[MAX_SIZE][MAX_SIZE];
    M(){}
};

void mult(M &m, M &m1, M &m2){
    memset(m.X,0,sizeof(m.X));
    for(int i=0;i<size;i++)
         for(int j=0;j<size;j++)
             for(int k=0;k<size;k++)
                 m.X[i][k] = (m.X[i][k]^(m1.X[i][j] & m2.X[j][k]));
}

M M0,aux1,aux2;

M exp(int n){
    if(n==1) return M0;
    if(n==0){
        for(int i=0;i<size;i++) fill(aux1.X[i],aux1.X[i]+size,0);
        for(int i=0;i<size;i++) aux1.X[i][i]=1;
        return aux1;
    }
    
    aux1=exp(n/2);
    for(int i=0;i<size;i++) fill(aux2.X[i],aux2.X[i]+size,0);
    for(int i=0;i<size;i++) aux2.X[i][i]=1;
    mult(aux2,aux1,aux1);
    if(n&1){
        mult(aux1,aux2,M0);
        return aux1;
    }
    return aux2;
}


int main(){
    int T,n,t,s,m,ind1,ind2;
    char name[21];
    map<string,int> I;
    int cont,A[100];

    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d %d",&n,&t);
        size = n;

        for(int i=0;i<n;++i) for(int j=0;j<i;++j) M0.X[i][j] = M0.X[j][i] = 0;
        for(int i=0;i<n;++i) M0.X[i][i] = 1;
        
        cont = 0;
        I.clear();
        
        for(int i=0;i<n;++i){
            scanf("%s %d %d",name,&s,&m);
            if(I.find(name)==I.end()) I[name] = cont++;
            ind1 = I[name];
            A[ind1] = (s&1);
            
            for(int j=0;j<m;++j){
                scanf("%s",name);
                if(I.find(name)==I.end()) I[name] = cont++;
                ind2 = I[name];
                M0.X[ind2][ind1] ^= 1;
            }
        }
        
        M ans = exp(t-1);

        cont = 0;
        for(int i=0;i<n;++i){
            int aux = 0;
            for(int j=0;j<n;++j) aux ^= (ans.X[i][j] & A[j]);
            if(aux==1) ++cont;
        }
        printf("%d\n",cont);
    }
    
    return 0;
}
