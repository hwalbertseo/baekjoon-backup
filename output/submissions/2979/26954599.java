import java.util.*;

public class Main {

	public static void main(String[] args) {
		/*
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i = 1;i <= n;i++) {
			for(int j = 0;j < i;j++) {
				System.out.print("*");
			}
			for(int j = 0;j < n-i;j++) {
				System.out.print(" ");
			}
			for(int j = 0;j < n-i;j++) {
				System.out.print(" ");
			}
			for(int j = 0;j < i;j++) {
				System.out.print("*");
			}
			System.out.println();
		}
		for(int i = n-1;i >= 0;i--) {
			for(int j = 0;j < i;j++) {
				System.out.print("*");
			}
			for(int j = 0;j < n-i;j++) {
				System.out.print(" ");
			}
			for(int j = 0;j < n-i;j++) {
				System.out.print(" ");
			}
			for(int j = 0;j < i;j++) {
				System.out.print("*");
			}
			System.out.println();
		}
		*/
		Scanner sc = new Scanner(System.in);
		int a, b, c;
		a = sc.nextInt();
		b = sc.nextInt();
		c = sc.nextInt();
		int[][] arr = new int[3][2];
		for(int i = 0;i < 3;i++) {
			arr[i][0] = sc.nextInt();
			arr[i][1] = sc.nextInt();
		}
		int cost = 0;
		for(int i = 0;i < 100;i++) {
			//System.out.print(i + " ");
			int cnt = 0;
			int sel = 0;
			if(arr[0][0] <= i && i < arr[0][1]) {
				cnt++;
			}
			if(arr[1][0] <= i && i < arr[1][1]) {
				cnt++;
			}
			if(arr[2][0] <= i && i < arr[2][1]) {
				cnt++;
			}
			//System.out.println(cnt);
			if(cnt == 1) {
				cost += a;
			}
			else if(cnt == 2) {
				cost += b*2;
			}
			else if(cnt == 3) {
				cost += c*3;
			}
		}
		System.out.println(cost);
	}

}
