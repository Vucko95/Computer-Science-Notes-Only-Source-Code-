public class PalindromeTester
{
   public static void main(String[] args)
   {
      Sentence s1 = new Sentence("Madam, I'm Adam!");
      System.out.println(s1.isPalindrome());
      System.out.println("Expected: true");
      Sentence s2 = new Sentence("Sir, I'm Eve!");
      System.out.println(s2.isPalindrome());
      System.out.println("Expected: false");
   }
}
