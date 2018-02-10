#include<cstdio>

bool A[25000],Check = 1;
int N,K,Alen = 0;

int main(){
	scanf("%d%d",&N,&K);
	int Tmp;
	for(int i = 1;i <= N;i++){
		scanf("%d",&Tmp);
		A[Tmp] = 1;
		Alen = Alen<Tmp ? Tmp:Alen;
	}
	Tmp = 0;
	for(int i = 1;i <= Alen;i++){
		if(A[i]) Tmp++;
		if(Tmp == K){
			printf("%d",i);
			Check = 0;
			break;
		}
	}
	if(Check) printf("NO RESULT");
	return 0;
}
