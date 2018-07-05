#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Link List Node
 */
typedef struct node {
    char data[100];
    struct node *next;
} node;
/**
 * Create a new node
 * This is use only for the first node. other data will append.
 *
 * @param data initial data
 * @param next headNode
 * @return newNode
 */
node *create(char data[], node *next) {
    node *new_node = (node *) malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }
    strcpy(new_node->data, data);
    new_node->next = next;
    return new_node;
}
/**
 * Add a new node at the end of link list
 *
 * @param head headNode of the link list
 * @param data new node data
 * @return  updated link list with new node at the end of link list
 */
node *append(node *head, char data[]) {
    if (head == NULL)
        return NULL;
    /* go to the last node */
    node *cursor = head;
    while (cursor->next != NULL)
        cursor = cursor->next;
    /* create a new node */
    node *new_node = create(data, NULL);
    cursor->next = new_node;
    return head;
}
/**
 * return the number of elements in the list
 *
 * @param head headNode of the link list
 * @return number of nodes
 */
int count(node *head) {
    node *cursor = head;
    int c = 0;
    while (cursor != NULL) {
        c++;
        cursor = cursor->next;
    }
    return c;
}
void linklist_to_array(int array_index, char data[], node *head) {
    if (head == NULL) {
        return;
    }
    node *cursor = head;
    int array_count = 0;
    while (cursor != NULL) {
        strcpy(data, cursor->data);
        array_count++;
        if (array_count > array_index) {
            break;
        }
        cursor = cursor->next;
    }
}

// this function is used to print
// the resultant matrix
void printMatrix(char matrix[], int n)
{
	//for (int i = 0; i < n; i++)
		//cout << matrix[i] << endl;

for(int row=0;row<n;row++){
	//for(col = 0;col <4; col++){
		printf("%c",matrix[row]);
		//printf("%c",puzzle_matrix[row][col]);
	}
	//putchar('\n');
//}
}


// this function checks for the current word if it can be placed horizontally or not
// x -> it represent index of row
// y -> it represent index of column
// currentWord -> it represent the current word in word array
char checkHorizontal(int x, int y,char puzzle_matrix[][100], char words_matrix[]){
int n = strlen(words_matrix);
for (int i = 0; i < n; i++) {
	if (puzzle_matrix[x][y + i] == '#' || puzzle_matrix[x][y + i] == words_matrix[i]) {
	puzzle_matrix[x][y + i] = words_matrix[i];
	}
	else {
	// this shows that word cannot be placed horizontally
	printf("\nIMPOSSIBLE");
        //puzzle_matrix[0][0] = '@';
	return puzzle_matrix;
	}
}

return puzzle_matrix;
}

// this function checks for the current word if it can be placed vertically or not
// x -> it represent index of row
// y -> it represent index of column
// currentWord -> it represent the
// current word in word array
char checkVertical(int x, int y,char puzzle_matrix[][100], char words_matrix[]){
int n = strlen(words_matrix);

for (int i = 0; i < n; i++) {
	if (puzzle_matrix[x + i][y] == '#' || puzzle_matrix[x + i][y] == words_matrix[i]) {
	puzzle_matrix[x + i][y ] = words_matrix[i];
	}
	else {
	// this shows that word cannot be placed horizontally
	printf("\nIMPOSSIBLE");
	puzzle_matrix[0][0] = '@';
	return puzzle_matrix;
	}
}
return puzzle_matrix;
}

// this function recursively checks for every word that can align vertically in one loop
// and in another loop it checks for those word that can align horizontally 
// words -> it contains all the words to fill in a crossword
// puzzle matrix -> it contain the current state of crossword
// index -> it represent the index of current word 
// n -> it represent the length of row or column of the square matrix
void solvePuzzle(char words[][100],char matrix[][100],int index, int n)
{
	if (index < strlen(words)) {
		char currentWord = words[index];
		int maxLen = n - strlen(currentWord);

		// loop to check the words that can align vertically.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= maxLen; j++) {
				char temp = checkVertical(j, i,matrix, currentWord);

				if (temp[0][0] != '@') {
					solvePuzzle(words, temp, index + 1, n);
				}
			}
		}

		// loop to check the words that can align horizontally.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= maxLen; j++) {
				char temp = checkHorizontal(i, j,matrix, currentWord);

				if (temp[0][0] != '@') {
					solvePuzzle(words, temp, index + 1, n);
				}
			}
		}
	}
	else {
		// calling of print function to
		// print the crossword puzzle
		//cout << (ways + 1) << " way to solve the puzzle "
		//	<< endl;
		printMatrix(matrix, n);
		//cout << endl;

		// increase the ways
		//ways++;
		return;
	}
}

/**
 * Main Method
 * @return
 */
int main() {
    char inputs[100];
    ///
    /// Head Nodes of puzzel & words link lists
    ///
    node *puzzle = NULL;
    node *words = NULL;
    ///
    ///  While loop to get puzzel data
    ///
    while (1) {
        gets(inputs);
        if (strlen(inputs) == 0) {
            break;
        }
        if (puzzle == NULL) {
            puzzle = create(inputs, puzzle);
        } else {
            append(puzzle, inputs);
        }
    }
    ///
    /// While loop to get words data
    ///
    while (1) {
        gets(inputs);
        if (strlen(inputs) == 0) {
            break;
        }
        if (words == NULL) {
            words = create(inputs, words);
        } else {
            append(words, inputs);
        }
    }
    ///
    /// Print the count of puzzel & words lengths
    ///
    printf("number of Puzzel Lenght : %d\n", count(puzzle));
    printf("words Lenght : %d\n", count(words));
    ///
    /// Create 2D Arrays
    ///
    char array_puzzle[count(puzzle)][100];
    char array_words[count(words)][100];
    ///
    /// Copy Puzzel Link List data to 2D array
    ///
    for (int i = 0; i < count(puzzle); i++) {
        char data[100];
        linklist_to_array(i, data, puzzle);
        strcpy(array_puzzle[i], data);
    }
    ///
    /// Copy Words Link List data to 2D array
    ///
    for (int i = 0; i < count(words); i++) {
        char data[100];
        linklist_to_array(i, data, words);
        strcpy(array_words[i], data);
    }
    // Processing of Pass/ Fail is done from here
    /*Maximum Length of the Puzzle will be 100 characters*/

    ///solving the puzzle
    // recursive function to solve the puzzle
    // Here 0 is the initial index of words array
    
    solvePuzzle(array_words, array_puzzle, 0, count(puzzle));

    return 0;
}

