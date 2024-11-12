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
	double banben = 3.7;  // 版本号
	
	bool lg_ok = false;

	float usb_num = 0.0f; // kmbox串口号
	float usb_botelv = 115200.0f; // 设置的波特率
	float kmbox_nihe = 1.0f;// 多段拟合数
	bool usb_ok = false;
	bool usb_lianjie = false;

	bool net_lianjie = false;
	bool net_ok = false;
	char net_ip[20] = { 0 };
	char net_port[20] = { 0 };
	char net_mac[20] = { 0 };

	char rxID[20] = { 0 };
	bool RX_lianjie = false;

	float rx4_num = 0.0f; // RX-4串口号
	bool rx4_lianjie = false;
	bool rx4_ok = false;
	
	void (*down_zhizhen)();
	void (*up_zhizhen)();
	void (*move_zhizhen)(const int& x, const int& y);

	bool boolduqu = false; // 是否执行一遍读取
	bool kami_ok = true; // 卡密验证
	
	char* wenjian_show[100] = { (char*)"    " };
	std::vector<std::string> onnx;

	int mode_llist = 0; // 模型选择            ini

	int jietuxy_llist = 0; // 截图区域适配选择
	int jietuxy[4] = { 320,416,640,960 };
	int move_llist = 0;   // 移动方式选择

	int model_x;  //模型的长宽
	int model_y;
	int x_bili = 0;  // 截图与模型大小的比例
	int y_bili = 0;  // 截图与模型大小的比例

	bool beginAI = false; // 开始标记
	bool ingAI = false; // 运行标记
	bool stopAI = false; // 结束标记
	bool jianshiqi = false;
	bool cmd_window = true;
	bool cmd_yanzheng = true;
	
	int jietufangshi = 0; // 0 WIN32  1 dxgi 2 wgc
	
	float conf = 0.5f; // 置信度
	float iou = 0.25f; // 交叉

	bool qiyongfenlei = false; // 启用分类
	float fenlei = 0; // 分类

	int mid = 0; // 截图区域的一半
	char shuru_w[5] = { 0 };
	char shuru_h[5] = { 0 };
	bool autofenbianlv = true;

	float X_pid_d = 0.0f;
	float Y_pid_d = 0.0f;

	float head_y = 0.25f;
	float fanwei = 320.0;

	int yaqiang = 0; // 压枪补偿
	bool yaqiang_on = false;	// 压枪开关
	bool yaqiang_leiji = false; // 压枪累计
	float yaqiang_xiumian = 0.0f;	// 累加休眠
	float yaqiang_zuida = 0.0f;		// 压枪最大值

	bool miaozhun = false;// 瞄准总开关
	// 瞄准
	bool zuojian = false;
	bool youjian = false;
	bool zhongjian = false;
	bool cejian1 = false;
	bool cejian2 = false;

	// 扳机
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

