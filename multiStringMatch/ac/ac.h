#ifndef _AC_H_
#define _AC_H_
/** 定义节点对象 */
typedef struct _TreeNode {
	struct _TreeNode *children[100];//子节点
	struct _TreeNode *parent;//父节点
	struct _TreeNode *fail;//失败指针
	char inputchar;//当前节点的字符
	char string[1000];//当前节点的字符串
} TreeNode;
TreeNode * buildTree();
void fillToTree(TreeNode * root, char * str);
void buildingFailPath(TreeNode * root) ;
#endif
