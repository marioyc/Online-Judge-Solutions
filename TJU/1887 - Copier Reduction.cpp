#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int a,b,c,d;
    double x,y;
    
    while(1){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        
        if(a==0 && b==0 && c==0 && d==0) break;
        
        for(int i=100;i>=1;i--){
            x=a*i/100.0;
            y=b*i/100.0;
            
            if((x<=c && y<=d)||(x<=d && y<=c)){
                cout<<i<<"%"<<endl;
                break;
            }
        }
    }
    
    return 0;    
}
