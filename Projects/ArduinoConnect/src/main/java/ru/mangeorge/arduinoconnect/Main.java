package ru.mangeorge.arduinoconnect;

import ru.mangeorge.arduinoconnect.connection.Connect;

public class Main {

    public static void main(String[] args) throws Exception {
        Connect connect = new Connect();
        connect.initialize();
        Thread t = new Thread(() -> {
            try {
                Thread.sleep(1000000);
            } catch (InterruptedException ignore) {}
        });
        t.start();
        System.out.println("Started");
    }

}