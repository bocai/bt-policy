#ifndef POLICY_H
#define POLICY_H
#include "peer.h"

// 本文件实现了bittorrent协议的一些关键算法：

// 每隔10秒计算一次各个peer的上传下载速度
#define COMPUTE_RATE_TIME  10
// 以下结构体存储下载速度最快的4个peer的指针
#define UNCHOKE_COUNT  4
// 每次请求的slice数
#define REQ_SLICE_NUM  5

typedef struct _Unchoke_peers {
	Peer*  unchkpeer[UNCHOKE_COUNT];
	int    count;
	Peer*  optunchkpeer;
} Unchoke_peers;


void init_unchoke_peers();     // 初始化全局变量unchoke_peers


int select_unchoke_peer();     // 选择unchoke peer
int select_optunchoke_peer();  // 从peer队列中选择一个优化非阻塞peer


int compute_rate();            // 计算最近一段时间(10秒)每个peer的上传下载速度
int compute_total_rate();      // 计算总的上传下载速度


int is_seed(Peer *node);       // 判断某个peer是否为种子

// 构造数据请求,为了提高效率一次请求5个slice
int create_req_slice_msg(Peer *node);  

#endif
