#include <iostream>

using namespace std;

int main(){
    freopen("out.txt","w",stdout);

    bool M[10001];
    int ax,s;
    
    memset(M,true,sizeof(M));
    
    for(int i=1;i<10001;i++){
        if(!M[i]) continue;
        cout<<i<<endl;
        ax=i;
        while(ax<10001){
            M[ax]=false;
            s=ax;
            while(ax!=0){
                s+=ax%10;
                ax/=10;
            }
            ax=s;
        }
    }

    return 0;
}
