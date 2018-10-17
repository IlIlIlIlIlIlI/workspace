package cn.edu.dlmu.yiban.config;

import cn.edu.dlmu.yiban.controller.HomePageController;
import cn.edu.dlmu.yiban.controller.IdentityController;
import cn.edu.dlmu.yiban.controller.LeaveController;
import cn.edu.dlmu.yiban.controller.ReserveController;
import cn.edu.dlmu.yiban.model.*;
import com.jfinal.config.*;
import com.jfinal.plugin.activerecord.ActiveRecordPlugin;
import com.jfinal.plugin.activerecord.dialect.MysqlDialect;
import com.jfinal.plugin.c3p0.C3p0Plugin;
import com.jfinal.template.Engine;

public class YiBanConfig extends JFinalConfig {

    public void configConstant(Constants me) {
        me.setDevMode(true);
    }

    public void configRoute(Routes me) {
        me.add("/reserve", ReserveController.class);
        me.add("/identity", IdentityController.class);
        me.add("/home", HomePageController.class);
        me.add("/leave", LeaveController.class);
    }

    public void configEngine(Engine me) {
        me.setDevMode(true);
    }

    public void configPlugin(Plugins me) {
        loadPropertyFile("config.properties");
        C3p0Plugin c3p0 = new C3p0Plugin(getProperty("jdbcUrl"),
                getProperty("user"),
                getProperty("password"));
        me.add(c3p0);
        ActiveRecordPlugin arp = new ActiveRecordPlugin(c3p0);
        me.add(arp);
        arp.setDialect(new MysqlDialect());
        arp.addMapping("ClassRoom","CRID", ClassRoom.class);
        arp.addMapping("ClassRoomReserve","CRID", ClassRoomReserve.class);
        arp.addMapping("Institude","InstitudeID", Institude.class);
        arp.addMapping("Leader","LeaderID", Leader.class);
        arp.addMapping("Leave","LeaveID",Leave.class);
        arp.addMapping("Professional","ProID",Professional.class);
        arp.addMapping("Psychological","PsyID",Psychological.class);
        arp.addMapping("PsyReserve","ReserveID",PsyReserve.class);
        arp.addMapping("Student","StudentID",Student.class);
        arp.addMapping("Teacher","TeacherID",Teacher.class);
    }

    public void configInterceptor(Interceptors me) {

    }

    public void configHandler(Handlers me) {

    }
}
