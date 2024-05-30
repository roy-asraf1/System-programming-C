#include <stdio.h>
#include <string.h>

#define LINE 256 
#define WORD 30

int getline_(char s[]);
int getword(char w[]);
int substring(char *str1, char *str2);
int similar(char *s, char *t, int n);
void print_lines(char *str);
void print_similar_words(char *str);


int main() {
    char word[WORD];
    char user,blank;
    scanf("%s %c%c",word,&user,&blank);
    if (user == 'a')
    {
        print_lines(word);
    }

    else if (user == 'b')
    {
        print_similar_words(word);
    }    
    return 0;
}


//func A
/**
 * @brief getline_
 * 
 * @param s  character array to hold the input line
 * @return int  0 if EOF, 1 if empty line, else the length of the line
 */

int getline_(char s[])
{
    int i = 0,c = 0;
    for (i = 0; i < LINE - 1 && c != '\n' && c!='\r'; ++i){
        if((c = getchar()) != EOF)
            if(c != '\r')
                s[i] = c;
            else
                s[i] = '\n';
        else
            return 0;
    }

    if (i==0) return 1;   
    s[i] = '\0';
    return i;
}
/**
 * @brief substring 
 * 
 * @param str1  the substring to search for
 * @param str2   the string to search in
 * @return int  1 if str1 is a substring of str2, 0 otherwise
 */

int substring(char *str1, char *str2)
{
    int len1 = strlen(str1); // length of str1
    int len2 = strlen(str2); // length of str2

    for (int i = 0; i < len2 - len1 + 1; i++)
    {
        if (strncmp(str1, str2 + i, len1) == 0)
            return 1;
    }
    return 0; 
}

/**
 * @brief print_lines 
 * 
 * @param str  the string to search for
 */

void print_lines(char *str)
{
    char line[LINE]; // character array to hold the input line
    while (getline_(line) > 0)
    {
        if (substring(str, line)){
            printf("%s", line); 
        }
    }
}

// func B
/**
 * @brief getword 
 * 
 * @param w  character array to hold the input word
 * @return int  0 if EOF, else the length of the word
 * 
 */
int getword(char w[])
{
    int c, counter; // c is the current character, counter is the number of characters in the word

    for (counter = 0; counter < WORD - 1 && (c = getchar()) != EOF && c != ' ' && c != '\t' && c != '\n'; ++counter)
        w[counter] = c;
    
    if (c == '\n' && counter==0) 
        w[counter++] = c;

    w[counter] = '\0'; 
    return counter;
}
/**
 * @brief similar 
 * 
 * @param s  the string to search in
 * @param t  the string to search for
 * @param n  the number of allowed changes
 * @return int  1 if s is similar to t, 0 otherwise
 */


int similar(char *s, char *t, int n)
{
    int lens = strlen(s); // length of s
    int lent = strlen(t); // length of t

    if (lens < lent || lent + n < lens) return 0; 

    int i, j;
    for (i = 0, j = 0; i < lens && j < lent;)
    {
        if (s[i] == t[j])//if the characters are equal 
        {
            j++; 
        }

        i++; 
    }
      
    return j == lent; 
}


/**
 * @brief print_similar_words 
 * 
 * @param str  the string to search for
 */

void print_similar_words(char *str) {
    char word[WORD]; 
    while (getword(word) > 0) {  // get the next word
        if (similar(word, str, 1)) {  // check if it is similar to str
            printf("%s\n", word);  // print the word
        }   
    }
}


