#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*struct node{
	int length;
	struct Node *next;
};
*/


//this function is to print the matrix
void print_matrix(char matrix,int n){

}
int main(){

	char word[100];
	int k = 1;
	char matrix[i][j];
	int i,j;

	while(1){
		//gets(word);
		word = getchar();
 		printf("\nLength of input : %d\n", strlen(word));
 		/*if(word[0] == NULL){
			printf("Null test 1");
			break;
		}*/
		if(strlen(word) == 0){
			printf("Null test 2");
		break;
		}

		printf("Got data : %s & length : %d\n" ,word,strlen(word));
		k++;
		

		//adding values to 2D array
		for(i=0;i<strlen(word);i++){
			for(j=0;j<k;j++){
			matrix[i][j] = (char) word;
			scanf("%s",&matrix[i][j]);
			printf("%s", matrix[i][j]);
			}
		}
			printf("%s", matrix[i][j]);
	}

		while(1){
		//gets(word);
		//word = getchar(); 		
		printf("\nLength of input : %d\n", strlen(word));
 		/*if(s[0] == NULL){
			printf("Null test 1");
			break;
		}*/
		if(strlen(word) == 0){
			printf("Null test 2");
		break;
		}

		printf("Got data : %s & length : %d\n" ,word,strlen(word));
		k++;
	}

	
	printf("\n number of Node Reads : %d\n",k);
return 0;
}
