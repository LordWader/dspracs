MulClientTime.java
//Berkely Algorithm Client
import java.net.*;
import java.util.*;
class  MulClientTime
{   public static int serverPort=998;
     public static int clientPort;
	  public static int buffer_size=1024;
	   public  static DatagramSocket ds;
      public static byte buffer[]=new byte[buffer_size];
	  	
	public static void theclient() throws Exception
	{
	  Date d=new Date();
	  long l=d.getTime();
	  String str=Long.toString(l);
	  System.out.println("Current client TIME:"+str+"-"+d.toString());
	  buffer=str.getBytes();//convert string to bytes
	 ds.send(new DatagramPacket(buffer,buffer.length,InetAddress.getByName("ideacomp"),serverPort));
  System.out.println("Time Sent to server");
	 //recieve new time from server program
	 DatagramPacket p=new DatagramPacket(buffer,buffer.length);
	 ds.receive(p);
	 String newtimest=new String(p.getData(),0,p.getLength());
	 System.out.println("New time recieved:"+newtimest);
	 long newtime=Long.parseLong(newtimest);

	 //set clent machine to new value
	 d.setTime(newtime);
     System.out.println("Client time set to new value-"+d.toString());
	 } 
	  
	public static void main(String[] args) throws Exception
	{
		if(args.length==1)
		{ try
			{
			clientPort=Integer.parseInt(args[0]);
			}
		  catch(Exception e){System.out.println("exception Occured in main:"+e);}
	      ds=new DatagramSocket(clientPort);
		  theclient();
		}
		else
           System.out.println("Check command line arguments it should be Port no. of client");
		
	}
}

MulClientTime.java
//Berkely Algorithm Time Server(Daemon)
import java.net.*;
import java.nio.ByteBuffer;
import java.util.*;

class  MulServerTime1
{    public static int sereverPort=998;
     public static int clientPort[];
	 public static long clientTime[];
     public static String clientName[];
	 public static int argl;
	 public static int buffer_size=1024;
	  public static DatagramSocket ds;
      public static byte buffer[]=new byte[buffer_size];
	
	public static void theserver()throws Exception
	{
	 System.out.println("Welcome to server program..");

	 //recieve system time from clients
	for(int i=0;i<argl;i++)
		{
		DatagramPacket p=new DatagramPacket(buffer,buffer.length);
		ds.receive(p);
		String ctime=new String(p.getData(),0,p.getLength());
		System.out.println("Client time recieved:"+ctime);
		clientTime[i]=Long.parseLong(ctime);
		}
	
	//find out the server clock elapse
	  Date d=new Date();
	  long ls=d.getTime();
	  System.out.println("Server Time:"+ls+"-"+d.toString());
     
	 //find out the new aveage time for clock synchronization
	 long avg=0;
	 for(int i=0;i<argl;i++)
		avg+=clientTime[i];
	  avg=avg/argl;//find avg of all clients
	  
	  long newTime=(ls+avg)/2;
      System.out.println("New Time 4 Synchronization: "+newTime);

    //return new value to the clients
	 String stnewt=Long.toString(newTime);
	 buffer=stnewt.getBytes();
	 
	 for(int i=0;i<argl;i++)
		ds.send(new DatagramPacket(buffer,buffer.length,InetAddress.getByName(clientName[i]),clientPort[i]));
    System.out.println("New Time sent to all clients");

	//set Server Clock to new value
	 d.setTime(newTime);
	 System.out.println("System clock set to new Value-"+d.toString()+"\n...bye");
	}

	public static void main(String[] args) throws Exception
	{   if(args.length!=0)
		{
		 try
	     {
		 argl=Integer.parseInt(args[0]);
                      //allocate memory to arrays storing port no. , syastem name time
		 clientPort=new int[argl];
		 clientTime=new long[argl];
		 clientName=new String[argl];	 
		 if(args.length==2*argl+1)
			{ for(int i=0;i<argl;i++)
				{
			     clientPort[i]=Integer.parseInt(args[i+1]);
				}
              for (int i=0;i<argl ;i++ )
              {
				  	clientName[i]=args[argl+i+1];
              }
		      ds=new DatagramSocket(sereverPort);
		      theserver();
			}
         else 
			System.out.println("Check command line arguments it should be no. of cliets port nos of clients");

		 }catch(Exception e){ System.out.println("exception occured in main"+e);}
		}
		else
			 System.out.println("Check command line arguments it should be no. of clients port nos of clients");
		
	}//end main
}
