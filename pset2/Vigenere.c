/****************************************************************************
 * Vigenere.c
 *
 * Computer Science 50
 * Justin Chen
 *
 * Encryted the plaintext by encrypting messages using a sequence of keys (or, put another way, a keyword)  
 ********/

#include<cs50.h>
#include<stdio.h>
#include<string.h> // for using strlen func. and string structure
#include<stdlib.h> // for using atoi func.
#include<ctype.h> // for using isalpha, isupper and islower func.

char* VigenereEncrytedString(string plaintext, string word);

int main(int argc, string argv[]){
    // check the argument
    if( argc != 2)
    {
      printf("Usage: ./vigenere k\n");
      return 1;
    }
    // check "the input key string" is all alphabet
    string keyword = argv[1];
    for (int i = 0; i < strlen(keyword); i++)
    {
        if (!isalpha(keyword[i]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }

    string plaintext;

    // get the plaintext
    do
    {
        plaintext = get_string("plaintext:");
    }
    while (strlen(plaintext) == 0);

    string ciphertext = VigenereEncrytedString(plaintext, keyword);
    printf("ciphertext: ");
    printf("%s\n", ciphertext);
    return 0;

}

char* VigenereEncrytedString(string plaintext, string word){

    string ciphertext = plaintext;

    for (int i = 0, length = strlen(word), count = 0; i < strlen(plaintext); i++)
    {
        // check char of plaintext  is alphabet
        if (isalpha(plaintext[i]))
        {
            // get the key 
            // if the char of plaintext is upper word, -65
            // otherwise, -97
            // Note the index of string word !!!!!!
            int key = ( isupper(word[count%length]) > 0 ? word[count%length]-65 : word[count%length]-97 ) ;

            if (isupper(plaintext[i]))
                ciphertext[i] = ((plaintext[i]+ key - 'A')% 26) + 'A';
            else
                ciphertext[i] = ((plaintext[i]+ key - 'a')% 26) + 'a';
            
            // only increment when using    
            count++;
        }

    }

    // return  ciphertext
    return ciphertext;
}


/************************************************************************************
The VigenereEncrytedString of Version two.
The difference is the part of calculation.
*************************************************************************************/

char* VigenereEncrytedString(string message, string word){

    string ciphertext = message;

    for (int i = 0, length = strlen(word), count = 0; i < strlen(message); i++)
    {

        if (isalpha(message[i]))
        {
            // Note the index of string word!!!!
            int key = ( isupper(word[count]) > 0 ? word[count]-65 : word[count]-97 ) ;
            if (isupper(message[i]))
                ciphertext[i] = ((message[i]+ key - 'A')% 26) + 'A';
            else
                ciphertext[i] = ((message[i]+ key - 'a')% 26) + 'a';
            
            //Note that is "++count" not "count++"
            count = (count == (length-1) ? 0 : ++count);
        }

    }

    // return  ciphertext
    return ciphertext;
}
