#include<cstdio>
#include<cstring>

bool A[7][7];
int SX,SY,FX,FY,N,M,T,Sum = 0;
const int X[4] = {1,0,0,-1};
const int Y[4] = {0,1,-1,0};

void DFS(int x,int y){
	if(A[x][y]) return ;
	if(x == FX && y == FY) {
		Sum++;
		return ;
	}
	for(int i = 0;i < 4;i++){
		A[x][y] = 1;
		DFS(x+X[i],y+Y[i]);
		A[x][y] = 0;
	}
}

int main(){
	memset(A,true,sizeof(A));
	scanf("%d%d%d",&N,&M,&T);
	scanf("%d%d%d%d",&SX,&SY,&FX,&FY);
	for(int i = 1;i <= N;i++)
		for(int j = 1;j <= M;j++)
			A[i][j] = 0;
	for(int i = 1;i <= T;i++){
		int TX,TY;
		scanf("%d%d",&TX,&TY);
		A[TX][TY] = 1;
	}
	DFS(SX,SY);
	printf("%d",Sum);
	return 0;
}

