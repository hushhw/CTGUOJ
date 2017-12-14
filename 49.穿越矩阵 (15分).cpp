// 5.穿越矩阵 (15分)
// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
// 	题目内容：
// 	现在有一个 m * n 的整数矩阵，请你编写一个程序计算出一条从左到右穿过矩阵的路径，并使此路径的费用最小。路径从矩阵的左侧的第一列的任意单元格开始，逐步穿过矩阵到达最右侧的一列的任意单元格。每一步是指从某单元格进入它一列的相邻单元格（如下图，可以是横向或斜向）。矩阵的第一行和最后一行实际是相邻的，你可以想象矩阵是包裹在一个横放的圆柱体外面（这点很重要）。 
// 	路径的花费是指这条路径所穿越的所有单元格中的数字之和。
// 	输入描述
// 	输入包括一系列矩阵描述。每个矩阵描述的第一行是 m 和 n，即矩阵的行数和列数；之后的 m 行，每行包括 n 个以空格分开的整数，则是当前矩阵的值，注意矩阵的值未必是正数。 
// 	矩阵的行数 m 和列数 n 的范围是：1 <=m<=10、 1<=n<=100；所有路径的费用值都可以用 30bit 的整数表示。
// 
// 	输出描述
// 	针对每一个矩阵，找出费用最小的路径，并将其输出。每个矩阵的输出包括两行，第一行是路径本身，即输出每一步所在的行，第二行则是该路径的费用。 
// 	如果对于同一个矩阵有多条不同的费用最小路径，则输出左端行号较小的一条。
// 
// 	输入样例
// 	5 6
// 	3 4 1 2 8 6
// 	6 1 8 2 7 4
// 	5 9 3 9 9 5
// 	8 4 1 3 2 6
// 	3 7 2 1 2 3
// 
// 	输出样例
// 	1 2 1 5 4 5
// 	11
