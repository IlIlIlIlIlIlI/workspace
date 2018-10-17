package cn.edu.dlmu.yiban.service;

import cn.edu.dlmu.yiban.model.Student;

public class StudentService {
    //1 注册成功 0 已经注册过
    public static int register(String studentID,String name,String phoneNumber,String institudeID,String proID,String passwd){
        //检验是否已经注册过
        Student s = Student.dao.findFirst("select * from student where StudentID = ?",studentID);
        if(null!=s){
            return 0;
        }
        new Student().set("StudentID",studentID).set("StudentName",name).set("PhoneNumber",phoneNumber)
                .set("InstitudeID",institudeID).set("ProID",proID).set("Passwd",passwd).save();
        return 1;
    }
    //1登录成功  0没有注册 -1没有注册
    public static int login(String studentID,String passwd){
        Student s = Student.dao.findFirst("select * from student where StudentID = ?",studentID);
        if(null==s){
            return 0;
        }
        s = Student.dao.findFirst("select * from student where StudentID=? and Passwd=?",studentID,passwd);
        if(null==s){
            return -1;
        }
        return 1;
    }

    public static Student findByID(String StudentID){
        return Student.dao.findById(StudentID);
    }

    public static Student findMessage(String StudentID){
        return Student.dao.findFirst("select * from student s,institude i,professional p " +
                "where s.InstitudeID = i.InstitudeID and s.ProID=p.ProID and s.StudentID = ?",StudentID);
    }
}
