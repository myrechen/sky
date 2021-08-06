#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include "stdlib.h"
#include "assert.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <unistd.h>
int main()
{
	//定义发送缓冲区和接受缓冲区
    char send_buf[100];
    char recv_buf[100];
	int send_len = 0;
    int recv_len = 0;

	int bind_status,listen_status;

	//定义服务端套接字，接受请求套接字
	int server_sockfd, client_sockfd;
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

	socklen_t server_len, client_len;

	//服务端地址客户端地址
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	//填充服务端信息
	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	server_address.sin_port = htons(1234);	

	int opt = 1,ret;
	ret = setsockopt(server_sockfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof( opt ));	
	if(ret == -1)
		printf("set failed\n");
	if(ret == 0)
		printf("seccess\n");

	server_len = sizeof(server_address);
	bind_status = bind(server_sockfd, (struct sockaddr*)&server_address, server_len);
	if(bind_status == -1)
		printf("socket bind fail\n");
	else
		printf("socket bind success\n");
	
	listen_status = listen(server_sockfd, 5);
	if(listen_status == 0)
		printf("listen success\n");
	else
		printf("listen fail\n");
	
	printf("server listening\n");

	client_len = sizeof(client_address);
	client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address, &client_len);
	if(client_sockfd == -1)
	{	printf("connect fail");
		return 0;
	}
	printf("recv data\n");

	//接收数据
	while(1) 
	{
		memset(recv_buf,0,sizeof(recv_buf));
		recv_len = recv(client_sockfd, recv_buf, 100, 0);
        if (recv_len < 0) {
            printf("receive fail\n");
            break;
        }
		else
			printf("client msg:%s\n",recv_buf);
		printf("please send msg:");
		scanf(" %s",send_buf);
		send_len = send(client_sockfd, send_buf, sizeof(send_buf), 0);
	}
	close(client_sockfd);
	close(server_sockfd);
}