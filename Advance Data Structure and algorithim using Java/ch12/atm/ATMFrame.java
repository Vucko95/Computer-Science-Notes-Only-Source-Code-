import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;

/**
   A frame displaying the components of an ATM.
*/
public class ATMFrame extends JFrame
{  
   private static final int FRAME_WIDTH = 300;
   private static final int FRAME_HEIGHT = 300;

   private JButton aButton;
   private JButton bButton;
   private JButton cButton;
   
   private KeyPad pad;
   private JTextArea display;

   private ATM theATM;

   /**
      Constructs the user interface of the ATM frame.
   */
   public ATMFrame(ATM anATM)
   {  
      theATM = anATM;
      
      // Construct components
      pad = new KeyPad();

      display = new JTextArea(4, 20);
      
      aButton = new JButton("  A  ");
      aButton.addActionListener(new AButtonListener());

      bButton = new JButton("  B  ");
      bButton.addActionListener(new BButtonListener());

      cButton = new JButton("  C  ");
      cButton.addActionListener(new CButtonListener());
      
      // Add components

      JPanel buttonPanel = new JPanel();
      buttonPanel.add(aButton);
      buttonPanel.add(bButton);
      buttonPanel.add(cButton);
      
      setLayout(new FlowLayout());
      add(pad);
      add(display);
      add(buttonPanel);
      showState();

      setSize(FRAME_WIDTH, FRAME_HEIGHT);
   }
   
   /** 
      Updates display message.
   */
   public void showState()
   {  
      int state = theATM.getState();
      pad.clear();
      if (state == ATM.START)
         display.setText("Enter customer number\nA = OK");
      else if (state == ATM.PIN)
         display.setText("Enter PIN\nA = OK");
      else if (state == ATM.ACCOUNT)
         display.setText("Select Account\n" 
               + "A = Checking\nB = Savings\nC = Exit");
      else if (state == ATM.TRANSACT)
         display.setText("Balance = " 
               + theATM.getBalance() 
               + "\nEnter amount and select transaction\n"
               + "A = Withdraw\nB = Deposit\nC = Cancel");
   }
   
   class AButtonListener implements ActionListener
   {  
      public void actionPerformed(ActionEvent event)
      {  
         int state = theATM.getState();
         if (state == ATM.START)
            theATM.setCustomerNumber((int) pad.getValue());
         else if (state == ATM.PIN)
            theATM.selectCustomer((int) pad.getValue());
         else if (state == ATM.ACCOUNT)
            theATM.selectAccount(ATM.CHECKING);
         else if (state == ATM.TRANSACT)
         {
            theATM.withdraw(pad.getValue());
            theATM.back();
         }
         showState();
      }
   }
   
   class BButtonListener implements ActionListener
   {  
      public void actionPerformed(ActionEvent event)
      {  
         int state = theATM.getState();
         if (state == ATM.ACCOUNT)
            theATM.selectAccount(ATM.SAVINGS);
         else if (state == ATM.TRANSACT)
         {
            theATM.deposit(pad.getValue());
            theATM.back();
         }
         showState();
      }
   }

   class CButtonListener implements ActionListener
   {  
      public void actionPerformed(ActionEvent event)
      {  
         int state = theATM.getState();
         if (state == ATM.ACCOUNT)
            theATM.reset();
         else if (state == ATM.TRANSACT)
            theATM.back();
         showState();
      }
   }
}
