#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void pwgen(int N) {
    int i = 0;
    int randomizer = 0;


    // seed prng with current time
    srand(time(NULL));

    // Arrays
    char number[] = "0123456789";
    char letterLower[] = "abcdefghijklmnopqrstuvwxyz";
    char letterUpper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char special[] = "!@#$^&*?";

    char password[N];

    randomizer = rand() % 4;

    for (i=0; i<N; i++) {
        switch (randomizer) {
	    case 1:
		    password[i] = number[rand() % 10];
		    randomizer = rand() % 4;
		    printf("%c", password[i]);
		    break;
	    case 2:
		    password[i] = special[rand() % 8];
                    randomizer = rand() % 4;
                    printf("%c", password[i]);
		    break;
	    case 3:
		    password[i] = letterUpper[rand() % 26];
                    randomizer = rand() % 4;
                    printf("%c", password[i]);
		    break;
	    default:
		    password[i] = letterLower[rand() % 26];
                    randomizer = rand() % 4;
                    printf("%c", password[i]);
		    break;
	}
    }
    printf("\n");
}




int main(int argc, char** argv) {

    if (argc < 2 || argc > 2) {
	fprintf(stderr, "Syntax error!\n");
	fprintf(stderr, "Usage: %s <length>\n", argv[0]);
	exit(EXIT_FAILURE);
   } else {
        int N = atoi(argv[1]);
        pwgen(N);
   }
    return 0;
}
