package com.flybear.SpringMVC.handlers;
//这是个人查询
import com.flybear.SpringMVC.beans.MyRequest;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import com.flybear.SpringMVC.beans.user;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.SessionAttributes;
import org.springframework.web.servlet.ModelAndView;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import java.util.ArrayList;
import java.util.List;

@Controller
@SessionAttributes(value = {"status","logname","logpass"})
public class SearchOne {

    @RequestMapping("/searchone")
    public String search(){
        return "search";
    }

    @RequestMapping("/fetch")
    public ModelAndView fetch(user user, ModelMap modelMap){
        modelMap.addAttribute("logname",user.getLogname());
        modelMap.addAttribute("logpass",user.getLogpass());
        ModelAndView md=new ModelAndView("searchfinally");
        return md;
    }


    @Autowired
    com.flybear.SpringMVC.Dao.GuestGetMsg GetMsg;
    @Autowired
    HttpServletRequest request;
    @RequestMapping("/guestsearch")
    public @ResponseBody
    List requestjson(@RequestBody MyRequest p){
        HttpSession httpSession = request.getSession();
        ArrayList result=GetMsg.search(p,(String) httpSession.getAttribute("logname"),(String) httpSession.getAttribute("logpass"));
        return result;

    }
}
