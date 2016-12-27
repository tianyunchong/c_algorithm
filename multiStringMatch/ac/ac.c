#include "ac.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 获取一个新的tree树节点
 */
TreeNode *getNewTreeNode() {
	TreeNode * node = (TreeNode *)malloc(sizeof(TreeNode));
	/** ------------------------------初始化下节点的数据------------------- */
	node->parent = NULL;// 父节点初始化为null
	// 所有子节点初始化为null
	for (int i= 0;i<100;i++) {
		node->children[i] = NULL;
	}
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
			current->children[str[i] - 'a'] = child;
			/** 设置当前节点为之前节点的新字节点 */
			current = child;
		} else {
			current = current->children[str[i] - 'a'];
		}
	}
}
