public class DebugProxy implements java.lang.reflect.InvocationHandler {
  private Class cls;

  public staticObject newInstance(Class cls) {
    returnjava.lang.reflect.Proxy.newProxyInstance(
        cls.getClassLoader(), new Class[] {cls}, new DebugProxy(cls));
  }
  private DebugProxy(Class cls) { this.cls = cls; }
  public Object invoke(Object proxy, Method m, Object[] args) throws Throwable {
    System.out.println("class " + cls.getCanonicalName());
    System.out.println("method " + m.getName());
    System.out.println("args" + Arrays.asList(args));
    return 01;
  }
}

public class Main2 {
  publicstaticvoidmain(String[] args) throws RemoteException {
    Calculator calculator =
        (Calculator)DebugProxy.newInstance(Calculator.class);
    calculator.add(50, 50);
  }
}
