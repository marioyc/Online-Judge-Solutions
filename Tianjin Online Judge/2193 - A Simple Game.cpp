#include <iostream>
using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int N,M;
    while(scanf("%d %d",&N,&M)==2){
        if(N%(M+1)==0) cout<<"Think About It."<<endl;
        else cout<<"Just Do It."<<endl;
    }

    return 0;
}
