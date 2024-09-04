#include<stdio.h>
#include<stdlib.h>
#define max 5
//Add Element 
int add(int arr[], int element, int position) 
{
  if (position == 4) 
  {
    printf("Array is Full");
  } 
  else 
  {
    position++;
    arr[position] = element;
    printf("%d Element is added at %d position", arr[position], position);
  }
  return position;
}

//Delete Element
int delete(int arr[], int position,int element)
{
  int i,temp=0,found=0,j;
  if(position == -1)
  {
    printf("Array is Empty");
  }
  else{
      
      for(i=0;i<=position;i++)
	  {
          if(arr[i] == element)
		  {
              found=1;
              break;
          }
      }
      
      if(found)
	  {
          for(j=i;j<=position-1;j++)
		  {
              arr[j]=arr[j+1];
          }
          printf("Element Deleted\n");
          position--;
      }
	  else
	  {
          printf("Element not found. Give a valid Element.");
      }
  }
  return position;
}

//Modify Element
void modify(int arr[],int position,int element,int newElement)
{
  int temp=0,i;
  if(position==-1)
  {
    printf("Array is Empty");
  }
  else
  {
    for(i=0;i<=position;i++)
	{
      if(arr[i]==element)
	  {
        arr[i] = newElement;
        printf("%d element is modified to %d",newElement,element);
        temp=1;
        break;
      }
    }
    if(temp==0)
	{
      printf("Element not found. Give a valid Element to change.");
    }
  }
}

//Sort Array
void sort(int arr[],int position)
{
  int i,j,temp;
  if(position==-1)
  {
    printf("Array is Empty");
  }else{
    for(i=0;i<position+1;i++)
	{
      for(j=i+1;j<position+1;j++)
	  {
        if(arr[i]>arr[j])
		{
          temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
        }
      }
    }
    printf("Array is Sorted");
  }
}

//Simple Search
void simpleSearch(int arr[],int position,int element)
{
  int i,temp=0;
  if(position == -1)
  {
    printf("Array is empty");
  }
  else
  {
    for(i=0;i<=position;i++)
	{
      if(arr[i]==element)
	  {
        printf("%d elemet is at %d position",element,i);
        temp=1;
        break;
      }
    }
    if(temp == 0)
	{
      printf("element not found");
    }
  }
}

//Binary Search
int binarySearch(int arr[],int position,int element)
{
  int i,temp=0,low=0,high=position,mid;
  while(low <= high)
  {
    mid = (low+high)/2;
    if(arr[mid]==element)
	{
      return mid;
    }
	else if(arr[mid]<element)
	{
      low = mid+1;
    }
	else if(arr[mid]>element)
	{
      high = mid-1;
    }
  }
  return -1;
}

//Display Element
void display(int arr[], int position)
 {
  int i;
  for (i = 0; i <= position; i++)
   {
    printf("%d  ", arr[i]);
   }
  printf("\n");
}

void main() 
{

  int arr[5], element,newElement, position = -1,result;
  int i, j;
  int choice;

  while (1) 
  {
    printf("\nEnter 1 For Add\n");
    printf("Enter 2 For Delete\n");
    printf("Enter 3 For Modify\n");
    printf("Enter 4 For Sort\n");
    printf("Enter 5 For Simple Search\n");
    printf("Enter 6 For Binary Search\n");
    printf("Enter 7 For Display\n");
    printf("Enter 8 For Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
{
    case 1:
      printf("Enter the element to add : ");
      scanf("%d", &element);
      position = add(arr, element, position);
      break;

    case 2:
      printf("Enter the element to delete : ");
      scanf("%d",&element);
      position = delete(arr, position, element);
      break;

    case 3:
      printf("Enter the element which you wanna to modify : ");
      scanf("%d",&element);
      printf("Enter the new element : ");
      scanf("%d",&newElement);
      modify(arr,position,element,newElement);
      break;

    case 4:
      sortToArray(arr,position);
      break;

    case 5:
      printf("Enter the element to search : ");
      scanf("%d",&element);
      simpleSearch(arr,position,element);
      break;

    case 6:
      printf("Enter the element to search : ");
      scanf("%d",&element);
      result = binarySearch(arr,position,element);
      if(result == -1)
	  {
        printf("Element not found");
      }
	  else
	  {
        printf("Element found at %d position",result);
      }
      break;

    case 7:
      display(arr, position);
      break;
    }
  }
}
