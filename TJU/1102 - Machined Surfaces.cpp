#include<iostream>
#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main(){    
    int N,total,L,R,x;
    vector<string> M(12);
    bool ok;
    
    while(1){
        scanf("%d\n",&N);
        if(N==0) break;
        
        for(int i=0;i<N;i++) getline(cin,M[i]);
        
        for(int i=0;i<N;i++){
            ok=false;
            
            for(int j=0;j<25;j++)
                if(M[i][j]==' ') ok=true;
            
            if(!ok) break;
        }
        
        if(!ok){
            total=0;
            
            for(int i=0;i<N;i++)
                for(int j=0;j<25;j++) if(M[i][j]==' ') total++;
            printf("%d\n",total);
            
            continue;
        }
        
        total=0;
        x=25;
        
        for(int i=0;i<N;i++){
            for(int j=0;;j++)
                if(M[i][j]==' '){
                    L=j;
                    break;
                }
            
            for(int j=24;;j--)
                if(M[i][j]==' '){
                    R=j;
                    break;
                }
            
            total+=R-L+1;
            x=min(x,R-L+1);
        }        
        
        printf("%d\n",total-x*N);
    }
    
    return 0;
}
