#include <iostream>
using namespace std;

int main(){
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n,m;
    int b,a;
    int cont;
    int ax=1;
    while(true){
        scanf("%d %d",&n,&m);
        if(!(n||m)) break;
        cont=0;
        for(b=2;b<n;b++){
            for(a=b-1;a>0;a--){
                if(((b-a)*(b-a)+m)%(a*b)==0) cont++;
            }
        }
        cout<<"Case "<<ax<<": "<<cont<<endl;
        ax++;
    }
    return 0;
}
