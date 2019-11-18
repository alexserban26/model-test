#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
char nume[30];
unsigned int IBAN;
unsigned char stare_civila;  ///1-casatorit, 0-necasatorit
unsigned char bit_paritate;
}client;

client *citire(int n)//1
{
    int i;
    client*clienti;
    clienti=malloc(n*sizeof(client));
    for (i=0;i<n;i++)
    {
        fgets(clienti[i].nume,29,stdin);
        clienti[i].nume[strlen(clienti[i].nume)-1]='\0';
        scanf("%u %c", &clienti[i].IBAN,&clienti[i].stare_civila);
    }return clienti;

}

void paritate(unsigned int iban,unsigned char *bit_par)//2
{ unsigned int count = 0;
    while (iban) {
        count += iban & 1;
        iban >>= 1;
    }
    if (count%2==0)
        bit_par=0;
    else bit_par=1;
}

/*void swap(client *x, client *y)
{
    client aux = *x;
    *x = *y;
    *y = aux;
}*/
qsort()

void reordonare(client*cl,int n)//3
{
    if(n==1)
        return;
    for(int i=0;i<n-1;i++)
        if(cl[i].stare_civila>cl[i+1].stare_civila)
           // swap(&cl[i],&cl[i+1]);
    reordonare(cl,n-1);
}
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main()
{ int n;
client*c;
scanf("%d",&n);
c=citire(n);
//reordonare(c,n);
qsort (c, n, sizeof(c), compare);
for(int i=0;i<n;i++)
    {
        paritate(c[i].IBAN,c[i].bit_paritate);
        printf("%c %d %c %c \n",c[i].nume,c[i].IBAN,c[i].stare_civila,c[i].bit_paritate);
    }
return 0;

}
