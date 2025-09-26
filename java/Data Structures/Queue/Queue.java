
/**
 * Write a description of class Queue here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class Queue<Item>
{
    Node <Item> head;
    Node <Item> tail;
    
    /*************************************
     * Constructor
     *************************************/
     public Queue()
     {
         head = null;
         tail = null;
     }
     
    public boolean isEmpty()
    {
        return head == null;    
    }
    
    public void enqueue(Item t) 
    {
        Node<Item> temp = new Node<Item>(t);
        if(isEmpty())
        {
            head = temp;
            tail = temp;
        }
        
        else
        {
            tail.setNext(temp);
            tail = temp;
        }
    }
    
    public Item dequeue() throws Exception
    {
        if(isEmpty()) throw new Exception("Queue is empty");
        Item data = head.getData();
        head = head.getNext();
        if(head == null){tail = null;}
        return data;
    }
    
    public Item peek() throws Exception
    {
        if(isEmpty()) throw new Exception("Queue is empty");
        return head.getData();
    }
}
