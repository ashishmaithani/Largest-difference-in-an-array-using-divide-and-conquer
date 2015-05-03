#include <stdio.h>

struct data{
	int min_;
	int max_;
};

/* CrossMinMax funtion finds the largest element on the right hand side of middle element *
 * and smallest element on the left hand side of the middle element.                      *
 * This ensures that Biggest element has index greater than the Smallest element          */
struct data crossminmax(int *p,int lo,int mid,int hi){
	int i,min,max;
	struct data temp;

// Find the smallest number on the left of mid
	min = p[mid];
	for(i=mid;i>=lo;i--){
		if(p[i] < min){
			min = p[i];
		}
	}

// find the biggest number on the right of mid
	max = p[mid+1];
	for(i=mid+1;i<=hi;i++){
		if(p[i] > max){
			max = p[i];
		}
	}
	temp.min_ = min;
	temp.max_ = max;
	return temp;
}

/* MinMax calculates the difference between Biggest and Smallest element  *
 * of an array using divide and conquer principles such that the position * 
 * of Biggest element is always greater than the Smallest element         */

struct data minmax(int *p,int lo,int hi){
	int mid,leftdiff,rightdiff,crossdiff;
	struct data left,right,cross,temp;

	if(lo == hi){
		temp.min_ = p[lo];
		temp.max_ = p[hi];
		return temp;
	}

	mid = (lo+hi)/2;
	left = minmax(p,lo,mid);
	right = minmax(p,mid+1,hi);

	cross = crossminmax(p,lo,mid,hi);
	leftdiff = left.max_ - left.min_;
	rightdiff = right.max_ - right.min_;
	crossdiff = cross.max_ - cross.min_;
	
	if(leftdiff > rightdiff && leftdiff > crossdiff){
		return left;
	}else if(rightdiff > crossdiff){
		return right;
	}else{
		return cross;
	}
}

int main(){
	int arr[] = {5,2,3,10,1,3,16,4,3};
	struct data dt;
	dt = minmax(arr,0,8);
	printf("Max difference = %d, Max Element=%d, Min Element = %d  \n",dt.max_ - dt.min_,dt.max_,dt.min_);
	return 0;
}

