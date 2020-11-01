/**
 * Basic implementation of a checked exception that supports the implementation
 * of the Vector interface.
 *
 * @author Rem Collier
 */
public class RankOutOfBoundsException extends Exception {
    public RankOutOfBoundsException(String msg) {
        super(msg);
    }

    public RankOutOfBoundsException() {
        super();
    }
}
