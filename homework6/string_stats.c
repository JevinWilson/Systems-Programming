#include <stdio.h>
#include <string.h>

int main() 
{
    //store up to 100 char in an array
    char input[100];
    //reads what the user types
    printf("Type anything: ");
    fgets(input, sizeof(input), stdin);
    //remove newline at the end of the users input
    input[strcspn(input, "\n")] = '\0';
    //converts to ascii and stores the value
    int charCounts[256] = {0};

    //looks through each char
    for (int i = 0; i < strlen(input); i++) 
    {
        //get the ascii code of the character
        int asciiCode = (int)input[i];
        //adds the count of a char
        charCounts[asciiCode]++;
    }
    printf("%-6s %-6s %-6s\n", "char", "code", "count");
    printf("====   ====   =====\n");

    for (int i = 0; i < 256; i++) 
    {
        if (charCounts[i] > 0) 
        {
            printf("'%c'     %-6d %-6d\n", (char)i, i, charCounts[i]);
        }
    }

    return 0;
}
