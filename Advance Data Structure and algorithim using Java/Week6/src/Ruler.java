
public class Ruler {
	// draw a tick with no label 
	public static void drawOneTick(int tickLength) { drawOneTick(tickLength, -1); }
							// draw one tick 
	public static void drawOneTick(int tickLength, int tickLabel) {
	  for (int i = 0; i < tickLength; i++)
	    System.out.print("-");
	  if (tickLabel >= 0) System.out.print(" " + tickLabel);
	  System.out.print("\n");
	}
	public static void drawTicks(int tickLength) {	// draw ticks of given length
	  if (tickLength > 0) {				// stop when length drops to 0
	    drawTicks(tickLength-1);			// recursively draw left ticks
	    drawOneTick(tickLength);			// draw center tick
	    drawTicks(tickLength-1);			// recursively draw right ticks
	  }
	}
	public static void drawRuler(int nInches, int majorLength) {	// draw ruler
	  drawOneTick(majorLength, 0);			// draw tick 0 and its label
	  for (int i = 1; i <= nInches; i++) {
	    drawTicks(majorLength-1);			// draw ticks for this inch
	    drawOneTick(majorLength, i);		// draw tick i and its label
	  }
	}

}
