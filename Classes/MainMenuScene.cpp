/*
 * MainMenuScene.cpp
 *
 *  Created on: Aug 14, 2014
 *      Author: Alain
 */
#include "MainMenuScene.h"
#include "Examples3d.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto item3D = MenuItemFont::create("3D Examples", CC_CALLBACK_1(
    		MainMenuScene::goToExamples3dScene, this ));
    item3D->setFontSize(200);
    item3D->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2);

    auto menu = Menu::create( item3D, NULL);
    menu->setPosition( Point::ZERO ); // we set the position for the individual items

    addChild( menu );

    return true;
}


void MainMenuScene::goToExamples3dScene( Ref *sender )
{
	auto scene = Examples3d::createScene();

	Director::getInstance()->replaceScene( TransitionFade::create( 0.5, scene ) );
}


