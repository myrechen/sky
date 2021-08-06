#pragma comment(lib, "Ws2_32.lib")
#include<iostream>
#include<winsock.h>

using namespace std;
void initialization();
int main(int argc, char *argv[])
{

    int send_len = 0;
    int recv_len = 0;
    //���巢�ͻ������ͽ��ܻ�����
    char send_buf[100];
    char recv_buf[100];
    //���������׽��֣����������׽���
    SOCKET s_server;
    //����˵�ַ�ͻ��˵�ַ
    SOCKADDR_IN server_addr;
    initialization();
    //���������Ϣ
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.S_un.S_addr = inet_addr("59.110.213.161");
    server_addr.sin_port = htons(1234);
    //�����׽���
    s_server = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(s_server, (SOCKADDR *)&server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR) {
        cout << "server connect fail" << endl;
        WSACleanup();
    }
    else {
        cout << "server connect success" << endl;
    }

    //����,��������
    while (1) {
        memset(send_buf,0,sizeof(send_buf));
        cout << "please send data:";
        cin >> send_buf;
        send_len = send(s_server, send_buf, 100, 0);
        if (send_len < 0) {
            cout << "send fail" << endl;
            break;
        }
         memset(recv_buf,0,sizeof(recv_buf));
        recv_len = recv(s_server, recv_buf, 100, 0);
        if (recv_len < 0) {
            cout << "rece fail" << endl;
            break;
        }
        else {
            cout << "server data:" << recv_buf << endl;
        }

    }
    //�ر��׽���
    closesocket(s_server);
    //�ͷ�DLL��Դ
    WSACleanup();
    return 0;
}
void initialization() {
    //��ʼ���׽��ֿ�
    WORD w_req = MAKEWORD(2, 2);//�汾��
    WSADATA wsadata;
    int err;
    err = WSAStartup(w_req, &wsadata);
    if (err != 0) {
        cout << "initialization socket fail" << endl;
    }
    else {
        cout << "initialization socket success" << endl;
    }
    //���汾��
    if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2) {
        cout << "socket version fail" << endl;
        WSACleanup();
    }
    else {
        cout << "socket version success" << endl;
    }
    //������˵�ַ��Ϣ

}
