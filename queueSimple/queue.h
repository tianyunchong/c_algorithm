#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdlib.h>
/**
 * 队列节点类型
 */
typedef struct _QueueNode {
	struct _QueueNode  * prex;//当前队列节点的前一个节点
	struct _QueueNode  * next;//当前队列节点的 后一个节点
	void * content;//节点的数据
} QueueNode;
/**
 * 队列类型
 */
typedef struct _Queue {
	int len; //队列长度
	QueueNode * start;//队列的开始节点
	QueueNode * end;//队列的终点节点
} Queue;
Queue * createNewQueue() ;
void addToQueue(Queue * queue, void * content, size_t len);
void * readFromQueue(Queue * queue);
#endif
