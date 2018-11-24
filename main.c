#include <stdio.h>
#include <stdlib.h>
#include "Btableau.h"
//void action(int T[100][100],int *l,int *c,int *elem)

int main()
{
    int a[100][100],l,c,elem,faire,gameover=0;
    char s;
    lect2D(a,&l,&c,&elem);
    ecri2D(a,l,c);
   while(!gameover)
   {s=getch();
   printf("%d\n",elem);
    switch(s)
    {
        case 75 : left(a,&faire,&elem);ins(a,faire,&elem);system("CLS");ecri2D(a,4,4); break;
        case 77 : right(a,&faire,&elem);ins(a,faire,&elem);system("CLS");ecri2D(a,4,4); break;
        case 72 : up(a,&faire,&elem);ins(a,faire,&elem);system("CLS");ecri2D(a,4,4); break;
        case 80 : down(a,&faire,&elem);ins(a,faire,&elem);system("CLS");ecri2D(a,4,4);; break;
    }
     printf("%d\n",elem);
     if(elem==16) gameover=GameOver(a);
   }

    return 0;
}
