#include<cstdio> 
#include<iostream>

int A[500],N,Alen = 0;
int main(){
	scanf("%d",&N);
	int Tmp;
	for(int i = 0;i < N;i++){
		scanf("%d",&Tmp);
		if(Tmp%2 != 0){
			A[(Tmp+1)/2]++;
			Alen = Alen<(Tmp+1)/2 ? (Tmp+1)/2:Alen;
		} 
	}
	for(int i = 1;i < Alen;i++){
		while(A[i]) {
			Tmp = i*2;
			Tmp--;
			printf("%d,",Tmp);
			A[i]--;
		}
	}
	while(A[Alen]){
		Tmp = Alen*2;
		Tmp--;
		if(A[Alen] == 1) printf("%d",Tmp);
		else printf("%d",Tmp);
		A[Alen]--;
	}
	return 0;
}
