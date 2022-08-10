#include<iostream>
#include<vector>
using namespace std;
#if 0 
// dp solution in O(n)
 vector<int> countBits(int n) {
        vector <int> dp(n+1);
        dp[0]=0;
        int offset = 1;
        for(int i=1 ; i <=n+1; i++)
        {
            if(offset *2 ==i)
            {  //update offset  1,2,4,8,16,32..........
                offset = i;
            }
            dp[i] = 1 + dp[i-offset];
        }
        return dp;
    }
#endif
// below iterative solution in O(nlogn) 
// logn comes here in counting logic by n%2 Any nu can be diveded by 2 for log N times only
vector<int> countBits(int n) {
        vector <int> res(n+1);
        for(int i=0;i<=n;i++)
        {
            //cnt bits of no
            int cnt=0;
            int nu = i;
            while(nu)
            {
                cnt = cnt + nu%2;
                nu = nu/2;
            }
            res[i]=cnt;
        }
        return res;
    }
int main()
{
  vector <int> res = countBits( 8);
  for (int j=0;j<res.size();j++)
  {
    cout<<res[j]<<",";
  }
  res = countBits(1);
  cout<<endl;
  for (int j=0;j<res.size();j++)
  {
    cout<<res[j]<<",";
  }
  cout<<endl;
  res = countBits(5);
  for (int j=0;j<res.size();j++)
  {
    cout<<res[j]<<",";
  }
}
