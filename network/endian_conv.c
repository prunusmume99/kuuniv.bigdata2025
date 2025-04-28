#include <stdio.h>
#include <arpa/inet.h>

int main(){
    unsigned short host_port = 0x1234;
    unsigned short net_port;
    unsigned long host_addr = 0x12345678;
    unsigned long net_addr;

    net_port = htons(host_port);
    net_addr = htonl(host_addr);

    printf("호스트 포트는 : %#x \n", host_port);
    printf("네트워크 포트는 : %#x \n", net_port);
    printf("호스트 주소는 : %#lx \n", host_addr);
    printf("네트워크 주소는 : %lx\n", net_addr);

    return 0;
}