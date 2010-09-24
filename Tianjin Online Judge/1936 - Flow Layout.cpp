#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    short m;
    
    int t1,t2,mx,cont,a,b;
    
    while(true){
        cin>>m;
        if(m==0) break;
        
        t1=0; t2=0;
        mx=0; cont=0;
        
        while(true){
            cin>>a>>b;
            if(a==-1 && b==-1) break;
            
            if(cont+a<=m){
                mx=max(mx,b);
                cont+=a;
            }else{
                t1=max(t1,cont);
                t2+=mx;
                mx=b;
                cont=a;
            }
        }
        if(mx!=0){
            t1=max(t1,cont);
            t2+=mx;
        }
        cout<<t1<<" x "<<t2<<endl;
    }

    return 0;
}
