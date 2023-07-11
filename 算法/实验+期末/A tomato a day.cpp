#include<cstdio>

const int Maxn=105;
int C[Maxn];  // Price on each day
int B[Maxn]={0}; // The number of tomatoes should be purchased on each day

int Min(int a, int b) // Find the smallest item from C[a+1] to C[b]
{                     // Return the index
    int mIndex = a + 1;
    for(int i = a + 1; i <= b; i++)
        if(C[i] < C[mIndex])
            mIndex = i;
    return mIndex;
}

void Buy(int d, int n) // Find the result of B[]
{
	B[1] = 1;  // The first day must buy a tomato
    int tmp = 1;  // Initialize the tmp
    for(int i = 2; i <= n; i++)
    {
        if(i - tmp + 1 > d)  // If the tomato purchased on tmp-th day expires on day i
            tmp = Min(tmp, i); // Update tmp
        else if(C[i] < C[tmp]) // If the tomato purchased on tmp-th day does not expire on day i
            tmp = i;  // Update tmp
        B[tmp]++; // Purchase a tomato sold on tmp-th day
    }
}

int main()
{
    int d, n;
    scanf("%d%d", &d, &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &C[i]);

	Buy(d, n);

    for(int i = 1; i <= n; i++)
    {
        printf("B[%d] = %d ", i, B[i]);
        printf("\n");
    }
}

