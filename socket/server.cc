#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <string.h>

int main(){
    //创建套接字
    /*
     * AF_INET is an address family that is used to designate
     * the type of addresses that your socket can communicate
     * with (in this case, Internet Protocol v4 addresses).
     * When you create a socket, you have to specify its address family,
     * and then you can only use addresses of that type with the socket.
     * The Linux kernel, for example, supports 29 other address families
     * such as UNIX (AF_UNIX) sockets and IPX (AF_IPX), and also communications with IRDA
     * and Bluetooth      * (AF_IRDA and AF_BLUETOOTH, but it is doubtful you'll use these at such a low level).
     * For the most part, sticking with AF_INET for socket programming over
     * a network is the safest option.
     * There is also AF_INET6 for Internet Protocol v6 addresses
     */
    /*
     * SOCK_STREAM
     * Provides sequenced, reliable, two-way, connection-
     * based byte streams.  An out-of-band data transmission
     * mechanism may be supported.
     */
    //IPPROTO_TCP 采用TCP协议
    int serv_sock =socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    //将套接字和IP 端口号进行绑定
    struct sockaddr_in serv_addr;
    //初始化结构体serv_addr
    memset(&serv_addr,0,sizeof(serv_addr));
    //使用ipv4地址
    serv_addr.sin_family=AF_INET;
    //设置ip地址
    serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    //设置端口号
    serv_addr.sin_port =htons(2896);
    //将套接字和结构体进行绑定 结构体中存储了套接字的协议 端口号  以及ip地址
    bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    //进入监听状态,等待用户发起请求
    //进入被动监听状态,套接字一直处于睡眠状态,直至客户端发起请求才会被重新唤醒
    listen(serv_sock,20);
    //客户端请求对应的套接字结构体
    struct sockaddr_in client_addr;
    //客户端请求套接字结构体的大小
    socklen_t  client_addr_size =sizeof(client_addr);
    //用于接受客户端的请求
    int client_sock =accept(serv_sock,(struct sockaddr *)&client_addr,&client_addr_size);
    char str[]="hello world";
    //向客户端发送数据
    //向客户端套接字中写入数据
    write(client_sock,str,sizeof(str));
    //关闭套接字
    close(client_sock);
    close(serv_sock);
    return 0;
}