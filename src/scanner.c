#include "scanner.h"

/* Opens a file and returns a FILE pointer */
FILE* openFile(const char* path, const char* op) {
    FILE* filePtr;
    filePtr = fopen(path, op);
    if(filePtr == NULL) {
        perror("[SCANNER-ERROR] Error opening file.");
        return NULL;
    }
    return filePtr;
}

/* Appends a char to a string */
void append(char* string, char c) {
    string[strlen(string)] = c;
    string[strlen(string) + 1] = '\0';
}

int main()
{
    // TODO: inputPath should come from arg
    const char* inputPath = "../input/input.txt";

    // Open input for reading
    FILE* ifp = openFile(inputPath, "r");

    // Loop through input as DFA simulation
    while(!feof(ifp)) {

        // Get Character from stream
        char ch = getc(ifp);

        // Copy character into a temp string
        char tempToken[12] = "";

        // Check if ch is part of an Identifier or Reserved Word
        if(isalpha(ch)) {

            // Get the next char while checking if it's alphanumeric
            while( (isalpha(ch) || isdigit(ch)) && !feof(ifp)) {

                // TODO: If it has digits then it's not a reserved word

                // Append ch to temp token
                append(tempToken, ch);

                // Get next ch
                ch = getc(ifp);
            }

            // Go back 1 char
            ungetc(ch, ifp);

            // TODO: create and return identifer or reserved word token

        } else {
            // Not alphabetic, go back
            ungetc(ch, ifp);
        }

        // Get next char
        ch = getc(ifp);

        // Check if ch is part of a Value
        if(isdigit(ch)) {

            while(isdigit(ch)) {
                // Append ch to temp token
                append(tempToken, ch);

                // Get next ch
                ch = getc(ifp);
            }

            // Parse int value
            int value = atoi(tempToken);

            // Go back 1 char
            ungetc(ch, ifp);

            // TODO: create and return token

        } else {
            // Not a digit, go back
            ungetc(ch, ifp);
        }

        // Get next ch
        ch = getc(ifp);

        // TODO: Check for +
        // TODO: Check for -
        // TODO: Check for *
        // TODO: Check for /
        //
        // TODO: Check for odd
        // TODO: Check for =
        // TODO: Check for <, <=, <>
        // TODO: Check for >. >=
        //
        // TODO: Check for (
        // TODO: Check for )
        // TODO: Check for ,
        // TODO: Check for ;
        // TODO: Check for :=
        //
        // TODO: Check for begin
        // TODO: Check for end
        // TODO: Check for if
        // TODO: Check for then
        // TODO: Check for while
        // TODO: Check for do
        // TODO: Check for call
        // TODO: Check for const
        // TODO: Check for var
        // TODO: Check for procedure
        // TODO: Check for write
        // TODO: Check for read
        // TODO: Check for else
        // TODO: Check for comments
    }

    // Close input
	fclose(ifp);

	return 0;
}

