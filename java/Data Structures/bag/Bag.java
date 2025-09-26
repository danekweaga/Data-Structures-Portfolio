import java.util.Iterator;

/*****************************************************
 * Bag Class Consisting of a LinkedLists Question 3 
 * 
 * @title Bag Class
 * @author Chukwunonso Ekweaga
 ******************************************************/
public class Bag<Type> implements Iterable<Type>
{
    private LinkedList<Type> list;

    /******************************************
     * Constructor
     ******************************************/
    public Bag()
    {
        list = null;;
    }

    /***********************************
     * Method to add a node to a bag
     ***********************************/
    public void add(Type data)
    {
        list.insertAtStart(data);
    }

    /************************************************************
     * Method that checks whether the bag is empty.
     *
     * @return - true if the bag has no items, false otherwise.
     ************************************************************/
    public boolean isEmpty()
    {
        return list.isEmpty();
    }

    /************************************************************
     * Method that tracks the item count in the bag
     *
     * @return size - amount of items in the bag.
     ************************************************************/
    public int size()
    {
        return list.size(); 
    }
    
    /******************************************
     * Method that deletes all items from bag
     ******************************************/
     public void clear()
     {
         list.clearList();
     }
    
    /**************************************************************
     * Method that returns an iterator to traverse the Bag's items
     *
     * @return Iterator<Type> - an iterator for the bag's elements
     **************************************************************/
    @Override
    public Iterator<Type> iterator() 
    {
        return list.iterator();
    }
     
}
