#ifndef __LEVEL3_SCENE_H__
#define __LEVEL3_SCENE_H__
#include "BaseGameLayer.h"


class HealthParticle;
class PlayerUpgradeParticle;
class PlayerUpgradeParticle2;

class Level3 : public BaseGameLayer
{
	enum ActionScheduler { MediumScheduler, HeightScheduler, Upgrade };
	HealthParticle* _health;
	PlayerUpgradeParticle * _upgrade;
	PlayerUpgradeParticle2 * _upgrade2;

	bool _heightSchedulerRunning;

	//enemigos de nivel medio
	int _numMediumEnemies;
	int _mediumEnemyIndex;
	//enemigos de nivel alto
	int _numHeightEnemies;
	int _heightEnemyIndex;


	
	void checkCollisions();

	void awakeMediumEnemyScheduler();
	void awakeMediumEnemy();

	void awakeHeightEnemyScheduler();
	void awakeHeightEnemy();
	void launchHeightEnemies();
	void launchMediumEnemies();

	void scheduleActions();
	void schduleUpgrades();
	void launchHealth();
	void launchUpgrade();
	void launchUpgrade2();

	void initActors();
	void initializeVariables();

protected:
	virtual void respawnButtonAction();
	virtual void pauseButtonAction();
	virtual void playButtonAction();

public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void update(float dt);

	CREATE_FUNC(Level3);
};

#endif // __LEVEL3_SCENE_H__