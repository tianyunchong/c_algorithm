#include <stdio.h>
#include "multiStringMatch/ac/ac.h"
int main() {
	/** 测试ac自动机算法使用 */
	TreeNode * root = buildTree();
	/** 填充tree树 */
	fillToTree(root, "agced");
	fillToTree(root, "abc");
	fillToTree(root, "xyz");

	return 1;
}
