package exercise_6;

import java.io.File;
import java.io.FilenameFilter;

public class FileAccept implements FilenameFilter {
    private String extendName;

    public void setExtendName(String extendName) {
        this.extendName = "." + extendName;
    }
    @Override
    public boolean accept(File dir, String name) {
        return name.endsWith(extendName);
    }
}