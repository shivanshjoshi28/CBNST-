
#include <conio.h>
#include <stdio.h>
#include "pbPlots.h"
#include "supportLib.h"
#include<math.h>
int thirdcoef,secondcoef,firstcoef,num,coeftrig;
char trig;
double f(double a)
{
    double rada=3.14159*a/180;
    if(trig=='c')
    {
        return ((thirdcoef*rada*rada*rada)+(secondcoef*rada*rada)+(firstcoef*rada)+num+(coeftrig*cos(rada)));
    }
    else if(trig==' ')
    {
        return ((thirdcoef*a*a*a)+(secondcoef*a*a)+(firstcoef*a)+num);
    }
        else if(trig=='l')
    {
        return ((thirdcoef*a*a*a)+(secondcoef*a*a)+(firstcoef*a)+num+(coeftrig*log10(a)));
    }
    else
        return ((thirdcoef*rada*rada*rada)+(secondcoef*rada*rada)+(firstcoef*rada)+num+(coeftrig*sin(rada)));
}
void drawGraph(double sb,double sa,double c)
{
    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();


    int size=(sb-sa+20)*1;
    double *xarr,*yarr;
    xarr=(double*) malloc(size*sizeof(double));
    yarr=(double*) malloc(size*sizeof(double));
    int k=0;
    printf("size = %d",size);
    for(double i=sa-10;i<sb+10;i+=1)
    {
        xarr[k]=i;
        yarr[k]=f(i);
        k++;
    }
    double xarr2[2]={c,c};
    double yarr2[2]={-50,50};




	ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
	series->xs = xarr;
	series->xsLength = size;
	series->ys = yarr;
	series->ysLength = size;
	series->linearInterpolation = true;
	series->pointType = L"dashed";
	series->pointTypeLength = wcslen(series->lineType);
	series->lineThickness = 2;
	series->color = CreateRGBColor(1, 0, 0);

	ScatterPlotSeries *series2 = GetDefaultScatterPlotSeriesSettings();
	series2->xs = xarr2;
	series2->xsLength = sizeof(xarr2)/sizeof(double);
	series2->ys = yarr2;
	series2->ysLength = sizeof(yarr2)/sizeof(double);
	series2->linearInterpolation = true;
	series2->lineType = L"solid";
	series2->lineTypeLength = wcslen(series->lineType);
	series2->lineThickness = 2;
	series2->color = CreateRGBColor(0, 0, 1);

	ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
	settings->width = 600;
	settings->height = 400;
	settings->autoBoundaries = true;
	settings->autoPadding = true;
	settings->title = L"3*x^3 + x^2 + 2*x -6+5*cos(x)";
	settings->titleLength = wcslen(settings->title);
	settings->xLabel = L"X axis";
	settings->xLabelLength = wcslen(settings->xLabel);
	settings->yLabel = L"Y axis";
	settings->yLabelLength = wcslen(settings->yLabel);
	ScatterPlotSeries *s [] = {series, series2};
	settings->scatterPlotSeries = s;
	settings->scatterPlotSeriesLength = 2;


	DrawScatterPlotFromSettings(imageReference, settings);

	size_t length;
	double *pngdata = ConvertToPNG(&length, imageReference->image);
	WriteToFile(pngdata, length, "RegularFalsy_Output.png");
	DeleteImage(imageReference->image);

	printf("\nSuccessfully created graph\n");

}


int startRegular_Falsy()
{
    printf("*** Regular Falsi Method ( With Graph ) ***\n");
    printf("Solving equation (3x^3 + x^2 - 2x + 5 cos(x) -6 =0) \n");
    thirdcoef=3;
    secondcoef=1;
    firstcoef=-2;
    num=-6;
    coeftrig=5;
    trig='c';
    double a,b;
    double sa,sb;
    bool set=false;

    while(1)
    {
        printf("Enter the approximate range :: ");
        scanf("%lf %lf",&a,&b);
        if(!set)
        {
            set=true;
            sb=b;
            sa=a;
        }
        if(f(a)*f(b)>0)
        {
            printf("Please Try again \n");
            set=false;
        }
        else if(f(a)==0)
        {
            printf("Root is %lf\n",a);
            drawGraph(sb,sa,a);
            exit(0);
            break;
        }
        else if(f(b)==0)
        {
            printf("Root is %lf\n",b);
            drawGraph(sb,sa,b);
            exit(0);
            break;
        }
        else
        {
            break;
        }
    }
        int iter;
        double tol;
        printf("Enter the iteration and tolerance :");
        scanf("%d %lf",&iter,&tol);
        for(int i=0;i<iter ;i++)
        {
            double c= (double) ((a*f(b)- b*f(a))/(f(b)-f(a)));
            printf("At %d a= %lf ,b= %lf\n",i+1,a,b);
            printf("f(a)= %lf  f(b)= %lf\n",f(a),f(b));


            double temp=c;
            printf("At %d temp= %lf\n",i+1,temp);

            if(f(c)==0)
            {
                printf("Root is : %lf \n",c);
                drawGraph(sb,sa,c);
                exit(0);
                break;
                exit(0);
            }
            if(f(a)*f(c)<0)
            {
                b=c;
            }
            else 
            {
                a=c;
            }
            c= (double )(a*f(b)- b*f(a))/(f(b)-f(a));


            if(fabs(temp-c)<tol)
            {
                printf("temp= %lf c= %lf\n",temp,c);
                printf("Got final answer as %lf \n",c);
                drawGraph(sb,sa,c);

                exit(0);
                break;
            }
            else
            {
                printf("In iteration no. %d we have a= %lf and b= %lf and got c as %lf",i+1,a,b,c);
            }
            
        }
        printf("Sorry your equation can't be solved ... Please increase the no. of iteration !! It might help You !!\n");
    return 0;
}







