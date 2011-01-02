#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string s1,s2;
    cin>>s1>>s2;
    
    int dx = s2[0]-s1[0],dy = s2[1]-s1[1];
    
    cout<<max(abs(dx),abs(dy))<<'\n';
    
    while(dx!=0 && dy!=0){
        if(dx<0){
            ++dx;
            
            if(dy<0){
                cout<<"LD\n";
                ++dy;
            }else{
                cout<<"LU\n";
                --dy;
            }
        }else{
            --dx;
            
            if(dy<0){
                cout<<"RD\n";
                ++dy;
            }else{
                cout<<"RU\n";
                --dy;
            }
        }
    }
    
    if(dx>0) for(int i = 0;i<dx;++i) cout<<"R\n";
    if(dx<0) for(int i = 0;i<-dx;++i) cout<<"L\n";
    if(dy>0) for(int i = 0;i<dy;++i) cout<<"U\n";
    if(dy<0) for(int i = 0;i<-dy;++i) cout<<"D\n";
    
    return 0;
}
