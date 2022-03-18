#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<unistd.h>
#include <arpa/inet.h>
#include<sys/socket.h>
int main(){
    /*
     * This constant has the value 0.     * It's actually an automatic choice depending on socket type and family.
     * If you use it, and if the socket type is SOCK_STREAM and the family is AF_INET,
     * then the protocol will automatically be TCP (exactly the same as if you'd used IPPROTO_TCP).
     * Buf if you use IPPROTO_IP together with AF_INET and SOCK_RAW, you will have an error,
     * because the kernel cannot choose a protocol automatically in this case.
     */
    int sock =socket(AF_INET,SOCK_STREAM,IPPROTO_IP);

    struct sockaddr_in serv_addr;
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port= htons(2896);
    //通过connect函数向客户端发起请求,服务器的套接字信息存储在结构体serv_addr中
    connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

    char buffer[40];
    //通过read从套接字中读取数据
    read(sock,buffer,sizeof(buffer)-1);

    printf("message from server: %s\n",buffer);
    //关闭套接字
    close(sock);
    return 0;


}