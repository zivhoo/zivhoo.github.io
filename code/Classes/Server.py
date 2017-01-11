#!/usr/local/bin/python

#coding=UTF-8

import socket
import threading
import struct
import ClownServerMessage_pb2

class Packer(object):

    __receiveData = ""
    __headSize = 0
    __fmt = "ii"
    
    def __init__(self):
        super(Packer, self).__init__()

        self.__headSize = struct.calcsize(self.__fmt)
        self.__structObject = struct.Struct(self.__fmt);

    def pack(self):
        pass

    def unPack(self,pack):

        self.__receiveData += pack

        packSize = len(self.__receiveData)

        if packSize < self.__headSize:
            return

        head =  self.__structObject.unpack(self.__receiveData[:self.__headSize])

        totalSize = head[1] + self.__headSize
        print "unpack " + "True" if packSize >= totalSize else "False"
        while packSize >= totalSize:

            login = ClownServerMessage_pb2.AckLogin()
            login.ParseFromString(self.__receiveData[self.__headSize: totalSize])

            print "userName:" + login.username + "\n"
            print "userId:" + str(login.userId) + "\n"
            print "sessionId:" + str(login.sessionId) + "\n"
            print "ratio:" + str(login.ratio) + "\n"

            self.__receiveData = self.__receiveData[totalSize:]

            packSize = len(self.__receiveData)
            if packSize < self.__headSize:
                break
            else:
                head =  self.__structObject.unpack(self.__receiveData[:self.__headSize])
                totalSize = head[1] + self.__headSize


def startServer():
    server = socket.socket()
    server.bind(("127.0.0.1",10001))
    server.listen(5)

    packer = Packer()

    while True:
        connect,address = server.accept()

        while True:

            pack = connect.recv(10)
            packer.unPack(pack)



    server.close()


if "__main__" == __name__:
    startServer()

    # print struct.calcsize("ii");