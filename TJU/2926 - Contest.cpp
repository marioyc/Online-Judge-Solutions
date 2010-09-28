#include<iostream>

using namespace std;

int n,m;
int s[3][10];
int total[3];
int cont;
int max_problems;

void backtracking(int a){
    if(a==n){
        max_problems=max(cont,max_problems);
        return;
    }
    
    for(int i=0;i<3;i++){
        if(s[i][a]==-1 || total[i]+s[i][a]>m) continue;
        
        cont++;
        total[i]+=s[i][a];
        
        backtracking(a+1);
        
        cont--;
        total[i]-=s[i][a];
    }
    
    backtracking(a+1);
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int t;
    
    cin>>t;
    
    total[0]=total[1]=total[2]=0;
    
    for(int caso=0;caso<t;caso++){
        cin>>n>>m;
        
        for(int i=0;i<3;i++)
            for(int j=0;j<n;j++) cin>>s[i][j];
        
        max_problems=0;
        cont=0;
        
        backtracking(0);
        
        cout<<max_problems<<endl;
    }
    
    
    return 0;
}
