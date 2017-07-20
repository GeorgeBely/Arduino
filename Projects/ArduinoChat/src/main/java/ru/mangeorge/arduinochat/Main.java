package ru.mangeorge.arduinochat;

import ru.mangeorge.arduinochat.connection.Connect;
import ru.mangeorge.arduinochat.frame.ChatFrame;

import java.awt.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Connect.getInstance().initialize();

        EventQueue.invokeLater(ChatFrame::new);

        System.out.println("Started");
    }

}