#include "ac.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../queueSimple/queue.h"
/**
 * 获取一个新的tree树节点
 */
TreeNode *getNewTreeNode() {
	TreeNode * node = (TreeNode *) malloc(sizeof(TreeNode));
	/** ------------------------------初始化下节点的数据------------------- */
	node->parent = NULL; // 父节点初始化为null
	node->fail = NULL; //失败指针初始化未null
	node->isMatch = 0;
	node->childNum = 0;
	// 所有子节点初始化为null
	for (int i = 0; i < 100; i++) {
		node->children[i] = NULL;
	}
	/** 空节点的所有的空间设置未空 */
	memset(node->string, '\0', sizeof(node->string));
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
	TreeNode * current = root;
	//遍历下当前字符串，中英文字符各占用一个节点
	char tmp[4] = {0};
	while (*str != '\0') {
		if (isascii(*str)) {
			str++;
			memcpy(tmp, str, sizeof(char));
		} else {
			memcpy(tmp, str, sizeof(char) * 3);
			str = str + 3;
		}
		//开始处理增加节点,判断下当前字符是否已经在当前节点的子节点中存在
		int numOfChild = getChildNumOfTreeNode(current, tmp);
		if (numOfChild < 1) {
			TreeNode * child = getNewTreeNode();
			strcpy(child->inputchar, tmp);
			child->inputcharId = getIntOfWideChar(getFirstIntOfMultiChar(tmp));
			child->parent = current;
			//如果当前指针的下一个指针是\0,则当前字符节点是匹配节点
			if (*(str+1) == '\0') {
				child->isMatch = 1;
			}
			/** 设置下当前节点代表的字符串 */
			sprintf(child->string, "%s%s", current->string, tmp);
			printf("%s\n", tmp);
			current->children[current->childNum++] = child;
			/** 设置当前节点为之前节点的新字节点 */
			current = child;
		} else {
			current = current->children[numOfChild - 1];
		}
	}
}
/**
 * 广度优先扫描下所有的节点
 */
void bfsScanTreeNode(TreeNode * root) {
	//创建个队列
	Queue * queue = createNewQueue();
	addToQueue(queue, &root, sizeof(TreeNode *));
	TreeNode * current;
	while (1) {
		//从队列里读取下内容
		void * tmp = readFromQueue(queue);
		if (tmp == NULL) {
			printf("%s\n", "jump out");
			break;
		}
		//转换为treeNode
		current = *((TreeNode **) tmp);
		//输出下节点的信息
		if (current->string[0] != '\0') {
			printf("当前节点为:%s\n", current->string);
			printf("当前节点子节点数量:%d\n", current->childNum);
			printf("当前节点字符为:%s\n", current->inputchar);
			printf("当前节点字符对应数字:%d\n", current->inputcharId);
			if (current->isMatch == 1) {
				printf("当前节点是匹配节点\n");
			}
			printf("\n");
		} else {
			printf("当前为root节点\n");
		}
		//将当前节点的字节点打入队列
		if (current->childNum < 1) {
			continue;
		}
		for (int i = 0; i < current->childNum; i++) {
			addToQueue(queue, &(current->children[i]), sizeof(TreeNode *));
		}
	}
}
/**
 * 判断节点是否有含有字符chr的子节点
 */
int isHasCharChildNode(TreeNode * node, char * chr) {
	int len = node->childNum;
	if (len < 1) {
		return 0;
	}
	int n = getFirstIntOfMultiChar(chr);
	for (int i = 0; i < len; i++) {
		if (node->children[i]->inputcharId == n) {
			return 1;
		}
	}
	return 1;
}
/**
 * 获取字符是节点的子节点的第几个
 */
int getChildNumOfTreeNode(TreeNode * node, char * str) {
	int len = node->childNum;
	if (len < 1) {
		return 0;
	}
	int intofchr = getFirstIntOfMultiChar(str);
	for (int i = 0; i < len; i++) {
		if (node->children[i]->inputcharId == intofchr) {
			return ++i;
		}
	}
	return 0;
}
/**
 * 获取宽字节字符对应的数字
 */
int getIntOfWideChar(wchar_t chr) {
	char *tmp = (char *)malloc(sizeof(char) * 20);
	char * tmp1;
	//获取下宽字符对应的16进制字符串
	sprintf(tmp, "%x", chr);
	//转换成10进制
	int res = (int)strtol(tmp, &tmp1, 16);
	free(tmp);
	return res;
}

/**
 * 获取多字节字符的第一个中文或者英文字符对应的十进制的数字
 */
int getFirstIntOfMultiChar(char * chr) {
	//转为宽字节编码
	wchar_t * wstr = (wchar_t *) malloc(sizeof(wchar_t) * 100);
	memset(wstr, L'\0', sizeof(wchar_t) * 100);
	mbstowcs(wstr, chr, sizeof(wchar_t) * 100);
	//转为16进制字符串
	char res[4] = {0};
	while (*wstr != L'\0') {
		sprintf(res, "%x", *wstr);
		break;
	}
	char * tmp;
	int n = (int)strtol(res, &tmp, 16);
	return n;
}

/**
 * 创建失败指针路径
 */
void buildingNodeFailPath(TreeNode * current, TreeNode * root) {
	if (current == root) {
		current->fail = root;
		return;
	}
	// 设置下当前节点的失败指针
//	if (current->string[0] != '\0') {
//		printf("----------------当前处理节点%s----------------\n", current->string);
//	} else {
//		printf("----------------当前处理节点%s-----------------\n", "root");
//	}
	TreeNode * parent = NULL;
	int numChildOfNode;
	while (1) {
		parent = current->parent;
		//如果是二级节点，节点的失败指针为root，避免把自己给标记为失败指针
		if (parent == root) {
			current->fail = root;
			break;
		} else if (parent->fail != NULL
				&& (numChildOfNode = getChildNumOfTreeNode(parent->fail, current->inputchar)) > 0) {
			current->fail = parent->fail->children[numChildOfNode-1];
			break;
		} else if (parent->fail == root) {
			current->fail = root;
			break;
		} else if (parent->fail == NULL) {
			current->fail = root;
			break;
		} else {
			//如果父节点的失败指针的子节点不存在和当前节点字符一样的节点，则找父节点的失败节点的父节点继续找
			parent = parent->fail->parent;
		}
	}
//	if (current->string[0] != '\0' && current->fail->string[0] != '\0') {
//		printf("%s的失败指针是%s\n", current->string, current->fail->string);
//	} else if (current->string[0] != '\0') {
//		printf("%s的失败指针是%s\n", current->string, "root");
//	} else if (current->fail != NULL && current->fail->string[0] != '\0') {
//		printf("%s的失败指针是%s\n", "", current->fail->string);
//	} else {
//		printf("%s的失败指针是%s\n", "", "");
//	}
}
/**
 * 广度优先一层层的遍历所有的节点
 */
void buildingFailPath(TreeNode * root) {
	//创建个队列
	Queue * queue = createNewQueue();
	//root节点打入队列
	addToQueue(queue, &root, sizeof(TreeNode *));
	TreeNode * current;
	while (1) {
		//从队列中读取一条数据
		void * tmp = readFromQueue(queue);
		if (tmp == NULL) {
			break;
		}
		//获取下节点数据
		current = *(TreeNode **) tmp;
		//开始创建当前节点的失败指针
		buildingNodeFailPath(current, root);
		//将当前节点的子节点入下队列
		if (current->childNum < 1) {
			continue;
		}
		for (int i = 0; i < current->childNum; i++) {
			addToQueue(queue, &(current->children[i]), sizeof(TreeNode *));
		}
	}
}

/**
 * 搜索获取匹配的字符串
 */
//void SearchAc(TreeNode * root, char * text) {
//	TreeNode * tmp = root;
//	int len = strlen(text);
//	int i = 0;
//	//循环遍历text的内容
//	int numChildOfNode;
//	while (i < len) {
//		if ((numChildOfNode = getChildNumOfTreeNode(tmp, text[i]))) {
//			tmp = tmp->children[numChildOfNode-1];
//			//是叶子节点，输出匹配的内容
//			if (tmp->isMatch == 1) {
//				printf("匹配到:%s\n", tmp->string);
//			}
//		} else {
//			tmp = tmp->fail;
//		}
//		i++;
//	}
//}
