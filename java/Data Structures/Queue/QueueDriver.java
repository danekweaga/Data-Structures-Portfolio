/**
 * Driver program for Queue class
 * @author Chukwunonso Ekweaga
 */

public class QueueDriver {
    public static void main(String[] args) 
    {
        System.out.println("=== QUEUE DRIVER PROGRAM ===");
        Queue<String> queue = new Queue<>();
        
        try
         {
            // Test 1: Basic queue operations
            System.out.println("\n1. Testing basic queue operations:");
            System.out.println("Is queue empty? " + queue.isEmpty());
            
            queue.enqueue("First");
            queue.enqueue("Second");
            queue.enqueue("Third");
            queue.enqueue("Fourth");
            
            System.out.println("After enqueuing 4 items:");
            System.out.println("Peek at front: " + queue.peek());
            
            // Test 2: Dequeue operations
            System.out.println("\n2. Testing dequeue operations:");
            System.out.println("Dequeued: " + queue.dequeue());
            System.out.println("Dequeued: " + queue.dequeue());
            System.out.println("Peek after two dequeues: " + queue.peek());
            
            // Test 3: Enqueue more items
            System.out.println("\n3. Adding more items:");
            queue.enqueue("Fifth");
            queue.enqueue("Sixth");
            System.out.println("Peek after new additions: " + queue.peek());
            
            // Test 4: Process remaining items
            System.out.println("\n4. Processing all remaining items:");
            while (!queue.isEmpty()) 
            {
                System.out.println("Dequeued: " + queue.dequeue());
            }
            
            // Test 5: Error handling
            System.out.println("\n5. Testing error handling:");
            try 
            {
                queue.dequeue();
            } 
            
            catch (Exception e) 
            {
                System.out.println("Expected error: " + e.getMessage());
            }
            
            // Test 6: Integer queue
            System.out.println("\n6. Testing with integers:");
            Queue<Integer> intQueue = new Queue<>();
            intQueue.enqueue(10);
            intQueue.enqueue(20);
            intQueue.enqueue(30);
            
            System.out.println("Integer queue contents:");
            while (!intQueue.isEmpty()) 
            {
                System.out.println("Dequeued: " + intQueue.dequeue());
            }
            
        } 
        
        catch (Exception e)
         {
            System.out.println("Error during testing: " + e.getMessage());
            e.printStackTrace();
        }
        
        System.out.println("\n=== QUEUE DRIVER COMPLETED ===");
    }
}