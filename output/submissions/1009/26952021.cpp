#include<stdio.h>
int main(){
	int a, b;
	int temp; 
	int input;
	
	scanf("%d", &input);
	
	for(int i=0; i<input; i++){
		scanf("%d %d", &a, &b);
		
		temp = a;
		
		for(int j=0; j<b-1; j++)
			a = temp * a % 10;
		
		
		if(a == 0)
			a=10;
		
		printf("%d\n", a);
	}
	
	return 0;
}