#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

float calculateSentences(string sentence);
float calculateLetters(string sentence);
float calculateWords(string sentence);

int main(void)
{
    string sentences = get_string("Text: ");
    float a = calculateSentences(sentences);
    float b = calculateLetters(sentences);
    float c = calculateWords(sentences);

    float L = ((b/c)*100);
   float S = ((a/c)*100);

   float index = 0.0588 * L - 0.296 * S - 15.8;

    printf("Grade %.0f", round(index));

}

float calculateSentences(string sentence) {
    float k = 0;
    for(int i = 0, n= strlen(sentence); i<n; i++){
        if(sentence[i] == '.' || sentence[i] == '!'){
          k++;
        }
    }
    return k;
}

float calculateLetters(string sentence) {
    float k = 0;
    for(int i = 0, n= strlen(sentence); i<n; i++){
        if((sentence[i]>=65 && sentence[i]<=90) || (sentence[i]>=97&&sentence[i]<=122)){
            k++;
        }
        else {
           continue;
        }

    }
    return k;
}

float calculateWords(string sentence){
float k = 0;
    for(int i = 0, n= strlen(sentence); i<n; i++){
        if(sentence[i] == ' ' || (sentence[i] == '.' && sentence[i+1]!=' ') ){
          k++;
        }
    }
    return k;
}

