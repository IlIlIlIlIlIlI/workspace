package exercise_6;

import java.io.File;

public class Test {
    public static void main(String[] args) {
        File dirFile = new File(".");
        FileAccept fileAccept = new FileAccept();
        fileAccept.setExtendName("java");
        String[] fileName = dirFile.list(fileAccept);
        for (String name : fileName){
            System.out.println(name);
        }
    }
}
