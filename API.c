#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) 
{
    fd_set rfds;
    struct timeval tv;
    int n = 0l;

    FD_ZERO(&rfds);//初期化
    FD_SET(0, &rfds);

    tv.tv_sec = 5; //何秒でタイムアウトするかの設定(秒)
    tv.tv_usec = 0;
    
    n = select(1, &rfds, NULL, NULL, &tv);
    	
    if (n == 0) {
		printf("timeout\n");
	}
   	
   	if (n){
   		printf("数字が検出されました．");
   	}
}
