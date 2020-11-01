public class Sentence
{
   private String text; 

   /**
      Constructs a sentence. 
      @param aText a string containing all characters of the sentence 
   */
   public Sentence(String aText)
   {
      text = aText;
   }

   /**
      Tests whether this sentence is a palindrome. 
      @return true if this sentence is a palindrome, false otherwise 
   */
   public boolean isPalindrome()
   {
      int length = text.length();

      // Separate case for shortest strings. 
      if (length <= 1) return true;

      // Get first and last characters, converted to lowercase. 
      char first = Character.toLowerCase(text.charAt(0));
      char last = Character.toLowerCase(text.charAt(length - 1));

      if (Character.isLetter(first) && Character.isLetter(last))
      {
         // Both are letters. 
         if (first == last)
         {
            // Remove both first and last character. 
            Sentence shorter = new Sentence(text.substring(1, length - 1));
            return shorter.isPalindrome();
         }
         else
         {
            return false;
         }
      }
      else if (!Character.isLetter(last))
      {
         // Remove last character. 
         Sentence shorter = new Sentence(text.substring(0, length - 1)); 
         return shorter.isPalindrome();
      }
      else
      {
         // Remove first character. 
         Sentence shorter = new Sentence(text.substring(1)); 
         return shorter.isPalindrome();
      }
   }   
}
