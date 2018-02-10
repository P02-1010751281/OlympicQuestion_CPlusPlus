#include <algorithm>
#include <cstdio>

const int Maxn = 50 + 5;

int Atlas[Maxn][Maxn];
int Equation[Maxn][Maxn][Maxn];
int Line,List;

int Dp(){
	for(int i = 1;i <= Line;i++)
		for(int j = 1;j <= List;j++)
			for(int k = 1;k < i + j  && k <= Line;k++)
				if((i != k || (i == Line && k == Line && j == List)) && (i + j - k) <= List)
					Equation[i][j][k] += Atlas[i][j] + Atlas[k][i + j - k] + std::max(std::max(Equation[i - 1][j][k],Equation[i - 1][j][k - 1]),std::max(Equation[i][j - 1][k],Equation[i][j - 1][k - 1]));
//					printf("	i=%d j=%d k=%d i+j-k=%d : %d\n",i,j,k,i+j-k,Equation[i][j][k]);
	return Equation[Line][List][Line];
}

void Read(){
	scanf("%d%d",&Line,&List);
	for(int i = 1;i <= Line;i++)
		for(int j = 1;j <= List;j++)
			scanf("%d",&Atlas[i][j]);
}

int main(){
	Read();
	printf("%d",Dp());
	return 0;
}
/*
#include <algorithm>
#include <cstdio>

const int Maxn = 50 + 5;

int Atlas[Maxn][Maxn];
int Equation[Maxn][Maxn][Maxn][Maxn];
int Line,List;

int Dp(){
	for(int i = 1;i <= Line;i++)
		for(int j = 1;j <= List;j++)
			for(int k = 1;k <= Line;k++)
				for(int n = 1;n <= List;n++)
					if((i != k && j != n) || (i == Line && k == Line && j == List && n == List))
						Equation[i][j][k][n] += std::max(std::max(Equation[i - 1][j][k - 1][n],Equation[i - 1][j][k][n -1 ]),std::max(Equation[i][j - 1][k - 1][n],Equation[i][j - 1][k][n - 1])) + Atlas[i][j] + Atlas[k][n];
	return Equation[Line][List][Line][List];
}

void Read(){
	scanf("%d%d",&Line,&List);
	for(int i = 1;i <= Line;i++)
		for(int j = 1;j <= List;j++)
			scanf("%d",&Atlas[i][j]);
}

int main(){
	Read();
	printf("%d",Dp());
	return 0;
}
*/
/*
#include <algorithm>
#include <cstdio>

const int Maxn = 50 + 5;

int Atlas[Maxn][Maxn];
int Equation[Maxn][Maxn][Maxn];
int Line,List;

int Dp(){
	for(int i = 1;i <= List;i++)
		for(int j = 1;j <= Line;j++)
			for(int k = 1;k <= List;k++)
				if((i != k && j != (i + j - k)) || (i == Line && k == Line && j == List && (i + j - k) == List))
					Equation[i][j][k] += Atlas[i][j] + Atlas[k][i + j - k] + std::max(std::max(Equation[i - 1][j][k],Equation[i][j - 1][k]),std::max(Equation[i - 1][j][k - 1],Equation[i][j - 1][k - 1]));
	return Equation[List][Line][List];
}

void Read(){
	scanf("%d%d",&Line,&List);
	for(int i = 1;i <= List;i++)
		for(int j = 1;j <= Line;j++)
			scanf("%d",&Atlas[i][j]);
}

int main(){
	Read();
	printf("%d",Dp());
	return 0;
}
*/
/*
#include <cstdio>
#include <iostream>

int n,m,ans,a[51][51] = {0},f[51][51][51][51] = {0};
int DFS(int x,int y,int x2,int y2){
    if (x == n && x2 == n && y == n && y2 == m) return 0;
    if (f[x][y][x2][y2]) return f[x][y][x2][y2];
    int t = 0;
    if (x < n && x2 < n) t = std::max(t,DFS(x+1,y,x2+1,y2)+a[x][y]+a[x2][y2]-a[x][y]*(x == x2 && y == y2));
    if (x < n && y2 < m) t = std::max(t,DFS(x+1,y,x2,y2+1)+a[x][y]+a[x2][y2]-a[x][y]*(x == x2 && y == y2));
    if (y < m && x2 < n) t = std::max(t,DFS(x,y+1,x2+1,y2)+a[x][y]+a[x2][y2]-a[x][y]*(x == x2 && y == y2));
    if (y < m && y2 < m) t = std::max(t,DFS(x,y+1,x2,y2+1)+a[x][y]+a[x2][y2]-a[x][y]*(x == x2 && y == y2));
    //if (y < m) t = std::max(t,DFS(x,y+1,sum+a[x][y+1]));
    return f[x][y][x2][y2] = t;
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            scanf("%d",&a[i][j]);
    printf("%d",DFS(0,0,0,0));
}
*/
