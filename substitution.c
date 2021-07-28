#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

//Function to count and validate the number of characters in the key
bool validation(string key);
//Function to check alphabetic characters in the key
bool alphaKey(string key);
//Function to check for no repeated letters
bool noRepeatedLetter(string key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];
        if (validation(key) == true)  // Calls function validation
        {
            if (alphaKey(key) == true)  // Calls function alphaKey
            {
                if (noRepeatedLetter(key) == true)  // Calls function noRepeatedLetter
                {

                    string text = get_string("Planitext: ");
                    int ptcount = strlen(text);
                    char ciphertext[ptcount + 1];  //Included to count and exclude not valid ASCII characters
                    string az = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                    printf("ciphertext: ");
                    for (int i = 0; i < ptcount; i++)  //Evaluates every character of text and replaces for key
                    {
                        if (islower(text[i]) != 0)  //Maintains lowercase in every character of ciphertext
                        {
                            for (int j = 0; j < 26; j++)
                            {
                                if (az[j] == toupper(text[i]))
                                {
                                    ciphertext[i] = tolower(key[j]);
                                    break;
                                }
                            }
                        }
                        else if (isupper(text[i]) != 0)  //Maintains uppercase in every character of ciphertext
                        {
                            for (int j = 0; j < 26; j++)
                            {
                                if (az[j] == (text[i]))
                                {
                                    ciphertext[i] = toupper(key[j]);
                                    break;
                                }
                            }
                        }
                        else
                        {
                            ciphertext[i] = text[i];
                        }
                        printf("%c", ciphertext[i]);  //Prints one character of ciphertex at the time every iteration 
                    }
                    printf("\n");
                }
                else
                {
                    printf("Key must not have repeated letters\n");
                    return 1;
                }
            }
            else
            {
                printf("Key must contain only alphabetic characters\n");
                return 1;
            }
        }
        else
        {
            printf("Please insert a 26 letters key. eg. ASDFGHJKLPOIUYQWERTZXCVBMN\n");
            return 1;
        }
    }
    else
    {
        printf("Input issue. Please provide a key on command-line\n");
        return 1;
    }

}

bool validation(string key)
{
    if (strlen(key) == 26)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Evaluate every single character from the string using isalpha
bool alphaKey(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }
    return true;
}

//Checks every letter converting it into upper case. The loop compares each letter in
// key with the alphabet. Once found adds 1 to repeat. 
bool noRepeatedLetter(string key)
{
    int repeat = 0;
    for (char c = 'A'; c <= 'Z'; c++)
    {
        for (int i = 0; i < 26; i++)
        {
            if (toupper(key[i]) == c)
            {
                repeat++;  // If one or more is repeated, repeat will be != 26 and it will return 1.
                break;
            }
        }
    }
    if (repeat == 26) 
    {
        return true;
    }
    else
    {
        return false;
    }
}