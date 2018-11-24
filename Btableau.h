#include <stdio.h>
#include <math.h>
void lect1d (  int T[4],  int *N )
    {
     int i ;
    printf ("Donnez la taille de tableau : ");
	scanf ("%d",&*N);
     for (i=0;i<*N;i++) {
                       printf (" T [%d]=  ",i);scanf("%d",&(T[i]));
                            }
    }
 void ecri1D(int T[4],  int N)
   {
    int i;
    printf ("\n""~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~""\n");
    printf ("le tableau est :\n \n \a");
    for (i=0;i<N;i++){
                          printf(" %6d | " ,T[i]);

    } printf("\n \n") ;
   }


void lect2D(int T[4][4],int *l,int *c,int *elem)
{
int i,j;
    *l=4;
    *c=4;
    *elem=2;
	for (i=0;i<*l;i++)
	{
		for (j=0;j<*c;j++)
		{
			T[i][j]=0;
		}
	}
	i=rand()%4;
	j=rand()%4;
    T[i][j]=2;
    i=(i+1)%4;
    j=(i+1)%4;
     T[i][j]=2;
}
void ecri2D(int T[4][4],int l,int c ){ int i,j;
   printf ("\n""~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~""\n");
         printf ("le tableau est:\n \n ");
         for (i=0;i<l;i++)
	{

		for (j=0;j<c;j++)
		{
			printf(" %6d | ", T[i][j]);
		}
		printf("\n\n");
	} }
void ecrich(char *T[4],  int N)
   {
    int i;
    printf ("\n""~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~""\n");
    printf ("le tableau est :\n \n \a");
    for (i=0;i<N;i++){
                          printf(" %6s | " ,T[i]);

    } printf("\n \n") ;
   }
void up(int T[4][4],int *faire ,int *elem)
{
    int i=0,j,stop=0,v[4][4]={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    *faire=0;
    while(!stop)
    {
    stop=1;
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
            {
                if(T[i][j]==0)
                {
                    if((T[i+1][j]!=0))
                    {
                    stop=0;
                   * faire=1;
                    T[i][j]=T[i+1][j];
                    T[i+1][j]=0;

                    }
                }
                else
                {
                    if((T[i][j]==T[i+1][j])&&(v[i+1][j]==1))
                    {
                        stop=0;
                       * faire=1;
                       T[i][j]+=T[i+1][j];
                       T[i+1][j]=0;
                        *elem=*elem-1;
                      v[i][j]=0;
                    }
                }
            }
    }

    }
}

void left(int T[4][4],int *faire,int *elem)
{
    int i=0,j,stop=0,v[4][4]={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    *faire=0;
    while(!stop)
    {
    stop=1;
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
            {
                if(T[i][j]==0)
                {
                    if((T[i][j+1]!=0))
                    {
                    stop=0;
                   * faire=1;
                    T[i][j]=T[i][j+1];
                    T[i][j+1]=0;

                    }
                }
                else
                {
                    if((T[i][j]==T[i][j+1])&&(v[i][j+1]==1))
                    {
                        stop=0;
                       * faire=1;
                       T[i][j]+=T[i][j+1];
                       T[i][j+1]=0;
                      *elem=*elem-1;
                      v[i][j]=0;
                    }
                }
            }
    }

    }
}

void right(int T[4][4],int *faire,int *elem)
{
    int i=0,j,stop=0,s,pass,v[4][4]={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    *faire=0;
    while(!stop)
    {
    stop=1;
    for(i=3;i>-1;i--)
    {
        for(j=3;j>0;j--)
            {
                if(T[i][j]==0)
                {
                    if(T[i][j-1]!=0)
                    {
                    stop=0;
                   * faire=1;
                    T[i][j]=T[i][j-1];
                    T[i][j-1]=0;
                    }
                }
                else
                {
                    if((T[i][j]==T[i][j-1])&&(v[i][j-1]==1))
                    {
                        stop=1;
                       * faire=1;
                       T[i][j]+=T[i][j-1];
                        *elem=*elem-1;
                       T[i][j-1]=0;
                       v[i][j]=0;
                    }
                }

            }
    }
    }
}

void down(int T[4][4],int *faire,int *elem)
{
    int i=0,j,stop=0,s,pass,v[4][4]={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    *faire=0;
    while(!stop)
    {
    stop=1;
    for(i=3;i>0;i--)
    {
        for(j=3;j>-1;j--)
            {
                if(T[i][j]==0)
                {
                    if(T[i-1][j]!=0)
                    {
                    stop=0;
                   * faire=1;
                    T[i][j]=T[i-1][j];
                    T[i-1][j]=0;
                    }
                }
                else
                {
                    if((T[i][j]==T[i-1][j])&&(v[i-1][j]==1))
                    {
                        stop=1;
                       * faire=1;
                       T[i][j]+=T[i-1][j];
                       T[i-1][j]=0;
                       *elem=*elem-1;
                       v[i][j]=0;
                    }
                }

            }
    }
    }
}

int GameOver(int T[4][4])
{
    int i,j,go1=0,go2=0;
    if((T[0][0]!=T[0][1])&&(T[1][0]!=T[0][0])&&(T[3][2]!=T[3][3])&&(T[3][3]!=T[2][3])&&(T[0][3]!=T[0][2])&&(T[0][3]!=T[1][3])&&(T[3][0]!=T[2][0])&&(T[3][0]!=T[3][1])) go1=1;

if(!go2){    for(i=1;i<3;i++)
    {
        for(j=1;j<3;j++)
            {
                if((T[i][j]!=T[i+1][j])&&(T[i-1][j]!=T[i][j])&&(T[i][j]!=T[i][j+1])&&(T[i][j]!=T[i][j-1])) go2=1;
            }
    }}
    return (go1+go2)-1 ;
}
void ins(int T[4][4],int faire,int *elem)
{
    int i,j;
    if(faire)
    {do{
    i=rand()%4;
	j=rand()%4;
    } while (T[i][j]!=0);
    T[i][j]=2;
    *elem=*elem+1;}
}
