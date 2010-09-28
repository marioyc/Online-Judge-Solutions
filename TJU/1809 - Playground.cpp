#include <iostream>
#include <algorithm>

using namespace std;

int main(){    
    int K;
    double a[20];
    
    while(1){    
        cin>>K;
        if(K==0) break;
        
        for(int i=0;i<K;i++) cin>>a[i];
        
        sort(a,a+K);
        
        double S=a[0];
        bool found=false;
        
        for(int i=1;i<K && !found;i++){
            if(a[i]<=S) found=true;
            S+=a[i];
        }
        
        if(found) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}
