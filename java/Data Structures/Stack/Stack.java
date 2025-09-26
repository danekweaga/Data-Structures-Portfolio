
/**
 * Stack Class for Question 1
 *
 * @author Chukwunonso Ekweaga
 */
public class Stack<Item>
{
    // instance variables 
    private Node<Item> head;

    /**
     * Constructor for objects of class Stack
     */
    public Stack()
    {
        head = null;
    }

    public void push (Item y)throws Exception
    {
        Node<Item> temp = head;
        head = new Node<Item>(y);
        head.setNext(temp);
    }
    
    public Item pop()throws Exception
    {
        if(isEmpty())
        {
            throw new Exception ("Stack is Empty.");
        }
        Item data = head.getData();
        head = head.getNext();
        return data;
    }
    
    public Item peek() throws Exception
    {
        if(isEmpty())
        {
            throw new Exception ("Stack is Empty.");
        }
        return head.getData();
    }
    
    public boolean isEmpty() 
    {
        boolean output = false;
        if(head == null)
        {
            output = true;
        }
        return output;
    }
}
