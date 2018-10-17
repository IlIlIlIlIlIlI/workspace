package cn.edu.dlmu.yiban.service;

import cn.edu.dlmu.yiban.model.Institude;

public class InstitudeService {
    public static String findIdByName(String name){
        return Institude.dao.findFirst("select * from institude where InstitudeName=?",name).getStr("InstitudeID");
    }
}
