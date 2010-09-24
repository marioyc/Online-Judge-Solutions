#include <iostream>

using namespace std;

int main(){
    int N,M,K,a[100];
    
    while(true){
    	cin>>N>>M>>K;
    	if(N==0 || M==0 || K==0) break;
    	
    	for(int i = 0;i<K;++i) cin>>a[i];
    	
    	long long ans = N;
    	
    	for(int i = 0;i+1<M;++i){
    	    N += a[i%K];
    	    ans += N;
    	}
    	
    	cout<<ans<<endl;
    }
    
    return 0;
}