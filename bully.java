Bully.java
import java.io.*;
import java.util.Scanner;
 
class Bully{
    static int n;
    static int pro[] = new int[100];
    static int sta[] = new int[100];
    static int co;
     
    public static void main(String args[])throws IOException
    {
        System.out.println("Enter the number of process");
        Scanner in = new Scanner(System.in);
        n = in.nextInt(); 
        int i,j,k,l,m; 
        for(i=0;i<n;i++)
        {
            System.out.println("For process "+i+":");
            System.out.println("Status:");
            sta[i]=in.nextInt();
            System.out.println("Priority");
            pro[i] = in.nextInt(); }
        System.out.println("Which process will initiate election?");
        int x = in.nextInt(); 
        for(i=x;i<n;i++)
	{
		if(sta[i]==1)
		{
			for(j=i+1;j<n;j++)
				{
					if(sta[j]==1)
					{
					System.out.println("Election message is sent from "+i+" to "+j);
						co=j;
					}
				}
		}
	}
	System.out.println("Co-ordinator is "+co);
		for(i=0;i<n;i++)
		{
			if(sta[i]==1&&co!=i)
			{
				System.out.println("Confirmation message sent from "+co+" to "+i);
			}
		}
    }
}
