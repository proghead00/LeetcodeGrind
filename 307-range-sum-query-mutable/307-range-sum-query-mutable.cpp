class NumArray {
public:
    vector<int> nums{};
    int total=0 , len;
    NumArray(vector<int>& nums) 
    {   
        this->nums = nums;
        len = nums.size();
        for(int i=0 ; i<len ;i++)
            total+=nums[i]; //Summation of all elements in the array is stored in variable total.
        
    }
    
    void update(int index, int val) 
    {
        total = total + (val-nums[index]); //When we update a value in nums , the summation is also updated accordingly.
        nums[index] = val;
        
    }
    
    //We calculate the sumRange for the minimum(right-left , len-(right-left)) . Worst Case TC still remains to be O(n)
    int sumRange(int left, int right) 
    {
        int sum = 0;
        if(right-left+1 < len-(right-left)) // if the range that is requested(right-left) is less than all the elements remaining(len-(righ-left)) in the array.
            for(int i=left ; i<=right ; i++)
                sum+=nums[i];
        else
        {
            for(int i=0 ; i<left ; i++)//calculating the sum from 0 to left-1
                sum+=nums[i];
            for(int i=right+1 ; i<len ; i++) //calculating the sum from right+1 to len-1
                sum+=nums[i];
            sum = total-sum; //Subtracting the above values from the total to obtain the requested rangeSum.
        }
        return sum;
        
    }
};