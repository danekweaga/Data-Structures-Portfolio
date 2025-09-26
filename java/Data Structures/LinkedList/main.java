import java.util.Iterator;

/**
 * Driver program for LinkedList class
 * @author Chukwunonso Ekweaga
 */
public class main
 {
    public static void main(String[] args)
     {
        System.out.println("=== LINKED LIST DRIVER PROGRAM ===");
        LinkedList<Integer> list = new LinkedList<>();
        
        try 
        {
            // Test 1: Basic Operations
            System.out.println("\n1. Testing basic operations:");
            System.out.println("Is list empty? " + list.isEmpty());
            
            list.insertAtStart(30);
            list.insertAtStart(20);
            list.insertAtStart(10);
            System.out.println("After inserting 10, 20, 30 at start:");
            list.printList();
            System.out.println("Size: " + list.size());
            
            // Test 2: Insert at end
            System.out.println("\n2. Testing insert at end:");
            list.insertAtEnd(40);
            list.insertAtEnd(50);
            System.out.println("After inserting 40, 50 at end:");
            list.printList();
            
            // Test 3: Search operations
            System.out.println("\n3. Testing search operations:");
            System.out.println("Contains 20? " + list.searchList(20));
            System.out.println("Contains 99? " + list.searchList(99));
            
            // Test 4: Delete operations
            System.out.println("\n4. Testing delete operations:");
            System.out.println("Deleted from start: " + list.deleteAtStart());
            System.out.println("After deleting from start:");
            list.printList();
            
            System.out.println("Deleted from end: " + list.deleteAtEnd());
            System.out.println("After deleting from end:");
            list.printList();
            
            // Test 5: Iterator
            System.out.println("\n5. Testing iterator:");
            System.out.println("List contents using iterator:");
            Iterator<Integer> iterator = list.iterator();
            while (iterator.hasNext()) 
            {
                System.out.println("Element: " + iterator.next());
            }
            
            // Test 6: Clear list
            System.out.println("\n6. Testing clear:");
            list.clearList();
            System.out.println("After clear - Is empty? " + list.isEmpty());
            System.out.println("Size: " + list.size());
            
            // Test 7: Error handling
            System.out.println("\n7. Testing error handling:");
            try 
            {
                list.deleteAtStart();
            } 
            
            catch (Exception e) 
            {
                System.out.println("Expected error: " + e.getMessage());
            }
            
        } 
        
        catch (Exception e) 
        {
            System.out.println("Error during testing: " + e.getMessage());
            e.printStackTrace();
        }
        
        System.out.println("\n=== LINKED LIST DRIVER COMPLETED ===");
    }
}