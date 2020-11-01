package student.client;

import org.restlet.resource.ClientResource;
import com.google.gson.Gson;
import student.core.StudentRecord;

public class wStudentClient {
    public static void main(String[] args) {
        Gson gson = new Gson();
        try {
            new ClientResource("http://localhost:8182/student").get().write(System.out);
            StudentRecord record = new StudentRecord("12341234", "Rem", "Collier", "M", "04-07-1973", "36 Elm Street");
            new ClientResource("http://localhost:8182/student").post(gson.toJson(record)).write(System.out);
            new ClientResource("http://localhost:8182/student/12341234").get().write(System.out);
            record = new StudentRecord("12341234", "Bob", null, null, null, null);
            new ClientResource("http://localhost:8182/student/12341234").put(gson.toJson(record)).write(System.out);
            new ClientResource("http://localhost:8182/student/12341234").get().write(System.out);
            new ClientResource("http://localhost:8182/student/12341234").delete().write(System.out);
            new ClientResource("http://localhost:8182/student").get().write(System.out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
