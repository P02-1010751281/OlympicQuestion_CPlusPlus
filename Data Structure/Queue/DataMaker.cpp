#include <cstdio>

int main(){
	freopen("Test.txt","w",stdout);
	for(int i = 0;i <= 300000;i++) printf("%d ",i);
	fclose(stdin);
	return 0;
} 
