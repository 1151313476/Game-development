#include "../include/Enemy.h"
#include <list>

class EnemyPool{
private:
    std::list<std::shared_ptr<Enemy>> activeEnemies; // �Ѽ���ĵ����б�
    std::list<std::shared_ptr<Enemy>> inactiveEnemies; // δ����ĵ����б�

public:
    EnemyPool(size_t size);
    void getEnemy(); // ��ȡһ�����õĵ��˶���
    void returnEnemy(std::shared_ptr<Enemy> enemy ); // ���յ��˶���

    //��Ⱦ�Ѽ������
  	void ActiveEnemies_Rendering();
    
    //�Ѽ������ҵ���߼�
    void  ActiveEnemies_Pursuit(std::shared_ptr<Entity> target, DWORD time);

    //�Ѽ��������ײ���
    void  ActiveEnemies_CollisionDetection(std::shared_ptr<Entity> target);

};
