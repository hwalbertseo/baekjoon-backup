package 분산처리;

import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] ans = new int[n];
		int p,q;
		for(int i = 0;i < n;i++) {
			p = sc.nextInt(); 
			q = sc.nextInt();
			int k = p % 10;
			for(int j = 1;j < q;j++) {
				int temp = k % 10;
				k = temp*p % 10;
				//System.out.println(temp*p);
			}
			//System.out.println();
			ans[i] = k;
		}
		
		for(int i = 0;i < n;i++) {
			System.out.println(ans[i]);
		}
	}
}
