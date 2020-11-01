
public class ListMap<K, V> implements Map<K, V> {
	public class ListMapEntry implements Entry<K,V> {
		K key;
		V value;
		
		public ListMapEntry(K key, V value) {
			this.key = key;
			this.value = value;
		}
		
		@Override
		public K key() {
			return key;
		}

		@Override
		public V value() {
			return value;
		}
		
	}
	
	private List<Entry<K,V>> list = new LinkedList<Entry<K,V>>();
	
	@Override
	public int size() {
		return list.size();
	}

	@Override
	public boolean isEmpty() {
		return list.isEmpty();
	}

	@Override
	public V get(K k) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public V put(K k, V v) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public V remove(K k) {
		// TODO Auto-generated method stub
		return null;
	}

	private Position<ListMapEntry> find(K key) {
		return null;
	}
	@Override
	public Iterator<K> keys() {
		return new Iterator<K>() {
			Iterator<Entry<K,V>> iterator = list.iterator();
			
			@Override
			public boolean hasNext() {
				return iterator.hasNext();
			}

			@Override
			public K next() {
				return iterator.next().key();
			}
		};
	}

	@Override
	public Iterator<V> values() {
		return new Iterator<V>() {
			Iterator<Entry<K,V>> iterator = list.iterator();
			
			@Override
			public boolean hasNext() {
				return iterator.hasNext();
			}

			@Override
			public V next() {
				return iterator.next().value();
			}
		};
	}

	@Override
	public Iterator<Entry<K, V>> entries() {
		return list.iterator();
	}

	public static void main(String[] args) {
	}
}
