TokenRing.java
import java.io.*;
import java.util.*;
public class token
{
	static int d[]=new int[100];
	static int l=0;
	public static void main(String args[])
	{
		int n,x,i,j,winner,max=-1,start;
		Scanner sc=new Scanner(System.in);	
		System.out.println("Enter the number of processes");
		n=sc.nextInt();
		winner=n;
		int a[]=new int[n+1];
		int s[]=new int[n+1];
		System.out.println("Enter the status of processes 1/0");
		for(i=0;i<n;i++)
		{
			a[i]=i;
			System.out.println("Enter the status of process "+i+" ");
			s[i]=sc.nextInt();
		}
		System.out.println("Enter the process initiator");
		x=sc.nextInt();
		start=i;
		for(i=x;i<n;i++)
		{
			if(s[i]==1)
			{
				if((i+1)<n)
				{
					if(s[i+1]==1)	
					{
				System.out.println("Election message is sent from "+i+" to "+(i+1));
						d[l]=i;
						l++;
						print();
						winner=i+1;
						//start++;
					}
				}
			}
		}
		System.out.println("Election message is sent from "+winner+" to 0");
		d[l]=winner;
		l++;
		print();
		for(i=0;i<x;i++)
		{
			if(s[i]==1)
			{
				if((i+1)<n)
				{
					if(s[i+1]==1)	
					{
						System.out.println("Election message is sent from "+i+" to "+(i+1));
						d[l]=i;
						l++;
						print();
					}
				}
			}
		}
		for(i=0;i<l;i++)
		{
			if(d[i]>max)
				max=d[i];
		}
		System.out.println("Co-ordinator is "+max);
		
		/*for(i=0;i<n;i++)
		{
			if(s[i]==1&&max!=i)
			{
				System.out.println("Confirmation message sent from "+winner+" to "+i);
			}
		}*/
	}
	public static void print()
	{
		System.out.print("Token received:");
		for(int i=0;i<l;i++)	
			System.out.print(d[i]+",");
		System.out.println();
	}
}
