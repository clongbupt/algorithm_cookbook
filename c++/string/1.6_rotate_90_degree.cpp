/**
 * 二维数组的表示法 第二维要带上确定范围
 *
 * 返回值问题  对于传入的二维数组修改情况如何判断
 *
 * 矩阵的逆时针旋转90度  : 先做镜面旋转   再做水平对称旋转
 *
 * 镜面旋转 : a[i][j], a[j][i]
 * 水平对称旋转 : a[i][j], a[n-i-1][j]
 * 垂直对称旋转 : a[i][j], a[i][n-j-1]
 *
 */

#define MAXN 100
int ** rotate_90_degree(int matrix[][MAXN], int n){

	int tmp;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			tmp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = tmp;
		}

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			tmp = matrix[i][j];
			matrix[i][j] = matrix[n-1-i][j];
			matrix[n-1-i][j] = tmp;
		}

	return matrix;

}