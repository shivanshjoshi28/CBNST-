#include "Gauss_seidel.h"
#include "Gauss_elimination.h"
#include "Regular_falsy_method.h"
#include "Newton_Raphson.h"
#include "Gauss_jordan.h"
extern double f1(double a);
extern void startBisection();
int main()
{
    printf(" *** Welcome to Equation Solving !! *** \n");
    int ch;
    char ch1='y';
    do
    {
        printf("Enter 1 for finding roots of polynomials \nEnter 2 for finding roots of equation with n numbers of variables \n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                printf("Enter \n");
                printf("1- Bisection Method with Equation input \n2- Regular Falsi Method with Graph Output \n3- Newton Raphson Method \n");
                int insidechoise;
                scanf("%d",&insidechoise);
                switch (insidechoise)
                {
                    case 1:
                        startBisection();
                        break;
                    case 2:
                        startRegular_Falsy();
                        break;
                    case 3:
                        startNewton_Raphson();
                        break;
                    default:
                        printf("Invalid Choise \n");
                        break;
                }

                break;
            case 2:
                printf("Enter \n");
                printf("1- Gauss Elimination Method \n2- Gauss Jordan Method \n3- Gauss Seidel Method \n");
                int insidechoise1;
                scanf("%d",&insidechoise1);
                switch (insidechoise1)
                {
                    case 1:
                        startGauss_Elimination();
                        break;
                    case 2:
                        startGauss_Jordan();
                        break;
                    case 3:
                        startGauss_Seidel();
                        break;
                    default:
                        printf("Invalid Choise \n");
                        break;
                }
                break;
            default:
                printf("Invalid Input\n");
                break;
        }
        fflush(stdin);
        printf("\nDo you want to run again !! Enter 'y' or 'n'\n");
        scanf("%c",&ch1);
    }while(ch1=='y'|| ch1=='Y');
    return 0;
}