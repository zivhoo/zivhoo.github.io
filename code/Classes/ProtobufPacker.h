//
//  ProtobufPacker.hpp
//  protobuf
//
//  Created by huxf on 16/1/6.
//
//

#ifndef ProtobufPacker_hpp
#define ProtobufPacker_hpp

#include "MessagePacker.h"

class ProtobufPacker : public MessagePacker {
    
    typedef struct
    {
        int messageID;
        int bodySize;
    }MessageHeader;
    
public:
    
    ProtobufPacker();
    
    virtual int pack(std::string &result,void *data,va_list args);
    virtual void unPack(const char* data, int size);
    
    void HandleMessage(MessageHeader* header);
    
protected:

    std::string _receiveData;//接受到的数据
    int         _receiveSize;//数据的长度
    
};

#endif /* ProtobufPacker_hpp */
