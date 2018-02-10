#include<cstdio>

int A[2500],Alen = 0;

void Change(int x){
	if(x != 0){
		A[Alen++] = x%8;
		Change(x/8);
	} 
} 

int main(){
	freopen("change.in","r",stdin);
	freopen("change.out","w",stdout);
	int N;
	scanf("%d",&N);
	Change(N);
	for(int i = Alen-1;i >= 0;i--) printf("%d",A[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
