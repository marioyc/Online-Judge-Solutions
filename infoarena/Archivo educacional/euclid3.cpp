#include <cstdio>

using namespace std;

struct EuclidReturn{
    int u,v,d;
	
    EuclidReturn(int _u, int _v, int _d){
        u = _u; v = _v; d = _d;
    }
};
    
EuclidReturn Extended_Euclid(int a, int b){
    if(b==0) return EuclidReturn(1,0,a);
	
    EuclidReturn aux = Extended_Euclid(b,a%b);
    int v = aux.u-(a/b)*aux.v;
    return EuclidReturn(aux.v,v,aux.d);
}

int main(){
	freopen("euclid3.in","r",stdin);
	freopen("euclid3.out","w",stdout);	
	
	int T,a,b,c;	
	scanf("%d",&T);
	
	while(T--){
		scanf("%d %d %d",&a,&b,&c);
		
		EuclidReturn ret = Extended_Euclid(a,b);
	
		if(c%ret.d!=0) printf("0 0\n");
		else printf("%d %d\n",ret.u*(c/ret.d),ret.v*(c/ret.d));
	}
	
	return 0;
}
