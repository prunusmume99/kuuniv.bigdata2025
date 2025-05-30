#include <arpa/inet.h>
 #include <stdio.h>
 #include <stdlib.h>
 
 void print_addr(unsigned long conv_addr);
 
 int main()
 {
     const char *addr1 = "127.212.124.78";  // 01111111.11010100.01111100.01001110 7F.D4.7C.4E
     const char *addr2 = "127.212.124.256"; // 256 error
     struct sockaddr_in addr_inet;
 
     unsigned long conv_addr = inet_addr(addr1);
     print_addr(conv_addr); // 0x4e 7c d4 7f
 
     conv_addr = inet_addr(addr2);
     print_addr(conv_addr);
 
     int ret = inet_pton(AF_INET, addr1, &addr_inet.sin_addr); // iton 사라짐. ipv6 때문에.
     if (ret)
     {
         printf("네트워크 인티저 addr: %#x \n", addr_inet.sin_addr.s_addr);
         // printf("sockaddr 의 s_data : %#x \n", ((struct sockaddr *)&addr_inet)->sa_data);
     }
     return 0;
 }
 
 void print_addr(unsigned long conv_addr)
 {
     if (conv_addr == INADDR_NONE)
         printf("Error occured! \n");
     else
         printf("네트워크의 인트 addr: %#lx \n", conv_addr);
 }