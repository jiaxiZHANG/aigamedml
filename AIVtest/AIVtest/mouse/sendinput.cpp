
#include <windows.h>
#include <iostream>

INPUT send_input;
INPUT send_input2;
VOID Send_Move(const int& x, const int& y) {
	send_input.mi.dx = x;
	send_input.mi.dy = y;
	SendInput(1, &send_input, sizeof(INPUT));
}

VOID InitSendInput() {
	send_input.type = INPUT_MOUSE;
	send_input.mi.dx = 0;
	send_input.mi.dy = 0;
	send_input.mi.mouseData = 0;
	send_input.mi.dwFlags = MOUSEEVENTF_MOVE;   //MOUSEEVENTF_ABSOLUTE 代表决对位置  MOUSEEVENTF_MOVE代表移动事件
	send_input.mi.time = 0;
	send_input.mi.dwExtraInfo = 0;

	send_input2.type = INPUT_MOUSE;
	send_input2.mi.dx = 0;
	send_input2.mi.dy = 0;
	send_input2.mi.mouseData = 0;
	send_input2.mi.dwFlags = MOUSEEVENTF_MOVE;   //MOUSEEVENTF_ABSOLUTE 代表决对位置  MOUSEEVENTF_MOVE代表移动事件
	send_input2.mi.time = 0;
	send_input2.mi.dwExtraInfo = 0;

}
void send_leftdown()
{
    send_input2.type = INPUT_MOUSE;
    send_input2.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &send_input2, sizeof(INPUT));
}


void send_leftup()
{
    send_input2.type = INPUT_MOUSE;
    send_input2.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &send_input2, sizeof(INPUT));
}


