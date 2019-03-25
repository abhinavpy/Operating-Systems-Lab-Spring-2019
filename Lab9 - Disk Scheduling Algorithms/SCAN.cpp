#include<stdio.h>

void scan_algorithm(int left[], int right[], int count, int limit)
{
      int arr[20];
      int x = count - 1, y = count + 1, c = 0, d = 0, j;
      while(x > -1)
      { 
            printf("\nX:\t%d", x);
            printf("\nLeft[X]:\t%d", left[x]);
            arr[d] = left[x];
            x--;
            d++;
      }
      arr[d] = 0;
      while(y < limit + 1)
      {
            arr[y] = right[c];
            c++;
            y++;
      }
      printf("\nScanning Order:\n");
      for(j = 0; j < limit + 1; j++)
      {
            printf("\n%d", arr[j]);
      }
}

void division(int elements[], int limit, int disk_head)
{
      int count = 0, p, q, m, x;
      int left[20], right[20];
      for(count = 0; count < limit; count++)
      {
            if(elements[count] > disk_head)
            {
                  printf("\nBreak Position:\t%d\n", elements[count]);
                  break;
            }
      }
      printf("\nValue:\t%d\n", count);
      q = 1;
      p = 0;
      m = limit;
      left[0] = elements[0];
      printf("\nLeft:\t%d", left[0]);
      while(q < count)
      {
            printf("\nElement[l] value:\t%d" , elements[q]);
            left[q] = elements[q];
            printf("\nLeft:\t%d", left[q]);
            q++;
            printf("\nl:\t%d", q);
      }
      x = count;
      while(x < m)
      {
            right[p] = elements[x];
            printf("\nRight:\t%d", right[p]);
            printf("\nElement:\t%d", elements[x]);
            p++;
            x++;
      }
      scan_algorithm(left, right, count, limit);
}

void sorting(int elements[], int limit)
{
      int location, count, j, temp, small;
      for(count = 0; count < limit - 1; count++)
      {
            small = elements[count];
            location = count;
            for(j = count + 1; j < limit; j++)
            {
                  if(small > elements[j])
                  {
                        small = elements[j];
                        location = j;
                  }
            }
            temp = elements[location];
            elements[location] = elements[count];
            elements[count] = temp;
      }
}

int main()
{
      int count, disk_head, elements[20], limit;
      printf("Enter total number of locations:\t");
      scanf("%d", &limit);
      printf("\nEnter position of disk head:\t");
      scanf("%d", &disk_head);
      printf("\nEnter elements of disk head queue\n");
      for(count = 0; count < limit; count++)
      {
            printf("Element[%d]:\t", count + 1);
            scanf("%d", &elements[count]);
      }
      sorting(elements, limit);
      division(elements, limit, disk_head);
      return 0;
}