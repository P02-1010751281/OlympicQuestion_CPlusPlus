#include<cstdio>

int MaxGcd(int x,int y){
	if(x%y == 0) return y;
	return MaxGcd(y,x%y);
}

int main(){
	freopen("gcdmax.in","r",stdin);
	freopen("gsdmax.out","w",stdout);
	int M,N;
	scanf("%d%d",&M,&N);
	printf("%d",MaxGcd(M,N));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
