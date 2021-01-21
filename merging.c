#include <profileapi.h>
#include <stdio.h>

int merge(int a[], int b[], size_t size_of_arrays_combined)
{
    printf("size=%llu\n", size_of_arrays_combined);
    int* temp = (int*)malloc(size_of_arrays_combined * sizeof(int));
    printf("num = %d\n", a[0] + b[0]);
    free(temp);
    return 0;
}

int main()
{
    LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
    LARGE_INTEGER Frequency;
    
    QueryPerformanceFrequency(&Frequency); 
    QueryPerformanceCounter(&StartingTime);
    
    int a[5] = {4};
    int b[5] = {6};
    size_t combined = (sizeof(a)+sizeof(b))/sizeof(int);
    merge(a,b, combined);

    // Activity to be timed

    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;


    //
    // We now have the elapsed number of ticks, along with the
    // number of ticks-per-second. We use these values
    // to convert to the number of elapsed microseconds.
    // To guard against loss-of-precision, we convert
    // to microseconds *before* dividing by ticks-per-second.
    //

    ElapsedMicroseconds.QuadPart *= 1000000;
    ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;
    printf("The elapsed time is: %lld microseconds\n", ElapsedMicroseconds.QuadPart);
}