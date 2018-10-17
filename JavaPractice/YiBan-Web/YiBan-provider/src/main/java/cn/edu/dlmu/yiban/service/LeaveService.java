package cn.edu.dlmu.yiban.service;

import cn.edu.dlmu.yiban.model.Leave;
import com.jfinal.plugin.activerecord.Db;

import java.sql.Timestamp;
import java.util.Date;
import java.util.List;

public class LeaveService {

    public static List<Leave> findStuHistory(String StudentID){
        return Leave.dao.find("select * from `leave` where StudentID=?",StudentID);
    }


    public static  List<Leave> findTeaHistory(String teacherID){
        return Leave.dao.find("select * from `leave` where teacherID=?",teacherID);
    }

    public static  List<Leave> findNotIdentity(String teacherID){
        return Leave.dao.find("select * from `leave` where teacherID = ? and Status=0",teacherID);
    }

    // 1 提交成功 0 提交失败
    public static int  leaveRequest(String sID,String tName,String tIn,String des,int dNum){
        //查询教师或者领导的编号
        //查询学院的编号

        String inti = InstitudeService.findIdByName(tIn);
        if(inti == null){
            return 0;
        }
        //获取当前系统时间
        Timestamp TB = new Timestamp(new Date().getTime());
        Timestamp TE = new Timestamp(TB.getTime()+dNum*60*60);
        //查询老师的编号
        String tID = TeacherService.findId(tName,inti);
        if(tID != null){
            new Leave().set("StudentID",sID).set("TeacherID",tID).set("Description",des).set("BeginTime",TB)
                    .set("EndTime",TE).set("Status",2).save();
            return 1;
        }
        String lID = LeaderService.findID(tName,inti);
        if(lID!=null){
            new Leave().set("StudentID",sID).set("LeaderID",tID).set("Description",des).set("BeginTime",TB)
                    .set("EndTime",TE).set("Status",2).save();
            return 1;
        }
        return 0;
    }

    //-1 已经过期 1确认成功
    public static int leaveIdentity(String tID,String lId){
        //查看请假时间
        Timestamp TE = Leave.dao.findFirst("select * from `leave` where LeaveID = ?",lId)
                .getTimestamp("EndTime");
        Timestamp now = new Timestamp(new Date().getTime());
        if(now.compareTo(TE)>=0){
            return -1;
        }
        Db.update("update `leave` set Status=? where LeaveID = ?",1,lId);
        return 1;
    }

    public static int leaveCancel(String id,String lId){
        Timestamp TE = Leave.dao.findFirst("select * from `leave` where LeaveID = ?",lId)
                .getTimestamp("EndTime");
        Timestamp now = new Timestamp(new Date().getTime());
        if(now.compareTo(TE)>=0){
            return -1;
        }
        Db.update("update `leave` set Status=? where LeaveID = ?",-1,lId);
        return 1;
    }
}
