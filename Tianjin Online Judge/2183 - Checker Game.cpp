#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N;
    int board[100][100];
    int M[100][100];
    int max_score;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++) scanf("%d",&board[i][j]);
        
        for(int i=0;i<N;i++) M[0][i]=board[0][i];
        
        for(int i=1;i<N;i++){
            for(int j=0;j<N;j++){
                M[i][j]=M[i-1][j]+board[i][j];
                if(j>0) M[i][j]=max(M[i][j],M[i-1][j-1]+board[i][j]);
                if(j<N-1) M[i][j]=max(M[i][j],M[i-1][j+1]+board[i][j]);
            }
        }
        
        max_score=M[N-1][0];
        
        for(int i=1;i<N;i++) max_score=max(max_score,M[N-1][i]);
        
        cout<<max_score<<endl;
    }
    
    return 0;
}
