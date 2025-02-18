#include "sha256.c"

#include <stdio.h>

int main(void)
{
    /* Input text. */
    const char * text = "toto";
	char * hashedText = hash((char *) text);
	const char * onlineHash = "31f7a65e315586ac198bd798b6629ce4903d0899476d5741a9f32e2e521b6a66";
	
    // /* Print result. */
    printf("The SHA-256 sum of \"%s\" is:\n", text);
    printf("%s\n\n", hashedText);

    printf("The online SHA-256 sum of \"toto\" is:\n");
	printf("%s\n\n", onlineHash);

	printf("Let's compare the two:\n");
	printf("Cmp: %d\n", verify(hashedText, (char *) onlineHash));

    return 0;
}
