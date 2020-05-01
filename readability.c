#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int letterCounter(string sentence);
int wordCounter(string sentence);
int sentenceCounter(string sentence);


int main(void) {
    //index = 0.0588 * L - 0.296 * S - 15.8
    //here, L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

    string inputText = get_string("Please enter string: ");
    float index = 0.0;
    int wordCount = wordCounter(inputText);
    int letterCount = letterCounter(inputText);
    int sentenceCount = sentenceCounter(inputText);

    index = 0.0588 * (letterCount / (float) wordCount * 100) - 0.296 * (sentenceCount / (float)wordCount * 100) - 15.8;

    if (index < 1.0) {
        printf("Before Grade 1\n");
    } else if (index > 16.0) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %.0f\n", round(index));
    }


}

int letterCounter(string sentence) {
    int count = 0;

    for(int i = 0, stringLength = strlen(sentence); i < stringLength; i++) {
       //Increases the letter count, if it is indeed a letter.
        if(isalpha(sentence[i])) {
            count++;
        }
    }

    return count;

}

int wordCounter(string sentence) {
    //starting at one to account for last word in sentence.
    int count = 1;
    for(int i = 0, stringLength = strlen(sentence); i < stringLength; i++) {
        //for every space, we put the wordcount up.
        if(sentence[i] == 32) {
            count++;
        }
    }

    return count;

}

int sentenceCounter(string sentence) {
    int count = 0;
    for(int i = 0, stringLength = strlen(sentence); i < stringLength; i++) {
        //for every period, exclamation point and quesitons mark we increase sentencecount.
        if(sentence[i] == 46 || sentence[i] == 33 || sentence[i] == 63) {
            count++;
        }
    }

    return count;
}