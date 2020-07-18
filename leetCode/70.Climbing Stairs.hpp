//
// Created by xuche on 2020/7/18.
//

#ifndef PROGRAMSTUDY_LEETCODE_70_CLIMBING_STAIRS_HPP
#define PROGRAMSTUDY_LEETCODE_70_CLIMBING_STAIRS_HPP

int climbStairs(int n) {
    int ans = 1;
    int i = 1, j = 1;
    for(int index = 1; index < n; ++index){
        i = j;
        j = ans;
        ans = i + j;
    }
    return ans;
}

#endif //PROGRAMSTUDY_LEETCODE_70_CLIMBING_STAIRS_HPP
