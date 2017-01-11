//
//  MessagePacker.h
//  zivkit
//
//  Created by huxf on 16/1/6.
//  Copyright © 2016年 ziv. All rights reserved.
//

#ifndef MessagePacker_h
#define MessagePacker_h

#include <string>

class MessagePackerDelegate {
    
public:
    
    virtual void onReceivePack(std::string pack,...){}
    
};

class MessagePacker {
    
public:
    
    MessagePacker():_delegate(NULL){}
    
    /**
     *  数据打包
     *
     *  @param result 结果
     *  @param data   消息体
     *  @param args   额外参数
     *
     *  @return 数据包长度
     */
    virtual int pack(std::string &result,void *data,va_list args) = 0;
    
    /**
     * 数据解包
     *
     * @param data 接受到的数据
     * @param size 接受到的数据大小
     */
    virtual void unPack(const char* data, int size) = 0;
    
    void setDelegate(MessagePackerDelegate *delegate)
    {
        _delegate = delegate;
    }
    
protected:
    
    MessagePackerDelegate *_delegate;
    
};

#endif /* MessagePacker_h */
