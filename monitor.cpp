#include<iostream>
#include<stdlib.h>
using namespace std;
int flag=0;
class critical_section_monitor
{
	int data;
	public:
		void access()
		{
			delay(4000);
			
		}
		void signal()
		{
			if(flag==0)
			flag=1;
			
		}
		void access_path()
		{
			if(flag==0)
			{
				flag=1;
				cout<<endl<<"process is allocated to rsource ";
				cout<<endl<<"now the path is blocked ....no one can access the critical ssection";
				access();
				signal(flag);
				
			}
			else
			{
				cout<<"resources is already allocated ";
				cout<<endl<<"please try later ";
				return;
			}
		}
};
