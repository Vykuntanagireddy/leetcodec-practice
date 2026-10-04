int  compare(const void* a,const void* b){
    return(*(int*)a-*(int*)b);
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int i=0,j=0;
  int totalsize = nums1Size + nums2Size;
int* arr = (int*)malloc(totalsize * sizeof(int));
  while(i<nums1Size){
    arr[i]=nums1[i];
    i++;
  }  
  while(j<nums2Size){
    arr[i]=nums2[j];
    i++;
    j++;
  }
  qsort(arr,totalsize,sizeof(int),compare);

  double median;
  if(totalsize % 2==1){
    median=arr[totalsize/2];
  }else{
    median=(arr[(totalsize/2)-1]+arr[totalsize/2])/2.0;
  }
  free(arr);
  return median;
}