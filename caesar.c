#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int is_argument_valid(string arg);

int main(int argc, string argv[]) {

    string passed_argument = argv[1];

    if (argc == 2 && is_argument_valid(passed_argument) == 0) {
        int key = atoi(passed_argument);
        int shift = key % 26;

        string plaintext = get_string("Text to be encrypted: ");

        printf("ciphertext: ");

        for(int i = 0; i < plaintext[i] != '\0'; i++) {

            if(plaintext[i] >= 'A' && plaintext[i] <= 'Z') {

                if(plaintext[i] + shift > 'Z') {
                    prinft("%c", 64 + (plaintext[i] + shift - 'Z'))
                }


            } else if(plaintext[i] >= 'a' && plaintext[i] <= 'z') {


            } else {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");



    } else {
        printf("Usage: %s int key\n", argv[0]);
        return 1;
    }

}

int is_argument_valid(string arg) {
     for(int i = 0, l = strlen(arg); i < l; i++) {
        if(isdigit(arg[i]) == 0) {
            return 1;
        }
    }

    return 0;
}