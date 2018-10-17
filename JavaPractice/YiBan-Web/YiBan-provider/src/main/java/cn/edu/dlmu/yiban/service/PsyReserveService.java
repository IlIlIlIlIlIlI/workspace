package cn.edu.dlmu.yiban.service;

import cn.edu.dlmu.yiban.model.Leave;
import cn.edu.dlmu.yiban.model.PsyReserve;
import com.jfinal.plugin.activerecord.Db;

import java.sql.Timestamp;
import java.util.Date;
import java.util.List;

public class PsyReserveService {
    public static List<PsyReserve> stuReserveHistory(String stuID){
        return PsyReserve.dao.find("select * from psyreserve where StudentID = ?",stuID);
    }
    public static List<PsyReserve> teaReviceHistory(String teaID){
        return PsyReserve.dao.find("select * from psyreserve where TeacherID = ?",teaID);
    }

    //1 成功 0 失败
    public static int stuPsyRequst(String stuID,String name,int dNum,String des){
        //获取当前时间
        Timestamp TB = new Timestamp(new Date().getTime());
        Timestamp TE = new Timestamp(TB.getTime()+dNum*24*60*60);
        //查询老师的编号
        String pID = PsychologicalService.findID(name);
        if(pID == null){
            return 0;
        }
        new PsyReserve().set("StudentID",stuID).set("TeacherID",pID).set("Description",des).set("BeginTime",TB)
                .set("EndTime",TE).save();
        return 1;
    }

    //-1 失败 1成功
    public static int psyRecive(String reserveID){
        Timestamp TE = PsyReserve.dao.findFirst("select * from psyreserve where ReserveID = ?",reserveID)
                .getTimestamp("EndTime");
        Timestamp now = new Timestamp(new Date().getTime());
        if(now.compareTo(TE)>=0){
            return -1;
        }
        Db.update("update psyreserve set Status=? where ReserveID = ?",1,reserveID);
        return 1;
    }
}
