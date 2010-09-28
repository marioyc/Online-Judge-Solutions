#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n,a,x,y;
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        x=-1;
        y=-1;
        
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            if(a>y){
                x=y;
                y=a;
            }else if(a>x && a<y) x=a;
        }
        
        cout<<x<<endl;
    }
}
