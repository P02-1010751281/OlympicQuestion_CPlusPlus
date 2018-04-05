#include<cstdio>
#include<iostream>

int A[250000],Ans[250000],Alen = 1,AnsL = 1,N;

int Plus(){
	AnsL = AnsL<Alen ? Alen:AnsL;
	for(int i = 1;i <= AnsL;i++){
		Ans[i] += A[i];
		if(Ans[i] >= 10){
			Ans[i+1] += (Ans[i]/10);
			Ans[i] %= 10;
			if (i == AnsL) AnsL++;
		}
	}
}

int Multiply(int x){
	for(int i = 1;i <= Alen;i++) A[i] *= x;
	for(int i = 1;i <= Alen;i++){
		if(A[i] >= 10){
			A[i+1] += (A[i]/10);
			A[i] %= 10;
			if(i == Alen) Alen++;
		}
	}
}

int main(){
	scanf("%d",&N);
	A[1] = 1;
	for(int i = 1;i <= N;i++){
		Multiply(i);
		Plus();
	}
	for(int i = AnsL;i >= 1;i--) printf("%d",Ans[i]);
	return 0;
}
