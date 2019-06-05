
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define MAXLINE 4096
int main(int argc, char **argv)
{
	int sockfd, n;
	char recvline[MAXLINE+1];
	struct sockaddr_in servaddr;
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof servaddr);
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(1234);
  
	
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	
	connect(sockfd, (struct sockaddr *)&servaddr, sizeof servaddr);
	while ((n = read(sockfd, recvline, MAXLINE)) > 0)
	{
		recvline[n] = 0;
		fputs(recvline, stdout);
		
	}
	exit(0);
}
* */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(){
	//创建套接字
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	//向服务器（特定的IP和端口）发起请求
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
	serv_addr.sin_family = AF_INET;  //使用IPv4地址
	serv_addr.sin_addr.s_addr = inet_addr("192.168.0.103");  //具体的IP地址
	serv_addr.sin_port = htons(1234);  //端口
	connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
   
	//读取服务器传回的数据
	char buffer[40];
	read(sock, buffer, sizeof(buffer)-1);
   
	printf("Message form server: %s\n", buffer);
   
	//关闭套接字
	close(sock);
	return 0;
}
    
    
    
    




