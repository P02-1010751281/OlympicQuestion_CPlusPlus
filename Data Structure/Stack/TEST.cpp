#include<cstdio>

int main(){
	freopen("Test.txt","w",stdout);
	for(int i = 0;i <= 30000;i++) printf("%d ",i);
	fclose(stdout);
	return 0;
}
