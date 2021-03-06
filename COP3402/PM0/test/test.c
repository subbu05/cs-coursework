#include "../src/stack.c"
#include <assert.h>

void read_test() {

    const char* inputPath = "../input/mcode.txt";
    FILE* filePtr = openFile(inputPath, "r");
    instruction instructions[50];
    read(filePtr, instructions);
    fclose(filePtr);

    assert(instructions[0].opcode == 7);
    assert(instructions[0].lex == 0);
    assert(instructions[0].param == 10);

    assert(instructions[1].opcode == 7);
    assert(instructions[1].lex == 0);
    assert(instructions[1].param == 2);

    assert(instructions[2].opcode == 6);
    assert(instructions[2].lex == 0);
    assert(instructions[2].param == 6);

    assert(instructions[3].opcode == 1);
    assert(instructions[3].lex == 0);
    assert(instructions[3].param == 13);

    assert(instructions[4].opcode == 4);
    assert(instructions[4].lex == 0);
    assert(instructions[4].param == 4);

    assert(instructions[5].opcode == 1);
    assert(instructions[5].lex == 0);
    assert(instructions[5].param == 1);

    assert(instructions[6].opcode == 4);
    assert(instructions[6].lex == 1);
    assert(instructions[6].param == 4);

    assert(instructions[7].opcode == 1);
    assert(instructions[7].lex == 0);
    assert(instructions[7].param == 7);

    assert(instructions[8].opcode == 4);
    assert(instructions[8].lex == 0);
    assert(instructions[8].param == 5);

    assert(instructions[9].opcode == 2);
    assert(instructions[9].lex == 0);
    assert(instructions[9].param == 0);

    assert(instructions[10].opcode == 6);
    assert(instructions[10].lex == 0);
    assert(instructions[10].param == 6);

    assert(instructions[11].opcode == 1);
    assert(instructions[11].lex == 0);
    assert(instructions[11].param == 3);

    assert(instructions[12].opcode == 4);
    assert(instructions[12].lex == 0);
    assert(instructions[12].param == 4);

    assert(instructions[13].opcode == 1);
    assert(instructions[13].lex == 0);
    assert(instructions[13].param == 0);

    assert(instructions[14].opcode == 4);
    assert(instructions[14].lex == 0);
    assert(instructions[14].param == 5);

    assert(instructions[15].opcode == 5);
    assert(instructions[15].lex == 0);
    assert(instructions[15].param == 2);

    assert(instructions[16].opcode == 11);
    assert(instructions[16].lex == 0);
    assert(instructions[16].param == 3);

    printf("READ_TEST PASSED\n");
}

void halt_test() {
    instruction* IR = malloc(1 * sizeof(instruction));
    IR->opcode = 11;
    IR->lex = 0;
    IR->param = 3;

    int halt = 0;
    int PC = 0;
    int SP = 0;
    int BP = 0;
    int stack[MAX_STACK_HEIGHT];
    memset(stack, 0, sizeof(int));

    execute(IR,&PC,&SP,&BP,&halt, stack);

    assert( halt == 1 );

    printf("HALT_TEST PASSED\n");
}

void jmp_test() {
    instruction* IR = malloc(1 * sizeof(instruction));
    IR->opcode = 7;
    IR->lex = 0;
    IR->param = 10;

    int halt = 0;
    int PC = 0;
    int SP = 0;
    int BP = 1;
    int stack[MAX_STACK_HEIGHT];
    memset(stack, 0, sizeof(int));

    execute(IR,&PC,&SP,&BP,&halt, stack);

    assert( PC == 10 );
    assert( halt == 0 );
    assert( SP == 0 );
    assert( BP == 1 );

    printf("JMP_TEST PASSED\n");
}

void lit_test() {
    instruction* IR = malloc(1 * sizeof(instruction));
    IR->opcode = 1;
    IR->lex = 0;
    IR->param = 1;

    int halt = 0;
    int PC = 0;
    int SP = 0;
    int BP = 0;
    int stack[MAX_STACK_HEIGHT];
    memset(stack, 0, sizeof(int));

    execute(IR,&PC,&SP,&BP,&halt, stack);

    assert( SP == 1);
    assert( stack[1] == 1);

    printf("LIT_TEST PASSED\n");
}

void lod_test() {
    instruction* IR = malloc(1 * sizeof(instruction));
    IR->opcode = 3;
    IR->lex = 0;
    IR->param = 3;

    int halt = 0;
    int PC = 0;
    int SP = 0;
    int BP = 0;
    int stack[MAX_STACK_HEIGHT];
    memset(stack, 0, sizeof(int));

    stack[3] = 4;

    execute(IR,&PC,&SP,&BP,&halt, stack);

    assert( SP == 1);
    assert( stack[1] = 4);

    printf("LOD_TEST PASSED\n");
}

void sto_test() {
    instruction* IR = malloc(1 * sizeof(instruction));
    IR->opcode = 4;
    IR->lex = 0;
    IR->param = 4;

    int halt = 0;
    int PC = 0;
    int SP = 6;
    int BP = 1;
    int stack[MAX_STACK_HEIGHT];
    memset(stack, 0, sizeof(int));

    stack[6] = 4;

    execute(IR,&PC,&SP,&BP,&halt, stack);

    assert( stack[5] == 4);
    assert( SP == 5 );

    PC = 12;
    SP = 13;
    BP = 7;
    stack[13] = 8;

    execute(IR,&PC,&SP,&BP,&halt, stack);

    assert( stack[11] == 8);

    PC = 14;
    SP = 13;
    IR->lex = 1;
    stack[13] = 8;

    execute(IR,&PC,&SP,&BP,&halt, stack);

    assert( stack[5] == 8 );

    printf("STO_TEST PASSED\n");
}

void inc_test() {
    instruction* IR = malloc(1 * sizeof(instruction));
    IR->opcode = 6;
    IR->lex = 0;
    IR->param = 5;

    int halt = 0;
    int PC = 0;
    int SP = 5;
    int BP = 1;
    int stack[MAX_STACK_HEIGHT];
    memset(stack, 0, sizeof(int));

    execute(IR,&PC,&SP,&BP,&halt, stack);

    assert( SP == 10 );

    printf("INC_TEST PASSED\n");
}

void sio_1_test() {
    instruction* IR = malloc(1 * sizeof(instruction));
    IR->opcode = 9;
    IR->lex = 0;
    IR->param = 1;

    int halt = 0;
    int PC = 0;
    int SP = 5;
    int BP = 1;
    int stack[MAX_STACK_HEIGHT];
    memset(stack, 0, sizeof(int));

    stack[5] = 101;

    printf("[SIO_1_TEST] THE NEXT PRINT SHOULD BE 101\n");
    execute(IR,&PC,&SP,&BP,&halt, stack);

    assert( SP == 4 );

    printf("SIO_1_TEST PASSED\n");
}

void sio_2_test() {
    instruction* IR = malloc(1 * sizeof(instruction));
    IR->opcode = 10;
    IR->lex = 0;
    IR->param = 2;

    int halt = 0;
    int PC = 0;
    int SP = 1;
    int BP = 1;
    int stack[MAX_STACK_HEIGHT];
    memset(stack, 0, sizeof(int));

    printf("[SIO_2_TEST] INPUT 101 ON THE NEXT LINE\n");
    execute(IR,&PC,&SP,&BP,&halt, stack);

    assert( stack[2] == 101 );
    assert( SP == 2 );

    printf("SIO_2_TEST PASSED\n");
}

void jpc_test() {
    instruction* IR = malloc(1 * sizeof(instruction));
    IR->opcode = 8;
    IR->lex = 0;
    IR->param = 2;

    int halt = 0;
    int PC = 0;
    int SP = 2;
    int BP = 1;
    int stack[MAX_STACK_HEIGHT];
    memset(stack, 0, MAX_STACK_HEIGHT * sizeof(int));
    stack[1] = 2;

    execute(IR,&PC,&SP,&BP,&halt, stack);

    assert( PC == 2 );
    assert( SP == 1 );

    execute(IR,&PC,&SP,&BP,&halt, stack);

    assert( SP == 0 );
    assert( PC == 3 );

    printf("JPC_TEST PASSED\n");
}

void cal_test() {
    instruction* IR = malloc(1 * sizeof(instruction));
    IR->opcode = 5;
    IR->lex = 0;
    IR->param = 10;

    int halt = 0;
    int PC = 6;
    int SP = 7;
    int BP = 1;
    int stack[MAX_STACK_HEIGHT];
    memset(stack, 0, MAX_STACK_HEIGHT * sizeof(int));

    execute(IR,&PC,&SP,&BP,&halt, stack);

    assert( stack[8] == 0 );
    assert( stack[9] == 1 );
    assert( stack[10] == 1 );
    assert( stack[11] == 7 );
    assert( BP == 8 );
    assert( PC == 10 );

    printf("CAL_TEST PASSED\n");
}

void opr_0_test() {
    instruction* IR = malloc(1 * sizeof(instruction));
    IR->opcode = 2;
    IR->lex = 0;
    IR->param = 0;

    int halt = 0;
    int PC = 4;
    int SP = 13;
    int BP = 7;
    int stack[MAX_STACK_HEIGHT];
    memset(stack, 0, MAX_STACK_HEIGHT * sizeof(int));

    stack[10] = 10;
    stack[9] = 20;

    execute(IR,&PC,&SP,&BP,&halt, stack);

    assert( SP == 6 );
    assert( PC == 10 );
    assert( BP == 20 );

    printf("OPR_0_TEST PASSED\n");
}

void opr_all_test() {
    instruction* IR = malloc(1 * sizeof(instruction));
    IR->opcode = 2;
    IR->lex = 0;

    int halt = 0;
    int PC = 1;
    int SP = 5;
    int BP = 1;
    int stack[MAX_STACK_HEIGHT];
    memset(stack, 0, MAX_STACK_HEIGHT * sizeof(int));

    IR->param = 1;
    stack[5] = 10;
    execute(IR,&PC,&SP,&BP,&halt, stack);
    assert( stack[5] == -10 );

    SP = 6;
    IR->param = 2;
    stack[5] = 10;
    stack[6] = 10;
    execute(IR,&PC,&SP,&BP,&halt, stack);
    assert( stack[5] == 20 );
    assert( SP  == 5 );

    SP = 6;
    IR->param = 3;
    stack[5] = 10;
    stack[6] = 20;
    execute(IR,&PC,&SP,&BP,&halt, stack);
    assert( stack[5] == -10 );
    assert( SP  == 5 );

    SP = 6;
    IR->param = 4;
    stack[5] = 10;
    stack[6] = 20;
    execute(IR,&PC,&SP,&BP,&halt, stack);
    assert( stack[5] == 200 );
    assert( SP  == 5 );

    SP = 6;
    IR->param = 5;
    stack[5] = 100;
    stack[6] = 5;
    execute(IR,&PC,&SP,&BP,&halt, stack);
    assert( stack[5] == 20 );
    assert( SP  == 5 );

    SP = 6;
    IR->param = 6;
    stack[6] = 5;
    execute(IR,&PC,&SP,&BP,&halt, stack);
    assert( stack[6] == 1 );
    assert( SP  == 6 );

    SP = 6;
    IR->param = 7;
    stack[5] = 100;
    stack[6] = 5;
    execute(IR,&PC,&SP,&BP,&halt, stack);
    assert( stack[5] == 0 );
    assert( SP  == 5 );

    SP = 6;
    IR->param = 8;
    stack[5] = 100;
    stack[6] = 100;
    execute(IR,&PC,&SP,&BP,&halt, stack);
    assert( stack[5] == 1 );
    assert( SP  == 5 );

    SP = 6;
    IR->param = 9;
    stack[5] = 99;
    stack[6] = 100;
    execute(IR,&PC,&SP,&BP,&halt, stack);
    assert( stack[5] == 1 );
    assert( SP  == 5 );

    SP = 6;
    IR->param = 10;
    stack[5] = 99;
    stack[6] = 100;
    execute(IR,&PC,&SP,&BP,&halt, stack);
    assert( stack[5] == 1 );
    assert( SP  == 5 );

    SP = 6;
    IR->param = 11;
    stack[5] = 100;
    stack[6] = 100;
    execute(IR,&PC,&SP,&BP,&halt, stack);
    assert( stack[5] == 1 );
    assert( SP  == 5 );

    SP = 6;
    IR->param = 12;
    stack[5] = 199;
    stack[6] = 100;
    execute(IR,&PC,&SP,&BP,&halt, stack);
    assert( stack[5] == 1 );
    assert( SP  == 5 );

    SP = 6;
    IR->param = 13;
    stack[5] = 100;
    stack[6] = 100;
    execute(IR,&PC,&SP,&BP,&halt, stack);
    assert( stack[5] == 1 );
    assert( SP  == 5 );

    printf("OPR_ALL_TEST PASSED\n");
}
int main() {
    read_test();
    halt_test();
    jmp_test();
    lit_test();
    lod_test();
    sto_test();
    inc_test();
    sio_1_test();
    sio_2_test();
    jpc_test();
    cal_test();
    opr_0_test();
    opr_all_test();
    return 0;
}
