int trap(int* height, int heightSize){
// 暴力求解
// 从头遍历数组
// 找到左边的最大值，和其右边的最大值。找到 左右最小值与自身的差值 才能储水。
    int ans = 0,  heigh = 0;
    for(int h = 0; h < heightSize-1; h++){
        int left_max = 0, right_max = 0;
        for(int j =h ; j>=0; j--)
            //找出该值左边最大值
            left_max = height[j] > left_max ? height[j] : left_max;
        for(int j =h; j < heightSize ; j++)
            //找出该值右边最大值
            right_max = height[j] > right_max ? height[j] : right_max;
        // 左右的最小值
        heigh = left_max > right_max ? right_max: left_max;
        ans = ans + heigh - height[h];
    }
    return ans;
}
 // 动态规划,
 // 这个方法和上一个的差异在于，上一个是每次用的时候去计算，这是提前计算好该点左边最大值和又边最大值，存到数组，到时候直接用。
 int trap(int* height, int heightSize){
    if(heightSize == 0)
        return 0;
    int ans = 0;
    int * left_max = (int *)malloc(heightSize * sizeof(heightSize));
    int * right_max = (int *)malloc(heightSize * sizeof(heightSize));
    left_max[0]= height[0];
    right_max[heightSize-1] = height[heightSize -1];
    for(int i = 1; i < heightSize ; i++){
        left_max[i] = height[i] > left_max[i-1] ? height[i] : left_max[i-1];
    }
    for(int i = heightSize-2 ; i >=0 ; i--){
        right_max[i] = height[i] > right_max[i+1] ? height[i] : right_max[i+1];
    }
    for(int i = 1; i < heightSize -1; i++){
        int h = left_max[i] < right_max[i] ? left_max[i] : right_max[i];
        ans += h - height[i];
    }
    free(left_max);
    free(right_max);
    return ans;
}
//双指针法
int trap(int* height, int heightSize){
    int l = 0 , r = heightSize -1;
    int ans = 0;
    int l_max = 0, r_max = 0;
    while(l < r){
        if(height[l] < height[r]){
            //如果   heigh[l] >= l_max 形成不了低洼，就更新l_max值；
            // 如果 heigh[l] < l_max,  heigh[l] < heigh[r] ==》形成了一个低洼，求面积
            height[l] >= l_max ? (l_max = height[l] ) : (ans += (l_max -height[l]));
            ++l;
        }
        else
        {
            height[r] >= r_max ?(r_max = height[r]) : (ans += (r_max -height[r]));
            --r;
        }
    }
    return ans;
}
// 解法4 栈
// 形成 高低高才能够储水
// 注意栈中存储的是 下标，不是高度
// 所以现在元素比栈顶低时，就入栈， 否则，进行出栈循环
// 
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        length = len(height)
        if length < 3:
            return 0;
        res , inx = 0, 0
        stack = []
        while inx < length:
            while len(stack) > 0 and height[inx] > height[stack[-1]]:
                top = stack.pop()   #最后一个元素出站
                //如果栈中没有元素了，那就形成了低高，不能储水
                if len(stack) == 0:
                    break
                //height[stack[-1]] 是对应左边的高， height[inx] 是对应右边的高， height[top] 对应的低的值
                //这个算的是高度
                h = min(height[stack[-1]], height[inx])- height[top]
                // 相当于算长度
                dist = inx - stack[-1] -1
                res += (dist * h)
            stack.append(inx)
            inx += 1
        return res
    时间复杂度 O(n)
    空间复杂度 O(n)