#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX_SIZE 19
int size;

struct M{
    double X[MAX_SIZE][MAX_SIZE];
    
    M(){
    }
};

const double eps=1e-7;

double determinant(M M0){
    double ans=1,aux;
    bool found;
    
    for(int i=0,r=0;i<size;i++){
        found=false;
        
        for(int j=r;j<size;j++)
            if(fabs(M0.X[j][i])>eps){
                found=true;
                
                if(j>r) ans=-ans;
                else break;
                
                for(int k=0;k<size;k++) swap(M0.X[r][k],M0.X[j][k]);
                break;
            }
        
        if(found){
            for(int j=r+1;j<size;j++){
                aux=M0.X[j][i]/M0.X[r][i];
                for(int k=i;k<size;k++) M0.X[j][k]-=aux*M0.X[r][k];
            }
            
            r++;
        }else return 0;
    }
    
    for(int i=0;i<size;i++) ans*=M0.X[i][i];
    return ans;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int T,n;
    int a[11],b[10];
    double det;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d",&n);
        
        for(int i=0;i<=n;i++) scanf("%d",&a[i]);
        
        if(n==0 || n==1){
            printf("Yes!\n");
            continue;
        }
        
        for(int i=0;i<=n-1;i++) b[i]=a[i]*(n-i);
        
        M M0;
        size=2*n-1;
        for(int i=0;i<size;i++) fill(M0.X[i],M0.X[i]+size,0);
        
        for(int i=0;i<n-1;i++)
            for(int j=0;j<=n;j++)
                M0.X[i][j+i]=a[j];
        
        for(int i=n-1;i<size;i++)
            for(int j=0;j<=n-1;j++)
                M0.X[i][j+i-n+1]=b[j];
        
        det=determinant(M0);
        
        if(fabs(det)<eps) printf("No!\n");
        else printf("Yes!\n");
    }
    
    return 0;
}
