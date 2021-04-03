#include<stdio.h>
#include<conio.h>
#include<math.h>
float calcf(float x)
{
    return ( x*x*x- 4*x-9);
}
float df(float x)
{
    return ( 3*x*x- 4);
}
int startNewton_Raphson()
{
    printf("\n\n*** Newton Raphson Method ***\n\n");
    printf("Equation x^3-4x-9=0 is Solved\n");
    int iter;
    float c,tol;
    printf("Enter the expected starting starting point : ");
    scanf("%f",&c);
    printf("Enter the no. of iteration : ");
    scanf("%d",&iter);

    printf("Enter the tolerance : ");
    scanf("%f",&tol);
    for(int i=0;i<iter;i++)
    {
        float d= c- calcf(c)/df(c);
        if(fabs(c-d)<=tol)
        {
            printf("You have got the answer : %f",d);
            break;
        }
        else
            printf("Your c at iteration %d is : %f and d at iteration %d is : %f\n",i+1,c,i+1,d);
        c=d;
    }
    return 0;
}

