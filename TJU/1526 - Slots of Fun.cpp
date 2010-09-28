#include <cstdio>
#include <algorithm>

using namespace std;

int dist2(const int &x1, const int &y1, const int &x2, const int &y2){
	return ((x1-x2)*(x1-x2)*3+(y1-y2)*(y1-y2));
}

int main(){
	int x[78],y[78];
	
	for(int i=0,k=0;i<12;i++){
		for(int j=-i;j<=i;j+=2){
			x[k]=i; y[k]=j;
			k++;
		}
	}
	
	char s[79],ans[79];
	int n,m,d1,d2,d3;
	
	while(1){
		scanf("%d",&n);
		if(n<1) break;
		
		scanf("%s",s);
		
		n=n*(n+1)/2;
		m=0;
		
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					if(s[i]!=s[j] || s[i]!=s[k]) continue;
					d1=dist2(x[i],y[i],x[j],y[j]);
					d2=dist2(x[i],y[i],x[k],y[k]);
					d3=dist2(x[j],y[j],x[k],y[k]);
					if(d1==d2 && d1==d3) ans[m++]=s[i];
				}
			}
		}
		
		sort(ans,ans+m);
		
		for(int i=0;i<m;i++) printf("%c",ans[i]);
		if(m==0) printf("LOOOOOOOOSER!");
		printf("\n");
	}
	
	return 0;
}
