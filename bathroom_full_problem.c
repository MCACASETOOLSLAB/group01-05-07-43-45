#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


char gents[2]={'f','f'};
char ladies[2]={'f','f'};
static int semaphore=0;
static int total_encome = 0;

typedef struct user
 {
       char name[25];
       char sex;
       struct user *next;
       }queue;
       
queue *G_front=NULL,*G_rear=NULL;
queue *L_front = NULL, *L_rear = NULL;

queue *waiting_queue(char *,char);
void use_bathroom(char *,char );
int critical_section(char *);
int monitoring(char );
void display(char *);
void allocate(char );
void bathroom();
void show();

int main()
  {
         
          static char status = 'f';
          bathroom();
          printf("\n\n\t\t Total encome =%d:\t",total_encome);
          getch();
          return 0;
  }
  
  void bathroom()
  {
          int i,pos; 
          char sex,ch;
          char name[20];
          while(1)
            {      system("cls");
                   printf("\n\n\t\t -:Welcome to bathroom problem:-\n ");
                   printf(" \n\n\t press 1. For usingbathroom.");
                   printf(" \n\t press 2. Relase bathroom.");
                   printf(" \n\t press 3. show status of bathroom.");
                   printf(" \n\t press 4. Show waiting queue.");
                   printf(" \n\t press 0. Exit.");
                   printf(" \n\n\t Enter your choice:\t");
                   fflush(stdin);
                   ch = getchar();
                   switch(ch)
                         {
                             case '1' : system("cls");     
                                       printf("\n\n\t Enter the name of User:-\t");
                                       fflush(stdin);
                                       i=0;
                                       while( (ch = getchar())!='\n')
                                              name[i++]=ch;
                                       name[i]='\0';
                                       fflush(stdin);
                                       printf("\n\t Enter geder(M/F):\t");
                                       sex = getchar();
                                       use_bathroom(name,sex);                            
                                       break;
                             case '2' : system("cls");
                                       printf("\n\n\t who is going to release the bathroom(M/f):\t");
                                       fflush(stdin);
                                       sex=getchar();
                                       printf("\n\t Enter the  bathroom no(1/2):\t");
                                       scanf("%d",&pos);
                                       if(sex == 'm' || sex == 'M')
                                                  gents[pos-1]='f';
                                       else
                                                  ladies[pos-1]='f';
                                       semaphore--;
                                       allocate(sex);
                                       break;
                             case '3' : system("cls");
                                       for(i=0;i<2;i++)
                                          {
                                            if( i ==0 )
                                               {
                                                 printf(" \n\n\t ladies bathrrom: \t");
                                                 display(ladies);
                                               }
                                            else
                                               {
                                                 printf(" \n\t Gents bathroom \t");
                                                 display(gents);
                                               }
                                           }
                                           getch();
                                         break;
                              case '4' : system("cls");
                                        show();
                                        getch();
                                        break;
                              case '0' : system("cls");
                                         printf(" \n\n\n\t\t Thank you .....................");
                                         getch();
                                         exit(0);
                   }
            }
      }
 
  
 void use_bathroom(char *name,char sex)
  {
      int flage=0;
      queue *temp; 
      flage = monitoring(sex);
      if( flage == 0 )
             waiting_queue(name,sex);
  }         
  
  
 int monitoring( char sex )
    {
          int flage =0;
         if(semaphore <= 4)
          {
            if( sex == 'm' || sex == 'M' )
                flage = critical_section(gents);
            else
                flage = critical_section(ladies);
          }
         if(!flage)
               {
                      printf("\n Bathroom are not free.");
                      printf("\n User are waiting for release the bathroom.");
                      getch();
                      return 0;
               }
         return 1;
    }

    
   int critical_section(char bathroom[])
    {
        int i;
        for(i=0;i<2;i++)
               {
                     if( bathroom[i] == 'f' )
                     {
                          bathroom[i] = 'u';
                          semaphore++; 
                          total_encome+= 5;
                          return 1;
                     }
               }
         return 0;           
    }       
   
    queue *waiting_queue(char *name,char sex)
                   {   
                      queue *temp; 
                       printf(" \n Name :- %s",name);
      
                      temp=(queue *)malloc(sizeof(queue));
                         strcpy(temp->name,name);
                         temp->sex = sex;
                         temp->next = NULL;
                     if( sex == 'm' || sex == 'M')
                     {
                             if(G_front)
                                {
                                      G_rear->next=temp;
                                      G_rear=temp;
                                }
                              else
                                  {
                                      G_front = temp;
                                      G_rear = temp;
                                   }    
                     }
                     else 
                         {
                              if(L_front)
                                    {
                                             L_rear->next=temp;
                                             L_rear=temp;
                                    }
                                 else
                                       {
                                             L_front = temp;
                                             L_rear = temp;
                                       } 
                         }
                   }
  
    
  void allocate(char sex)
   {
       queue *temp,*front,*rear;
       if( sex == 'm' || sex == 'M')
         {
           if(G_front)
              {
                temp = G_front;
                G_front = G_front->next;
                use_bathroom(temp->name,temp->sex);
                free(temp);
              }
               if( !G_front )
                   G_front = G_rear = NULL;
         }
       else 
       {
           if(L_front)
              {
                temp = L_front;
                L_front = L_front->next;
                use_bathroom(temp->name,temp->sex);
                free(temp);
              }
          if( !L_front )
               L_front = L_rear = NULL;
      } 
   }
                              
     
  void display(char bathroom[])
  {
       int j;
       for(j=0;j<2;j++)
       {
           printf("\n --------- ");
           printf("\n|         |");
           printf("\n|   %c     |",bathroom[j]);
           printf("\n|         |");
           printf("\n --------- ");
        }                       
   }
          
  void show()
   {
       int i;
       queue *temp,*end;
       for(i=0;i<2;i++)
       {
                       if(i==0)
                       {
                          temp = G_front;
                          end = G_rear;
                           printf("\n\n Waiting Queue of Gents:-\n");
                        }
                       else
                       {
                          temp = L_front;
                          end = L_rear;
                          printf("\n\n Waiting Queue of Ladies:-\n");
                       }
            if(temp)
            {
              while( temp  )
                {
                  printf("\n %d :- %s",++i,temp->name);
                  printf("\n   sex :%c",temp->sex);
                  temp = temp->next;  
                }
            }
           else 
             {  printf(" \n\t Queue is empty"); }
       }    
  }    
          
