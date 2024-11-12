#include <opencv2/opencv.hpp>
#include "dml/module2.h"
#include "dml/module.h"
#include "bit/bit.h"

#include "imgui/imgui_main.h"
#include "mouse/mouse.h"

#include "nother/another.h"
#include "sun.h"
using namespace std;

/*dml推理部分   send移动部分   GUI界面部分

	已移除移动算法，以及部分 对接API。

	整套源码可以直接编译通过，如果有报错请检查是否导入opencv库路径。



*/
Sun* sun = &Sun::Get();

static int Gui() {
	//启用循环
	imgui_main();
	return 0;
}
void banji_main() {
	while (true) {
		Sleep(200);
	}
}

int yaqiang_main() {
	while (true) {
		if (sun->yaqiang_on) {
			if (sun->yaqiang_leiji) {
				Sleep((int)sun->yaqiang_xiumian);
				if (sun->yaqiang < sun->yaqiang_zuida) {
					if (KEY_DOWN(VK_LBUTTON)) {
						sun->yaqiang = sun->yaqiang + 1;
					}
				}
			}
			else {
				sun->yaqiang = 0;
				Sleep(100);
			}
		}
		else {
			Sleep(100);

		}
	}
}


int chuli(vector<Box>& newbox, cv::Mat& a) {

	float juli = 0.0f;
	float old_juli = 100000.0f;
	float x = 0.0f, y = 0.0f, w = 0.0f, h = 0.0f;
	for (const Box& detection : newbox)
	{
		if (sun->qiyongfenlei) {
			if (detection.class_label != (int)sun->fenlei) {
				continue;
			}
		}
		juli = pow((pow(detection.x - sun->mid, 2)
			+ pow(detection.y - sun->mid, 2)),
			0.5);

		if (juli < old_juli) {
			old_juli = juli;
			x = detection.x;
			y = detection.y;
			w = detection.w;
			h = detection.h;
		}
		//画框
		if (sun->jianshiqi) {
			cv::rectangle(a, cv::Point((int)detection.x - detection.w * 0.5f, (int)detection.y - detection.h * 0.5f), cv::Point((int)detection.x + detection.w * 0.5f, (int)detection.y + detection.h * 0.5f), cv::Scalar(0, 255, 0), 1);
		}

	}

	if (juli > sun->fanwei) {
		return 0;
	}
	//鼠标移动
	if (KEY_DOWN(VK_LBUTTON) && sun->miaozhun) {
		// 在这里对接你自己的移动算法和移动函数
		// 
		// X Y 坐标都算出来了 传递去 move  就可以了
		// move(x,y);
		//==================================================

	}


}

vector<Box> newbox;
cv::Mat a;

int bitmain() {
	auto* frame = new IDML();
	frame->AnalyticalModel(sun->onnx[sun->mode_llist]);
	const int imgsize = frame->imgsize; // 模型长宽 只接受正方形
	sun->mid = imgsize / 2;
	sun->fanwei = sun->mid;
	BYTE* bgr = new BYTE[imgsize * imgsize * 3];
	//获得屏幕的宽
	//获得屏幕的高
	int screen_x = 0, screen_y = 0;
	if (sun->autofenbianlv) {
		screen_x = GetSystemMetrics(SM_CXSCREEN);
		screen_y = GetSystemMetrics(SM_CYSCREEN);
	}
	else {
		screen_x = stoi(sun->shuru_w);
		screen_y = stoi(sun->shuru_h);
	}
	capturec bitcap;
	bitcap.start(screen_x, screen_y, imgsize, imgsize, "A");
	auto t2 = std::chrono::steady_clock::now();
	while (true)
	{
		auto t1 = std::chrono::steady_clock::now();


		bgr = (BYTE*)bitcap.cap();
		float* data = frame->Detect(bgr);

		vector<Box> box;
		newbox = houchuli(data, box, frame->out1, frame->out2, sun->conf, sun->iou);

		if (sun->jianshiqi) {
			a = cv::Mat(imgsize, imgsize, CV_8UC3, bgr);
		}

		if (!newbox.empty())
		{
			chuli(newbox, a);
		}
		else {
			sun->banji_biubiu = false;
		}

		if (sun->jianshiqi) {
			cv::imshow(" 展示自定义", a);
			cv::waitKey(1);
		}
		else {
			cv::destroyAllWindows();
		}

		if (sun->stopAI || sun->exit_main) {
			sun->stopAI = false;
			sun->ingAI = false;
			frame->Release();
			cv::destroyAllWindows();

			return 0;
		}

	}
	return 0;
}
//====================================================================== 

int main() {

	all_chushihua();
	//隐藏控制台
	HWND main_hwnd = GetForegroundWindow();
	std::thread(Gui).detach();
	Sun* sun = &Sun::Get();

	std::thread(key_listen).detach();
	std::thread(banji_main).detach();
	std::thread(yaqiang_main).detach();
	//主循环
	while (true) {

		if (sun->beginAI) {
			sun->beginAI = false;
			sun->ingAI = true;
			std::thread(bitmain).detach();

		}

		//move函数指针
		switch (sun->move_llist) {
		case 0:
			sun->move_zhizhen = Send_Move;
			sun->down_zhizhen = send_leftdown;
			sun->up_zhizhen = send_leftup;
			break;
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		default:
			break;
		}


		if (sun->cmd_window != sun->cmd_yanzheng) {

			sun->cmd_yanzheng = sun->cmd_window;
		}

		if (sun->usb_lianjie) {

		}

		if (sun->RX_lianjie) {

		}

		if (sun->net_lianjie) {

		}
		if (sun->exit_main) {

			Sleep(300);
			return 0;
		}
		Sleep(200);
	}

	return 0;
}




