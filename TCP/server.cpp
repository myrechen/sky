#include<iostream>
#include<winsock.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
void initialization();

int main(int argc, char *argv[])
{
    int send_len = 0;
    int recv_len = 0;
    int len = 0;
    //定义发送缓冲区和接受缓冲区
    char send_buf[100];
    char recv_buf[100];
    //定义服务端套接字，接受请求套接字
    SOCKET s_server;
    SOCKET s_accept;
    //服务端地址客户端地址
    SOCKADDR_IN server_addr;
    SOCKADDR_IN accept_addr;
    initialization();
    //填充服务端信息
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(5010);
    //创建套接字
    s_server = socket(AF_INET, SOCK_STREAM, 0);
    if (bind(s_server, (SOCKADDR *)&server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR) {
        cout << "socket bind fail" << endl;
        WSACleanup();
    }
    else {
        cout << "socket bind success" << endl;
    }
    //设置套接字为监听状态
    if (listen(s_server, SOMAXCONN) < 0) {
        cout << "listen fail" << endl;
        WSACleanup();
    }
    else {
        cout << "listen success" << endl;
    }
    cout << "server is listening...." << endl;
    //接受连接请求
    len = sizeof(SOCKADDR);
    s_accept = accept(s_server, (SOCKADDR *)&accept_addr, &len);
    if (s_accept == SOCKET_ERROR) {
        cout << "connect fail"<< endl;
        WSACleanup();
        return 0;
    }
    cout <<"recv data"<< endl;
    //接收数据
    while (1) {
        memset(recv_buf,0,sizeof(recv_buf));
        recv_len = recv(s_accept, recv_buf, 100, 0);
        if (recv_len < 0) {
            cout <<"rece fail"<< endl;
            break;
        }
        else {
            cout << "client msg:" << recv_buf << endl;
        }
        cout << "please send msg:";
        memset(send_buf,0,sizeof(send_buf));
        cin >> send_buf;
        send_len = send(s_accept, send_buf, sizeof(send_buf), 0);
        if (send_len < 0) {
            cout << "send fail" << endl;
            break;
        }
    }
    //关闭套接字
    closesocket(s_server);
    closesocket(s_accept);
    //释放DLL资源
    WSACleanup();
}
void initialization() {
    //初始化套接字库
    WORD w_req = MAKEWORD(2, 2);//版本号
    WSADATA wsadata;
    int err;
    err = WSAStartup(w_req, &wsadata);
    if (err != 0) {
        cout << "initialization socket fail" << endl;
    }
    else {
        cout << "initialization socket success" << endl;
    }
    //检测版本号
    if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2) {
        cout << "socket version fail" << endl;
        WSACleanup();
    }
    else {
        cout << "socket version success" << endl;
    }
    //填充服务端地址信息

}
