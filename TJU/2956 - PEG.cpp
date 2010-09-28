#include <iostream>
#include <string>

using namespace std;

int main(){
    string M[7];
    
    for(int i=0;i<7;i++) getline(cin,M[i]);
    
    int ans=0;
    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};
    
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if(M[i][j]!='o') continue;
            
            for(int k=0;k<4;k++){
                int r=i+dr[k],c=j+dc[k];
                if(r>=0 && r<7 && c>=0 && c<7 && M[r][c]=='o'){
                    r+=dr[k];
                    c+=dc[k];
                    if(r>=0 && r<7 && c>=0 && c<7 && M[r][c]=='.') ans++;
                }
            }
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
