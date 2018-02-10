#include <cstdio>

int X,Y;

int Gcd(int A,int B){
	return !(A%B) ? B : Gcd(B,A%B);
}

int main(){
	int A,B;
	scanf("%d%d",&A,&B);
	printf("Greatest Common Divisor : %d",Gcd(A,B));
	return 0;
}
