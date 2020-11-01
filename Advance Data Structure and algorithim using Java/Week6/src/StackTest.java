 // Testing the Stack class of the java.util package
import java.util.Stack; 
import java.util.*;
 import java.awt.*;
 import java.awt.event.*;
 import javax.swing.*;

 public class StackTest extends JFrame 
 {

	 public StackTest()
	 {
		 super( "Stacks" );

		 Container c = getContentPane();

		 final JLabel status = new JLabel();
		 final Stack s = new Stack();

		 c.setLayout( new FlowLayout() );
		 c.add( new JLabel( "Enter a string" ) );
		 final JTextField input = new JTextField( 10 );
		 c.add( input );

		 JButton pushBtn = new JButton( "Push" );
		 pushBtn.addActionListener( new ActionListener() 
		 {
			 public void actionPerformed( ActionEvent e )
			 {
				 status.setText( "Pushed: " + s.push( input.getText() ) );
			 }
		 } );
		 c.add( pushBtn );

		 JButton popBtn = new JButton( "Pop" );
		 popBtn.addActionListener( new ActionListener() 
		 {
			 public void actionPerformed( ActionEvent e )
			 {
				 try 
				 {
					 status.setText( "Popped: " + s.pop() );
				 }
				 catch ( EmptyStackException exception ) 
				 {
					 status.setText( exception.toString() );
				 }
			 }
		 } );
		 c.add( popBtn );

		 JButton peekBtn = new JButton( "Peek" );
		 peekBtn.addActionListener( new ActionListener() 
		 {
			 public void actionPerformed( ActionEvent e )
			 {
				 try 
				 {
					 status.setText( "Top: " + s.peek() );
				 }
				 catch ( EmptyStackException exception ) 
				 {
					 status.setText( exception.toString() );
				 }
			 }
		 } );
		 c.add( peekBtn );

		 JButton emptyBtn = new JButton( "Is Empty?" );
		 emptyBtn.addActionListener( new ActionListener() 
		 {
			 public void actionPerformed( ActionEvent e )
			 {
				 status.setText( s.empty() ? "Stack is empty" : "Stack is not empty" );
			 }
		 } );
		 c.add( emptyBtn );

		 JButton searchBtn = new JButton( "Search" );
		 searchBtn.addActionListener( new ActionListener() 
		 {
			 public void actionPerformed( ActionEvent e )
			 {
				 String searchKey = input.getText();
				 int result = s.search( searchKey );

				 if ( result == -1 )
					 status.setText( searchKey + " not found" );
				 else
					 status.setText( searchKey + " found at element " + result );
			 }
		} );
		c.add( searchBtn );

		 JButton displayBtn = new JButton( "Display" );
		 displayBtn.addActionListener( new ActionListener() 
		 {
			 public void actionPerformed( ActionEvent e )
			 {
				 Enumeration enum1 = s.elements();
				 StringBuffer buf = new StringBuffer();

				 while ( enum1.hasMoreElements() )
					 buf.append( enum1.nextElement() ).append( " " );

				 JOptionPane.showMessageDialog( null, buf.toString(), "Display", JOptionPane.PLAIN_MESSAGE );
			 }
		 } );
		 c.add( displayBtn );
		 c.add( status );

		 setSize( 675, 100 );
		 show();
	 }

	 public static void main( String args[] )
	 {
		 StackTest app = new StackTest();

		 app.addWindowListener( new WindowAdapter() 
		 {
			 public void windowClosing( WindowEvent e )
			 {
				 System.exit( 0 );
			 }
		 } );
	 }
 }
