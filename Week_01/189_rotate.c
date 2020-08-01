/*给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
示例 1:
输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:
输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:
尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的 原地 算法。*/
// 解法一：暴力求解：
void rotate(int* nums, int numsSize, int k){
    暴力求解
    for(int i = 0 ; i < k ; i++){
        //每次第一个值都是数组最后额值，
        int pre = nums[numsSize - 1];
        for(int j= 0; j < numsSize; j++){
            //记录现在的值，先前的值放到的现在的这个位置，这个位置的值就成了先前的值。
            int tmp = nums[j];
            nums[j] = pre;
            pre = tmp;
        }
    }
}
// 解法二：添加一个新数组，新数组记录旋转后的值，再复制到原来的数组
void rotate(int* nums, int numsSize, int k){
    k = k % numsSize;
    int * nums1 = (int *) malloc(numsSize * sizeof(numsSize));
    for(int i = 0; i < numsSize; i++){
        nums1[(i + k ) % numsSize] = nums[i];
    }
    for(int i =0 ; i < numsSize; i++)
        nums[i] = nums1[i];
    free(nums1);
}
//解法3 环状循环
void rotate(int* nums, int numsSize, int k){
    k = k % numsSize;
    int count = 0; 
    for(int start = 0 ; count < numsSize; start++){
        int current = start;
        int pre = nums[start];
        do{
            int next = (current + k ) % numsSize;
            int tmp = nums[next];
            nums[next] = pre;
            pre = tmp;
            current = next;
            count++;
        }while(start != current);
    }
}
//解法4:  旋转。先全旋转，再转前k个，再转后n-k个
void reverse(int *nums, int start, int end){
    while(start < end){
        int tmp = nums[start];
        nums[start] = nums[end];
        nums[end] = tmp;
        start++;
        end--;
    }
}
void rotate(int* nums, int numsSize, int k){
    k = k % numsSize;
    //旋转整个数组
    reverse(nums, 0, numsSize-1);
    //旋转前k个
    reverse(nums, 0 , k-1);
    //旋转后numsSize-k个
    reverse(nums, k, numsSize -1);
}