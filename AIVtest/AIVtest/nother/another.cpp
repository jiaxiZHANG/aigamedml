#include "another.h"
#include <fstream>
#include <cassert>
#include "sun.h"
#include <chrono>

#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>

#include <corecrt_math.h>
#include <iostream>

#include "mouse/mouse.h"


#include <ShlObj.h> //IsUserAnAdmin()


void path_chushihua() {
	Sun* mainc = &Sun::Get();
	// 清理 show
	for (int i = 0; i < 100; i++) {
		mainc->wenjian_show[i] = NULL;
	}
	mainc->onnx.clear();
	//获取该路径下的所有文件  
	get__list("./onnx", mainc->onnx);
	
	
	for (int i = 0; i < 100; i++) {
		mainc->wenjian_show[i] = (char*)"    ";
	}
	//  赋值show  涟漪文件
	for (int i = 0; i < mainc->onnx.size(); i++) {
		mainc->wenjian_show[i] = (char*)mainc->onnx[i].c_str();
	}
}


//=====================================================================

int key_listen()
{
	// 安装钩子
	//keyboardHook = SetWindowsHookEx(
		//WH_KEYBOARD_LL,			
		//LowLevelKeyboardProc,
		//GetModuleHandleA(NULL),	// Dll 句柄
		//NULL
	//);
	//if (//keyboardHook == 0) { std::cout << "键盘响应初始化失败" << std::endl; return -1; }

	//不可漏掉消息处理，不然程序会卡死
	//MSG msg;
//	while (true)
	//{
		// 如果消息队列中有消息
		//if (PeekMessageA(
			//&msg,		
		//	NULL,	
		//	NULL,	
		//	NULL,		
		//	PM_REMOVE	
	//	)) {
			// 把按键消息传递给字符消息
			//TranslateMessage(&msg);

			// 将消息分派给窗口程序
			//DispatchMessageW(&msg);
		//}
		//else
		//	Sleep(10);   
	//}
	// 删除钩子
	//UnhookWindowsHookEx(keyboardHook);
	return 0;
}



//获取文件列表
int get__list(std::string path, std::vector<std::string>& files) {
	//文件句柄  
	intptr_t hFile = 0;
	//这里写一个对文件夹下文件进行检索的函数
	
	return 0;
}




VOID all_chushihua() {

	//if (IsUserAnAdmin() == false) {
	//	MessageBoxA(NULL, "尊敬的用户, 请以管理员身份运行涟漪", " 运行环境初始化: 外设控制接入", MB_YESNO | MB_ICONHAND);
	//	Sun::Get().exit_main = true;
	//	return;
	//}

	srand(time(0));
	path_chushihua();
	// 初始化sendinput
	InitSendInput();

}