

// #include <iostream>

// void swap(int *a, int *b)
// {
// 	int tmp = *b;
// 	*b = *a;
// 	*a = tmp;
// }

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

// int main()
// {
//     int arr[10] = {0,4,3,2,5,4,3,27,4,9};

//     qsort(arr,10,[](int x, int y){
//         return int(x > y);
//     });

//     for(int i = 0 ; i < 10 ; i++)
//     {
//         std::cout << arr[i] << " ";
//     }
// }

/////////////////////////////////////////////////////////////
//1.
// [1,2,3,4,2,4,2,4,5,6,4,3] 
// x0         p0            xn
//2.
//[1,2,3,4,2]    [2,4,5,6,4,3]
//x0  p1    xn  x0    p2    xn
//
//  [1,2,3,4,2] <- p1 < p0 < p2 -> [2,4,5,6,4,3]
//
//...
//
//
// pm < ... < p1 < p0 < p2 < ... < pn  <- sorted array - finish recursion here
// it will give us back the sorted array
/////////////////////////////////////////////////////////////


#define RANDOM_RANGE 100
#define LENGTH 10

void swap(int32_t *first, int32_t *second)
{
	int32_t tmp = (*second);
	(*second) = (*first);
	(*first) = tmp ;
}

int QuickSort(int *arr, unsigned int x0, unsigned int xn, int(*cmp)(int,int)) {

	if(x0 > xn) return -1;
	if(xn - x0 <= 1) return -1;
	
	uint32_t pivot_index = xn - 1;
	int32_t pivot = arr[pivot_index];
	
	int32_t tmp_pivot = x0;
	for(int32_t i = x0; i < xn; i++)
	{
		if(cmp(arr[i],pivot))
		{
			swap(&arr[i],&arr[tmp_pivot]);
			tmp_pivot++;
			pivot_index = i;
		}
	}
	
	tmp_pivot++;
	if(tmp_pivot < xn)
	{
		swap(&arr[pivot_index],&arr[tmp_pivot]);
		pivot_index = tmp_pivot;
	}

	QuickSort(arr,x0,pivot_index,cmp);
	QuickSort(arr,pivot_index,xn,cmp);
	return 0;
}

void init_random(int32_t *array, uint32_t length)
{
	srand((int)(clock()));
	
	for(uint32_t i = 0 ; i < length ; i++)
	{
		array[i] = rand()%RANDOM_RANGE;
	}
}

void show_array(int32_t* array, uint32_t length )
{
	printf("===========ARRAY=============\n");
	printf("Length: %u \n[", length);
	for(int32_t i = 0 ; i < length ; i++)
	{
		printf("%u",array[i]);
		if(i < length - 1)
		{
			printf(", ");
		}
	}
	printf("]\n");	
	printf("============================\n");
}

int main()
{
	int32_t test_array[LENGTH];
	init_random(test_array,LENGTH);
	//show_array(test_array, LENGTH);
	
	clock_t start = clock();
	QuickSort(test_array,0,LENGTH,[](int x, int y){
		if((x % 2) < (y % 2))
		{
			return 1;
		}
		else
		{
			if(x <= y and (x % 2) == (y % 2))
			{
				return 1;
			}
		}

		return 0;
	});

	float execution_time = (float)(clock() - start)/CLOCKS_PER_SEC;
	printf("Sorting took: %fs\n",execution_time);
	
	show_array(test_array, LENGTH);
	return 0;
}
