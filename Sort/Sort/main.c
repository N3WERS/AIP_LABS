#include <stdio.h>
#include <stdlib.h>

void qSort(int* a, int first, int last);
void sortBubble(int n, int* a);
void shakerSort(int m, int* a);

int main()
{
    int num;
    int n;
    int* a;

    printf("Size of array: ");
    scanf_s("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    for (int t = 0; t < n; t++)
    {
        printf("a[%d]: ", t);
        scanf_s("%d", &a[t]);
    }
    printf("Choose method sorted (1 = BubbleSort, 2 = ShakerSort, 3 = QuickSort): ");
    scanf_s("%d", &num);
    if (num == 1)
        sortBubble(n, a);
    if (num == 2)
        shakerSort(n, a);
    if (num == 3)
        qSort(a, 0, n - 1);
    printf("Sorted array: ");
    for (int h = 0; h <= n - 1; h++)
    {
        printf("%d ", a[h]);
    }
}

void sortBubble(int n, int* a)
{
    int x = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int k = 0; k < n - 1; k++)
        {
            if (a[k] > a[k + 1])
            {
                x = a[k];
                a[k] = a[k + 1];
                a[k + 1] = x;
            }
        }
    }
}

void qSort(int* a, int first, int last)
{
    if (first < last)
    {
        int left = first;
        int right = last;
        int middle = a[(left + right) / 2];
        do {
            while (a[left] < middle)
                left++;
            while (a[right] > middle)
                right--;
            if (left <= right)
            {
                int temp = a[left];
                a[left] = a[right];
                a[right] = temp;
                left++;
                right--;
            }
        } while (left < right);
        qSort(a, first, right);
        qSort(a, left, last);
    }
}

void shakerSort(int m, int* a)
{
    int left = 0, right = m, bufSort, bufSort2;
    while (left <= right)
    {
        for (int i = left; i <= right - 2; i++)
        {
            if (a[i] > a[i + 1])
            {
                bufSort = a[i];
                a[i] = a[i + 1];
                a[i + 1] = bufSort;
            }
        }
        right--;

        for (int j = right; j >= left; j--)
        {
            if (a[j - 1] > a[j])
            {
                bufSort2 = a[j];
                a[j] = a[j - 1];
                a[j - 1] = bufSort2;
            }
        }
        left++;
    }
}




