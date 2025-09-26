
/********************************************
 * Singly Linked Node Class for Question 1 
 * 
 * @title Node class
 * @author Chukwunonso Ekweaga
 ********************************************/
public class Node<Type>
{
    //instance variables  
    private Type data;
    private Node<Type> next;

    /*****************************************************************
     * Constructot that creates a new node containing specified data
     * 
     * @param data - The element to store in this node
     *****************************************************************/
    public Node(Type x)
    { 
        this.data = x;
        next = null; 
    }
    
    /*******************************************************
     * Method to get the data stored in the node
     * 
     * @return data - the data stored in the node
     *******************************************************/
    public Type getData()
    {
        return data;
    } 
    
    /****************************************************
     * Method to get the next node in the list
     * 
     * @return next - Reference to next node (or null)
     ****************************************************/
    public Node<Type> getNext()
    { 
        return next;
    }
    
    /**************************************************
     * Method to update the next node in the LinkedList
     * 
     * @param s - the next node to be set
     **************************************************/
    public void setNext(Node<Type> s)
    {
        this.next = s; 
    }
         
    /********************************************************
     * Method to return a string representation of the node
     * 
     * @return result - Data contents as string
     ********************************************************/
    @Override
    public String toString()
    {
        String result = "Data: " + data;
        return result; 
    }   
}

