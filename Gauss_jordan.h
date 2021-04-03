#include<stdio.h>
#include<string.h>
#include<conio.h>
int setcoefjordan(int start,int end,char *s)
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
int startGauss_Jordan()
{
    printf("\n\n*** Gauss Elimination Method ***\n\n");
    int n;
    printf("Enter the order of equation : ");
    scanf("%d",&n);
    float x[100];
    printf("\nEnter the equation in the form of pa+qb+rc=constant :: \n");
    int alphabetindexarr[26];
    float mat[100][100+1];
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
                // printf("check string from %d to %d\n",prevpos+1,pos);
                
                float a=(float)setcoefjordan(prevpos+1,pos,s);//code for calculating the coefficient .
                mat[j][k]=a;
            }

        }
        mat[j][n]=(float)setcoefjordan(strrchr(s,'=')-s+1,strlen(s),s);
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


    //first method 
    // for(int i=0;i<n-1;i++)
    // {
    //     for(int j=i+1;j<n;j++)
    //     {
    //         float t=mat[j][i]/mat[i][i];
    //         cout<<"mat[j][i]="<<mat[j][i]<<" i= "<<i<<"j= "<<j<<endl;
    //         for(int k=0;k<n+1;k++)            
    //         {
    //         float Toreduceby = mat[i][k]*t;
    //             mat[j][k]=mat[j][k]-(Toreduceby);
    //         }
    //     }
    // }


    //second method( better )
    for(int j=0;j<n;j++)
    {

        // code for checking parallel lines 
            if (mat[j][j] == 0) {
            for (int i = j + 1; i< n; i++) {
                if (mat[i][j] != 0) {
                    for (int k = 0; k < n + 1; k++) {
                        float temp = mat[j][k];
                        mat[j][k] = mat[i][k];
                        mat[i][k] = temp;
                    }
                }
            }
        }
        if (mat[j][j] == 0) {
            fprintf(stderr, "Given system of eq do not have a Unique Solution.");
            return 0;
        }
        //code ends here
        
        for(int i=0;i<n;i++)
        {
            if(i!=j)
            {
                float c=mat[i][j]/mat[j][j];
                for(int k=0;k<n+1;k++)
                {
                    mat[i][k]=mat[i][k]-c*mat[j][k];
                }
            }
        }
    }

    //for debugging (after making 0's )
    printf("\n**** After Gauss Jordan ****\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            printf("%f ",mat[i][j]);
        }
        printf("\n");
    }

    printf("\nThe solution is:\n");
    for(int i=0; i<n; i++)
    {
        x[i]=mat[i][n]/mat[i][i];
        printf("\n %c =%f\n",alphabet[i],x[i]);
    }

    return 0;
}