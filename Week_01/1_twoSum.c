// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
// 示例:
// 给定 nums = [2, 7, 11, 15], target = 9
// 因为 nums[0] + nums[1] = 2 + 7 = 9
// 所以返回 [0, 1]

//暴力求解，
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    if( numsSize == 0)
        return 0;
    int value = 0;
    int *ret = (int *)malloc(2 * sizeof(int));
    for(int i = 0; i< numsSize-1; i++)
    {
        value = target - nums[i];
        for(int j = i + 1 ; j< numsSize; j++ )
        {
            if(nums[j] == value)
            {
                ret[0] = i;
                ret[1] = j;
                *returnSize =2;
            }
        }
    }
    return ret;
//方法2 字典 python实现
// 利用字典存储值(target-nums[i], 下标 i)
// nums = [2,7, 11,15] target = 9
//dic = {7:0, 2:1, -2:2, -6:3}
// 在遍历时，在dic找到与nums[i] 相同的值，
// 返回的时dic值nums[i]对应的value值和 nums[i]的下标 i
def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dic = {}
        for i in range(len(nums)):
            value = target - nums[i]
            if nums[i] in dic:
                return [dic[nums[i]],i]
            else:
                dic[value] = i
