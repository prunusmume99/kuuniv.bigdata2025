#include <stdio.h>
#include <unistd.h>

int main()
{
  while (1)
  {
    printf("process infinit!\n");
    sleep(1);
  }
  return 0;
}