#include<cstdio>
#include<cstring>

int A[250000],B[250000],Blen = 1,M,N;

int main(){
	scanf("%d%d",&M,&N);
	A[0] = 0;
	B[0] = 1;
	for(int i = M+1;i <= N;i++){
		for(int j = 0;j < Blen;j++) {
			B[j] += A[j];
			A[j] = B[j]-A[j];
			B[j] -= A[j];
		}
		for(int j = 0;j < Blen;j++) B[j] += A[j];
		for(int j = 0;j < Blen;j++) {
			if(B[j] >= 10){
				B[j+1] += B[j]/10;
				B[j] %= 10;
				if(j == Blen-1) Blen++;
			}
		} 
	} 
	for(int i = Blen-1;i >= 0;i--) printf("%d",B[i]);
	return 0;
} 
