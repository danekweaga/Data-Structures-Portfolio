import java.util.NoSuchElementException;
import java.util.Iterator;

/**********************************************************************
 * A LinkedList class consisting of singly linked nodes.
 * 
 * @title   LinkedList class
 * @author  Chukwunonso Ekweaga
 **********************************************************************/
public class LinkedList<Item> 
{
    // Instance data 
    private Node<Item> start;
    private int size;

    /******************************************
     * Constructor
     ******************************************/
    public LinkedList() 
    {
        start = null;
        size = 0;
    }
    
    /*******************************************************************
     * Method to insert a node at the beginning of the linked List
     * 
     * @param data - The value of the data will be stored in the node
     ******************************************************************/
    public void insertAtStart(Item data)
    {
        Node<Item> temp = new Node(data);
        temp.setNext(start);
        start = temp;
        size++;
    } 
    
    /*****************************************************************
     * Method to insert a node at the end of the linked List
     * 
     * @param data - The value of the data will be stored in the node
     *****************************************************************/
    public void insertAtEnd(Item data)
    {
        if(!isEmpty())
        {
            Node<Item> current = start;
            Node<Item> newNode = new Node(data);
            while(current.getNext() != null)
            {
                current = current.getNext();
            }
            current.setNext(newNode);
        }
        else 
        {
            insertAtStart(data);
        }
        size++;
    }
    
    /*****************************************************************
     * Method that deletes the node at the beginning of the Linked List
     * 
     * @return  - the node deleted from the linkedlist
     *****************************************************************/
    public Item deleteAtStart() throws Exception
    {
        Item output;
        if(!isEmpty())
        {
            output = start.getData();
            start = start.getNext();
        }
        
        else
        {
            throw new Exception("This LinkedList is empty.");
        }
        size--;
        return output;
    }

    /*****************************************************************
     * Method that deletes the node at the end of the Linked List
     * 
     * @return output - the node deleted from the linkedlist
     *****************************************************************/
    public Item deleteAtEnd() throws Exception
    {
        Item output;
        Node<Item> current;
        Node<Item> previous;
        //Case 1 : If the LinkedList is empty
        if(isEmpty())
        {
            throw new Exception("This LinkedList is empty.");
        }
        
        //Case 2 : If the LinkedList contains only one node
        else if(start.getNext() == null)
        {
            output = start.getData();
            start = null;
            size--;
        }
        
        //Case 3 : If the LinkedList contains multiple nodes.
        else
        {
            current = start;
            previous = null;
            while(current.getNext() == null)
            {
                previous = current;
                current = current.getNext();
            }
            output = current.getData();
            previous.setNext(null);
            size--;
        }
        return output;
    }
    
    /******************************************************************************************
     * Method that traverses the linkedList till it finds the node containing the data needed
     * 
     * @returns output - true if the value is in the LinkedList , otherwise false.
     ******************************************************************************************/
     public boolean searchList(Item data) throws Exception
    {
        Node<Item> current = start;
        if(isEmpty())
        {
            throw new Exception("This LinkedList is empty.");
        }
         
        while(current != null)
        {
            if((current.getData() == null && data == null) ||
              (current.getData() != null && current.getData().equals(data)))
            {
             return true;
            }
            current = current.getNext();
        }
        return false;
    }
    
    /***********************************************************************
     * Method that prints the value of each node in the LinkedList
     * 
     * @returns output - the value of each in node in the LinkedList
     ***********************************************************************/
     public void printList()
     {
         String output = "";
         Node current = start;
         while(current != null)
         {
             output += current.toString() + "\n";
             current = current.getNext();
         }
         System.out.print(output);
     }
    
    /************************************************************
     * Method that tracks the size of the LinkedList
     *
     * @return size - the current size of the LinkedList.
     ************************************************************/
    public int size()
    {
        return size; 
    }
    
    /****************************************************************************************
     * Method that checks whether the linked list is empty.
     *
     * @return - true if the list has no nodes , false otherwise.
     ****************************************************************************************/
    public boolean isEmpty()
    {
        return start == null; 
    }
    
    /************************************************************
     * Method that deletes all the nodes in the LinkedList
     ***********************************************************/
     public void clearList()
    {
        start = null;    
    }
    /************************************************************
     * Inner class: Iterator for the LinkedList
     ************************************************************/
    public class LinkedListIterator implements Iterator<Item> 
    {
        private Node<Item> current = start;
    
        @Override
        public boolean hasNext() 
        {
            return current != null;
        }
    
        @Override
        public Item next() 
        {
            if (!hasNext()) 
            {
                throw new NoSuchElementException("No more elements.");
            }
            Item data = current.getData();
            current = current.getNext();
            return data;
        }
    }
    
    /************************************************************
     * Method to return an iterator over the linked list
     *
     * @return LinkedListIterator instance
     ************************************************************/
    public LinkedListIterator iterator() 
    {
        return new LinkedListIterator();
    }

}
