#include <stdio.h>
#include <stdlib.h>
int main(){
	int counter9, counter10, counter11, counter12 = 0;
	int basecounter = 0;
	FILE *fp = NULL; 
	fp = fopen("107.txt", "r");
	char a[10000] = {0};

	int count[100] = {0};
	if(fp == NULL)
	{
		return 0;
	}
	for(int i=0; i<10000; i++)
	{
		
			fscanf(fp,"%c",&a[i]);
			//printf("%c ", a[i]);
			if(a[i] == '1'){
				basecounter ++;
			}
			if(a[i] == '0' && a[i-2] == '1'){
/*
			if(basecounter == 9){counter9 ++;}
			if(basecounter == 10){counter10 ++;}
			if(basecounter == 11){counter11 ++;}
			if(basecounter == 12){counter12 ++;}
*/			
				count[basecounter]++;
				basecounter = 0;
			}
		
	}
	//getchar();
/*
	printf("%d\n", counter9);
	printf("%d\n", counter10);
	printf("%d\n", counter11);
	printf("%d\n", counter12);
*/
	for(int i = 0; i < 100; i++){
		printf("%d %d\n", i, count[i]);	
	}
	fclose(fp);	
	return 0;
}
