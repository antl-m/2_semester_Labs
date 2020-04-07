#pragma once

#include <iostream>
#include <string>
#include <algorithm>

using std::size_t;
using std::string;

template<class T>
void selection_sort_desc(T* arr, size_t low, size_t high)
{
	T tmp;

	for (size_t start = low; start < high + 1; start++)
	{
		size_t max_index = start;
		for (size_t current = start + 1; current < high + 1; current++)
		{
			if (arr[current] > arr[max_index])
			{
				max_index = current;
			}
		}
		tmp = arr[start];
		arr[start] = arr[max_index];
		arr[max_index] = tmp;
	}
}

template<class T>
size_t partition(T* arr, size_t low, size_t high)
{
	T pivot(arr[(low + high) / 2]);

	size_t i = low;
	size_t j = high;
	while (1)
	{
		while (arr[i] > pivot) {
			i++;
		}

		while (arr[j] < pivot) {
			j--;
		}

		if (i >= j)
			return j;

		T tmp(arr[i]);
		arr[i] = arr[j];
		arr[j] = tmp;
		i++;
		j--;
	}
}

template<class T>
void quick_sort(T* arr, size_t low, size_t high)
{
	if (low >= high)
		return;

	size_t pivot = partition(arr, low, high);

	quick_sort(arr, low, pivot);

	quick_sort(arr, pivot + 1, high);
}

template<class T>
void merge(T* tmp, T* arr, int left, int middle, int right)
{
	int i = left;
	int temp = middle;
	while (left < temp && middle < right)
	{
		if (arr[left] > arr[middle])
		{
			tmp[i] = arr[left];
			left++;
		}
		else
		{
			tmp[i] = arr[middle];
			middle++;
		}
		i++;
	}

	if (left >= temp)
	{
		temp = middle;
	}
	else
	{
		right = temp;
		temp = left;
	}

	while (temp < right)
	{
		tmp[i] = arr[temp];
		i++;
		temp++;
	}
}

template<class T>
void merge_sort(T* arr, size_t size)
{
	T* tmp = new T[size];

	for (int width = 1; width < size; width *= 2)
	{
		for (int i = 0; i < size; i += 2 * width)
		{
			int left, middle, right;

			left = i;
			middle = i + width;
			right = i + 2 * width;

			if (right > size)
			{
				if (middle >= size)
				{
					while (left < size) 
					{
						tmp[left] = arr[left];
						left++;
					}
					break;
				}
				right = size;
			}
			merge(tmp, arr, left, middle, right);
		}
		for (int i = 0; i < size; i++)
		{
			arr[i] = tmp[i];
		}
	}
	delete[] tmp;
}

template<class T>
void combinated_sort(T* arr, size_t low, size_t high, size_t border)
{
	if (high - low + 1 > border)
	{
		size_t pivot = partition(arr, low, high);
		combinated_sort(arr, low, pivot, border);
		combinated_sort(arr, pivot + 1, high, border);
	}
	else
	{
		selection_sort_desc(arr, low, high);
	}
}

template<class T>
void lib_sort(T* arr, size_t low, size_t high)
{
	sort(&arr[low],&arr[high+1], std::greater<T>());
}

void start_menu();
void demo_menu();
void bench_menu();

void selection_bench(string* list, size_t N);
void quick_bench(string* list, size_t N);
void merge_bench(string* list, size_t N);
void combinated_bench(string* list, size_t N);
void randomize(string* list, size_t N);
