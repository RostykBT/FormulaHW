#include <stdio.h>
#include <math.h>

float getY(float);

int main(void)
{
    // declare all the required variables
    float A, B, N;
    float x;
    float H;
    float y;

    // input values
    printf("Enter A: ");
    scanf("%f", &A);

    printf("Enter B: ");
    scanf("%f", &B);

    printf("Enter N: ");
    scanf("%f", &N);

    H = (B - A) / (N - 1); // calculate the step size

    for (int i = 0; i < N && i < 15; i++)
    {
        x = A + i * H; // calculate the x value for ecah step

        if (x == 0) // exclde the case of x = 0, as the value of y is undefined
        {
            printf("%f\t", x);
            printf("not avilable\n");
        }
        else
        {   
            printf("%f\t", x);
            printf("%f\n", getY(x));
        }
    }
    return 0;
}
float getY(float x){
    float y;
    y = x + (x / (x + (pow(x, 2) / (x + ((pow(x, 3)) / 5)))));
    return y;
}

