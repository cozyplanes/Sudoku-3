#include<stdio.h>
#include<stdlib.h>
void build_board(int a[][9])
{
    int i,j;
    printf("Enter the board:\n");
    for(i=0;i<9;i++)
     for(j=0;j<9;j++)
      scanf("%d",&a[i][j]);
    return ;
}

void display_board(int a[][9])
{
    int i,j;
    for(i=0;i<9;i++)
    {
	for(j=0;j<9;j++)
	{
	    printf("%d  ",a[i][j]);
	}
	printf("\n");
    }
 return ;
}
int row_check(int a[][9],int i,int j,int k)
{
    int m;
    for(m=0;m<9;m++)
	if(a[i][m]==k)
	  return 0;
    return 1;
}
int column_check(int a[][9],int i,int j,int k)
{
    int m;
    for(m=0;m<9;m++)
       if(a[m][j]==k)
	 return 0;
    return 1;
}
int box_check(int a[][9],int i,int j,int k)
{
    int n,m;
    if(i==0 || i==3 || i==6)
    {
	if(j==0 || j==3 || j==6)
	{
	    for(n=i;n<i+3;n++)
		 for(m=j;m<j+3;m++)
		    if(a[n][m]==k)
		     return 0;

	}
	if(j==1 || j==4 || j==7)
	{
	    for(n=i;n<i+3;n++)
	       for(m=j-1;m<j+2;m++)
		 if(a[n][m]==k)
		  return 0;
	}
	if(j==2 || j==5 || j==8)
	{
	    for(n=i;n<i+3;n++)
	      for(m=j-2;m<j+1;m++)
		 if(a[n][m]==k)
		   return 0;
	}
    }


    if(i==1 || i==4 || i==7)
    {
	if(j==0 || j==3 || j==6)
	{
	    for(n=i-1;n<i+2;n++)
	      for(m=j;m<j+3;m++)
		if(a[n][m]==k)
		  return 0;
	}
	if(j==1 || j==4 || j==7)
	{
	    for(n=i-1;n<i+2;n++)
	      for(m=j-1;m<j+2;m++)
		if(a[n][m]==k)
		  return 0;
	}
	if(j==2 || j==5 || j==8)
	{
	    for(n=i-1;n<i+2;n++)
	      for(m=j-2;m<j+1;m++)
		if(a[n][m]==k)
		  return 0;
	}
    }


    if(i==2 || i==5 || i==8)
    {

	if(j==0 || j==3 || j==6)
	{
	    for(n=i-2;n<i+1;n++)
	     for(m=j;m<j+3;m++)
	       if(a[n][m]==k)
		 return 0;
	}
	if(j==1 || j==4 || j==7)
	{
	    for(n=i-2;n<i+1;n++)
	     for(m=j-1;m<j+2;m++)
	       if(a[n][m]==k)
		 return 0;
	}
	if(j==2 || j==5 || j==8)
	{
	    for(n=i-2;n<i+1;n++)
	     for(m=j-2;m<j+1;m++)
	       if(a[n][m]==k)
		 return 0;
	}
    }
    return 1;
}
void compute(int a[][9])
{
    int i,j,k,z=1;
    int stk1[100],stk2[100],stk3[100];
    int top1=-1,top2=-1,top3=-1;
    int row=0,col=0,box=0;
    for(i=0;i<9;i++)
    {
	for(j=0;j<9;j++)
	{
	    if(a[i][j]==0)
	    {
	     z=1;
	      vadi1:for(k=z;k<10;k++)
		{
		    row=row_check(a,i,j,k);
		    col=column_check(a,i,j,k);
		    box=box_check(a,i,j,k);
		    if(row && col)
		    {
			if(box)
			{
			    a[i][j]=k;
			    stk1[++top1]=i;
			    stk2[++top2]=j;
			    stk3[++top3]=k;
			    goto vadi;
			}
		    }
		}
		if(k==10)
		{
		    a[i][j]=0;
		    i=stk1[top1--];
		    z=stk3[top3--]+1;
		    j=stk2[top2--];
		    goto vadi1;
		}

	    }
	    vadi: ;
	}
	z=1;
    }
}
int main()
{
    int a[9][9];
    build_board(a);
    printf("\nThe entered Board is:\n");
    display_board(a);
    compute(a);
    printf("\nThe solution is:\n");
    display_board(a);
    printf("\nThanks for Using!!!!Greatings from VADIRAJ JAHAGIRDAR\nBye");
    return 0;
}

