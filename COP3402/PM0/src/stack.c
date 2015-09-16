#include "stack.h"

const int MAX_STACK_HEIGHT = 200;
const int MAX_CODE_LENGTH = 500;
const int MAX_LINE_LENGTH = 10;
const int MAX_LEXI_LEVEL = 3;

int stack(FILE* inputPtr, FILE* outputPtr) {

    int SP = 0;
    int BP = 0;
    int PC = 0;
    instruction* IR;

    int halt = 0;

    // Initialize stack
    int stack[MAX_STACK_HEIGHT];
    memset(stack, 0, sizeof(int));

    // Read instructions
    instruction instructions[MAX_CODE_LENGTH];
    read(inputPtr, instructions);

    // Build and write Instructions string to file
    fprintf(outputPtr, "%s", buildInstructionsString(instructions));

    // Fetch Cycle
    while(halt == 0) {
        // Fetch instruction
        IR = &instructions[PC];

        // Execute instruction and return new PC
        int prevPC = PC;
        execute(IR, &PC, &SP, &BP, &halt, stack);

        // Write execution trace line to file
        fprintf(outputPtr, "%s", buildTraceLine(prevPC, IR, PC, BP, SP, stack));
    }

    printf("Stack operations halted.\n");

    return 0;
}

/* Fills the instruction array with instructions from the input file */
void read(FILE* inputPtr, instruction* instructions) {

    // Char array of each line in the file
    char line[MAX_LINE_LENGTH];

    // Loop through the end of the file
    int i = 0;
    while ( fgets(line, MAX_LINE_LENGTH, (FILE*)inputPtr) != NULL ) {
        // Parse token chars to int and assign instruction
        instructions[i].opcode = (int)atoi((char *)strtok(line, " "));
        instructions[i].lex = (int)atoi((char *)strtok(NULL, " "));
        instructions[i].param = (int)atoi((char *)strtok(NULL, " "));
        i++;
    }
}

/* Build string showing all instructions */
char* buildInstructionsString(instruction* instructions) {
}

/* Build string showing execution trace line */
char* buildTraceLine(int prevPC, instruction* IR, int PC, int BP, int SP, int* stack) {
}

/* Executes the instruction IR and increments the PC */
void execute(instruction* IR, int* PC, int* SP, int* BP, int* halt, int* stack) {

    // Read Instructions
    int opcode = IR->opcode;
    int lex = IR->lex;
    int param =  IR->param;

    // Switch statement on opcode
    switch (opcode) {
        case 1: // LIT
            break;
        case 2: // OPR
            break;
        case 3: // LOD
            break;
        case 4: // STO
            break;
        case 5: // CAL
            break;
        case 6: // INC
            break;
        case 7: // JMP
            *PC = param;
            break;
        case 8: // JPC
            break;
        case 9: // SIO 1
            break;
        case 10: // SIO 2
            break;
        case 11: // SIO 3
            *halt = 1;
            break;
    }

    // Increment PC
    *PC = *PC + 1;
}
