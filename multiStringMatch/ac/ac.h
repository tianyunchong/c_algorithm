#ifndef _AC_H_
#define _AC_H_
/** 定义节点对象 */
typedef struct _TreeNode {
	struct TreeNode *children[100];//子节点
	struct TreeNode *parent;//父节点
	char inputchar;//当前节点的字符
} TreeNode;
TreeNode * buildTree();
void fillToTree(TreeNode * root, char * str);
#endif
