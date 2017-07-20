package ru.mangeorge.arduinochat.frame;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ComponentEvent;
import java.awt.event.ComponentListener;

public class ChatFrame extends JFrame {

    /** Заголовок фрейма */
    private static final String FRAME_NAME = "Arduino chat";

    private static final int WIDTH = 350;

    private static final int HEIGHT = 400;

    private static final int MESSAGE_TEXT_HEIGHT = 50;


    private JScrollPane textChatScrollPane;
    private JScrollPane textMessageScrollPane;
    private JButton sendButton;

    public ChatFrame() {
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        Dimension frameSize = new Dimension(WIDTH, HEIGHT);
        setLocation((screenSize.width - WIDTH) / 2, (screenSize.height - HEIGHT) / 2);
        setSize(frameSize);
        setResizable(true);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setVisible(true);
        setTitle(FRAME_NAME);
        addComponentListener(new ComponentListener() {
            @Override
            public void componentResized(ComponentEvent e) {
                resizeComponent();
            }
            public void componentMoved(ComponentEvent e) {}
            public void componentShown(ComponentEvent e) {}
            public void componentHidden(ComponentEvent e) {}
        });
        toFront();

        JPanel panel = new JPanel() {{
            setFocusable(true);
            setLayout(null);
        }};
        add(panel);

        textChatScrollPane = new JScrollPane() {{
            setViewportView(new JTextArea() {{
                setLineWrap(true);
                setWrapStyleWord(true);
            }});
            setLocation(5, 5);
        }};
        panel.add(textChatScrollPane);

        textMessageScrollPane = new JScrollPane() {{
            setViewportView(new JTextArea() {{
                setLineWrap(true);
                setWrapStyleWord(true);
            }});
            setSize(100, 30);
        }};
        panel.add(textMessageScrollPane);

        sendButton = new JButton("Send") {{
            setSize(100, 30);
        }};
        panel.add(sendButton);
    }

    private void resizeComponent() {
        textChatScrollPane.setSize(this.getWidth() - 25, this.getHeight() - 150);
        textMessageScrollPane.setSize(this.getWidth() - 25, MESSAGE_TEXT_HEIGHT);
        textMessageScrollPane.setLocation(5, textChatScrollPane.getHeight() + 10);
        sendButton.setLocation(this.getWidth() / 2 - 50, this.getHeight() - 80);
    }
}
