#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a[4];
    for(int i = 0;i<4;++i) cin>>a[i];
    sort(a,a+4);
    
    bool triangle = false,segment = false;
    
    for(int i = 0;i<4;++i){
        for(int j = i+1;j<4;++j){
            for(int k = j+1;k<4;++k){
                if(a[i]<a[j]+a[k] && a[j]<a[k]+a[i] && a[k]<a[i]+a[j]) triangle = true;
                if(a[k]==a[i]+a[j]) segment = true;
            }
        }
    }
    
    if(triangle) cout<<"TRIANGLE\n";
    else if(segment) cout<<"SEGMENT\n";
    else cout<<"IMPOSSIBLE\n";
    
    return 0;
}
