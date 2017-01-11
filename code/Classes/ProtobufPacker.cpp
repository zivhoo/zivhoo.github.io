//
//  ProtobufPacker.cpp
//  protobuf
//
//  Created by huxf on 16/1/6.
//
//

#include "ProtobufPacker.h"
#include "google/protobuf/message_lite.h"
#include "ClownServerMessage.pb.h"

using namespace google::protobuf;

ProtobufPacker::ProtobufPacker():
_receiveSize(0)
{
    _receiveData.clear();
}

int ProtobufPacker::pack(std::string &result,void *data,va_list args)
{
    MessageLite *message = ((MessageLite*)data);
    
    int headSize    = sizeof(MessageHeader);
    int bodySize    = message->ByteSize();
    int totalSize   = headSize + bodySize;
    
    /**
     * 创建数据包内存块，用来存储消息头和消息体
     * 待填充完消息头和消息体后将这块数据发送给服务器。
     */
    char *pack = (char*)malloc(totalSize);
    
    /**
     * 1.创建消息头
     * 2.填充消息头数据到pack
     */
    int messageId = va_arg(args, int);
    MessageHeader header = { messageId, bodySize };
    memcpy(pack, &header, headSize);
    
    /**
     *  1.移动指针到存储数据体的位置
     *  2.填充消息体数据到pack
     */
    void *packBody = pack + headSize;
    message->SerializeToArray(packBody, bodySize);
    
    result.append(pack, totalSize);
    
    free(pack);
    
    return totalSize;
}

void ProtobufPacker::unPack(const char* data, int size)
{
    /* 本次接收到的数据拼接到上次数据 */
    _receiveData.append(data, size);
    _receiveSize += size;
    
    /* 强制转换成MessageHeader指针 */
    MessageHeader* header = (MessageHeader*)_receiveData.data();
    
    /**
     * 1.把完整的数据包交给上层处理
     * 2.重新设置数据包内容及其长度
     */
    int packSize = 0;
    int headSize = sizeof(MessageHeader);
    int bodySize = htonl(header->bodySize);
    
    /**
     * 1.判断消息头是否接收完整
     * 2.判断消息头和消息体是否都接收完整
     *
     * 按理说 有了条件2，条件1就可以省略了；其实不然，因为在消息头还未接收完整的情况下，
     * header所指向的内存是什么样的数据都有可能；这样header->bodySize可能就是一个负数，
     * 如果bodySize是一个负数第二个条件就有可能成立，这样就不能识别消息是否完成接收了！
     * 所以条件1必不可少
     */
    while ( _receiveSize > headSize && _receiveSize >= (bodySize + headSize) )
    {
        //处理完整的消息
        HandleMessage(header);
        
        //完整的消息大小
        packSize = headSize + bodySize;
        //减去处理过的消息长度
        _receiveSize -= packSize;
        
        //删除处理过的消息字符
        string::iterator begin  = _receiveData.begin();
        string::iterator end    = begin + packSize;
        _receiveData.erase(begin, end);
        
        //设置下条消息头及其消息体大小
        header = (MessageHeader*)_receiveData.data();
        bodySize = htonl(header->bodySize);
    }
}

void ProtobufPacker::HandleMessage(MessageHeader* header)
{
    char *body      = ((char*)header) + sizeof(MessageHeader);
    
    int bodySize    = htonl(header->bodySize);
    int messageID   = htonl(header->messageID);
    
//    com::ourgame::clown::msg::AckLogin login;
//    login.ParseFromArray(body, bodySize);
//    
//    if (!login.username().empty())
//    {
//        GOOGLE_LOG(INFO) << login.username();
//    }
    if (_delegate)
    {
        string message(body,bodySize);
        _delegate->onReceivePack(message,bodySize,messageID);
    }
    
}