#include <cstdio>
#include <windows.h>

int main(){
	freopen("Test.txt","w",stdout);
	for(int i = 0;i <= 300000;i++) printf("%d ",rand()%2);
	fclose(stdin);
	return 0;
} 
