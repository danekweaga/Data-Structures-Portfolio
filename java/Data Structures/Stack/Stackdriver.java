
/**
 * Driver Class for Question 1
 *
 * @author Chukwunonso Ekweaga
 */
public class Stackdriver
{
    public static void main(String[] args)
    {
        try
        {
            //instance data
            int[] array = {1,2,3,4,5,6,7,8,9,10};
            Stack<Integer> numberStack = new Stack<Integer>();
            
            //Step 1 - Print Original Array
            System.out.println("Original array:");
            for(int value : array)
            {
                System.out.print(value + " ");
            }
            System.out.println();
            
            //Step 2 - Push values into the stack
            for(int i = 0; i < array.length; i++)
            {
                numberStack.push(array[i]);
            }   
            
            //Step 3 - Pop elements in stack to reverse the array
            for(int i = 0; i < array.length; i++)
            {
                array[i] = numberStack.pop();
            }   

            //Step 4 - Print Reversed Array
            System.out.println("Reversed array:");
            for(int value : array)
            {
                System.out.print(value + " ");
            }
            System.out.println();
        }
        
        catch(Exception e)
        {
            System.out.println("An error occurred: " + e.getMessage());       
        }
        
    }
}
