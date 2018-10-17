package cn.edu.dlmu.yiban.model;

import com.jfinal.plugin.activerecord.Model;

public class Leader extends Model<Leader> {
    public static final Leader dao = new Leader().dao();
}
