#include <iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,f,ax,a,b;
    
    while(cin>>n){
        ax=1;
        f=1;
        while(ax<n){
            f++;
            ax+=f;
        }
        if(f%2==0){
            a=1;
            b=f;
            ax=f*(f-1)/2+1;
            while(ax!=n){
                a++;
                b--;
                ax++;
            }
        }else{
            a=f;
            b=1;
            ax=f*(f-1)/2+1;
            while(ax!=n){
                a--;
                b++;
                ax++;
            }
        }
        cout<<"TERM "<<n<<" IS "<<a<<"/"<<b<<endl;
    }

    return 0;
}
