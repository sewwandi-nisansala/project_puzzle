#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char capital_simple_letters(char letter);

int main() {
    char inputs[100];

    char puzzel[100][100];
    char words[100][100];

    //  While loop to get puzzel data
    int input_count = 0;
    while (1) {
        gets(inputs);
        if (strlen(inputs) == 0) {
            break;
        }
        strcpy(puzzel[input_count], inputs);
        input_count++;
    }

    int length_of_puzzle = input_count;

    //While loop to get words data
    input_count = 0;
    while (1) {
        gets(inputs);
        if (strlen(inputs) == 0) {
            break;
        }
        strcpy(words[input_count], inputs);
        input_count++;
    }

    int num_of_words = input_count;

    int count = 0;

    //Set All Letters to capital
    for (int i = 0; i < num_of_words; i++) {
        for (int j = 0; j < strlen(words[i]); j++) {
            words[i][j] = capital_simple_letters(words[i][j]);
        }
    }

    bool is_done = false;
    //Fill horizontal
    count = 0;
    char empty_word[100];

    for (int j = 0; j < length_of_puzzle; j++) {
        count = 0;
        for (int k = 0; k < strlen(puzzel[j]); k++) {
            if (puzzel[j][k] == '#') {
                count++;
            }
        }
        for (int i = 0; i < num_of_words; i++) {
            if (count == strlen(words[i])) {
                char word[100];
                strcpy(word, words[i]);
                int letter = 0;
                for (int k = 0; k < strlen(puzzel[j]); k++) {
                    if (puzzel[j][k] == '#') {
                        puzzel[j][k] = word[letter];
                        letter++;
                        is_done = true;
                    }
                }
                if (is_done) {
                    strcpy(words[i], empty_word);
                }
            }
        }
    }

    //Fill vertical
    count = 0;
    for (int j = 0; j < strlen(puzzel[j]); j++) {
        count = 0;
        for (int k = 0; k < length_of_puzzle; k++) {
            if (puzzel[k][j] != '*') {
                count++;
            }
        }
        for (int i = 0; i < num_of_words; i++) {
            if (count == strlen(words[i])) {
                char word[100];
                strcpy(word, words[i]);
                int letter = 0;
                for (int k = 0; k < length_of_puzzle; k++) {
                    if (puzzel[k][j] == '#') {
                        puzzel[k][j] = words[i][letter];
                        letter++;
                        is_done = true;
                    } else if (puzzel[k][j] == words[i][letter]) {
                        puzzel[k][j] = word[letter];
                        letter++;
                        is_done = true;
                    } else if (puzzel[k][j] != words[i][letter]) {
                        //is_done = false;
                    }

                    if (!is_done) {
                        k = length_of_puzzle;
                    }
                }
                if (is_done) {
                    strcpy(words[i], empty_word);
                }
            }
        }
    }

    //Print impossible & exit
    for (int i = 0; i < num_of_words; i++) {
        int k = (int) strlen(words[i]);
        if (strlen(words[i]) != 0) {
            printf("IMPOSSIBLE");
            return 0;
        }
    }

    //Print Solution & exit
    for (int i = 0; i < length_of_puzzle; i++) {
        printf("%s\n", puzzel[i]);
    }
    return 0;
}


//convert simple letters to capital leters
char capital_simple_letters(char letter) {
    if (letter == 'a') {
        letter = 'A';
    } else if (letter == 'b') {
        letter = 'B';
    } else if (letter == 'c') {
        letter = 'C';
    } else if (letter == 'd') {
        letter = 'D';
    } else if (letter == 'e') {
        letter = 'E';
    } else if (letter == 'f') {
        letter = 'F';
    } else if (letter == 'g') {
        letter = 'G';
    } else if (letter == 'h') {
        letter = 'H';
    } else if (letter == 'i') {
        letter = 'I';
    } else if (letter == 'j') {
        letter = 'J';
    } else if (letter == 'k') {
        letter = 'K';
    } else if (letter == 'l') {
        letter = 'L';
    } else if (letter == 'o') {
        letter = 'O';
    } else if (letter == 'p') {
        letter = 'P';
    } else if (letter == 'q') {
        letter = 'Q';
    } else if (letter == 'r') {
        letter = 'R';
    } else if (letter == 's') {
        letter = 'S';
    } else if (letter == 't') {
        letter = 'T';
    } else if (letter == 'u') {
        letter = 'U';
    } else if (letter == 'v') {
        letter = 'V';
    } else if (letter == 'w') {
        letter = 'W';
    } else if (letter == 'x') {
        letter = 'X';
    } else if (letter == 'y') {
        letter = 'Y';
    } else if (letter == 'z') {
        letter = 'Z';
    }
    return letter;
}


