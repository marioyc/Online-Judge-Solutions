import java.io.*;
import java.util.StringTokenizer;
import java.math.BigInteger;

public class GEOPROB{
	public static void main(String args[]){
		 BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		 
		 String s;
		 StringTokenizer st;
		 
		 int t;
		 BigInteger b,c,d,ans;
		 
		 try{
		 	s=stdin.readLine();
		 	t=Integer.parseInt(s);
		 	
		 	for(int i=0;i<t;i++){
		 		s=stdin.readLine();
		 		st=new StringTokenizer(s);
		 		
		 		
		 		b=new BigInteger(st.nextToken());
		 		c=new BigInteger(st.nextToken());
		 		d=new BigInteger(st.nextToken());
		 		
		 		b=c.subtract(b);
		 		d=c.subtract(d);
		 		ans=b.add(d);
		 		
		 		System.out.println(ans);
		 	}
		 }catch(IOException e){};		 
		 
		 
	}
}