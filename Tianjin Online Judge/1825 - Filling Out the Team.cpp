#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	double a,b,c;
	const double eps=1e-6;
	bool found;
	
	while(1){
		cin>>a>>b>>c;
		if(a<=eps && b<=eps && c<=eps) break;
		
		found=false;
		
		if(a<=4.5+eps && b>=150-eps && c>=200-eps){
			cout<<"Wide Receiver ";
			found=true;
		}
		
		if(a<=6+eps && b>=300-eps && c>=500-eps){
			cout<<"Lineman ";
			found=true;
		}
		
		if(a<=5+eps && b>=200-eps && c>=300-eps){
			cout<<"Quarterback ";
			found=true;
		}
		
		if(!found) cout<<"No positions";
		cout<<endl;
	}
	
	return 0;
}
