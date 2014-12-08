/*
 * examples3d.h
 *
 *  Created on: Dec 2, 2014
 *      Author: alain
 */

#ifndef EXAMPLES3D_H_
#define EXAMPLES3D_H_

#include "cocos2d.h"
#include <vector>

using namespace cocos2d;

class Examples3d : public LayerColor
{
private:
	//============================ Others ===================================
	Size visibleSize;
	Vec2 origin;
	//========================= Sprite3D =========================
	Sprite3D *sprite;
	Sprite3D* orc;
	Sprite3D* turtle;
	Sprite3D* woman;
	//========================= Menu Items =========================
	LabelTTF *lbl_sprite;
	LabelTTF *lbl_animation;
	LabelTTF *lbl_light_ambient;
	LabelTTF *lbl_light_directional;
	LabelTTF *lbl_light_point;
	LabelTTF *lbl_light_spot;

	std::vector<int> labels_bits;
	void createMenu();

    //====================== SingleTouchEvents =============================
    bool onTouchBegan(Touch *touch, Event *unused_event);
    void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
public:
    // There's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    // Initializes the game
    virtual bool init();
    // Implement the "static create()" method manually
    CREATE_FUNC(Examples3d);
};

#endif /* EXAMPLES3D_H_ */
