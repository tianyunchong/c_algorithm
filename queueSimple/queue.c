#include "../queueSimple/queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 创建一个新的队列
 */
Queue * createNewQueue() {
	Queue * queue = (Queue *)malloc(sizeof(Queue));
	/** 设置下开始节点和终点节点 */
	queue->start = NULL;
	queue->end   = NULL;
	queue->len   = 0;
	return queue;
}
/**
 * 增加一个数据到队列
 */
void addToQueue(Queue * queue, void * content, size_t len) {
	//创建一个节点 */
	QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
	node->content = (void *)malloc(sizeof(size_t) * len);
	//将传入的数据内容拷贝到节点content中
	memcpy(node->content, content, len);
	node->prex = NULL;
	node->next = NULL;
	//开始将当前节点加入队列中
	if (queue->end != NULL) {
		node->prex = queue->end;
		queue->end->next = node;
		queue->len++;
		queue->end = node;
	} else {
		queue->start = node;
		queue->end   = node;
		queue->len++;
	}
}
/**
 * 从队列里读取内容
 */
void * readFromQueue(Queue * queue) {
	if (queue->start == NULL) {
		return NULL;
	}
	QueueNode * read = queue->start;
	//队列里就剩下最后一个节点数据
	if (read->next == NULL) {
		queue->start = NULL;
		queue->end   = NULL;
	} else {
		queue->start = read->next;
	}
	queue->len--;
	void * content = read->content;
	free(read);
	return content;
}
