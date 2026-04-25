package main;

import java.util.Scanner;

public class fibonacci {
	public static int fib(int x) {
		if(x == 0) return 0;
		else if(x == 1) return 1;
		else {
			return fib(x - 1) + fib(x - 2);
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		System.out.println(fib(n));
	}
}