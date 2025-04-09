int queue[100];
int rear;
int front;

void push(int data)
{
    queue[rear] = data;
    ++rear;         // 위치 값 +1
}

int pop(void)
{
    int i = front;  // 임시 변수 선언
    ++front;
    return queue[i];
}