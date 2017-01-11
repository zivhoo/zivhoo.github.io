#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Socket.h"

class HelloWorld : public cocos2d::Layer,public SocketDelegate
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    virtual void onReceive(std::string body,va_list args);
//    virtual void onStateChange(MessageState state);
};

#endif // __HELLOWORLD_SCENE_H__
