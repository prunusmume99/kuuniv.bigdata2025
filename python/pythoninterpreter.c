#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    OP_PRINT,
    OP_UNKNOWN
} OpCode;

// 바이트코드 -> .pyc
typedef struct
{
    OpCode opcode;
    const char *arg;
} Instruction;

// 파서
Instruction parse(const char *source)
{
    Instruction inst;
    if (strncmp(source, "print(\"hello\")", 15) == 0)
    {
        inst.opcode = OP_PRINT;
        inst.arg = "hello";
    }
    else
    {
        inst.opcode = OP_UNKNOWN;
        inst.arg = NULL;
    }
    return inst;
}

// PVM 가상 머신 실행기
void execute(Instruction inst)
{
    switch (inst.opcode)
    {
    case OP_PRINT:
        printf("%s\n", inst.arg);
        break;
    case OP_UNKNOWN:
        printf("실행할 수 없는 Instruction!!\n");
        break;
    }
}

int main()
{
    char source[256];

    printf("파이썬 프로토 타입 V1.0 ( print(\"hello\") ):\n>>>");
    fgets(source, sizeof(source), stdin);
    source[strcspn(source, "\n")] = 0;

    Instruction inst = parse(source);
    execute(inst);
    return 0;
}