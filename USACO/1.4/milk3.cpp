/*
ID:zion_ba1
LANG:C++
TASK:milk3
*/

#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct state{
    int A,B,C;
    
    state(){
    }
    
    state(int _A, int _B, int _C){
        A=_A;
        B=_B;
        C=_C;
    }
};

int main(){
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
    
    int capA,capB,capC;
    
    scanf("%d %d %d",&capA,&capB,&capC);
    
    vector<int> L;
    
    bool visited[21][21];
    for(int i=0;i<21;i++)   
        for(int j=0;j<21;j++)
            visited[i][j]=false;
    
    bool possible[capC+1];
    for(int i=0;i<capC+1;i++) possible[i]=false;
    
    stack<state> S;
    S.push(state(0,0,capC));
    visited[0][0]=true;
    
    state aux;
    int x;
    
    while(!S.empty()){
        aux=S.top();
        S.pop();
        
        if(aux.A==0) possible[aux.C]=true;
        
        x=min(aux.A,capB-aux.B);
        if(!visited[aux.A-x][aux.B+x]){
            S.push(state(aux.A-x,aux.B+x,aux.C));
            visited[aux.A-x][aux.B+x]=true;
        }
        
        x=min(aux.A,capC-aux.C);
        if(!visited[aux.A-x][aux.B]){
            S.push(state(aux.A-x,aux.B,aux.C+x));
            visited[aux.A-x][aux.B]=true;
        }
        
        x=min(aux.B,capA-aux.A);
        if(!visited[aux.A+x][aux.B-x]){
            S.push(state(aux.A+x,aux.B-x,aux.C));
            visited[aux.A+x][aux.B-x]=true;
        }
        
        x=min(aux.B,capC-aux.C);
        if(!visited[aux.A][aux.B-x]){
            S.push(state(aux.A,aux.B-x,aux.C+x));
            visited[aux.A][aux.B-x]=true;
        }
        
        x=min(aux.C,capA-aux.A);
        if(!visited[aux.A+x][aux.B]){
            S.push(state(aux.A+x,aux.B,aux.C-x));
            visited[aux.A+x][aux.B]=true;
        }
        
        x=min(aux.C,capB-aux.B);
        if(!visited[aux.A][aux.B+x]){
            S.push(state(aux.A,aux.B+x,aux.C-x));
            visited[aux.A][aux.B+x]=true;
        }
    }
    
    bool space=false;
    
    for(int i=0;i<=capC;i++)
        if(possible[i]){
            if(space) printf(" ");
            space=true;
            
            printf("%d",i);
        }
    
    printf("\n");
    
    return 0;
}
