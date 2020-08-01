/*
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
说明:
初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

示例:
输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
输出: [1,2,2,3,5,6]
*/

// 解法一：类比合并两个链表，重新分配一个数组nums3，把nums1的值复制过去，
//然后nums3和nums2的值依次比较，较小的放入到nums1里   
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){ 
    int *nums3 = (int *)malloc(m * sizeof(int)) ;
    for(int i =0 ; i< m ; i++){
        nums3[i] = nums1[i];
    }
    memset(nums1,0,m);
    int p1 =0,p2 = 0,p=0;
    while(p1<m && p2 < n){
        if(nums3[p1] > nums2[p2]){
            nums1[p] = nums2[p2];
            p2++;
        }
        else
        {
            nums1[p] = nums3[p1];
            p1++;
        }
        p++;
    }
    for(int k = p1; k < m; k++)  {
        nums1[p] = nums3[k];
        p++;
    }   
        
    for(int k2 = p2; k2 < n; k2++){
        nums1[p] = nums2[k2];
        p++;
    }
}
//解法2：先把数组nums2都复制nums1 中m个数后面。在对nums1和nums2的合数组按从小到大排序
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){ 
    for(int i= 0 ; i < n; i++)
        nums1[m+i] = nums2[i];
    int nums = n + m ;
    for(int j = 0; j < nums-1; ++j){
        for(int k = 0; k < nums -1 - j; ++k){
            if(nums1[k] > nums1[k+1]){
                int tmp = nums1[k+1];
                nums1[k+1] = nums1[k];
                nums1[k] = tmp;
            }
        }
    }
}
//解法3 
/* nums1和nums2排序后的数组长度是n+m，
    那么找nums1 和 nums2 从后比较 较大的数 放到 nums1 合并nums2 后对应的长度的最后位
    都依次递减。
    最后考虑nums2没有都添加到数组nums1的情况，把其填到前面
*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){ 
    //nums1 的最后一位
    int p1 = m - 1;
    //nums2 的最后一位
    int p2 = n - 1;
    //nums1和nums2合并后的最后一位
    int p = m + n -1;
    //比较nums1和nums2值的大小，大的值从后往前填，大的值对应的指针减一。
    while( p1 >= 0 && p2 >=0){
        if(nums1[p1] > nums2[p2]){
            nums1[p] = nums1[p1];
            p1--;
        }
        else
        {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }
    //最后考虑nums2没有都添加到数组nums1的情况，把其填到前面
    for(int i = 0; i <= p2; i++)
        nums1[i] = nums2[i];
}
