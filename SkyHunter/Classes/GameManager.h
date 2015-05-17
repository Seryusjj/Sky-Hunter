#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__
#include "cocos2d.h"
#define LEVELKEY "level"
#define BGVOLUMEKEY "bgvolume"
#define EFFECTSVOLUMEKEY "effectvolume"

class GameManager
{
private:
	GameManager();
	static GameManager* _instance;
	GameManager(GameManager const&) = delete;// copy constructor is private
	void operator=(GameManager const&) = delete;// assignment operator is private
	int _nextLevel;


public:
	CC_SYNTHESIZE(int, _bgVolume, BgVolume);
	CC_SYNTHESIZE(int, _effectsVolume, EffectsVolume);
	void saveSetting();
	enum DrawOrder {};
	CC_SYNTHESIZE(int, _playerScore, PlayerScore);
	static GameManager* getInstance();
	void saveGame();
	int getNextLevel();
	~GameManager();
};

#endif //__GAMEMANAGER_H__;