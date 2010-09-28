#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(){
    char a[101][31];
    char b[101][32];
    int n,m,lcs;
    int LCS[100][100];
    bool equal[101][101];
    
    while(1){
        if(scanf("%s",a[0])!=1) break;
        
        n=1;
        
        for(int i=1;;i++){
            scanf("%s",a[i]);
            
            if(a[i][0]=='#') break;
            else n++;
        }
        
        m=0;
        
        for(int i=0;;i++){
            scanf("%s",b[i]);
            
            if(b[i][0]=='#') break;
            else m++;
        }
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(strcmp(a[i],b[j])==0) equal[i][j]=true;
                else equal[i][j]=false;
        
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i==n || j==m) LCS[i][j]=0;                
                else if(equal[i][j]) LCS[i][j]=1+LCS[i+1][j+1];
                else LCS[i][j]=max(LCS[i][j+1],LCS[i+1][j]);
            }
        }
        
        lcs=LCS[0][0];
        
        for(int i=0;i<n;i++){            
            for(int j=0;j<m;j++){
                if(equal[i][j] && LCS[i][j]==lcs){
                    printf("%s",a[i]);
                    if(lcs==1) printf("\n");
                    else printf(" ");
                    lcs--;
                    break;                    
                }
            }
        }
    }
    
    return 0;
}
