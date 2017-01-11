#include "HelloWorldScene.h"
#include "ProtobufPacker.h"
#include <iostream>
#include "ClownServerMessage.pb.h"
#include "MessageTypeDefine.h"

USING_NS_CC;
using namespace std;
using namespace com::ourgame::clown::msg;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}

void HelloWorld::onReceive(std::string body,va_list args)
{
    int bodySize = va_arg(args, int);
    int messageId = va_arg(args, int);
    
    AckLogin login;
    login.ParseFromArray(body.data(), bodySize);
    
    GOOGLE_LOG(INFO) << "messageId:" << messageId;
    GOOGLE_LOG(INFO) << "username:"<< login.username();
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Socket *socket = new Socket(this);
    socket->setMessagePacker(new ProtobufPacker());
    
    socket->connect("127.0.0.1", 10001);
    //    socket->connect("172.28.26.21", 10001);
    
    AckLogin login;
    login.set_sessionid(10000);
    login.set_success(1);
    login.set_userid(123);
    
    stringstream str;
    for (int i = 0; i < 10; ++i)
    {
        str << i << "a,";
    }
    
    login.set_username(str.str());
    
    
    for (int i = 0; i < 1; ++i)
    {
        socket->send(&login, ACK_LOGIN);
    }
    
}
