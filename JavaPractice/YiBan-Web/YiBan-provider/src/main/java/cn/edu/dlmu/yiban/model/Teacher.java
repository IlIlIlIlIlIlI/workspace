package cn.edu.dlmu.yiban.model;

import com.jfinal.plugin.activerecord.Model;

public class Teacher extends Model<Teacher> {
    public static final Teacher dao = new Teacher().dao();
}
