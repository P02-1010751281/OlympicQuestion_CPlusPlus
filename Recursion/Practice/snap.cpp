#include<cstdio>

int A[25000],N,S;

int Dfs(int n,int s){
	if(s == 0) 	return 1;
	else if(s < 0 || (s > 0 && n == 0))  return 0;
	else if(Dfs(n-1,s-A[n])){
		printf("number:%d weight:%d\n",n,A[n]);
		return 1;
	}else if(Dfs(n-1,s)) return 1;
	else return 0;
}

int main(){
	freopen("snap.in","r",stdin);
	freopen("snap.out","w",stdout);
	scanf("%d%d",&N,&S);
	for(int i = 1;i <= N;i++) scanf("%d",&A[i]);
	if(!Dfs(N,S)) printf("not found");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
