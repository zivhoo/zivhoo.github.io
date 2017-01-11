//
//  Socket.hpp
//  test
//
//  Created by huxf on 15/12/8.
//
//

#ifndef Socket_hpp
#define Socket_hpp

#include <string>
#include "MessagePacker.h"

class ODSocket;

enum SocketState
{
    SUCCESS,
    FAILED,
    DISCONNECT
};

class SocketDelegate
{
    
public:
    
    virtual void onReceive(std::string body,va_list ap){}
    virtual void onStateChange(SocketState state){}
    
};

class Socket : public MessagePackerDelegate{
    
public:
    
    Socket(SocketDelegate* delegate = NULL);
    ~Socket();
    
    void connect(const char* ip, unsigned short port);
    
    bool send(void *data,...);
    void receive();
    
    void setDelegate(SocketDelegate *delegate = NULL);
    void setMessagePacker(MessagePacker* messagePack);
    
    void onReceivePack(std::string pack,...);
    
protected:
    
    ODSocket        *_socket;
    SocketDelegate  *_delegate;
    MessagePacker   *_packer;
    
    
};

#endif /* Socket_hpp */
