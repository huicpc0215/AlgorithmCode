import java.math.BigInteger;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		BigInteger f[];
		int n;
		f = new BigInteger[30];
		f[1]=cin.nextBigInteger();
		f[2]=cin.nextBigInteger();
		n=cin.nextInt();
		for(int i=3;i<=n;i++)
			f[i] = f[i-1].multiply(f[i-1]).add(f[i-2]);
		System.out.println(f[n]);
	}
}

