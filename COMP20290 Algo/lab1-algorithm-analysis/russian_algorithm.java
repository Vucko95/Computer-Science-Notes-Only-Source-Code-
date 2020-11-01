import java.io.*;
 
class RussianMultiplication
{
 public static void main(String[] args)
 {
  //get the input numbers
  Console con=System.console();
  System.out.print("Enter the first number: ");
  int num1=Integer.parseInt(con.readLine());
  
  System.out.print("Enter the second number: ");
  int num2=Integer.parseInt(con.readLine());
  int product=0;
  
  if(num1%2!=0)
   product=product+num2;
  System.out.println("Multiplicand Multiplier Product");
  System.out.println("\t"+num1+"\t"+num2+"\t"+product);
  while(num1!=1)
  {
   num1=num1/2;
   num2=num2*2;
   if(num1%2!=0)
    product=product+num2;
   System.out.println("\t"+num1+"\t"+num2+"\t"+product);
  }
  
  System.out.println("The product is: "+product);
 }
}



