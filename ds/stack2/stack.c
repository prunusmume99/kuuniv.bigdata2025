int stack[100] = {0};	// 배열 
int tos= 0; 		// top of stack (스택의 꼭대기)
// 전역 공간에 배열과 변수 선언

void push(int data)		// func, definition
 {
	stack[tos] = data;
	++tos; 	//tos = tos +1; ( ++ 쓰는 이유는 increase 라는 기계어 명령과 대입해서 빠름) 
}
 
 int pop(void)
 {
	--tos;
	return stack[tos];
 }
// 지역변수는 괄호 안에 있는 것들이 지역변수
