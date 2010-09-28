#include <cstdio>

using namespace std;

int main(){
	int s,p,y,j,x1,x2,x3;
	bool solved;
	
	while(scanf("%d %d %d %d",&s,&p,&y,&j)==4){
		solved=false;
		
		for(int a=p;a<=p+1 && !solved;a++){
			for(int b=y;b<=y+1 && !solved;b++){
				x3=12+j-a-b;
				if(x3>=0 && x3%3==0){
					x3/=3;
					x2=x3+a;
					x1=x3+b;
					if((x1-x2==s || x1-x2==s+1) && (x2-x3==p || x2-x3==p+1) && (x1-x3==y || x1-x3==y+1)){
						printf("%d %d %d\n",x1,x2,x3);
						solved=true;
					}
				}
			}
		}
	}
	
	return 0;
}
