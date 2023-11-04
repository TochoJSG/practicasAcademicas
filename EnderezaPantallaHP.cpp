#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
int main(){
	bool b = false;
	while(1){
			 if(GetAsyncKeyState(0x55)){
			 							 keybd_event(VK_RMENU,0,0,0);
			 							 keybd_event(0x26,0,0,0);
			 							 b = true;
			 							 if(b==true){
										  			 exit(1);
									   				 }else{printf("No apretaste shift");}
			 							 }
			 }
	system("pause"); return 0;
	}
