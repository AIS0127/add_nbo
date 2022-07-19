#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include <netinet/in.h>


int main(int argc, char *argv[]){
	uint32_t val1,val2;
	FILE *fp1,*fp2;
	if(!(fp1 = fopen(argv[1],"r")) || !(fp2 = fopen(argv[2],"r"))){
				printf("open error\n");
				exit(0);
	}	
	if(((int)(fread(&val1,4,1,fp1)) < 0) || ((int)(fread(&val2,4,1,fp2)) < 0)){
		printf("read error\n");
		exit(0);
	}
	val1 = htonl(val1);
	val2 = htonl(val2);
	printf("%d(%#x) + %d(%#x) = %d(%#x)\n",val1,val1,val2,val2,val1+val2,val1+val2);

}
	

