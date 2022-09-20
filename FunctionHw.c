#include <stdio.h>
#include <math.h>

float getY(float);
float getX(float, float, float);
int getPointAvailability(float);
float inputNumber(char[]);
float getStepSize(float, float, float);
void printRow(float, float, int);

int main(void)
{
    // declare all the required variables
    
    float x;
    float y;

    float A = inputNumber("insert A: ");
    float B = inputNumber("insert B: ");
    float N = inputNumber("insert N: ");

    float H = getStepSize(A, B, N);

    int points = N;

    if(points > 15){
        points = 15;
    }

    float xs[points];
    float ys[points];
    int availabilities[points];

    for (int i = 0; i < points; i++)
    {
        x = getX(A, H, i); // calculate the x value for ecah step
        xs[i] = x;
        availabilities[i] = getPointAvailability(x);
        if(availabilities[i] == 1){
            y = getY(x); // calculate the y value for each step
            ys[i] = y;
        } else {
            ys[i] = y;
        }
    }

    for (int i = 0; i < points; i++)
    {
        printRow(xs[i], ys[i], availabilities[i]);
    }
    return 0;

}

float inputNumber(char message[])
{
    float number;
    printf("%s", message);
    scanf("%f", &number);
    return number;
}

float getStepSize(float A, float B, float N)
{
    float H = (B - A) / (N - 1);
    return H;
}

float getX(float A, float H, float i)
{
    float x = A + H * i;
    return x;
}

int getPointAvailability(float x){
    if(x == 0){
        return 0;
    } else {
        return 1;
    }
}

float getY(float x){
    float y;
    y = x + (x / (x + (pow(x, 2) / (x + ((pow(x, 3)) / 5)))));
    return y;
}

void printRow(float x, float y, int availability){
    if(availability == 1){
        printf("%f\t%f\n", x, y);
    } else {
        printf("%f\t%s", x, "N/A");
    }
}
