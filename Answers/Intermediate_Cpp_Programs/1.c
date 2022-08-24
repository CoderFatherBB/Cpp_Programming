// WAP to add modify delete and view following information(also store data in file and fetch next time)
// vehicle information ,name,type,company name,capacity in cc, milage (C Programming + File Handling)
#include<stdio.h>
struct Vehicle
{
    char name[10];
    unsigned int capacity, milage, type;
}V[100];
void main()
{
    int i;
    FILE *try;
    try = fopen("Info_c.txt","w");
    for (i = 0; i < 1; i++) // change the for loop accouding the number of entries -> i < n
    {
        printf("\nEnter your Vehicle's name : ");
        scanf("%s",V[i].name);
        printf("Enter your Vehicle's type (2 , 4) : ");
        scanf("%d",&V[i].type);
        printf("Enter your Vehicle's capacity in cc : ");
        scanf("%d",&V[i].capacity);
        printf("Enter your Vehicle's milage : ");
        scanf("%d",&V[i].milage);
    }
    for (i = 0; i < 1; i++) // change the for loop accouding the number of entries -> i < n
    {
        fprintf(try, "\n\nYour Vehicle's name : %s", V[i].name);
        fprintf(try, "\nYour Vehicle's type : %d", V[i].type);
        fprintf(try, "\nYour Vehicle's capacity in cc : %d", V[i].capacity);
        fprintf(try, "\nYour Vehicle's milage : %d", V[i].milage);
    }
    fclose(try);
}