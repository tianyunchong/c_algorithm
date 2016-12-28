#include "ac.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../queueSimple/queue.h"
/**
 * 获取一个新的tree树节点
 */
TreeNode *getNewTreeNode() {
	TreeNode * node = (TreeNode *) malloc(sizeof(TreeNode));
	/** ------------------------------初始化下节点的数据------------------- */
	node->parent = NULL; // 父节点初始化为null
	node->fail = NULL; //失败指针初始化未null
	// 所有子节点初始化为null
	for (int i = 0; i < 100; i++) {
		node->children[i] = NULL;
	}
	/** 空节点的所有的空间设置未空 */
	memset(node->string, '\0', sizeof(node->string) / sizeof(char));
	return node;
}
/**
 * 创建一个tree树
 */
TreeNode * buildTree() {
	TreeNode * root = getNewTreeNode();
	return root;
}

/**
 * 初始化tree树
 */
void fillToTree(TreeNode * root, char * str) {
	int len = strlen(str);
	TreeNode * current;
	current = root;
	/** 遍历填充tree树*/
	for (int i = 0; i < len; i++) {
		/** 当前字符不在当前节点的字节点中 */
		if (current->children[str[i] - 'a'] == NULL) {
			TreeNode * child = getNewTreeNode();
			child->inputchar = str[i];
			child->parent = current;
			/** 设置下当前节点代表的字符串 */
			sprintf(child->string, "%s%c", current->string, child->inputchar);
			current->children[str[i] - 'a'] = child;
			/** 设置当前节点为之前节点的新字节点 */
			current = child;
		} else {
			current = current->children[str[i] - 'a'];
		}
	}
}
/**
 * 创建失败指针路径
 */
void buildingNodeFailPath(TreeNode * current, TreeNode * root) {
	/** 首先处理下当前队列的失败指针 */
	if (current->parent != NULL) {
		if (current->string[0] != '\0') {
				printf("----------------当前处理节点%s----------------\n", current->string);
		} else {
				printf("----------------当前处理节点%s-----------------\n", "root");
		}
		TreeNode * parent = NULL;
		while (1) {
			parent = current->parent;
			if (parent->fail != NULL
					&& parent->fail->children[current->inputchar - 'a'] != NULL) {
				current->fail =
						current->parent->fail->children[current->inputchar - 'a'];
				printf("%s\n", "aaa");
				break;
			} else if (parent->fail == root) {
				current->fail = root;
				printf("%s\n", "bbb");
				break;
			} else if (parent->fail == NULL) {
				current->fail = root;
				printf("%s\n", "ccc");
				break;
			} else {
				printf("%s\n", "ddd");
				parent = parent->fail->parent;
			}
		}
	}
	if (current->string[0] != '\0' && current->fail->string[0] != '\0') {
		printf("%s的失败指针是%s\n", current->string, current->fail->string);
	} else if (current->string[0] != '\0') {
		printf("%s的失败指针是%s\n", current->string, "root");
	} else if (current->fail != NULL && current->fail->string[0] != '\0') {
		printf("%s的失败指针是%s\n", "", current->fail->string);
	} else {
		printf("%s的失败指针是%s\n", "", "");
	}
}
/**
 * 广度优先一层层的遍历所有的节点
 */
void buildingFailPath(TreeNode * root) {
	//创建个队列
	Queue * queue = createNewQueue();
	for (int i = 0; i < 100; i++) {
		if (root->children[i] != NULL) {
			addToQueue(queue, root->children[i], sizeof(*(root->children[i]))/sizeof(TreeNode));
		}
	}
	TreeNode * current;
	void * tmp = (void *)root;
	while (tmp == NULL) {
		//从队列中读取一个tree节点
		tmp = readFromQueue(queue);
		printf("%s\n", "aaaa");
		break;
		//current = (TreeNode *)tmp;
		// 输出下当前节点字符串
		//printf("%s\n", current->string);
		//break;
		//将当前节点的所有子节点入下队列
//		for (int i = 0; i < 100; i++) {
//			if (current->children[i] != NULL) {
//				addToQueue(queue, current->children[i], sizeof(*(current->children[i]))/sizeof(TreeNode));
//			}
//		}
	}
}
