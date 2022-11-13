class Solution 
{
    public:
    
    bool isPossible(int A[], int N, int M , int mid){
        
        int studentcount = 1;
        int pagesum = 0;
        
        for(int i =0; i<N ; i++){
            if(pagesum + A[i] <= mid){
                pagesum = pagesum + A[i];
            }
            else{
                studentcount++;
                if(studentcount > M || A[i] > mid){
                    return false;
                }
                
                pagesum = A[i];
            }
            
            if(studentcount > M){
                return false;
            }
        }
        
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M>N) return -1;  //important condition 
        
       int start = 0;
       int sum = 0;
       
       for(int i =0; i<N; i++){
           sum = sum + A[i];
       }
       
       int end = sum;
       int answer = -1;
       int mid = start + (end-start)/2;
       
       while(start<=end){
           
           if(isPossible(A , N , M , mid)){
               answer = mid;
               end = mid-1;
           }
           else{
               start = mid+1;
           }
           
           mid = start + (end-start)/2;
       }
       
       return answer;
    }
};