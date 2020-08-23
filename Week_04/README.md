学习笔记

其余见脑图

使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方：

我理解，因为之前这是个有序的数组，经过旋转后，变成了一个半有序的的数组
找一个半有序数组中间无序的地方，就是值最小的地方

```dotnetcli
#/usr/bin/python3
#-*-encoding:utf-8 -*-


def search(nums):
    left = 0
    right = len(nums) - 1

    while left < right:
        mid = left + (right - left) // 2
        if nums[right] < nums[mid]:
            left = mid + 1
        else:
            right = left
        return left


if __name__ == "__main__":
    nums = [4, 5, 6, 7, 0, 1, 2]
    nums1 = [4, 5, 6, 0, 1, 2]
    print(search(nums1))

```
