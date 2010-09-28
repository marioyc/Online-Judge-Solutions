#include <vector>
#include <iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n;
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        vector<int> a(n);
        
        for(int i=0;i<n;i++) cin>>a[i];
        
        vector<int> v;
        
        for(int i=n;i>0;i--){
            v.insert(v.begin()+a[i-1],i);
        }
        
        for(int i=0;i<n-1;i++) cout<<v[i]<<",";
        cout<<v[n-1]<<endl;
    }

    return 0;
}
