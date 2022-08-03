#if 1
#include<iostream>
#include<vector>
using namespace std;

int binarySearchRow(vector<vector<int>> & matrix,int row,int col, int target )
{
    int low= 0 ;
    int high = row-1;
    while (low <= high)
    {
          int mid = low + (high-low)/2;
          if( matrix[mid][0] <= target && target <= matrix[mid][col-1])
            return mid;
          else
          {
            if(matrix[mid][0] > target)
               high = mid-1;  
            else
                   low = mid+1;       
          }
    }
    return -1;
}
bool binarySearchCol(vector<int>arr,int low,int high, int target )
{
    while (low <= high)
    {
          int mid = low + (high-low)/2;
          if( arr[mid] == target )
            return true;
          else
          {
            if(arr[mid] > target)
               high = mid-1;  
            else
                   low = mid+1;       
          }
    }
    return false;
}
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        // find row
        int searchRow = binarySearchRow(matrix,row,col , target );
#ifdef WIN32
        cout<<"searchRow "<<searchRow<<endl;
#endif
      if(searchRow<0) //initially i forgot to add this case
       return false;
        bool result = binarySearchCol(matrix[searchRow], 0 , col-1, target );
#ifdef WIN32
        if (result)
          cout<<"target  "<<target<< " found"<<endl;
          else 
          cout<<"target  "<<target<< "  Not found"<<endl;
#endif
        return result;
    }
int main()
{
    vector<vector<int>> vect
    {   {1, 3,5,7}, 
        {10,11,16,20}, 
        {23,30,34,60} 
    };
    //searchMatrix(vect,7);
    //searchMatrix(vect,16);
    //searchMatrix(vect,23);
     //searchMatrix(vect,28);

      vector<vector<int>> vect1
    {   {10} 
    };
     searchMatrix(vect1,7);
    return 0;
}
#endif