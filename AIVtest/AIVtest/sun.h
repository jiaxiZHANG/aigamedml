#pragma once
#include <vector>
#include <string>

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)


struct Sun
{
	static Sun& Get() {
		static Sun main_wusuowei;
		return main_wusuowei;
	}
	double banben = 3.7;  // �汾��
	
	bool lg_ok = false;

	float usb_num = 0.0f; // kmbox���ں�
	float usb_botelv = 115200.0f; // ���õĲ�����
	float kmbox_nihe = 1.0f;// ��������
	bool usb_ok = false;
	bool usb_lianjie = false;

	bool net_lianjie = false;
	bool net_ok = false;
	char net_ip[20] = { 0 };
	char net_port[20] = { 0 };
	char net_mac[20] = { 0 };

	char rxID[20] = { 0 };
	bool RX_lianjie = false;

	float rx4_num = 0.0f; // RX-4���ں�
	bool rx4_lianjie = false;
	bool rx4_ok = false;
	
	void (*down_zhizhen)();
	void (*up_zhizhen)();
	void (*move_zhizhen)(const int& x, const int& y);

	bool boolduqu = false; // �Ƿ�ִ��һ���ȡ
	bool kami_ok = true; // ������֤
	
	char* wenjian_show[100] = { (char*)"    " };
	std::vector<std::string> onnx;

	int mode_llist = 0; // ģ��ѡ��            ini

	int jietuxy_llist = 0; // ��ͼ��������ѡ��
	int jietuxy[4] = { 320,416,640,960 };
	int move_llist = 0;   // �ƶ���ʽѡ��

	int model_x;  //ģ�͵ĳ���
	int model_y;
	int x_bili = 0;  // ��ͼ��ģ�ʹ�С�ı���
	int y_bili = 0;  // ��ͼ��ģ�ʹ�С�ı���

	bool beginAI = false; // ��ʼ���
	bool ingAI = false; // ���б��
	bool stopAI = false; // �������
	bool jianshiqi = false;
	bool cmd_window = true;
	bool cmd_yanzheng = true;
	
	int jietufangshi = 0; // 0 WIN32  1 dxgi 2 wgc
	
	float conf = 0.5f; // ���Ŷ�
	float iou = 0.25f; // ����

	bool qiyongfenlei = false; // ���÷���
	float fenlei = 0; // ����

	int mid = 0; // ��ͼ�����һ��
	char shuru_w[5] = { 0 };
	char shuru_h[5] = { 0 };
	bool autofenbianlv = true;

	float X_pid_d = 0.0f;
	float Y_pid_d = 0.0f;

	float head_y = 0.25f;
	float fanwei = 320.0;

	int yaqiang = 0; // ѹǹ����
	bool yaqiang_on = false;	// ѹǹ����
	bool yaqiang_leiji = false; // ѹǹ�ۼ�
	float yaqiang_xiumian = 0.0f;	// �ۼ�����
	float yaqiang_zuida = 0.0f;		// ѹǹ���ֵ

	bool miaozhun = false;// ��׼�ܿ���
	// ��׼
	bool zuojian = false;
	bool youjian = false;
	bool zhongjian = false;
	bool cejian1 = false;
	bool cejian2 = false;

	// ���
	float qiantime = 0.0;
	float zhongtime = 0.0;
	bool bjall = false;
	bool bjyoujian = false;
	bool bjzhongjian = false;
	bool bjcejian1 = false;
	bool bjcejian2 = false;
	bool banji_biubiu = false;
	
	bool exit_main = false;
};

