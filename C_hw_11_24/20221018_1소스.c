#include<stdio.h>
#define LEN 5

typedef struct
{
    char name[20];
    int cost;
    int quantity;
}com2;

int sum(com2 pc[])
{
    int total = 0;
    for (int i = 0; i < LEN; i++)
        total += pc[i].cost * pc[i].quantity;

    return total;
}

void sort_name(com2 pc[])
{
    com2 temp;
    for (int i = 0; i < LEN - 1; i++)
    {
        for (int j = 0; j < LEN - 1 - i; j++)
        {
            if (strcmp(pc[j].name, pc[j + 1].name) == 1)
            {
                temp = pc[j];
                pc[j] = pc[j + 1];
                pc[j + 1] = temp;
            }
        }
    }
}

int main()
{
    com2 pc2[LEN];
    FILE* fp;
    fp = fopen("computer.bin", "rb");
    if (fread(pc2, sizeof(com2), LEN, fp) != LEN)
    {
        printf("fread ����");
        exit(1);
    }

    sort_name(pc2);

    printf("ǰ��\t\t�ܰ�(��)\t����\n");
    for (int i = 0; i < 5; i++)
        printf("%-10s\t%-6d\t%10d\n", pc2[i].name, pc2[2].cost, pc2[i].quantity);
    printf("�ݾ� ���� : %d\n", sum(pc2));
    fclose(fp);
    return 0;
}