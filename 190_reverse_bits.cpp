#include <iostream>
using namespace std;

uint32_t reverseBits(uint32_t n) {
        uint32_t rightMask = 1; ///int rightMask = 1; this was a problem as -ve no shifting undefined
        uint32_t res = 0 ;
        int len = sizeof(int) *8;
        for(int i =0;i<len;i++)
        {
            if(n&rightMask)
            { // set leftMost bit in result
              res = res | 1<<(31-i);
            }
            rightMask = rightMask<<1;            
        }
        return res;
    }
int main()
{  //00000010100101000001111010011100
    uint32_t k = reverseBits(43261596);

    cout<<k<<endl;
}

#if 0 
// not sure why this code has an issue. 
uint32_t reverseBits(uint32_t n) {
        int rightMask = 1;
        int leftMask = 1<<31;
        uint32_t res = 0 ;
        int len = sizeof(int) *4;
        for(int i =0;i<len;i++)
        {
            if(n&leftMask)
            { // set rightmost bit in result
                 res = res | 1<<i;
            }
            if(n&rightMask)
            { // set leftMost bit in result
              res = res | 1<<(31-i);
            }
            rightMask = rightMask<<1;
            leftMask = leftMask>>1;
        }
        return res;
    }

    #endif
