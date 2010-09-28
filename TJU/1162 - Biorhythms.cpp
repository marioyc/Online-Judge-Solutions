#include <iostream>

using namespace std;

int main(){
    int tc=0,a,b,c,date,ans;
    
    while(true){
        scanf("%d %d %d %d",&a,&b,&c,&date);
        if(a==-1) break;
        
        ans = -1;
        
        for(int i=1;i<=21252;++i){
            if((date+i)%23==a%23 &&
                (date+i)%28==b%28 &&
                (date+i)%33==c%33){
                ans = i;
                break;
            }
        }
        
        cout<<"Case "<<(++tc)<<": the next triple peak occurs in "<<ans<<" days."<<endl;
    }
    
    return 0;
}
