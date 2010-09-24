#include <iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int M[99][99],F[99],C[99],n,conti,contj,I,J;
    
    while(true){
        cin>>n;
        if(n==0) break;
        memset(C,0,sizeof(C));
        for(int i=0;i<n;i++){
            F[i]=0;
            for(int j=0;j<n;j++){
                cin>>M[i][j];
                F[i]+=M[i][j];
                C[j]+=M[i][j];
            }
        }
        conti=0;
        contj=0;
        for(int i=0;i<n;i++){
            if(F[i]%2==1){
                conti++;
                I=i;
            }
            if(C[i]%2==1){
                contj++;
                J=i;
            }
            if(conti+contj>2) break;
        }
        if(conti+contj==0) cout<<"OK"<<endl;
        else if(conti==1 && contj==1) cout<<"Change bit ("<<I+1<<","<<J+1<<")"<<endl;
        else if(conti+contj>0) cout<<"Corrupt"<<endl;
    }

    return 0;
}
