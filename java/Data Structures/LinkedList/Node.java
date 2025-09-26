
/**
 * Node Class for Queustion 1 
 *
 * @author Chukwunonso Ekweaga
 */
public class Node<Item>
{
    // instance variables - replace the example below with your own
    private Item data;
    private Node<Item> next;

    /******************************************
     * Constructor
     ************************A******************/
    public Node(Item x)
    {
        this.data = x;
        next = null;
    }
    
    public Item getData()
    {
        return data;
    }
    
    public Node<Item> getNext()
    {
        return next;
    }
    
    public void setNext(Node<Item> s)
    {
        this.next = s;
    }
    
    @Override
    public String toString()
    {
        String result = "Data: " + data;
        return result;
    }
}
