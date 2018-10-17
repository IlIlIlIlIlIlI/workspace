package cn.edu.dlmu.yiban.service;

import cn.edu.dlmu.yiban.model.PsyReserve;
import cn.edu.dlmu.yiban.model.Psychological;

import java.util.List;

public class PsychologicalService {
    public static Psychological findByID(String psyID){
        return  Psychological.dao.findById(psyID);
    }

    public static String findID(String name){
        return Psychological.dao.findFirst("select * from psychological where PName = ?",name).getStr("PsyID");
    }
}
