#include<iostream>
#include<cmath>

using namespace std;

int main(){    
    double M[5][5];
    int n;
    int c[11];
    int cur;
    double x;
    
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++) cin>>M[i][j];
    
    while(1){
        cin>>n;
        if(n==0) break;
        
        for(int i=0;i<n;i++) cin>>c[i];
        c[n]=1;
        cin>>x;
        
        cur=1;
        
        for(int i=0;i<n+1;i++){
            x*=M[cur-1][c[i]-1];
            x=round(x*100)/100;
            
            cur=c[i];
        }
        
        printf("%.2f\n",x);
    }
    
    return 0;
}
