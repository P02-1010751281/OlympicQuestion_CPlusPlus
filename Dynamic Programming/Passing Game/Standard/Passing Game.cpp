#include <cstdio>

const int Maxn = 30 + 5;

int Times,Number;
int Equation[Maxn + 5][Maxn + 5];

int Dp(){
	Equation[0][1] = 1;
	for(int i = 1;i <= Times;i++){
		Equation[i][1] = Equation[i - 1][2] + Equation[i - 1][Number];
		for(int j = 2;j < Number;j++) Equation[i][j] = Equation[i - 1][j - 1] + Equation[i - 1][j + 1];
		Equation[i][Number] = Equation[i - 1][Number - 1] + Equation[i - 1][1];
	}
	return Equation[Times][1]; 
}

void Read(){
	scanf("%d%d",&Number,&Times);
}

int main(){
	Read();
	printf("%d",Dp());
	return 0; 
} 

/*
#include <cstdio>
#include <iostream>

int n,m,f[31][31] = {0};
bool c[31][31] = {0};

int DFS(int x,int y){
    if (x == 0) x = n;
    if (x == n+1) x = 1;
    if (y == m+1) {
        if (x == 1) return 1;
        return 0;
    }
    if (f[x][y] || c[x][y]) return f[x][y];
    c[x][y] = 1;
    return f[x][y] = DFS(x+1,y+1)+DFS(x-1,y+1);
}

int DP(){
    f[1][0] = 1;
    for (int i = 1;i <= m;i++) { //次数
        f[1][i] = f[2][i-1] + f[n][i-1]; //处理圈首
        for (int j = 2;i < n;j++) f[j][i] = f[j-1][i-1]+f[j+1][i-1]; //处理圈
        f[n][i] = f[1][i-1]+f[n-1][i-1]; //处理圈尾
    }
    return f[1][m];
}

int main(){
    scanf("%d%d",&n,&m);
    printf("%d",DFS(1,1));
}
*/
