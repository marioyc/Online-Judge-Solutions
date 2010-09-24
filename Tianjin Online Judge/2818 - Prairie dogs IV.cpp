#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int x,y,I,J,r;
    
    while(scanf("%d %d",&x,&y)==2){
        if(x==0 && y==0) cout<<1<<endl;
        else{
            r=max(abs(x),abs(y));
            
            I=r;
            J=-r+1;
        
            for(int i=(2*r-1)*(2*r-1)+1;i<=(2*r+1)*(2*r+1);i++){                
                if(I==x && J==y){
                    cout<<i<<endl;
                    break;
                }
                
                if(i<(2*r-1)*(2*r-1)+2*r) J++;
                else if(i<(2*r-1)*(2*r-1)+4*r) I--;
                else if(i<(2*r-1)*(2*r-1)+6*r) J--;
                else I++;
            }
        }
    }
    
    return 0;
}
