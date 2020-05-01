#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//declaring function

int is_argument_valid(string arg);

int main(int argc, string argv[]) {

    string passed_argument = argv[1];

    //checking whether use supplied enoguh arguments, and if second argument is all digits.
    if (argc == 2 && is_argument_valid(passed_argument) == 0) {

        //converting string to int.
        int key = atoi(passed_argument);

        //Calculating how much each number has to shift.
        //26 is the length of the alphabet
        //so the shift would be the remainder of how many times 26 goes into the supplied key.
        int shift = key % 26;

        string plaintext = get_string("Text to be encrypted: ");
        printf("ciphertext: ");

        for(int i = 0; i < plaintext[i] != '\0'; i++) {
        //for readability, I add shift to the provided ascii, to use when those together exceeds upperbound
        int sum_of_plaintext_and_shift = plaintext[i] + shift;

        //The following is conditions determining the shift of the key.
            if(plaintext[i] >= 'A' && plaintext[i] <= 'Z') {

                if(sum_of_plaintext_and_shift > 'Z') {
                    //add the result of sum_of_plaintext_and_shift - upperbound of selected alphabet to 64, to get correct shift.
                   printf("%c", 64 + (sum_of_plaintext_and_shift - 90));
                } else {
                   printf("%c", sum_of_plaintext_and_shift);
                }


            } else if(plaintext[i] >= 'a' && plaintext[i] <= 'z') {

                if(sum_of_plaintext_and_shift > 'z') {
                    //same
                    printf("%c", 96 + (sum_of_plaintext_and_shift - 122));
                } else {
                   printf("%c", sum_of_plaintext_and_shift);
                }

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
    //running through each element to see if digit. Return false if not.
     for(int i = 0, l = strlen(arg); i < l; i++) {
        if(isdigit(arg[i]) == 0) {
            return 1;
        }
    }

    return 0;
}