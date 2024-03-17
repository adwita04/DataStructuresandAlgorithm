/*
Name: Adwita Deshpande
Roll no.: 2203303
Branch: MnC 2022

*/

#include <stdio.h>
void plot();
int main()
{
    char c='Y'; 
    while(c == 'Y' || c == 'y') //loop to repeat if you want to continue
    {
        plot(); //function call
        printf("Do you want to continue? ");
        scanf(" %c", &c);
    }
    return 0;
}

void plot()
{
    int x,y,xpos,ypos;
    printf("Enter the value of x,y:\t");
    scanf("%d%d",&x,&y); //input coordinates
    xpos = 19+x; //relative postion 
    ypos = 10-y;
    for(int i=0;i<23;i++) //outer loop to go to different lines in the y direction
    {
        for(int j=0;j<40;j++) //inner loop for x-direction 
        {
            if(x>=0) //if in 1st and 4th quadrant
            {
                if(j==xpos && i == ypos) //find point
                {
                    printf(".");
                    printf("(%d,%d)",x,y);
                    j=j+4; //increment after labeling
                }
            }
            else if(x<0) 
            {
                if (y>=0) //if in 2nd quadrant
                {
                    if(j==xpos-6 && i == ypos) //label (-x,y) takes 6 characters before point
                    {
                        printf("(%d,%d)",x,y);
                        printf(".");
                        j=j+7; //increment after labeling
                    }
                }
                else //if in 3rd quadrant
                {
                    if(j==xpos-7 && i == ypos) //label (-x,-y) takes 7 characters before point
                    {
                        printf("(%d,%d)",x,y);
                        printf(".");
                        j=j+8; //increment after labeling
                    }
                }
            }
            if(j==18) //print arrows and label Y axis
            {
                if(i==0)
                {
                    printf(" Y");
                    break;
                }
                if(i==1)
                {
                    printf("/|\\");
                    break;
                }
                else if(i==22)
                {
                    printf("\\|/");
                    break;
                }
            }
            else if(j==19) //print axes
            {
                if(i==10)
                {
                    printf("-");
                    continue;
                }
                else
                {
                    printf("|");
                    continue;
                }
            }
            if(i==10) //print X axis arrows 
            {
                if(j==0)
                    printf("<");
                else if(j==39) 
                    printf(">X");
                else
                    printf("-");
            }
            else //print space
                printf(" ");  
        }
        printf("\n"); //new line
    }
}