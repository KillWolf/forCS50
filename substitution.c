#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int is_key_valid(string key);

int main(int argc, string argv[]) {
    
    string key = argv[1];
    
    //1. Make sure there is a key (command line argument) 
    //2. Chceck the that the key is correct (function)
    if (argc == 2 && is_key_valid(key) == 0) { 
    
    //3. Ask user to provide plaintext to be encrypted
    string plaintext = get_string("Text to be encrypted: ");
    long plaintext_length = strlen(plaintext);
    int key_length = strlen(key);
    
    //4. Loop through plaintext, and encrypt
    //4.1 Case insensitive plaintext
    //4.2 Case insensitive key
    
    printf("ciphertext: ");
    for(int i = 0; i < plaintext_length; i++) {
        if(isalpha(plaintext[i]) == 0) {
            printf("%c", plaintext[i]);
        }
        
        for(int j = 0; j < key_length; j++) {
            
            //Problemet her, ligger i key[i]. Den arbejder udfra længden på plaintext, og kan defor aldrig overstige f.eks. 5 hvis Hello er plaintext.
            //Det er problematisk hvis f.eks. at key input har forskellige case. Key tjekket skal derfor være på samme sted som plaintextens bogstavs ASCII tal
        
            if(key[j] < 91) {
                if(plaintext[i] < 91 && plaintext[i] > 64) {
                    if(j == plaintext[i] - 65) {
                        printf("%c", key[j]);
                    }
                }
                
                if(plaintext[i] < 123 && plaintext[i] > 96) {
                    if(j == plaintext[i] - 97) {
                        printf("%c", key[j] + 32);
                    }
                }
            } else {
                
                if(plaintext[i] < 91 && plaintext[i] > 64) {
                    if(j == plaintext[i] - 65) {
                        printf("%c", key[j] - 32);
                    }
                }
                
                if(plaintext[i] < 123 && plaintext[i] > 96) {
                    if(j == plaintext[i] - 97) {
                        printf("%c", key[j]);
                    }
                }
            }
            
        }
    }
    printf("\n");
    
    } else {
        printf("Usage: %s key, where key is alphabetic characters, 26 long, and letters are unique\n", argv[0]);
        return 1;
    }
}

int is_key_valid(string key) {
    
    int key_length = strlen(key);
    
    //3. Check for length
    if(key_length != 26) {
        return 1;
    } 
    
    //4. Check for only alphabetic characters 
    for(int i = 0; i < key_length; i++) {
        if(isalpha(key[i]) == 0) {
            return 1;
        }
        
        if(i != 26 && key[i] == key[26]) {
            return 1;
        } 
        
        //5. Check to see if every letter is unique
        for(int j = i - 1; j >= 0; j--) {
            
            if(key[j] == key[i]) {
               return 1;
            } 
            
            if(key[j] == key[i] + 32) {
                return 1;
            }
            
            
            if(key[j] == key[i] - 32) {
                return 1;
            }
            
        }
    }
    
    return 0;
};
    