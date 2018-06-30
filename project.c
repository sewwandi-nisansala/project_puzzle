#include <stdio.h>
#include <string.h>
int main(){

	char s[100];
	int k = 1;

	while(1){
		gets(s);
 		printf("\nLength of input : %d\n", strlen(s));
 		if(s[0]== NULL){
			printf("Null test 1");
			break;
		}
		if(strlen(s) == 0){
			printf("Null test 2");
		break;
		}

		printf("Got data : %s & length : %d\n" ,s,strlen(s));
		k++;
	}

	
	printf("\n number of Node Reads : %d\n",k);
return 0;
}
