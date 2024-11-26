#include "../include/Player.h"
#include "../include/EnemyPool.h"

#include <memory>

const DWORD TIME_FRAME = 1000 / 60;

//��ֵ
ExMessage msg;  // ������Ϣ����
int up = 0;
int down = 0;
int left = 0;
int right = 0;

//��Դ
IMAGE background;
std::shared_ptr<Player> player;
EnemyPool enemy_pool(10);
//��ʼ��
void GameInitialize() {
	// ʹ�õ�ǰʱ����Ϊ��������ɵ�����
	srand(time(0));

	//���ر���
	loadimage(&background, _T("resources/img/background.png"));
	initgraph(1280, 720);  // ��ʼ��ͼ�δ���

	//�������
	player = std::make_shared<Player>(100, 10);
	for(int i = 0 ; i<6 ; i++){		//���ﶯ������
		std::string path = std::string("resources/img/player_left_") + std::to_string(i) + std::string(".png");
		player->Image_Load(path);
	}
	player->Image_Flip();			//��ȡ��ת��Դ
	player->CollisionLoad(100, 100);//������ײ�����

	//���ص���
	enemy_pool.getEnemy();
	enemy_pool.getEnemy();

	BeginBatchDraw();      // ��ʼ�������ƣ���ֹ��˸
}


//��׽����
void CaptureOperation() {

	while (peekmessage(&msg)) {
		if (msg.message == WM_KEYDOWN) {//��������
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

		if (msg.message == WM_KEYUP) {//����̧��
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

//��ֵ����
void NumericalComputation()
{
	//����ƶ�
	static DWORD time = GetTickCount();
	Vector2D vec( right - left, down - up);
	vec = vec.normalize();
	vec = vec * (GetTickCount() - time) * 0.02;
	player->Move(vec);

	//����
	enemy_pool.ActiveEnemies_Pursuit(player,time);

	//��ײ��
	enemy_pool.ActiveEnemies_CollisionDetection(player);
	//enemy->CollisionDetection(player);

	time = GetTickCount();
}


//��Դ��Ⱦ
void ResourceRendering() {
	cleardevice();  // ��մ�������
	//��ͼ����
	putimage(0, 0, &background);	
	//��ɫ����
	player->Resource_Rendering();

	//���˻���
	enemy_pool.ActiveEnemies_Rendering();

	FlushBatchDraw();  // ˢ����������
}

//��Դ�ͷ�
void ResourceRelease() {
	EndBatchDraw();  // ������������
	closegraph();    // �ر�ͼ�δ���
}

int main() {
	//��Ϸ��ʼ��
	GameInitialize();

	while (true) {
		// ��ȡ��ǰʱ�䣨���룩
		DWORD start_time = GetTickCount();

		//�������\�߼�����
		CaptureOperation();

		//��ֵ����		
		NumericalComputation();

		//��Դ��Ⱦ
		ResourceRendering();

		DWORD end_time = GetTickCount();

		DWORD time_interval = end_time - start_time;

		if (time_interval < TIME_FRAME) {
			Sleep(TIME_FRAME - time_interval);
		}
	}

	//��Դ�ͷ�
	ResourceRelease();
	return 0;
}