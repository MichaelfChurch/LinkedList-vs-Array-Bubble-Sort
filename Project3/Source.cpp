#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<time.h>

using namespace std;

struct llist {
	int data;
	llist* next;
};
//Inserting values into the linked list
void insert(llist** origin, int item)
{
	llist* temp = new llist;
	llist* ptr;
	temp->data = item;
	temp->next = NULL;

	if (*origin == NULL)
		*origin = temp;
	else {
		ptr = *origin;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = temp;
	}
}
//print the linked list
void display(llist* origin)
{
	while (origin != NULL) {
		cout << origin->data << " ";
		origin = origin->next;
	}
}
// Duplicating array values to linked list
llist* arrayToList(int arr[], int n)
{
	llist* origin = NULL;
	for (int i = 0; i < n; i++)
		insert(&origin, arr[i]);
	return origin;
}
//bubble sort array
void bubbleSort(int arr[], int n) {
	for (int j= 1; j < n; ++j) {
		for (int i = 0; i < n - j; ++i) {
			if (arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}
//swap between two pointers
void my_swap(llist* node_1, llist* node_2)
{
	int temp = node_1->data;
	node_1->data = node_2->data;
	node_2->data = temp;
}

//Bubble sort for linked list
void bubble_sortlink(llist* head)
{
	bool swapped;
	llist* point1; 
	llist* point2 = NULL;
	do
	{
		swapped = false;
		point1 = head;
		while (point1->next != point2)
		{
			if (point1->data > point1->next->data)
			{
				my_swap(point1, point1->next);
				swapped = true;
			}
			point1 = point1->next;
		}
		point2 = point1;

	} while (swapped);
}

int main()

{
	srand(time(NULL));
	int n, i = 0;
	//Getting size of array/linkedlist
	cout << "How many random values do you want? ";
	cin >> n;

	//array initilisation
	int* arr = new int[n];

	//Inserting data in array
	for (int i = 0; i < n; i++) {
		arr[i] = rand();
	}

	//Array test
	cout << endl << "List of numbers in the Array" << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	llist* origin = arrayToList(arr, n);

	//Linked List test
	cout << endl << "List of numbers in the Linked List" << endl;
	display(origin);

	//Array Bubble Sort
	clock_t start, end;
	start = clock();
	bubbleSort(arr, n);
	end = clock();
	double arrTime = (double)(end - start) / CLOCKS_PER_SEC;

	//Linked List Sort
	clock_t startlink, endlink;
	startlink = clock();
	bubble_sortlink(origin);
	endlink = clock();
	double linkTime = (double)(endlink - startlink) / CLOCKS_PER_SEC;

	/*Array test post sort
	cout << endl << "Sorted list of numbers in the Array "<< endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " "; */


	//Array sort time
	cout << endl << arrTime;

	//Linked List sort time
	cout << endl << linkTime;

	return 0;



}
