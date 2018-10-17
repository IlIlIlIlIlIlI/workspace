package cn.edu.dlmu.yiban.controller;
import cn.edu.dlmu.yiban.model.PsyReserve;
import cn.edu.dlmu.yiban.model.Student;
import cn.edu.dlmu.yiban.service.PsyReserveService;
import cn.edu.dlmu.yiban.service.StudentService;
import com.jfinal.core.Controller;

import java.util.List;

public class ReserveController extends Controller {

    public void index() {
        String dignity = getPara("dignity");

        if("teacher".equals(dignity)){
            render("teaIndex.html");
        }
        else{
            setSessionAttr("studentID","2220152908");
            String stuID = getSessionAttr("studentID");
            Student stu = StudentService.findMessage(stuID);
            setAttr("stu",stu);
            List reserves = PsyReserveService.stuReserveHistory(stuID);
            setAttr("res",reserves);
            render("stuIndex.html");
        }
    }

    //学生查询自己的预约历史
    public void psyReserveHistory(){
        String studentID = getPara("studentID");
        List<PsyReserve> psyReserves = PsyReserveService.stuReserveHistory(studentID);
        setAttr("psyReserves",psyReserves);
        render("psyStuHistory.html");
    }

    //学生申请预约
    public void psyReserveRequest(){
        String studenID = getSessionAttr("studentID");
        String tName = getPara("tName");
        int dNum =Integer.valueOf( getPara("dNum") );
        String des = getPara("description");
        int status = PsyReserveService.stuPsyRequst(studenID,tName,dNum,des);
        String result = "";
        if(0 == status){
            result = "error";
        }
        result = "ok";
        setAttr("result",result);
        renderJson();
    }

    //老师接受预约
    public void psyReserveRecive(){
        String teaID = getSessionAttr("teacherID");
        String reserveID = getAttr("reserveID");
        int status = PsyReserveService.psyRecive(reserveID);
        String result = "";
        if(-1 == status){
            result = "error";
        }
        result = "ok";
        setAttr("result",result);
        renderJson();
    }

    //老师查询自己的预约历史
    public void psyReciveHistory(){
        String teacherID = getPara("teacherID");
        List<PsyReserve> psyReserves = PsyReserveService.teaReviceHistory(teacherID);
        setAttr("psyReserves",psyReserves);
        render("psyTeaHistory.html");
    }
}
