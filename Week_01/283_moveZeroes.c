// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
// 示例:
// 输入: [0,1,0,3,12]
// 输出: [1,3,12,0,0]
// 说明:
// 必须在原数组上操作，不能拷贝额外的数组。
// 尽量减少操作次数。
void moveZeroes(int* nums, int numsSize){
    //快慢指针
    // 慢指针i记录非0数，快指针j 遍历，
    // 最后补0
    if( numsSize == 0)
        return NULL;
    int i =0;
    for(int j =0 ; j < numsSize; j++){
        if(nums[j] != 0)
        {
            nums[i] = nums[j];
            i++;
        }
    }
    for(int t = i; t <  numsSize; t++)
        nums[t] = 0;
}
//解法二： 遇见非0数就交换位置
void moveZeroes(int* nums, int numsSize){
     int i = 0;
    for(int j =0 ;j < numsSize; j++){
        if(nums[j] != 0){
            int tmp = nums[j];
            nums[j] = nums[i];
            nums[i++] = tmp;
        }
    }
}