long long int floorSqrt(long long int x) 
   {
        long long int s=0;
   long long int e=x;
   long long int mid=s+(e-s)/2;
   long long int ans=0;
   while(s<=e)
   {
       if(mid*mid==x)
       {
           return mid;
       }
       else if(mid*mid>x)
       {
           e=mid-1;
       }
       else if(mid*mid<x)
       {
            ans=mid;
           s=mid+1;
       }
       mid=s+(e-s)/2;
   }
   return ans;   
   }