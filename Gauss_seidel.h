#include<stdio.h>
#include<string.h>
#include<math.h>
#include<conio.h>
int setcoefseidel(int start,int end,char *s)
{
    int number=0;
    int sign=-1;
    if(s[start]=='+')
    {
        start++;
        sign=0;

    }
    else if(s[start]=='-')
    {
        start++;
        sign=1;
    }
    int play=0;
    for(int i=start;i<end;i++)
    {
        play=1;
        number=number*10+(int)(s[i]-'0');
    }
    if(play==0)
    {
        number=1;
    }
    if(sign==1)
    {
        number*=-1;

    }
    return number;
}
int startGauss_Seidel()
{
    printf("\n\n*** Gauss Seidel Method ***\n\n");
    int n;
    printf("Enter the order of equation : ");
    scanf("%d",&n);
    float x[10];
    printf("\nEnter the equation in the form of pa+qb+rc=constant :: \n");
    int alphabetindexarr[26];
    float mat[10][10+1];
    char *alphabet="abcdefghijklmnopqrstuvwxyz";
    for(int j=0;j<n;j++)
    {
        fflush(stdin);
        char s[1000];
        gets(s);
        for(int i=0;i<strlen(alphabet);i++)
        {
            if(strrchr(s,alphabet[i])==NULL)
            {
                alphabetindexarr[i]=-1;
            }
            else
            alphabetindexarr[i]=strrchr(s,alphabet[i])-s;
        }
        for(int k=0;k<n;k++)
        {
            if(alphabetindexarr[k]==-1)
            {
                mat[j][k]=(float)0;
            }
            else
            {
                int pos=alphabetindexarr[k];
                int prevpos;
                int i=k-1;
                while(alphabetindexarr[i]<0)
                {
                    i--;
                    if(i<0)
                    {
                        break;
                    }
                }
                if(i==-1)
                {
                    prevpos=-1;
                }
                else
                {
                    prevpos=alphabetindexarr[i];
                }
                float a=(float)setcoefseidel(prevpos+1,pos,s);//code for calculating the coefficient .
                mat[j][k]=a;
            }

        }
        mat[j][n]=(float)setcoefseidel(strrchr(s,'=')-s+1,strlen(s),s);
        printf("\n");
    }



    printf("\n**** Input matrix **** \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            printf("%f ",mat[i][j]);
        }
        printf("\n");
    }

    fflush(stdin);

    printf("Enter the iteration and tolerance :: ");
    int iteration ;float tolerance;
    scanf("%d %f",&iteration,&tolerance);
    char ch;
    fflush(stdin);
    printf("Do you want to enter the initial vaue of a,b,c... (Y or N): ");
    scanf("%c",&ch);
    if(ch=='y'|| ch=='Y')
    {
        for(int i=0;i<n;i++)
        {
            printf("Enter x[%d] : ",i);
            scanf("%f",&x[i]);
        }

    }
    else
    memset(x,0,n*sizeof(float));
    float e;
    for(int i=1;i<=iteration;i++)
    {
        float max=0;
        for(int j=0;j<n;j++)
        {
            int sum=0;
            for(int k=0;k<n;k++)
            {
                if(j!=k) sum+=mat[j][k]*x[k];
            }
            float t=(mat[j][n]-sum)/mat[j][j];
            e=fabs(x[j]-t);
            if(e>max) max=e;
            x[j]=t;
        }
        printf(" %d\t",i);
        for(int i=0;i<n;i++)
        printf(" %20.4f\t",x[i]);
        printf(" %20.4f\n",max);
        if(max<tolerance)
        {
            printf("We got answer :) \n");
            for(int j=0;j<n;j++)
            {
                printf("%c = %f \n",alphabet[j],x[j]);
            }
            return 0;

        }
    }
    printf("Sorry ! The answer might not be correct \n");
    return 0;
}