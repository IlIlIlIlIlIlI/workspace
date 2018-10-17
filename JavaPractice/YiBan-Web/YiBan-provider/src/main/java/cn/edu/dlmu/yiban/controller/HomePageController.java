package cn.edu.dlmu.yiban.controller;

import cn.edu.dlmu.yiban.service.LeaderService;
import cn.edu.dlmu.yiban.service.PsychologicalService;
import cn.edu.dlmu.yiban.service.StudentService;
import cn.edu.dlmu.yiban.service.TeacherService;
import com.jfinal.core.Controller;
import com.jfinal.plugin.activerecord.Model;

public class HomePageController extends Controller {
    public void index(){
        //查询用户信息
        String dignity = getPara("dignity");
        Model result = null;
        if("teacher".equals(dignity)){
            String teacherID = getPara("teacherID");
            result = TeacherService.findByID(teacherID);
        }
        else if("student".equals(dignity)){
            String studentID = getPara("studentID");
            result = StudentService.findByID(studentID);

        }
        else if("leader".equals(dignity)){
            String leaderID = getPara("leaderID");
            result = LeaderService.findByID(leaderID);

        }
        else if("psychological".equals(dignity)){
            String psyID = getPara("psyID");
            result = PsychologicalService.findByID(psyID);
        }
        setAttr("result",result);
        render("index.html");
    }
}
