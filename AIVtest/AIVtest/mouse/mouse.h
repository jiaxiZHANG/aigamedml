
#include <windows.h>

typedef int BOOL;


//send
VOID InitSendInput();
void Send_Move(const int& x, const int& y);
void send_leftdown();
void send_leftup();

//RX
void chushihuaRX(char rxID[20]);
void move_RX_duijie(const int& x, const int& y);
void RX_down();
void RX_up();

//RX-4
void chushihuaRX_4(int com);
void move_rx4_duijie(const int& x, const int& y);
void RX4_down();
void RX4_up();