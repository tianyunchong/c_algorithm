#ifndef _AC_H_
#define _AC_H_
#include <stdio.h>
#include <stdlib.h>
/** 定义节点对象 */
typedef struct _TreeNode {
	int childNum;//当前节点拥有的字节点数量
	struct _TreeNode *children[100];//子节点
	struct _TreeNode *parent;//父节点
	struct _TreeNode *fail;//失败指针
	char inputchar[4];//当前节点的字符
	int inputcharId;//当前节点字符对应的数字
	char string[1000];//当前节点的字符串
	int isMatch;//是否为匹配节点
} TreeNode;
TreeNode * buildTree();
void fillToTree(TreeNode * root, char * str);
void buildingFailPath(TreeNode * root) ;
void SearchAc(TreeNode * root, char * text);
int isHasCharChildNode(TreeNode * node, char * chr);
int getIntOfWideChar(wchar_t chr);
int getChildNumOfTreeNode(TreeNode * node, char * str);
int getFirstIntOfMultiChar(char * chr);
void bfsScanTreeNode(TreeNode * root);
#endif
