/*
link: https://www.codingninjas.com/codestudio/problems/count-inversions_615?leftPanelTab=0 
TC: O(nlogn)
SC: O(n)
Method: Use merge sort and count the number of inversions.
*/

long long merge(long long *arr, long long *temp, int left, int mid, int right){
	long long i=left, j=mid, k=left, inv_count=0;
	while(i<mid && j<=right){
		if(arr[i]<=arr[j]) temp[k++] = arr[i++];
		else {
			temp[k++] = arr[j++];
			inv_count += (mid-i);
		}
	}
	while(i<mid) temp[k++] = arr[i++];
	while(j<=right) temp[k++] = arr[j++];
	for(i = left; i<=right; i++) arr[i]=temp[i];
	return inv_count;
}

long long mergesort(long long *arr, long long *temp, int left, int right){
	long long mid, inv_count=0;
	if(right > left){
		mid = (right+left)/2;
		inv_count += mergesort(arr, temp, left, mid);
		inv_count += mergesort(arr, temp, mid+1, right);
		
		inv_count += merge(arr, temp, left, mid+1, right);
	}
	return inv_count;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
	long long temp[n];
	return mergesort(arr, temp, 0, n-1);
}