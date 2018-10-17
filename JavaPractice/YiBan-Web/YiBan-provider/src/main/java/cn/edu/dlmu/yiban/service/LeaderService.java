package cn.edu.dlmu.yiban.service;

import cn.edu.dlmu.yiban.model.Leader;
import cn.edu.dlmu.yiban.model.Teacher;

public class LeaderService {
    public static Leader findByID(String leaderID){
        return Leader.dao.findById(leaderID);
    }

    public static  String findID(String name,String inti){
        return Leader.dao.findFirst("select * from leader where LName = ? and InstitudeID = ?",name,inti)
                .getStr("LeaderID");
    }
}
