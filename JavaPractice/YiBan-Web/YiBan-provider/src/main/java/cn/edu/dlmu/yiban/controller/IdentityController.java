package cn.edu.dlmu.yiban.controller;

import cn.edu.dlmu.yiban.model.Student;
import cn.edu.dlmu.yiban.service.StudentService;
import cn.edu.dlmu.yiban.service.TeacherService;
import com.jfinal.core.Controller;

public class IdentityController extends Controller {
    public void index(){
        render("identity.html");
    }

    //学生
    public void register(){
        String studentID = getPara("studentID");
        String name = getPara("name");
        String phoneNumber = getPara("phoneNumber");
        String institudeID = getPara("institudeID");
        String proID = getPara("proID");
        String passwd = getPara("passwd");
        int status = StudentService.register(studentID,name,phoneNumber,institudeID,proID,passwd);
        String result = "";
        if(0 == status){
            result = "exited";
        }
        result = "ok";
        setSessionAttr("studentID",studentID);
        setAttr("result",result);
        renderJson();
    }

    public void login(){

        String dignity = getPara("dignity");
        int status = 0;
        String ID = "";
        if("teacher".equals(dignity)){
            ID = getPara("teacherID");
            String passwd = getPara("passwd");
            status = TeacherService.login(ID,passwd);
        }
        else{
            ID = getPara("studentID");
            String passwd = getPara("passwd");
            status = StudentService.login(ID,passwd);
        }
        String result = "";
        if(-1 == status){
            result = "errorPasswd";
        }
        else if(0 == status){
            result = "none";
        }
        result = "ok";
        if("teacher".equals(dignity)){
            setSessionAttr("teacherID",ID );
        }
        else{
            setSessionAttr("studentID",ID );
        }
        setAttr("result",result);
        renderJson();
    }


}
