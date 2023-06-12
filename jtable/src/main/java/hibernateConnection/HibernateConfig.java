package hibernateConnection;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

public class HibernateConfig {

	private static SessionFactory sesstionFactory;
	static{
		try{
			
			sesstionFactory = new Configuration().configure().buildSessionFactory();
			System.out.println("Succeful connection with database in hc.java");
		}catch(Throwable ex){
			System.out.println("Not able to create connection with database, Inside HibernateConfig.java");
			ex.printStackTrace();
		}
	}
	
	public static Session getSession(){
		return sesstionFactory.openSession();
	}
	
	public static void closeSession(Session session){
		if(session != null){
			session.close();
		}
	}
		
}