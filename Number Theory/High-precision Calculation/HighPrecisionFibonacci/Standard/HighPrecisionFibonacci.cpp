#include<cstdio>
#include<cstring>

int A[250000],B[250000],Blen = 1,N;

void Printf(){
	for(int i = Blen-1;i >= 0;i--) printf("%d",B[i]);
}

void Plus(){
	for(int i = 0;i < Blen;i++) B[i] += A[i];
	for(int i = 0;i < Blen;i++) {
		if(B[i] >= 10){
			B[i+1] += B[i]/10;
			B[i] %= 10;
			if(i == Blen-1) Blen++;
		}
	} 
}

void Prepare(){
	for(int i = 0;i < Blen;i++) {
		B[i] += A[i];
		A[i] = B[i]-A[i];
		B[i] -= A[i];
	}
}

int main(){
	scanf("%d",&N);
	A[0] = 0;
	B[0] = 1;
	for(int i = 3;i <= N;i++){
		Prepare();
		Plus();
	} 
	Printf();
	return 0;
} 

