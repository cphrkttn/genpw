#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char* pwgen(int N) {
    int i = 0;
    int randomizer = 0;

    // Arrays
    char number[] = "0123456789";
    char letterLower[] = "abcdefghijklmnopqrstuvwxyz";
    char letterUpper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char special[] = "!@#$^&*?";

    char* password = malloc(N + 1);
    if (password == NULL) {
	    fprintf(stderr, "Error: memory allocation failed.\n");
	    exit(EXIT_FAILURE);
    }

    randomizer = rand() % 4;

    for (i=0; i<N; i++) {
        switch (randomizer) {
	    case 1:
		    password[i] = number[rand() % 10];
		    randomizer = rand() % 4;
		    //printf("%c", password[i]);
		    break;
	    case 2:
		    password[i] = special[rand() % 8];
                    randomizer = rand() % 4;
                    //printf("%c", password[i]);
		    break;
	    case 3:
		    password[i] = letterUpper[rand() % 26];
                    randomizer = rand() % 4;
                    //printf("%c", password[i]);
		    break;
	    default:
		    password[i] = letterLower[rand() % 26];
                    randomizer = rand() % 4;
                    //printf("%c", password[i]);
		    break;
	}
    }
    //printf("\n");
    password[N] = '\0';
    return password;
}


int main(int argc, char** argv) {

    // if arg count less than two throw error
    if (argc != 2) {
	fprintf(stderr, "Usage: %s <length>\n", argv[0]);
	exit(EXIT_FAILURE);
    }
    
    // argc is good so init N
    int N = atoi(argv[1]);

    // check N because atoi doesn't handle errors
    if (N <= 0) {
	fprintf(stderr, "Error: length must be a positive integer.\n");
        exit(EXIT_FAILURE);
    }

    
    // seed prng with current time
    srand(time(NULL));

    // if all ok run function
    char* pw = pwgen(N);
    printf("%s\n", pw);
    free(pw);


    return 0;
}
