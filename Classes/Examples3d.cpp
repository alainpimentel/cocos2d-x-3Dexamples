/*
 * examples3d.cpp
 *
 *  Created on: Dec 2, 2014
 *      Author: alain
 */
#include "Examples3d.h"

USING_NS_CC;

Scene* Examples3d::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = Examples3d::create();

    scene->addChild(layer, 1);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Examples3d::init()
{
	if (!LayerColor::initWithColor(Color4B(255,255,255,255)))
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	// Turtle
	std::string fileName = "tortoise.c3b";
	auto sprite3D = Sprite3D::create(fileName);
	//mario3D->setTexture("marioD.jpg");
	sprite3D->setPosition(Point(origin.x + visibleSize.width/2, origin.y + visibleSize.height*4/5));
//	sprite3D->setRotation3D(Vec3(0,90,0));
	addChild(sprite3D);

	//Create animation3D by the same file of its Spirte3D
	auto animation = Animation3D::create(fileName);
	if (animation) {
	    //create the Animate3D
	    auto animate = Animate3D::create(animation);
//	    if(std::rand() %3 == 0) {
//	            animate->setPlayBack(true);
//	            int rand2 = std::rand();
//	            if(rand2 % 3 == 1)
//					animate->setSpeed(animate->getSpeed() + CCRANDOM_0_1());
//	            else if(rand2 % 3 == 2)
//	                animate->setSpeed(animate->getSpeed() - 0.5 * CCRANDOM_0_1());
//
//	       //Run Animate
//			sprite3D->runAction(RepeatForever::create(animate));
//	    }
	    sprite3D->runAction(RepeatForever::create(animate));
	}

	// ORC
	std::string fileNameOrc = "orc.c3b";
	auto orc3D = Sprite3D::create(fileNameOrc);
	orc3D->setPosition(Point(origin.x + visibleSize.width/2, origin.y + visibleSize.height*2/5));
	orc3D->setScale(10);
	orc3D->setRotation3D(Vec3(0,180,0));
	addChild(orc3D);
	auto animationOrc = Animation3D::create(fileNameOrc);

	if (animationOrc)
	{
		auto animate = Animate3D::create(animationOrc);
		orc3D->runAction(RepeatForever::create(animate));

//	    auto runAnimate = Animate3D::create(animationOrc, 0, 2);
//	    runAnimate->setSpeed(10);
//	    orc3D->runAction(runAnimate);
//
//	    auto attackAnimate = Animate3D::create(animationOrc, 3, 5);
//	    attackAnimate->setSpeed(10);
//	    orc3D->runAction(attackAnimate);
	}

	// ReskinGirl
	auto sprite = Sprite3D::create("ReskinGirl.c3b");

	// display the first coat
	auto girlTop0 = sprite->getMeshByName("Girl_UpperBody01");
	if(girlTop0)
	{
	    girlTop0->setVisible(true);
	}

	sprite->setPosition(Point(origin.x + visibleSize.width*1/3, origin.y + visibleSize.height/2));
	sprite->setScale(10);
	addChild(sprite);

//	auto mario = Sprite3D::create("IronMan.obj");
//	mario->setPosition(Point(origin.x + visibleSize.width*1/4, origin.y + visibleSize.height/3));
//	addChild(mario);


//	 LIGHTS
//	auto light = AmbientLight::create (Color3B::RED);
//	addChild (light);
//	auto light = DirectionLight::create(Vec3(-1.0f, -1.0f, 0.0f), Color3B::RED);
//	addChild (light);

//	auto light = PointLight::create(Vec3(0.0f, 0.0f, 0.0f), Color3B::BLUE, 10000.0f);
//	addChild (light);

//	auto spotLight = SpotLight::create(Vec3(-1.0f, -1.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f),
//	Color3B::RED, 0.0, 0.5, 10000.0f) ;
//	addChild (spotLight);

//	auto s = Director::getInstance()->getWinSize();
//	Camera* camera = Camera::createPerspective(60, (GLfloat)s.width/s.height, 1, 1000);
//
//	// set parameters for camera
//	camera->setPosition3D(Vec3(0, 100, 100));
//	camera->lookAt(Vec3(0, 0, 0), Vec3(0, 1, 0));

//	addChild(camera); //add camera to the scene



//	auto s = Director::getInstance()->getWinSize();
//	Camera* camera = Camera::createOrthographic(s.width, s.height, 1, 1000);

	return true;
}
