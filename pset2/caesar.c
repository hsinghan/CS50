#include<cs50.h>
#include<stdio.h>
#include<string.h> // for using strlen func. and string structure
#include<stdlib.h> // for using atoi func.
#include<ctype.h> // for using isalpha, isupper and islower func.

char* EncrytedString(string message, int n);

int main(int argc, string argv[]){
    // check the argument
    if( argc != 2)
    {
      printf("Error!!!!\n");
      return 1;
    }
    // confirm the number is real interger
    int key = atoi(argv[1]);
    if( key < 0)
    {
      printf("Error!!!!\n");
      return 1;
    }
    
    string plaintext;
    do
    {
        plaintext = get_string("plaintext:");
    }
    while (strlen(plaintext) == 0);

    string ciphertext = EncrytedString(plaintext, key);
    printf("ciphertext: ");
    printf("%s\n", ciphertext);
    return 0;

}

char* EncrytedString(string message, int k){
    
    string  ciphertext = message; // create a placeholder variable, allocating the size using equal length of plain
    for (int i = 0; i < strlen(message); i++)
    {
        // check the char is alphabet or not.
        if ( isalpha(message[i]) )
        {
            if (isupper(message[i]))
                ciphertext[i] = ((message[i]+k - 'A')% 26) + 'A';
            else
                ciphertext[i] = ((message[i]+k - 'a')% 26) + 'a';
        }
//      else
//         {
//             // Do not need to change if the letter is not alphabet.
//              ciphertext[i] = message[i];
//         }

    }
    // return  ciphertext
    return ciphertext;
}
