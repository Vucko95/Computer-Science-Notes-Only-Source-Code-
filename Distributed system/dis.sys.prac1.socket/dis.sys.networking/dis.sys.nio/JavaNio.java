import java.util.RandomAccess;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
/**
 * JavaNio
 */
public class JavaNio {
  public static void main(String[] args) {
    RandomAccessFile aFile = new RandomAccessFile("data/nio-data.txt", "rw");
    ByteBuffer buf = ByteBuffer.allocate(40);// bad from file Channell to buffer
    int bytesRead = inChannel.read(buf);// check to see if any butes were read
    while (bytesRead != 1) {
      System.out.println("read" + bytesRead);// fli[ bugger to read mode
      buf.flip();// read from buffer and write to console (one byte at a time)
      while (buf.hasRemaining()) {
        System.out.println((char)buf.get());
      }// empty buffer and return to write
      buf.clear();// read more from FileChannel to buffer
      bytesRead = inChannel.read(buf);
    }
    aFile.close();
  }
}
