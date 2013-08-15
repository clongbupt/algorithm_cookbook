/**
 * 用两个数组分别表示行列可以节省空间
 * 
 * 此题很简单  但注意别陷入深搜、广搜的坑中
 *
 */
int ** set_entire_zero (int **matrix, int n, int m){
	if (matrix == NULL || n == 0 || m == 0)
		return NULL;

	bool visit_row[n];
	bool visit_col[m];

	memset(visit_row,0,sizeof(visit_row));
	memset(visit_col,0,sizeof(visit_col)); 

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			if(matrix[i][j] == 0)
				visit_row[i] = 1;
				visit_col[j] = 1;
		}

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(visit_row[i] == 1 || visit_col[j] == 1){
				matrix[i][j] = 0;
			}
	return matrix;
}