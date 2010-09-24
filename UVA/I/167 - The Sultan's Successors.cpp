#include<iostream>
#include<iomanip>

using namespace std;

int board[8][8];
bool col[8];
bool diag1[15];
bool diag2[15];
int score, sum;

void backtracking(int n){
    if(n==8){
        score=max(score,sum);
        return;
    }
    
    for(int i=0;i<8;i++)
        if(!col[i] && !diag1[n-i+7] && !diag2[n+i]){
            col[i]=true;
            diag1[n-i+7]=true;
            diag2[n+i]=true;
            sum+=board[n][i];
            
            backtracking(n+1);
            
            col[i]=false;
            diag1[n-i+7]=false;
            diag2[n+i]=false;
            sum-=board[n][i];
        }
}

int main(){
    int T;
    
    cin>>T;
    
    memset(col,false,sizeof(col));
    memset(diag1,false,sizeof(diag1));
    memset(diag2,false,sizeof(diag2));
    
    for(int i=0;i<T;i++){
        for(int j=0;j<8;j++)
            for(int k=0;k<8;k++) cin>>board[j][k];
        
        score=-1;
        sum=0;
        backtracking(0);
        cout<<setw(5)<<setiosflags(ios::right)<<score<<endl;
    }
    
    return 0;
}
