

public class Main {

    public static void main(String[] args) throws Exception {
        Connect connect = new Connect();
        connect.initialize();
        Thread t = new Thread() {
            public void run() {
                try {
                    Thread.sleep(1000000);
                } catch (InterruptedException ignore) {}
            }
        };
        t.start();
        System.out.println("Started");
    }

}