package exercise_6;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        String direction = System.getProperty("user.dir");
        File file = new File(direction + File.separator + "src","Main.java");
        if (file.exists()){
            System.out.println("文件名为：" + file.getName() + " 存在！");
            System.out.println("文件的长度(单位：字节)为：" + file.length());
            System.out.println("文件的绝对路径为：" + file.getAbsolutePath());
        }else if (!file.exists()){
            try {
                file.createNewFile();
                System.out.println("文件创建成功！");
            }
            catch (IOException IOE){
                IOE.printStackTrace();
            }
        }

        //FileOutputStream fileOutputStream_1 = null;
        try {
            FileOutputStream fileOutputStream = new FileOutputStream(file);
            //fileOutputStream_1 = fileOutputStream;
            byte[] output = "public class Main{\npublic static void main(String[] args){\nSystem.out.println(\"我是新创建的文件\");\n}\n}".getBytes();
            fileOutputStream.write(output);
            System.out.println("文件写入完成！");
        }
        catch (IOException ioE){
            ioE.printStackTrace();
        }

        try {
            FileInputStream fileInputStream = new FileInputStream(file);
            System.out.println("我是输出流！");
            byte[] input = new byte[200];
            int n = -1;
            while ((n = fileInputStream.read(input,0,100)) != -1){
                System.out.println(n);
                String s = new String(input,0,n);
                System.out.println(s);
            }
            fileInputStream.close();
        }
        catch (IOException ioE){
            ioE.printStackTrace();
        }
    }
}
