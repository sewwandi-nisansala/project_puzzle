#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node1
{
    char list1[100];
    struct node1* next;
} node1;
 

typedef struct node2
{
    char list2[100];
    struct node2* next;
} node2;

typedef void (*callback)(node1* node1);
typedef void (*callback)(node1* node2);
 
//this function is to print the matrix
//void print_matrix(char matrix,int n){


int main(){

	char words[100];
	char inputs[100];
	int k = 1;
	//char matrix[i][j];
	
	while(1){
		gets(words);
		//words = getchar();
 		printf("\nLength of input : %d\n", strlen(words));
 		
		if(strlen(words) == 0){
			printf("Null test 2");
		break;
		}

		printf("Got data : %s & length : %d\n" ,words,strlen(words));
		k++;
		

//adding data(word) to a linked list
		/*
    		create a new node
   		 initialize the data and next field
 
   		 return the newly created node
		*/
		node1* create(char list1,node1* next){
   		node1* new_node1 = (node1*)malloc(sizeof(node1));
    		if(new_node1 == NULL){
   			printf("Error creating a new node1.\n");
      			exit(0);
   		 }
		
    		//new_node1->list1 = words;
		strcpy(new_node1->list1,words);
    		new_node1->next = next;
		printf("hello");
 		while( new_node1 != NULL){
			printf("hello");
			printf("%s\n",new_node1->list1);	
			
			new_node1->next = next;
		}
		//printf("%s\n",new_node1->list1);

    		return new_node1;
		}
		
	}
		

		while(1){
		
		gets(inputs);
		//inputs = getchar(); 		
		printf("\nLength of input : %d\n", strlen(inputs));
 		
		if(strlen(inputs) == 0){
			printf("Null test 2");
		break;
		}

//again add data to another linked list
/*
    		create a new node
   		 initialize the data and next field
 
   		 return the newly created node
		*/
		node2* create(char list2,node2* next){
   		node2* new_node2 = (node2*)malloc(sizeof(node2));
    		if(new_node2 == NULL){
   			printf("Error creating a new node2.\n");
      			exit(0);
   		 }
    		//new_node2->list2 = inputs;
		strcpy(new_node2->list2,inputs);
    		new_node2->next = next;
 
    		return new_node2;
		}


		printf("Got data : %s & length : %d\n" ,inputs,strlen(inputs));
		k++;
	}

	
//make 2D array obove linked lists

	printf("\n number of Node Reads : %d\n",k);
return 0;
}
