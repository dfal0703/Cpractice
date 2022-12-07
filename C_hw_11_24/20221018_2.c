#include<stdio.h>
#define LEN 5

typedef struct
{
    char name[20];
    int cost;
    int quantity;
}com;

void b_f_output(com* pc)
{
    FILE* fp;
    fp = fopen("computer.bin", "wb");

    if (fwrite(pc, sizeof(com), LEN, fp) != LEN)
    {
        printf("fwrite 에러");
        exit(1);
    }

    printf("품명\t\t단가(원)\t수량\n");
    for (int i = 0; i < 5; i++)
        printf("%-10s\t%-6d\t%10d\n", pc[i].name, pc[2].cost, pc[i].quantity);
    fclose(fp);
}

int main()
{
    com pc[LEN] =
    {
        {"Hard-disk", 135000, 5},
        {"CPU", 235000, 7},
        {"Mainboard", 162000, 9},
        {"Monitor", 260000, 4},
        {"DVD_RW", 73500, 6},
    };
    b_f_output(pc);
    return 0;
}

