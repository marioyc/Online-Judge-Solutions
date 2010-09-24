#include<cstdio>
#include<iostream>
#include<stack>
#include<map>

using namespace std;

int N;
char board[200][201];
bool visited[200][200];

bool black(){
    stack< pair<int, int> > S;
    pair<int, int> P;
    int di[]={-1,-1,0,0,1,1};
    int dj[]={-1,0,-1,1,0,1};
    int I,J;
    
    for(int i=0;i<N;i++)
        if(board[0][i]=='b'){
            S.push(make_pair(0,i));
            visited[0][i]=true;
        }
    
    while(!S.empty()){
        P=S.top();
        S.pop();
        
        if(P.first==N-1) return true;
        
        for(int i=0;i<6;i++){
            I=P.first+di[i];
            J=P.second+dj[i];
            
            if(I>=0 && I<N && J>=0 && J<N && board[I][J]=='b' && !visited[I][J]){
                visited[I][J]=true;
                S.push(make_pair(I,J));
            }
        }
    }
    
    return false;
}

int main(){
    int cont=1;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i=0;i<N;i++) scanf("%s",board[i]);
        
        printf("%d ",cont);
        cont++;
        
        for(int i=0;i<N;i++) fill(visited[i],visited[i]+N,false);
        
        if(black()) printf("B\n");
        else printf("W\n");
    }
        
    return 0;
}
