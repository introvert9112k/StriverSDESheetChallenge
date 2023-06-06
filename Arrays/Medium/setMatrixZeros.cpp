#include <bits/stdc++.h>
void setZeros(vector<vector<int>> &matrix)
{  
   int n = matrix.size(),m = matrix[0].size();
   unordered_set<int> rows,columns;
   for(int i = 0; i < n; ++i)
   {
	   for(int j = 0; j < m; ++j)
	   {
          if(matrix[i][j] == 0)
		  {
			  rows.insert(i);
			  columns.insert(j);
		  }
	   }
   }
   for(auto row : rows)
   {
	   for(int j = 0; j<m; ++j)
	     matrix[row][j] = 0;
   }	
   for(auto column : columns)
   {
	   for(int i = 0; i<n; ++i)
	      matrix[i][column] = 0;
   }
} 