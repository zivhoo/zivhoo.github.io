#ifndef clown_MessageTypeDefine_h
#define clown_MessageTypeDefine_h

#define CLOWN_GAME_MSG 10000

#define REQ_LOGIN                               (CLOWN_GAME_MSG+1)
#define ACK_LOGIN                               (CLOWN_GAME_MSG+2)


#define REQ_CHIP_IN                             (CLOWN_GAME_MSG + 3)
#define ACK_CHIP_IN_RESULT                      (CLOWN_GAME_MSG + 6)

#define ACK_TIP_MESSAGE                         (CLOWN_GAME_MSG + 8)

#define REQ_CHANGE_USER_DOUBLE_CHANCE           (CLOWN_GAME_MSG + 9)
#define ACK_CHANGE_USER_DOUBLE_CHANCE           (CLOWN_GAME_MSG + 10)


#define ACK_DOUBLE_CHANCE_AWARD                 (CLOWN_GAME_MSG + 12)
#define ACK_LOSE_TWO_MUCH                       (CLOWN_GAME_MSG + 14)

#define REQ_DOUBLE_BET                          (CLOWN_GAME_MSG + 15)
#define ACK_DOUBLE_BET                          (CLOWN_GAME_MSG + 16)

#define ACK_HUGE_AWARD                          (CLOWN_GAME_MSG + 18)

#define ACK_CLOSE_CONNNECTION                   (CLOWN_GAME_MSG + 20)

#define REQ_CHARGE                              (CLOWN_GAME_MSG + 21)
#define ACK_CHARGE                              (CLOWN_GAME_MSG + 22)

#define REQ_OPEN                                (CLOWN_GAME_MSG + 23)
#define ACK_OPEN                                (CLOWN_GAME_MSG + 24)

#define REQ_CLOSE                               (CLOWN_GAME_MSG + 25)
#define ACK_CLOSE                               (CLOWN_GAME_MSG + 26)

#define ACK_SERVER_IN_MAINTAINANCE              (CLOWN_GAME_MSG + 30)

#define ACK_PLAYER_AMOUNT                       (CLOWN_GAME_MSG + 32)
#define ACK_POOL_VALUE                          (CLOWN_GAME_MSG + 34)

#define REQ_RANKING_LIST                        (CLOWN_GAME_MSG + 35)
#define ACK_RANKING_LIST                        (CLOWN_GAME_MSG + 36)

#define REQ_ACTIVITY_AWARD_LIST                 (CLOWN_GAME_MSG + 37)
#define ACK_ACTIVITY_AWARD_LIST                 (CLOWN_GAME_MSG + 38)

#define REQ_AWARDS_HISTORY                      (CLOWN_GAME_MSG + 39)
#define ACK_AWARDS_HISTORY                      (CLOWN_GAME_MSG + 40)

#define REQ_FILL_USERINFO                       (CLOWN_GAME_MSG + 41)
#define ACK_FILL_USERINFO                       (CLOWN_GAME_MSG + 42)

#define ACK_ENTITY_AWARD                        (CLOWN_GAME_MSG + 43)

#define REQ_HANDSEL_AWARDS_HISTORY              (CLOWN_GAME_MSG + 45)
#define ACK_HANDSEL_AWARDS_HISTORY              (CLOWN_GAME_MSG + 46)

#define REQ_DEGRADE                             (CLOWN_GAME_MSG + 58)				//降级
#define ACK_EXPACTIVITYRESULT                   (CLOWN_GAME_MSG + 59)		//活动等级、经验信息
#define ACK_ACTIVITYINFO                        (CLOWN_GAME_MSG + 60)			//活动信息

#define REQ_BOX                                 (CLOWN_GAME_MSG + 61)					//请求礼盒
#define ACK_BOX                                 (CLOWN_GAME_MSG + 62)					//返回礼盒信息

#define ACK_USERMONEY                           (CLOWN_GAME_MSG + 63)				//返回用户现有万能豆
#define ACK_DEGRADEREMAINTIAM                   (CLOWN_GAME_MSG + 64)		//降级剩余时间

#define REQ_MOBLERECHARGE                       (CLOWN_GAME_MSG + 71)
#define ACK_MOBLERECHARGE                       (CLOWN_GAME_MSG + 72)

#define REQ_POP_MOBLERECHARGE                       (CLOWN_GAME_MSG + 73)
#define ACK_POP_MOBLERECHARGE                       (CLOWN_GAME_MSG + 74)

#define REQ_USERMONEY                           (CLOWN_GAME_MSG + 80)

#define SEND_IDLE (CLOWN_GAME_MSG + 75)
//#define GAME_IP "115.182.20.174"  //生产环境

#define GAME_IP "117.121.18.176"     //生产环境 外网
//#define GAME_IP "10.6.2.176"     //

//#define GAME_IP "172.28.14.209"     //测试环境
//#define GAME_IP "172.28.26.138"

//#define GAME_IP "192.168.3.72"      //仿真环境
#define GAME_PORT 7777

#endif
