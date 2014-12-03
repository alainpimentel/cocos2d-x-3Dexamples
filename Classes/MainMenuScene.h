/*
 * MainMenuScene.h
 *
 *  Created on: Aug 14, 2014
 *      Author: Alain
 */

#ifndef MAINMENUSCENE_H_
#define MAINMENUSCENE_H_

#include "cocos2d.h"

using namespace cocos2d;

class MainMenuScene : public cocos2d::Layer
{
private:

	// Changes the scene to the examples3d scene
	void goToExamples3dScene( Ref *sender );

public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(MainMenuScene);
};

#endif /* MAINMENUSCENE_H_ */
