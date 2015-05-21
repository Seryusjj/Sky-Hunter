#include "Background.h"

using namespace cocos2d;

Background::Background(std::string background) :_speed(150), _initialiced(false){
	_screen = Director::getInstance()->getVisibleSize();
	_bgPart1 = Sprite::createWithSpriteFrameName(background);
	_bgPart2 = Sprite::createWithSpriteFrameName(background);
	_bgPart1->setPosition(_screen.width*0.5, _screen.height*0.5);
	_bgPart2->setPosition(_screen.width*0.5, _screen.height*0.5 + _screen.height - 1);
}

void Background::setSptite(std::string part1){
	_parent->removeChild(_bgPart1);
	_parent->removeChild(_bgPart2);
	_bgPart1 = Sprite::createWithSpriteFrameName(part1);	
	_bgPart2 = Sprite::createWithSpriteFrameName(part1);
	_parent->addChild(_bgPart1, _pos);
	_parent->addChild(_bgPart2, _pos);

}


void Background::setParent(Node* parent,int pos){
	//prevent the bq to bee added more than once to the scene
	if (!_initialiced){
		_parent = parent;
		_pos = pos;
		parent->addChild(_bgPart1, pos);
		parent->addChild(_bgPart2, pos);
		_initialiced = true;
	}

}



void Background::update(float dt){
	_bgPart1->setPositionY(_bgPart1->getPositionY() - _speed*dt);
	_bgPart2->setPositionY(_bgPart2->getPositionY() - _speed*dt);
	if (_bgPart1->getPositionY() <= -(_screen.height*0.5)){
		_bgPart1->setPosition(_screen.width*0.5, _screen.height*0.5);
		_bgPart2->setPosition(_screen.width*0.5, _screen.height*0.5 + _screen.height - 1);
	}
}

Background::~Background()
{
}
