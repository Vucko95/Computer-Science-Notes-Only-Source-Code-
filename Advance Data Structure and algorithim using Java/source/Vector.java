/**
 * This is the interface of the Vector ADT as is outlined in the course notes
 *
 * @author Rem Collier
 */
public interface Vector {
	public int size();
	public boolean isEmpty();

	public Object elemAtRank(int rank) throws RankOutOfBoundsException;
        public Object replaceAtRank(int rank, Object element) throws RankOutOfBoundsException;
        public void insertAtRank(int rank, Object element) throws RankOutOfBoundsException;
	public Object removeAtRank(int rank) throws RankOutOfBoundsException;
}
