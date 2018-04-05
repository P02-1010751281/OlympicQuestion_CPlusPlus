#include <cstdio> 
#include <cstring>

bool used[];
memset(Dis,0x7f,sizeof(Dis));
Dis[s] = 0; 
for(int i = 1;i <= n;i++){
	int u = 0,min = 0x7fffffff;
	for(int j = 1;j <= n;j++){
		if(w[j] < min && !used[j]){
			u = j;
			min = w[j];
		}
	} 
	if(u == 0) break;
	used[k] = 1;
	for(int j = 1;j <= n;j++){
		if(Dis[u]+w[u][j] < Dis[j]) Dis[j] = Dis[u]+w[u][j];
	}
}

for(int k = 1;k <= n;k++){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(Dis[i][j] > Dis[i][k]+Dis[k][j]) Dis[j] = Dis[i][k]+Dis[k][j];
		}
	}
}
