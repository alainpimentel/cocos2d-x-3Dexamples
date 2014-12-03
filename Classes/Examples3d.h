/*
 * examples3d.h
 *
 *  Created on: Dec 2, 2014
 *      Author: alain
 */

#ifndef EXAMPLES3D_H_
#define EXAMPLES3D_H_

#include "cocos2d.h"

using namespace cocos2d;

class Examples3d : public LayerColor
{
private:
	//============================ Others ===================================
	Size visibleSize;
	Vec2 origin;
public:
    // There's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    // Initializes the game
    virtual bool init();
    // Implement the "static create()" method manually
    CREATE_FUNC(Examples3d);
};

#endif /* EXAMPLES3D_H_ */
