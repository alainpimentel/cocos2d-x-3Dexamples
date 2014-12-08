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

	createMenu();

	// Turtle
	std::string fileName = "tortoise.c3b";
	sprite = Sprite3D::create(fileName);
	sprite->setPosition(Point(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
	sprite->setRotation3D(Vec3(0,45,0));
	addChild(sprite);

//	//Create animation3D by the same file of its Spirte3D
//	auto animation = Animation3D::create(fileName);
//	if (animation) {
//	    //create the Animate3D
//	    auto animate = Animate3D::create(animation);
////	    if(std::rand() %3 == 0) {
////	            animate->setPlayBack(true);
////	            int rand2 = std::rand();
////	            if(rand2 % 3 == 1)
////					animate->setSpeed(animate->getSpeed() + CCRANDOM_0_1());
////	            else if(rand2 % 3 == 2)
////	                animate->setSpeed(animate->getSpeed() - 0.5 * CCRANDOM_0_1());
////
////	       //Run Animate
////			sprite3D->runAction(RepeatForever::create(animate));
////	    }
//	    sprite3D->runAction(RepeatForever::create(animate));
//	}
//
//	// ORC
//	std::string fileNameOrc = "orc.c3b";
//	auto orc3D = Sprite3D::create(fileNameOrc);
//	orc3D->setPosition(Point(origin.x + visibleSize.width/2, origin.y + visibleSize.height*2/5));
//	orc3D->setScale(10);
//	orc3D->setRotation3D(Vec3(0,180,0));
//	addChild(orc3D);
//	auto animationOrc = Animation3D::create(fileNameOrc);
//
//	if (animationOrc)
//	{
//		auto animate = Animate3D::create(animationOrc);
//		orc3D->runAction(RepeatForever::create(animate));
//
////	    auto runAnimate = Animate3D::create(animationOrc, 0, 2);
////	    runAnimate->setSpeed(10);
////	    orc3D->runAction(runAnimate);
////
////	    auto attackAnimate = Animate3D::create(animationOrc, 3, 5);
////	    attackAnimate->setSpeed(10);
////	    orc3D->runAction(attackAnimate);
//	}
//
//	// ReskinGirl
//	auto sprite = Sprite3D::create("ReskinGirl.c3b");
//
//	// display the first coat
//	auto girlTop0 = sprite->getMeshByName("Girl_UpperBody01");
//	if(girlTop0)
//	{
//	    girlTop0->setVisible(true);
//	}
//
//	sprite->setPosition(Point(origin.x + visibleSize.width*1/3, origin.y + visibleSize.height/2));
//	sprite->setScale(10);
//	addChild(sprite);
//
////	auto mario = Sprite3D::create("IronMan.obj");
////	mario->setPosition(Point(origin.x + visibleSize.width*1/4, origin.y + visibleSize.height/3));
////	addChild(mario);
//
//
////	 LIGHTS
////	auto light = AmbientLight::create (Color3B::RED);
////	addChild (light);
////	auto light = DirectionLight::create(Vec3(-1.0f, -1.0f, 0.0f), Color3B::RED);
////	addChild (light);
//
////	auto light = PointLight::create(Vec3(0.0f, 0.0f, 0.0f), Color3B::BLUE, 10000.0f);
////	addChild (light);
//
////	auto spotLight = SpotLight::create(Vec3(-1.0f, -1.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f),
////	Color3B::RED, 0.0, 0.5, 10000.0f) ;
////	addChild (spotLight);
//
////	auto s = Director::getInstance()->getWinSize();
////	Camera* camera = Camera::createPerspective(60, (GLfloat)s.width/s.height, 1, 1000);
////
////	// set parameters for camera
////	camera->setPosition3D(Vec3(0, 100, 100));
////	camera->lookAt(Vec3(0, 0, 0), Vec3(0, 1, 0));
//
////	addChild(camera); //add camera to the scene
//
//
//
////	auto s = Director::getInstance()->getWinSize();
////	Camera* camera = Camera::createOrthographic(s.width, s.height, 1, 1000);

	// Single Touches
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(Examples3d::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(Examples3d::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(Examples3d::onTouchEnded, this);
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;
}

void Examples3d::createMenu()
{
	auto width = 450;
	auto fontSize = 47.5f;
	lbl_sprite = LabelTTF::create(
			"Sprite",
			"fonts/Marker Felt.ttf",
			fontSize,
			Size(width, 0),
			TextHAlignment::LEFT);
	lbl_sprite->setColor(Color3B(0, 0, 0));
	lbl_sprite->setPosition( origin.x + lbl_sprite->getContentSize().width/1.9,
			origin.y + visibleSize.height*7/8);
	addChild(lbl_sprite);

	lbl_animation = LabelTTF::create(
			"Animation Off",
			"fonts/Marker Felt.ttf",
			fontSize,
			Size(width, 0),
			TextHAlignment::LEFT);
	lbl_animation->setColor(Color3B(0, 0, 0));
	lbl_animation->setPosition( origin.x + lbl_animation->getContentSize().width/1.9,
			origin.y + visibleSize.height*6/8);
	addChild(lbl_animation);

	lbl_light_ambient = LabelTTF::create(
			"Ambient Light Off",
			"fonts/Marker Felt.ttf",
			fontSize,
			Size(width, 0),
			TextHAlignment::LEFT);
	lbl_light_ambient->setColor(Color3B(0, 0, 0));
	lbl_light_ambient->setPosition( origin.x + lbl_light_ambient->getContentSize().width/1.9,
			origin.y + visibleSize.height*5/8);
	addChild(lbl_light_ambient);

	lbl_light_directional = LabelTTF::create(
			"Directional Light Off",
			"fonts/Marker Felt.ttf",
			fontSize,
			Size(width, 0),
			TextHAlignment::LEFT);
	lbl_light_directional->setColor(Color3B(0, 0, 0));
	lbl_light_directional->setPosition( origin.x + lbl_light_directional->getContentSize().width/1.9,
			origin.y + visibleSize.height*4/8);
	addChild(lbl_light_directional);

	lbl_light_point = LabelTTF::create(
			"Point Light Off",
			"fonts/Marker Felt.ttf",
			fontSize,
			Size(width, 0),
			TextHAlignment::LEFT);
	lbl_light_point->setColor(Color3B(0, 0, 0));
	lbl_light_point->setPosition( origin.x + lbl_light_point->getContentSize().width/1.9,
			origin.y + visibleSize.height*3/8);
	addChild(lbl_light_point);

	lbl_light_spot = LabelTTF::create(
			"Spot Light Off",
			"fonts/Marker Felt.ttf",
			fontSize,
			Size(width, 0),
			TextHAlignment::LEFT);
	lbl_light_spot->setColor(Color3B(0, 0, 0));
	lbl_light_spot->setPosition( origin.x + lbl_light_spot->getContentSize().width/1.9,
			origin.y + visibleSize.height*2/8);
	addChild(lbl_light_spot);

	for (int i = 0; i < 5; i++)
		labels_bits.push_back(0);
}

bool Examples3d::onTouchBegan(Touch *touch, Event *unused_event)
{
	return true;
}
void Examples3d::onTouchMoved(Touch *touch, Event *unused_event)
{

}
void Examples3d::onTouchEnded(Touch *touch, Event *unused_event)
{
	auto touchLocation = touch->getLocation();
	//========== Sprite Label ==========
	bool touchingSpriteLbl = this->lbl_sprite->getBoundingBox().containsPoint(touchLocation);
	if(touchingSpriteLbl) {
//		lbl_sprite->setString("Sprite ON");
	}
	bool touchingAnimLbl = this->lbl_animation->getBoundingBox().containsPoint(touchLocation);
	if(touchingAnimLbl) {
		if(!labels_bits.at(0)) {
			lbl_animation->setString("Animation ON");
			labels_bits.at(0) = 1;
		}
		else {
			lbl_animation->setString("Animation OFF");
			labels_bits.at(0) = 0;
		}
	}
	bool touchingAmbLtLbl = this->lbl_light_ambient->getBoundingBox().containsPoint(touchLocation);
	if(touchingAmbLtLbl) {
		if(!labels_bits.at(1)) {
			lbl_light_ambient->setString("Ambient Light ON");
			labels_bits.at(1) = 1;
		}
		else {
			lbl_light_ambient->setString("Ambient Light OFF");
			labels_bits.at(1) = 0;
		}
	}
	bool touchingDirLtLbl = this->lbl_light_directional->getBoundingBox().containsPoint(touchLocation);
	if(touchingDirLtLbl) {
		if(!labels_bits.at(2)) {
			lbl_light_directional->setString("Directional Light ON");
			labels_bits.at(2) = 1;
		}
		else {
			lbl_light_directional->setString("Directional Light OFF");
			labels_bits.at(2) = 0;
		}
	}
	bool touchingPtLtLbl = this->lbl_light_point->getBoundingBox().containsPoint(touchLocation);
	if(touchingPtLtLbl) {
		if(!labels_bits.at(3)) {
			lbl_light_point->setString("Point Light ON");
			labels_bits.at(3) = 1;
		}
		else {
			lbl_light_point->setString("Point Light OFF");
			labels_bits.at(3) = 0;
		}
	}
	bool touchingStLtLbl = this->lbl_light_spot->getBoundingBox().containsPoint(touchLocation);
	if(touchingStLtLbl) {
		if(!labels_bits.at(4)) {
			lbl_light_spot->setString("Spot Light ON");
			labels_bits.at(4) = 1;
		}
		else {
			lbl_light_spot->setString("Spot Light OFF");
			labels_bits.at(4) = 0;
		}
	}
}
