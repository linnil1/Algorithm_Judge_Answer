#include <stdio.h>
#include <stdio.h>

int n;
int min_distance;
char rankings[100][8];
char permutation[8];
char inverse_permutation[8];
char min_permutation[8];
char transform[8];
char buf[6];

void foo(int index)
{
    if (index == 5)
    {
        int i, j, k;
        int dist = 0;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < 5; j++)
                transform[j] = rankings[i][(int) inverse_permutation[j]];

            for (j = 0; j < 5; j++)
            {
                for (k = j + 1; k < 5; k++)
                {
                    if (transform[j] > transform[k])
                        dist++;
                }
            }
        }

        for (i = 0; i < 5; i++)
            permutation[(int) inverse_permutation[i]] = i;

        /* printf("# %d\n", dist); */
        /* for (i = 0; i < 5; i++) */
        /*     printf("%c", permutation[i] + 'A'); */
        /* printf("\n"); */
            
        if (dist <= min_distance)
        {
            for (i = 0; i < 5; i++)
                permutation[(int) inverse_permutation[i]] = i;

            if (dist < min_distance)
            {
                min_distance = dist;
                *(long long int*) min_permutation = *(long long int*) permutation;
            }
            else
            {
                for (i = 0; i < 5; i++)
                {
                    if (min_permutation[i] < permutation[i])
                    {
                        *(long long int*) min_permutation = *(long long int*) permutation;
                        break;
                    }
                    else if (min_permutation[i] > permutation[i])
                        break;
                }
            }
        }
        
        return;
    }

    foo(index + 1);

    int i;
    for (i = index + 1; i < 5; i++)
    {
        inverse_permutation[index] ^= inverse_permutation[i];
        inverse_permutation[i] ^= inverse_permutation[index];
        inverse_permutation[index] ^= inverse_permutation[i];
        foo(index + 1);
        inverse_permutation[index] ^= inverse_permutation[i];
        inverse_permutation[i] ^= inverse_permutation[index];
        inverse_permutation[index] ^= inverse_permutation[i];
    }
}

int main()
{
    while (1)
    {
        scanf("%d", &n);
        getchar();
        
        if (n == 0)
            return 0;

        int i, j;
        for (i = 0; i < n; i++)
        {
            fgets(buf, 8, stdin);

            for (j = 0; j < 5; j++)
                rankings[i][buf[j] - 'A'] = j;
        }

        min_distance = 0x7FFFFFFF;
        for (i = 0; i < 5; i++)
            inverse_permutation[i] = i;
        
        foo(0);

        for (i = 0; i < 5; i++)
            min_permutation[i] += 'A';

        printf("%s is the median ranking with value %d.\n", min_permutation, min_distance);
    }
    return 0;
}
