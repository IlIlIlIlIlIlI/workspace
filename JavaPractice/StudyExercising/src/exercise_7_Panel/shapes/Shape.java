package exercise_7_Panel.shapes;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public abstract class Shape implements Calculator{
    private String name;
    private double zc;
    private double mj;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setZc(double zc) {
        this.zc = zc;
    }

    public void setMj(double mj) {
        this.mj = mj;
    }

    public double getZc() {
        return zc;
    }

    public double getMj() {
        return mj;
    }

    public void printToFile(String string) {
        String dir =System.getProperty("user.dir") + File.separator + "src";
        String targetFileName = getName() + ".txt";
        File targetFile = new File(dir,targetFileName);
        //System.out.println(dir);

        if (!targetFile.exists() ){
            try {
                targetFile.createNewFile();
                System.out.println(targetFileName + "创建成功！");
            } catch (IOException ioE) {
                ioE.printStackTrace();
            }
        }
        try {
            FileWriter toTargetFileWriter = new FileWriter(targetFile,true);
            BufferedWriter toTargetBufferedWriter = new BufferedWriter(toTargetFileWriter);

            toTargetBufferedWriter.write(string);
            toTargetBufferedWriter.newLine();

            toTargetBufferedWriter.flush();
            toTargetFileWriter.flush();
            toTargetBufferedWriter.close();
            toTargetFileWriter.close();
        }
        catch (IOException IOE){
            IOE.printStackTrace();
        }
    }
}
