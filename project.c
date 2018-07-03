#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char array[100];
    struct node* next;
} node;
 

typedef void (*callback)(node* node);

 //function to add new nodes
node* createNewNode(char array,node* ptr){
/*
    	create a new node -initialize the data and next field
	return the newly created node
		*/
		//node* create(char list1,node1* next)
	node* next;
	node* new_node = (node*)malloc(sizeof(node));
        if(new_node == NULL){
   		printf("Error creating a new node.\n");
      		exit(0);
        }
		
        //new_node1->list1 = words;
	strcpy(new_node->array,ptr);
        new_node->next = next;
        return new_node;
}
 		

//function to count the elements of the linked list
int count(node* head){
	node *cursor = head;
	int c = 0;
	while(cursor != NULL)
	{
		c++;
		cursor = cursor->next;
	}
	return c;
}

//function to print the eleents in the linked list
void printlist(node * head){
	node * current = head;
	while( current != NULL)
	{
		printf("%s\n",current->array);
	}
	current = current->next;
}
		
int main(){

	char puzzle_array[100];
	char inputs[100];
	int k = 1;
	//char matrix[i][j];
	node* puzzle;	
	node* words;
	
	while(1){
		gets(puzzle_array);
		//words = getchar();
 		//printf("\nLength of input : %d\n", strlen(puzzle_array));
 		
		if(strlen(puzzle_array) == 0){
			printf("Null test 2");
		break;
		}

		//printf("Got data : %s & length : %d\n" ,puzzle_array,strlen(puzzle_array));
		k++;
		

//adding data(word) to a linked list
	createNewNode(puzzle,puzzle_array);
	printlist(&puzzle);	
	}
		

		while(1){
		
		gets(inputs);
		//inputs = getchar(); 		
		//printf("\nLength of input : %d\n", strlen(inputs));
 		
		if(strlen(inputs) == 0){
			printf("Null test 2");
		break;
		printlist(&words);	
		}

//again add data to another linked list
	createNewNode(words,inputs);
	

		//printf("Got data : %s & length : %d\n" ,inputs,strlen(inputs));
		k++;
	}

	
//make 2D array obove linked lists

	printf("\n number of Node Reads : %d\n",k);
return 0;
}
