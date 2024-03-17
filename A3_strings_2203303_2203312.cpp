/*
Name: Adwita Deshpande
Roll no.: 2203303
Branch: MnC 2022

*/

#include <stdio.h>
#include <stdbool.h>

bool str_copy(char source[], char dest[]) //function to copy string
{
    if(source == NULL)
    {
        return false; //if string is empty 
    }
    int i;
    for(i =0; source[i] != '\0';i++)
    {
        dest[i] = source[i]; //copying and store in destination
    }
    dest[i]='\0';
    return true;
}

bool is_suffix(char str[], char suf[]) //function to check if string suf is the suffix
{
    if (str == NULL || suf == NULL )
        return false;
    
    for (int i=0; suf[i] !='\0';i++)
    {
        if(str[i]==suf[i])
            continue;
        else 
            return false;
    }
    return true;
}
bool is_substring(char str[], char substr[]) //function to check if string substr is the substring
{
    if (str == NULL || substr == NULL) 
        return false;

    int str_len = 0, substr_len = 0;
    while (str[str_len] != '\0') //to calculate length of string
    { 
        str_len++;
    }

    while (substr[substr_len] != '\0') //to calculate length of string
    {
        substr_len++;
    }

    for (int i = 0; i <= str_len - substr_len; i++) //to check if substring is present
    {
        int j = 0;
        while (j < substr_len && str[i + j] == substr[j]) 
        {
            j++;
        }
        if (j == substr_len)
            return true;
    }
    return false;
}
bool get_suffix(char str[], char suf[], int len) //function to get suffix of desired length
{
    if (str == NULL)
        return false;
    int i;
    for(i=0;i<len;i++)
    {
        suf[i] = str[i];
    }
    suf[i]='\0';
    return true;
}
bool get_substring(char str[], char substr[], int start, int len) //function to get substring of desired length
{
    if (str == NULL)
        return false;
    int j=0;
    for(int i=start-1;i<len;i++)
    {
        substr[j] = str[i];
        j++;
    }
    substr[j]='\0';
    return true;
}

bool is_same(char str1[], char str2[])//function to check if two strings are same
{
    for(int i=0; str1[i]!='\0';i++)
    {
        if(str1[i] != str2[i])
            return false;
    }
    return true;
}

bool concatenate(char a[], char b[], char c[]) //function to concatenate two strings
{
    int i,j;
    for(i=0; a[i]!='\0';i++)
        c[i] = a[i];
    for(j=0; b[j]!= '\0';j++,i++)
        c[i]=b[j];
    return true;
}

bool convert_to_upper(char a[]) //function to convert string to uppercase
{
    for(int i=0; a[i]!='\0';i++)
    {
        if(a[i]>=97)
            a[i] -= 32;
    }
    return true;
}

int break_into_words(char input[], char words[][100]) //function to break the given string in words and return the number of words
{
    if (input == NULL || words == NULL )
        return false;

    int len = 0, word = 0,startIndex = 0;
    while (input[len] != '\0') {
        len++;
    }

    if (len == 0) {
        word= 0;
        return true;
    }

    for (int i = 0; i < len; i++) {
        if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n') 
        {
            if (i > startIndex) 
            {
                int k = 0;
                for (int j = startIndex; j < i; j++) {
                    words[word][k] = input[j];
                    k++;
                }
                words[word][k] = '\0';
                word++;
            }
            startIndex = i + 1;
        }
    }

    if (startIndex < len) {
        int k = 0;
        for (int j = startIndex; j < len; j++) {
            words[word][k] = input[j];
            k++;
        }
        words[word][k] = '\0';
        word++;
    }

    return word;
}
int main() //to print and call functions
{
    char source[] = "Hello, world!";
    char str[] = "This is a test string.";
    char suf[] = "This ";
    char substr[] = "test";
    char suf_output[10];
    char substr_output[10];
    char str1[] = "hello";
    char str2[] = "Hello";
    char concatenated[50];
    char input[] = "This is a sample input. \n We can break a string into words here \t";
    char words[10][100];

    // Call and print results for each function
    printf("str_copy:\n");
    printf("String to copy: %s\n", str);
    bool copy_result = str_copy(source, suf_output);
    printf("Copy successful: %s\n", copy_result ? "true" : "false");
    printf("Copied string: %s\n\n", suf_output);

    printf("Suffix to check: %s\n", suf);
    printf("is_suffix: %s\n\n", is_suffix(str, suf) ? "true" : "false");

    printf("Substring to check: %s\n", substr);
    printf("is_substring: %s\n\n", is_substring(str, substr) ? "true" : "false");

    printf("get_suffix:\n");
    bool get_suffix_result = get_suffix(str, suf_output, 7);
    printf("Length of suffix: 7\n");
    printf("Get suffix successful: %s\n", get_suffix_result ? "true" : "false");
    printf("Obtained suffix: %s\n\n", suf_output);

    printf("get_substring:\n");
    bool get_substring_result = get_substring(str, substr_output, 1, 4);
    printf("Get substring successful: %s\n", get_substring_result ? "true" : "false");
    printf("Obtained substring: %s\n\n", substr_output);

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    printf("is_same: %s\n\n", is_same(str1, str2) ? "true" : "false");

    printf("concatenate:\n");
    bool concatenate_result = concatenate(str1, str2, concatenated);
    printf("Concatenate successful: %s\n", concatenate_result ? "true" : "false");
    printf("Concatenated string: %s\n\n", concatenated);

    printf("convert_to_upper:\n");

    bool convert_result = convert_to_upper(str);
    printf("Conversion successful: %s\n", convert_result ? "true" : "false");
    printf("Converted string: %s\n\n", str);

    printf("break_into_words:\n");
    int word_count = break_into_words(input, words);
    //printf("Break successful: %s\n", break_result ? "true" : "false");
    printf("Word Count: %d\n", word_count);
    for (int i = 0; i < word_count; i++) {
        printf("Word %d: %s\n", i + 1, words[i]);
    }
}