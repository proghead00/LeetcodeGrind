	class Solution {
public:

//1 2 3  // 0 1 2

long long  merge(vector<int>&nums,vector<int>&temp,int low,int mid,int high){
    
    if(low>=high)
        return 0;
    
    
    long long res=0;
    long long j=mid;
    long long k=low;
    long long i=low;
    while(j<=high && i<mid){
        
        if(nums[i]<=nums[j]){
            temp[k++]=nums[i++];
        }
        else{
            temp[k++]=nums[j++];
            res+=(mid-i);
        }
    }
    
    while(i<mid){
        temp[k++]=nums[i++];
    }
    
    while(j<=high){
        temp[k++]=nums[j++];
    }
    
    
    for (int m = low; m <= high; m++)
	nums[m] = temp[m];
    
    
    return res;
}

long long mergeSort(vector<int>&nums,vector<int>&temp,int low,int high){
    
    if(low>=high)
        return 0;
    
    long long mid=low+(high-low)/2;
    
    long long left=mergeSort(nums,temp,low,mid);
    long long  right=mergeSort(nums,temp,mid+1,high);
    
    return left+right+merge(nums,temp,low,mid+1,high);
    
}

int countInversion(vector<int>&nums){
    
    vector<int>temp(nums.size());
    return mergeSort(nums,temp,0,nums.size()-1);
    
}

bool isIdealPermutation(vector<int>& nums) {
 
    int LI=0;
    
    for(int i=0;i<nums.size()-1;i++){
        
        if(nums[i]>nums[i+1])
            LI++;
        
    }
    
    int GI=countInversion(nums);
    return GI==LI;
    
}
};