import java.util.Scanner;
import java.math.BigInteger;

public class Main{
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		int n;
		
		BigInteger ans[] = new BigInteger[101];
		
		ans[0]=BigInteger.ONE;
		ans[1]=BigInteger.ONE;
		
		for(int i=2;i<=100;i++){
			ans[i]=BigInteger.ZERO;
			
			for(int j=0;j<i;j++) ans[i]=ans[i].add(ans[j].multiply(ans[i-1-j]));
		}
		
		try{
			while(true){
				n = in.nextInt();
				if(n==-1) break;
				
				System.out.println(ans[n]);
			}
		}catch(Exception e){}
	}
}
