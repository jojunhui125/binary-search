#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int search(int len, int arr[], int target);
int main(void)
{
    int n, m, temp, len;
    int arr[100000] = { 0 };
    int num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }


    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &num);
        printf("%d\n", search(n, arr, num));
    }

    return 0;

}

int search(int len, int arr[], int target)
{
    int first = 0;
    int last = len - 1;
    int middle;

    while (first <= last)
    {
        int middle = (first + last) / 2;
        if (arr[middle] == target)
        {
            return 1;

        }
        else
        {
            if (target < arr[middle])
            {
                last = middle - 1;
                first = 0;

            }
            else
            {
                first = middle + 1;
                last = len;
            }
        }

    }
    return 0;

}


