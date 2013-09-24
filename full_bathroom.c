#include<stdio.h>

int sem=0,slot[4]={0},wq=0;
int mutex=0,waitmutex=0;

int chkav(int f)
{
	if(f==1)
	{
	if(sem<4)
		return 1;
	return 0;
	}
	else
	{
	if(sem==0)
		return 0;
	return 1;
	}
}


void pe()
{
	int chk = chkav(1);
	int i;
	if(chk==1)
	{
		for(i=0;i<4;i++)
		{
			if(slot[i]==0)
			{slot[i]=1;printf("\n Person enters in slot no. %d",i+1);break;}
		}
		sem++;
		return;
	}
	wq++;
	printf("\n Slots full\nPerson enters in waiting queue at position %d",wq);
}


void px()
{
	int chk = chkav(2);
	int s,i;
	if(chk==1)
	{
		printf("\n Enter Slot from which person is exiting....\n");
		scanf("%d",&s);
		if(s>0 && s<5)
		{
			if(slot[s-1]==1)
			{
			printf("\n Person exits from slot no. %d",s);
			slot[s-1]=0;
			sem--;
			}
			else
			{
			printf("\n Slot already empty...\n");
			}
		}
		if(wq>0)
		{
			printf("\n person from waiting queue occupies the slot no. %d",s);
			wq--;
			for(i=0;i<4;i++)
			{
				if(slot[i]==0)
				{slot[i]=1;break;}
			}
			sem++;
		}
		return;
	}
	printf("\n All slots are empty....no one exits\n");
}



void entermutex()
{

    if(mutex==0)
    {
        printf("\n\t\t\tprocess is executing .............");
       sleep(10);
       mutex=1;
    }
    else
        {
            printf("\n\t\t\tresource is already allocated ...........wait in queue");
            waitmutex++;
        }


}
void exitmutex()
{

        if(mutex==0&&waitmutex==0)
        {
            printf("\n\t\t\tresource is empty .....and no one process in queue...");
            sleep(5000);
            return;
        }
      if(mutex==1&&waitmutex>0)
      {
          mutex=0;
          waitmutex--;
          printf("\n\t\t\told process has been released \n");
		  printf("\n\t\t\tand new process from witing queue has been added\n ");
          mutex=1;
          return;
      }

    if(mutex==1&&waitmutex==0)
    {
        printf("\n\t\t\tresources has been released \n");
        sleep(10);
        printf("\n\t\t\tno one process in wait \n");
    }
}
void status()
{
	if(mutex==1)
	{
		printf("\n\n\t\t\tresource is busy ....\n");
		printf("\n\n\t\t\t%d processes in wait....\n",waitmutex);
	}
	else
	{
		printf("\n\n\t\t\tresource is IDLE \n");
	}
}
int main()
{
	int ch,i,che;
	printf("\n**********BATHROOM PROBLEM**********\n\n");
	A:
	while(1)
    {
       printf("\n1.semaphore\n2.mutex\n3.monitor\n4.Exit\nenter choice  ");
       scanf("%d",&che);
       switch(che)
       {
            case 1:
	                 do
	                     {
                        	printf("\n\n\t\t\tOPTIONS\n");
	                        printf("\t\t\t1. Person enters\n\t\t\t2. Person exits\n\t\t\t3. Check Slots Status\n\t\t\t4. Close\n\n");
	                        printf("\n\t\t\tEnter choice ");
	                        scanf("%d",&ch);
	                               switch(ch)
	                                      {
	                                     	case 1:pe();break;
	                                     	case 2:px();break;
	                                     	case 3:printf("\n\n");for(i=0;i<4;i++){slot[i]==0?printf("\tempty"):printf("\toccupied");}printf("\n\n");break;
	                                     	case 4:system("cls");goto A;
	                                     	default:printf("\n Invalid Selection...\n");
                                           	}
                    	}while(1);
                    	break;
          case 2:     while(1)
                         {
                             printf("\n\t\t\t1.Enter person\n\t\t\t2.Exit person\n\t\t\t3.current status\n\t\t\t4.close mutex\n\t\t\tEnter your choice :");
                             scanf("%d",&ch);
                             switch(ch)
                             {

                                 case 1: entermutex();
                                         break;
                                 case 2: exitmutex();
                                           break;
                                 case 3: status();
								           break;
								case 4: system("cls"); goto A;
								default: printf("\n\n\t\t\tINVALID SELECTION......TRY AGAIN..");		             
                             }
                         }
                         break;
         case 3:  printf("\n\nmonitor is not completed ......");
		           sleep(1);
				   break;
	    case 4: return;
		default: printf("\n\nWRONG CHOICE ....");			                   

       }//end of main switch//
}///end of 1st while
}//end of main//
