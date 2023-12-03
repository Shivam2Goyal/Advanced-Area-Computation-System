#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define RESET "\x1B[0m"
#define BOLD "\x1B[1m" 
float area;

float Exponential_Curve(){
    float a,b;
    printf("Enter the parameters(a, b) of the exponnential curve of form a^(bx): ");
    scanf("%f %f",&a,&b);
    float x1;
    printf("Enter the lower value of x = x1: ");
    scanf("%f", &x1);
    float x2;
    printf("Enter the higher value of x = x2: ");
    scanf("%f", &x2);
    printf("Enter the number of segments in which you want to divide your interval: ");
    int n;
    scanf("%d",&n);
    float h=(x2-x1)/n;
    float a1=0;
    for(int i=0;i<n;i++){
        a1+= pow(a,b*(x1+h*i))*h;
    }
    area=a1;
    printf("Area=%s%.2f%s",BOLD,area,RESET);
}
//---------------------------------------------------------------------------------------------------------------------------------------
float Linear_Curve(){
    printf("The Linear function is of the form: y = mx + c");
    printf("\n%sEnter the Asked information to find the area under the line:%s \n",BOLD,RESET);
    float m;
    printf("Enter the slope (m): ");
    scanf("%f",&m);
    float c;
    printf("Enter the y-intercept (c): ");
    scanf("%f", &c);
    float x1;
    printf("Enter the lower value of x = x1: ");
    scanf("%f", &x1);
    float x2;
    printf("Enter the higher value of x = x2: ");
    scanf("%f", &x2);
    float root = ((-1)*c)/m;
    if(x1>x2){
        printf("Given Instruction not followed");
    }
    else if(x1<root && x2>root){
        float a1 = fabs(((root - x1)*((m*x1)+c))/2);
        float a2 = fabs(((x2 - root)*((m*x2)+c))/2);
        area = a1+a2;
        printf("%s%.2f%s",BOLD,area,RESET);
    }else{
        area = ((fabs(((m*x1)+c)+((m*x2)+c)))/2)*(x2 - x1);
        printf("%s%.2f%s",BOLD,area,RESET);
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------
float Quadratic_Curve(){
    printf("The quadratic function is of the form: ax^2 + bx + c = 0\n");
    float a,b,c,p,q;
    printf("Enter values of a,b,c seperated by a whitespace: ");
    scanf("%f %f %f",&a,&b,&c);
    printf("Enter the interval under which you want to find the area in the form: [p,q]\n");
    //printf("Enter values of a,b,c seperated by a whitespace: ");
    scanf("%f %f",&p,&q);
    printf("Enter the number of segments in which you want to divide your interval: ");
    int n;
    scanf("%d",&n);
    float h = (q-p)/n;
    float a1 = 0;
    for(int i=0;i<n;i++){
        a1 += fabs(((a*(p+h*i)*(p+h*i))+(b*(p+h*i))+c)*h);
    }
    area=a1;
    printf("Area=%s%.2f%s",BOLD,area,RESET);
}
//---------------------------------------------------------------------------------------------------------------------------------------
float Rectanle(){
    printf("\n%sEnter the Dimensions of Rectangle:%s \n",BOLD,RESET);
    float b,l;
    printf("Enter the value of Breadth: ");
    scanf("%f",&b);
    printf("Enter the value of Length: ");
    scanf("%f",&l);
    area=fabs(b)*fabs(l);
    printf("\nArea: %s%.2f%s",BOLD,area,RESET);
}
//---------------------------------------------------------------------------------------------------------------------------------------
float Triangle(){
    printf("\n%sEnter the Dimensions of Truangle:%s \n",BOLD,RESET);
    float theta,s1,s2;
    printf("Enter the angle(In Degrees) between any 2 sides, let's say Side1 & Side2:");
    scanf("%f",&theta);
    theta=3.1416/180*theta;
    printf("Enter the lenght of Side1: ");
    scanf("%f",&s1);
    printf("Enter the lenght of Side2: ");
    scanf("%f",&s2);
    area=(0.5)*fabs(s1)*fabs(s2)*fabs(sin(theta));
    printf("\nArea: %s%f%s",BOLD,area,RESET);
}
//---------------------------------------------------------------------------------------------------------------------------------------
float Ellipse(){
    printf("\n%sEnter the Dimensions of Ellipse:%s \n",BOLD,RESET);
    float a,b;
    printf("Enter the lenght of Major axis: ");
    scanf("%f",&a);
    printf("Enter the lenght of Minor axis: ");
    scanf("%f",&b);
    area = (3.14)*fabs(a/2)*fabs(b/2);
    printf("\nArea: %s%.2f%s",BOLD,area,RESET);
}
//---------------------------------------------------------------------------------------------------------------------------------------
float Trapezium(){
    printf("\n%sEnter the Dimensions of Trapezium:%s \n",BOLD,RESET);
    float a,b,h;
    printf("Enter the Lenght of any one of that parallel sides: ");
    scanf("%f",&a);
    printf("Enter the Lenght of the other parallel side: ");
    scanf("%f",&b);
    printf("Enter the seperation between the parallel sides: ");
    scanf("%f",&h);
    area = ((fabs(a)+fabs(b))/2)*fabs(h);
    printf("\nArea: %s%.2f%s",BOLD,area,RESET);
}
//---------------------------------------------------------------------------------------------------------------------------------------
float Circle(){
    float r;
    printf("\n%sEnter the Dimensions of the Circle:%s \n",BOLD,RESET);
    printf("Enter the Radius of the Circle: ");
    scanf("%f",&r);
    area=3.14159*fabs(r)*fabs(r);
    printf("\nArea: %s%.2f%s",BOLD,area,RESET);
}
//---------------------------------------------------------------------------------------------------------------------------------------
float Regular_Hexagon(){     
   float a;
   printf("\n%sEnter the Dimensions of the regular hexagon:%s \n",BOLD,RESET);
   printf("Enter the Side length of Regualr Hexagon: ");
   scanf("%f",&a);
   area=1.5*1.732*fabs(a)*fabs(a);
   printf("\nArea: %s%.2f%s",BOLD,area,RESET);
}
//---------------------------------------------------------------------------------------------------------------------------------------
float Rectangular_Arena(){
   float l,b,r;
   printf("\n%sEnter the Dimensions of the rectangular arena:%s \n",BOLD,RESET);
   printf("Enter the value of length: ");
   scanf("%f",&l);
   printf("Enter the value of breadth: ");
   scanf("%f",&b);
   r=b/2;
   area=(3.14159*fabs(r)*fabs(r)) + (fabs(l)*fabs(b));
   printf("\nArea: %s%.2f%s",BOLD,area,RESET);
}
//---------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    int n;
    printf("%sThis is the program to calculate AREA\nChoose a shape by pressing the corresponding number to calculate its area.%s\n",BOLD,RESET);
    printf("Press 1 for Rectangle\n");
    printf("Press 2 for Triangle\n");
    printf("Press 3 for Ellipse\n");
    printf("Press 4 for Trapezium\n");
    printf("Press 5 for Circle\n");
    printf("Press 6 for Regular Hexagon\n");
    printf("Press 7 for Rectangular Arena\n");
    printf("Press 8 for Linear Curve\n");
    printf("Press 9 for Quadratic curve\n");
    printf("Press 10 for Exponential curve\n");
    label:
    printf("%sEnter the Shape Number:%s ",BOLD,RESET);
    scanf("%d",&n);
        if(n==1){
            Rectanle();
        }
        else if(n==2){
            Triangle();            
        }
        else if(n==3){
           Ellipse();
        }
        else if(n==4){
            Trapezium();
        }
        else if(n==5){
            Circle();
        }
        else if(n==6){
            Regular_Hexagon();
        }
        else if(n==7){
            Rectangular_Arena();
        }
        else if(n==8){
            Linear_Curve();
        }
        else if(n==9){
            Quadratic_Curve();
        }
        else if(n==10){
            Exponential_Curve();
        }
        else{
            printf("\t->Please enter the value between 1 to 10\n");
            goto label;
        }
//---------------------------------------------------------------------------------------------------------------------------------------
        int opt;
        printf("\nThe area is calculated in m^2.\nDo you wish to print area in other units?\nAnswer in Yes(1) or No(0)\n");
        label1:
        scanf("%d",&opt);
        if(opt==1){
            int temp;
            printf("Please select the desired unit: \n");
            printf("1. cm^2\n2. in^2\n");
            scanf("%d",&temp);
            if(temp==1){
            area=10000*area;
           }
           else if(temp==2){
            area=1550*area;
           }
           else{
            printf("Enter a valid option number.\n");
           }
           printf("\nArea in the required unit is: %s%.2f%s",BOLD,area,RESET);
        }
        else if(opt==0){
            printf("Ok then;");
        }
        else{
            printf("Error, invalid option.\n Do you wish to go to previous step:yes=1;no=0");
            int p;
            scanf("%d",&p);
            if(p==1){
                goto label1;
            }
            else if(p==0){
            }
            else{
                printf("Area converter shutted down.");
            }
        }
        
//---------------------------------------------------------------------------------------------------------------------------------------
        int t;
        printf("\nPress 1 to again calculate area, 0 to quit\n");
        scanf("%d",&t);
        if(t==1){
            goto label;
        }
        else if(t==0){
            printf("Thank You\n  %sHAPPY CODING%s",BOLD,RESET);
            return 0;
        }else{
            printf("No a valid value, program executed");
        }
        return 0;
    }
