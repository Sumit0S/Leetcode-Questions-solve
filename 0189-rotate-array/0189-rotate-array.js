/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
        const n=nums.length;
        const temp = new Array(n);


        nums.forEach((val,i)=>{
            temp[(i+k)%n]=val;
        })
        
        for (let i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
};