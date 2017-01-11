//
//  Socket.cpp
//  zivkit
//
//  Created by huxf on 15/12/11.
//  Copyright © 2015年 ziv. All rights reserved.
//
#include <thread>
#include <assert.h>  
#include "Socket.h"
#include "ODSocket.h"
#include "MessagePacker.h"

using namespace std;

#define DELEGATE if (_delegate) _delegate
#define RECEIVE_DATA_SIZE 512

Socket::Socket(SocketDelegate *delegate):
_delegate(delegate)
{
    _socket = new ODSocket;
    _socket->Init();
    _socket->Create(AF_INET, SOCK_STREAM, 0);
}

Socket::~Socket()
{
    delete _socket;
    _socket         = NULL;
    _delegate       = NULL;
    _packer         = NULL;
}

void Socket::connect(const char* ip, unsigned short port)
{
    assert( NULL != _packer);
    
    bool result = _socket->Connect(ip, port);
    if (result)
    {
        // 开启新线程，在子线程中，接收数据
        std::thread recvThread = std::thread(&Socket::receive, this);
        recvThread.detach(); // 从主线程分离
    }

    DELEGATE->onStateChange(result? SUCCESS: FAILED);
}

bool Socket::send(void *data,...)
{
    va_list ap;
    va_start(ap, data);
    string result("");
    int len = _packer->pack(result,data,ap);
    va_end(ap);
    
    return _socket->Send(result.c_str(), len) > 0;
}

void Socket::receive()
{
    // 因为是强联网
    // 所以可以一直检测服务端是否有数据传来
    while (true) {
        // 接收数据 Recv
        char data[RECEIVE_DATA_SIZE] = "";
        int len = _socket->Recv(data, RECEIVE_DATA_SIZE, 0);
        
        // 与服务器的连接断开了
        if (len <= 0)
        {
            DELEGATE->onStateChange(DISCONNECT);
            break;
        }
        
        _packer->unPack(data, len);
    }
    // 关闭连接
    _socket->Close();
}

void Socket::onReceivePack(std::string pack,...)
{
    if (_delegate) {
        va_list ap;
        va_start(ap, pack);
        _delegate->onReceive(pack,ap);
        va_end(ap);
    }
}

void Socket::setDelegate(SocketDelegate *delegate)
{
    _delegate = delegate;
}

void Socket::setMessagePacker(MessagePacker* packer)
{
    packer->setDelegate(this);
    _packer = packer;
}

#undef DELEGATE
