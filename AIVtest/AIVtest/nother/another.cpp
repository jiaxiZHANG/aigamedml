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
	// ���� show
	for (int i = 0; i < 100; i++) {
		mainc->wenjian_show[i] = NULL;
	}
	mainc->onnx.clear();
	//��ȡ��·���µ������ļ�  
	get__list("./onnx", mainc->onnx);
	
	
	for (int i = 0; i < 100; i++) {
		mainc->wenjian_show[i] = (char*)"    ";
	}
	//  ��ֵshow  �����ļ�
	for (int i = 0; i < mainc->onnx.size(); i++) {
		mainc->wenjian_show[i] = (char*)mainc->onnx[i].c_str();
	}
}


//=====================================================================

int key_listen()
{
	// ��װ����
	//keyboardHook = SetWindowsHookEx(
		//WH_KEYBOARD_LL,			
		//LowLevelKeyboardProc,
		//GetModuleHandleA(NULL),	// Dll ���
		//NULL
	//);
	//if (//keyboardHook == 0) { std::cout << "������Ӧ��ʼ��ʧ��" << std::endl; return -1; }

	//����©����Ϣ������Ȼ����Ῠ��
	//MSG msg;
//	while (true)
	//{
		// �����Ϣ����������Ϣ
		//if (PeekMessageA(
			//&msg,		
		//	NULL,	
		//	NULL,	
		//	NULL,		
		//	PM_REMOVE	
	//	)) {
			// �Ѱ�����Ϣ���ݸ��ַ���Ϣ
			//TranslateMessage(&msg);

			// ����Ϣ���ɸ����ڳ���
			//DispatchMessageW(&msg);
		//}
		//else
		//	Sleep(10);   
	//}
	// ɾ������
	//UnhookWindowsHookEx(keyboardHook);
	return 0;
}



//��ȡ�ļ��б�
int get__list(std::string path, std::vector<std::string>& files) {
	//�ļ����  
	intptr_t hFile = 0;
	//����дһ�����ļ������ļ����м����ĺ���
	
	return 0;
}




VOID all_chushihua() {

	//if (IsUserAnAdmin() == false) {
	//	MessageBoxA(NULL, "�𾴵��û�, ���Թ���Ա�����������", " ���л�����ʼ��: ������ƽ���", MB_YESNO | MB_ICONHAND);
	//	Sun::Get().exit_main = true;
	//	return;
	//}

	srand(time(0));
	path_chushihua();
	// ��ʼ��sendinput
	InitSendInput();

}