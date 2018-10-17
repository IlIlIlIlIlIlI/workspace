package cn.edu.dlmu.yiban.controller;

import cn.edu.dlmu.yiban.model.Leave;
import cn.edu.dlmu.yiban.model.Student;
import cn.edu.dlmu.yiban.model.Teacher;
import cn.edu.dlmu.yiban.service.LeaveService;
import cn.edu.dlmu.yiban.service.StudentService;
import cn.edu.dlmu.yiban.service.TeacherService;
import com.jfinal.core.Controller;

import java.util.List;

public class LeaveController extends Controller {
    public void index(){
        String dignity = getPara("dignity");
        if("teacher".equals(dignity)){
            setSessionAttr("teacherID","2220152369");
            String teaID = getSessionAttr("teacherID");
            Teacher t = TeacherService.findMessage(teaID);
            setAttr("tea",t);
            List<Leave> leaves = LeaveService.findTeaHistory(teaID);
            //获取信息
            setAttr("lea",leaves);
            render("teaIndex.html");
        }
        else if("student".equals(dignity)){
            //获取信息

            String stuID = getSessionAttr("studentID");
            Student s = StudentService.findMessage(stuID);
            setAttr("student",s);
            List<Leave> leaves = LeaveService.findStuHistory(stuID);
            setAttr("leaves",leaves);
            render("stuIndex.html");
        }
    }


    //学生 查看自己的请假记录
    public void stuHistory(){
        String studentID = getSessionAttr("studentID");
        List<Leave> leaves = LeaveService.findStuHistory(studentID);
        setAttr("leaves",leaves);
        render("");
    }

    public void teaHistory(){
        String teacherID = getPara("teacherID");
        List<Leave> leaves = LeaveService.findTeaHistory(teacherID);
        setAttr("leaves",leaves);
        render("");
    }

    public void notIdentity(){
        String teacherID = getPara("teacherID");
        List<Leave> leaves = LeaveService.findNotIdentity(teacherID);
        setAttr("leaves",leaves);
        render("");
    }
    //学生发起请假信息
    public void leaveSubmit(){


        String studentID = getSessionAttr("studentID");
        String teaName = getPara("teaName");
        String teaInsti = getPara("teaInsti");
        String describe = getPara("describe");
        int dNum =Integer.valueOf(getPara("dNum"));
        int status = LeaveService.leaveRequest(studentID,teaName,teaInsti,describe,dNum);
        String result = "";
        if(0 == status){
            result = "error";
        }
        result = "ok";
        setAttr("result",result);
        renderJson();
    }
    //老师确认请假信息
    public void leaveIdentity(){
        String teacherID = getSessionAttr("teacherID");
        String leaveID = getPara("leaveID");
        int status = LeaveService.leaveIdentity(teacherID,leaveID);
        String result = "";
        if(-1 == status){
            result = "overtime";
        }
        else if(1 == status){
            result = "ok";
        }
        setAttr("result",result);
        renderJson();
    }

    public void leaveCancel(){
        String teacherID = getSessionAttr("teacherID");
        String leaveID = getPara("leaveID");
        int status = LeaveService.leaveCancel(teacherID,leaveID);
        String result = "";
        if(-1 == status){
            result = "overtime";
        }
        else if(1 == status){
            result = "ok";
        }
        setAttr("result",result);
        renderJson();
    }
}
