#include <fstream>

using namespace std;

int main(){
	ifstream in("ssm.in");
	
	int N,a;
	in>>N>>a;
	
	int ans = a,s = 0,n = 1,best = a,s2 = 0,n2 = 1;
	
	for(int i = 1;i<N;++i){
		in>>a;
		
		if(best<0){
			best = a;
			s2 = i;
			n2 = 1;
		}else{
			best += a;
			++n2;
		}
		
		if(best>ans){
			ans = best;
			s = s2;
			n = n2;
		}
	}
	
	ofstream out("ssm.out");
	out<<ans<<" "<<s+1<<" "<<s+n<<'\n';
	in.close(); out.close();
	
	return 0;
}
