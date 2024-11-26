#include "../include/Player.h"
#include "../include/EnemyPool.h"

#include <memory>

const DWORD TIME_FRAME = 1000 / 60;

//数值
ExMessage msg;  // 定义消息变量
int up = 0;
int down = 0;
int left = 0;
int right = 0;

//资源
IMAGE background;
std::shared_ptr<Player> player;
EnemyPool enemy_pool(10);
//初始化
void GameInitialize() {
	// 使用当前时间作为随机数生成的种子
	srand(time(0));

	//加载背景
	loadimage(&background, _T("resources/img/background.png"));
	initgraph(1280, 720);  // 初始化图形窗口

	//人物加载
	player = std::make_shared<Player>(100, 10);
	for(int i = 0 ; i<6 ; i++){		//人物动画加载
		std::string path = std::string("resources/img/player_left_") + std::to_string(i) + std::string(".png");
		player->Image_Load(path);
	}
	player->Image_Flip();			//获取翻转资源
	player->CollisionLoad(100, 100);//人物碰撞体加载

	//加载敌人
	enemy_pool.getEnemy();
	enemy_pool.getEnemy();

	BeginBatchDraw();      // 开始批量绘制，防止闪烁
}


//捕捉操作
void CaptureOperation() {

	while (peekmessage(&msg)) {
		if (msg.message == WM_KEYDOWN) {//按键按下
			switch (msg.vkcode) {
			case VK_UP:
				up++;
				break;
			case VK_DOWN:
				down++;
				break;
			case VK_LEFT:
				left++;
				break;
			case VK_RIGHT:
				right++;
				break;
			}
		}

		if (msg.message == WM_KEYUP) {//按键抬起
			switch (msg.vkcode) {
			case VK_UP:
				up = 0;
				break;
			case VK_DOWN:
				down = 0;
				break;
			case VK_LEFT:
				left = 0;
				break;
			case VK_RIGHT:
				right = 0;
				break;
			}

		}
	}
}

//数值计算
void NumericalComputation()
{
	//玩家移动
	static DWORD time = GetTickCount();
	Vector2D vec( right - left, down - up);
	vec = vec.normalize();
	vec = vec * (GetTickCount() - time) * 0.02;
	player->Move(vec);

	//敌人
	enemy_pool.ActiveEnemies_Pursuit(player,time);

	//碰撞体
	enemy_pool.ActiveEnemies_CollisionDetection(player);
	//enemy->CollisionDetection(player);

	time = GetTickCount();
}


//资源渲染
void ResourceRendering() {
	cleardevice();  // 清空窗口内容
	//地图绘制
	putimage(0, 0, &background);	
	//角色绘制
	player->Resource_Rendering();

	//敌人绘制
	enemy_pool.ActiveEnemies_Rendering();

	FlushBatchDraw();  // 刷新批量绘制
}

//资源释放
void ResourceRelease() {
	EndBatchDraw();  // 结束批量绘制
	closegraph();    // 关闭图形窗口
}

int main() {
	//游戏初始化
	GameInitialize();

	while (true) {
		// 获取当前时间（毫秒）
		DWORD start_time = GetTickCount();

		//捕获操作\逻辑处理
		CaptureOperation();

		//数值计算		
		NumericalComputation();

		//资源渲染
		ResourceRendering();

		DWORD end_time = GetTickCount();

		DWORD time_interval = end_time - start_time;

		if (time_interval < TIME_FRAME) {
			Sleep(TIME_FRAME - time_interval);
		}
	}

	//资源释放
	ResourceRelease();
	return 0;
}