CODE-
///////////////////// Hello.java ///////////////////// 
//This is Remote Interface
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Hello extends Remote 
{
    String sayHello() throws RemoteException;
}

///////////////////// Server.java /////////////////////
import java.rmi.registry.Registry;
import java.rmi.registry.LocateRegistry;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
        
public class Server implements Hello 
{      
    public Server() {}

    public String sayHello() 
    {
        return "Hello, world!";
    }
        
    public static void main(String args[]) 
    { 
        try 
        {
            // Create the remote object that provides the service and export to the
            // Java RMI runtime so that it may receive incoming remote calls 
 
            Server obj = new Server();
            Hello stub = (Hello) UnicastRemoteObject.exportObject(obj, 0);

            // Bind the remote object's stub in the registry
            // Obtain a stub for a registry on the local host and default registry 
            // port and then uses the registry stub to bind the name "Hello" to the
            // remote object's stub in that registry 
 
            Registry registry = LocateRegistry.getRegistry();
            registry.bind("Hello", stub);

            System.err.println("Server ready");
        } 
        catch (Exception e) 
        {
            System.err.println("Server exception: " + e.toString());
            e.printStackTrace();
        }
    }
}
 
///////////////////// Client.java /////////////////////
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client 
{
    private Client() {}

    public static void main(String[] args) 
    {
        String host = (args.length < 1) ? null : args[0];
        try 
        {
            Registry registry = LocateRegistry.getRegistry(host);
            Hello stub = (Hello) registry.lookup("Hello");
            String response = stub.sayHello();
            System.out.println("response: " + response);
        } 
        catch (Exception e) 
        {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }  }}
