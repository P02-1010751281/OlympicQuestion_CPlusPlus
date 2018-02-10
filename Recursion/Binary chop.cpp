#include<cstdio>

int A[250],N,x;

void Find(int L,int R){
	int Mid = (L+R)/2;
	if(x == A[Mid]) printf("Yes");
	else if(x > A[Mid]) Find(Mid+1,R);
	else if(x < A[Mid]) Find(L,Mid-1);
	else printf("No");
}

int main(){
	scanf("%d%d",&N,&x);
	for(int i = 1;i <= N;i++) scanf("%d",&A[i]);
	Find(1,N);
	return 0;
}
