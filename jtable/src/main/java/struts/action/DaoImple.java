package struts.action;

import org.hibernate.Criteria;
import org.hibernate.Session;
import hibernateConnection.HibernateConfig;
import model.Student;

import java.util.List;
	
public class DaoImple {
	public void addStudent(Student student) {
		Session session = null;
		
		System.out.println("sssssss " + student.getStdname());
		 try{
			 System.out.println("---Inside stdRegisterDAOImples AddStudent() methods try block---");
			 session = HibernateConfig.getSession();
			 
			 session.save(student);
			 
			 System.out.println("ddddddd " + student.getEmail());
			 System.out.println("ddddddd " + student.getAge());
			 session.beginTransaction().commit();
			 
			 
			 
		 }catch(Exception ex){
			 System.out.println("---Error Inside StdRegisterDAOImples AddStudent() methods catch block---");
			 ex.printStackTrace();
		 }finally{
			 System.out.println("---Inside stdRegisterDAOImples AddStudent() methods finally block---");
			 if(session != null){
				 session.close();
			 }
		 }
	}
	
	public void updateStudent(Student student){
		Session session = null;
		
			 try{
				 session = HibernateConfig.getSession();
				 
				
				 session.update(student);
				 
				 session.beginTransaction().commit();
				 
			 }catch(Exception ex){
				 System.out.println("---Error Inside stdRegisterDAOImples registerUser() methods catch block---");
				 ex.printStackTrace();
			 }finally{
				 System.out.println("---Inside stdRegisterDAOImples registerUser() methods finally block---");
				 if(session != null){
					 session.close();
				 }
			 }
		}

	public void deleteStudent(int userId){
		Session session = null;
		Student s1 = null;
		 try{
			 System.out.println("---Inside stdRegisterDAOImples deleteEmployee() methods try block---");
			 session = HibernateConfig.getSession();
			 
			 s1 = (Student) session.load(Student.class, userId);
			 session.delete(s1);
			 
			 session.beginTransaction().commit();
			 
		 }catch(Exception ex){
			 System.out.println("---Error Inside stdRegisterDAOImples deleteStudent() methods catch block---");
			 ex.printStackTrace();
		 }finally{
			 System.out.println("---Inside stdRegisterDAOImples deleteStudent() methods finally block---");
			 if(session != null){
				session.close();
			 }
		 }
	}
	
	public List<Student> getAllStudent() {
		Session session =  null;
		List<Student> list = null;  //list of all employee in db
		
		try{
			System.out.println("--Inside StdRegisterDAOImples getAllStudent() methods try Block--");
			session = HibernateConfig.getSession();
			Criteria cr = session.createCriteria(Student.class);
			list = cr.list();
		}catch(Exception ex){
			System.out.println("--- Error Inside stdRegisterDAOImples getAllStudent() methods catch block---");
			ex.printStackTrace();
		}finally{
			if(session!= null){
				System.out.println("--Inside stdRegisterDAOImples getAllStudent() methods finally Block--");
				session.close();
			}			
		}
		return list;
	}

}
