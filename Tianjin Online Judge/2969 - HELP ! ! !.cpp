#include <iostream>
using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    long long M[51][51];
    
    M[0][0]=1;M[1][0]=1;M[1][1]=1;
    for(int i=2;i<51;i++){
        M[i][0]=1;M[i][i]=1;
        for(int j=1;j<i;j++){
            M[i][j]=M[i-1][j-1]+M[i-1][j];
        }
    }    
    int n;
    while(true){
        cin>>n;
        if(n<0) break;
        
        cout<<1;
        
        for(int i=1;i<=n;i++) cout<<" "<<M[n][i];
        cout<<endl;
    }
    return 0;
}
