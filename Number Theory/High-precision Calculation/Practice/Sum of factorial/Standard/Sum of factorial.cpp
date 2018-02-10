#include<cstdio>
#include<cstring>
#include<iostream>

int A[250000],Ans[250000],Alen = 1,AnsL = 1,N;

int main(){
	scanf("%d",&N);
	A[1] = 1;
	for(int i = 1;i <= N;i++){
		for(int j = 1;j <= Alen;j++) A[j] *= i;
		for(int j = 1;j <= Alen;j++){
			if(A[j] >= 10){
				A[j+1] += (A[j]/10);
				A[j] %= 10;
				if(j == Alen) Alen++;
			}
		}
		AnsL = std::max(Alen,AnsL);
		for(int j = 1;j <= AnsL;j++){
			Ans[j] += A[j];
			if(Ans[j] >= 10){
				Ans[j+1] += (Ans[j]/10);
				Ans[j] %= 10;
				if(j == AnsL) AnsL++;
			}
		}
	}
	for(int i = AnsL;i > 0;i--) printf("%d",Ans[i]);
	return 0;
}
