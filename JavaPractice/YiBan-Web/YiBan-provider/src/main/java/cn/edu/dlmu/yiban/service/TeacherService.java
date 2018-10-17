package cn.edu.dlmu.yiban.service;

import cn.edu.dlmu.yiban.model.Student;
import cn.edu.dlmu.yiban.model.Teacher;

public class TeacherService {
    public static Teacher findByID(String teacherID){
        return Teacher.dao.findById(teacherID);
    }

    public static String findId(String tname,String inti){
        return Teacher.dao.findFirst("select * from teacher where TName = ? and InstitudeID = ?",tname,inti).getStr("TeacherID");
    }

    public static int login(String teaID,String passwd){
        Teacher t = Teacher.dao.findFirst("select * from teacher where teacherID = ?",teaID);
        if(null==t){
            return 0;
        }
        t = Teacher.dao.findFirst("select * from teacher where TeacherID=? and Passwd=?",teaID,passwd);
        if(null==t){
            return -1;
        }
        return 1;
    }

    public static Teacher findMessage(String teaID){
        return Teacher.dao.findFirst("select * from teacher t,institude i,professional p " +
                "where t.InstitudeID = i.InstitudeID and t.ProID=p.ProID and t.TeacherID= ?",teaID);
    }
}
