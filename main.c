#include <stdio.h>
#include "multiStringMatch/ac/ac.h"
#include <string.h>
#include <locale.h>
#include <ctype.h>


int main() {
	setlocale(LC_ALL, "");
	/** 测试ac自动机算法使用 */
	TreeNode * root = buildTree();
	char pattern[][30]={"bcc虽然", "nihao","hao","hs","hsr", "hsn", "但是"};
	/** 填充tree树 */
	for(int i= 0;i<5;i++) {
		fillToTree(root, pattern[i]);
	}
//	//广度优先扫描下所有节点
//	//bfsScanTreeNode(root);
//	//建立下失败指针路径
//	buildingFailPath(root);
//	//开始搜索字符串
//	char * text = "hsttp://www.baidu.comggghaobanixianggansha";
//	SearchAc(root, text);
	return 1;
}
