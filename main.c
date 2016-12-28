#include <stdio.h>
#include "multiStringMatch/ac/ac.h"
#include <string.h>
int main() {
	/** 测试ac自动机算法使用 */
	TreeNode * root = buildTree();
	char pattern[][30]={"nihao","hao","hs","hsr", "hsn"};
	/** 填充tree树 */
	for(int i= 0;i<5;i++) {
		fillToTree(root, pattern[i]);
	}
	//建立下失败指针路径
	buildingFailPath(root);
	return 1;
}
