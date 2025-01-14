/*
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。
示例 1:
输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:
输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。
*/

//解法一，逢9进1 。那个数就会变成0，如果不是9，那么就+1返回，
// 如果是例如99，999这种情况，原来数组不够用来，需要重新分配一个digitsSize+1的数组
// 数组第一个数是1，其余为0
int* plusOne(int* digits, int digitsSize, int* returnSize){
    for(int i = digitsSize-1; i >= 0; i--)
    {
        if(digits[i] == 9)
            digits[i] = 0;
        else{
            digits[i]++;
            * returnSize = digitsSize;
            return digits;
        }
    }
    //原来数组放不下了
    int *digits1 = (int *)malloc((digitsSize + 1) * sizeof(int));
    memset(digits1, 0, (digitsSize + 1)* sizeof(int));
    digits1[0] = 1;
    * returnSize = digitsSize +1;
    return digits1;
}
// 解法二，用python ，先换成整数。 +1后，在换回数组
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        sum = 0
        for i in range(len(digits)):
            sum = sum * 10 + digits[i]
        sum = sum + 1
        l = []
        for x in str(sum):
            l.append(int(x))
        return l