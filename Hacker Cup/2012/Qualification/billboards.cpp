#include <iostream>
#include <sstream>

using namespace std;

int main(){
    int T,N,W,H;
    int lo,hi,mi;
    string s,x;
    int a[1000];
    
    cin >> T;
	getline(cin,s);
    
    for(int tc = 1;tc <= T;++tc){
		getline(cin,s);
		istringstream is(s);
		
		is >> W >> H;
		N = 0;
		
		while(is >> x){
			a[N] = x.size() + 1;
			++N;
		}
		
		lo = 0; hi = 10000;
		
		while(lo < hi){
			mi = (lo + hi + 1) >> 1;
			
			int cont = 1;
			bool fit = true;
			int w = W / mi + 1;
			
			for(int i = 0,aux = 0;i < N;++i){
                if(a[i] > w) fit = false;
                
				if(aux + a[i] > w){
                    aux = a[i];
                    ++cont;
                }else{
                    aux += a[i];
                }
			}
			
			if(!fit || mi * cont > H) hi = mi - 1;
			else lo = mi;
		}
		
		cout << "Case #" << tc << ": " << lo << '\n';
    }
    
    return 0;
}
