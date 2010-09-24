#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,I,J;
    int max_score,sum;
    int cards[7][7];
    string s;
    
    scanf("%d",&N);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>s;
            if(s[0]=='A') cards[i][j]=1;
            else if(s[0]=='T') cards[i][j]=10;
            else if(s[0]=='J') cards[i][j]=11;
            else if(s[0]=='Q') cards[i][j]=12;
            else if(s[0]=='K') cards[i][j]=13;
            else cards[i][j]=s[0]-'0';
        }
    }
    
    max_score=-1;
    
    s="";
    
    for(int i=0;i<N-1;i++) s+='R';
    for(int i=0;i<N-1;i++) s+='U';
    
    do{
        I=N-1;
        J=0;
        
        sum=cards[N-1][0]+cards[0][N-1];
        
        for(int i=0;i<2*N-3;i++){
            if(s[i]=='R') J++;
            else I--;
            
            sum+=cards[I][J];
        }
        
        max_score=max(max_score,sum);
    }while(next_permutation(s.begin(),s.end()));
    
    printf("%d\n",max_score);
    
    return 0;
}
