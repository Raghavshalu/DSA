package struts.action;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

import org.hibernate.Session;

import com.opensymphony.xwork2.ActionSupport;

import hibernateConnection.HibernateConfig;

import model.Student;
public class strutsaction extends ActionSupport{
	private static final long serialVersionUID = 1L;
	Integer stdid;
	String stdname;
	String email;
	Integer age;
	
	private List<Student> records;
	private Student record;
	private String result;  //OK or ERROR
	private String message;  
	private DaoImple dao= new DaoImple();
	
	public String create()
	{
		try
		{
			record=new Student();
			record.setStdname(stdname);
			//createBy is retrieve from form, which is string Type. Hence, we convert it to integer before save in db
			if(age!=null)
			{
				if(!"".equals(age))
				{
					Integer ageIdAsInt = age;
					record.setAge(ageIdAsInt);
				}
			}
			record.setEmail(email);
			
			dao.addStudent(record);
			message="Data save successfully";
			result="OK";
		}
		catch(Exception ex)
		{
			ex.printStackTrace();
			result="ERROR";
		}
		return "success";
	}

	public String update()
	{
		Session session=null;	
		try
		{
		
		session=HibernateConfig.getSession();
		Integer stdidAsInt = stdid;
		record=(Student) session.get(Student.class, stdidAsInt);
	    record.setStdname(stdname);
	    record.setEmail(email);
	    Integer stdageAsInt = age;
	    record.setAge(stdageAsInt);
	    dao.updateStudent(record);
	    result="OK";
		//
		//
		}
		catch(Exception ex)
		{
			ex.printStackTrace();
			result="ERROR";
		}
		finally
		{
			if(session!=null)
			{
				session.close();
			}
		}
		return "success";	
	}
	
	public String delete()
	{
	
		
		Integer stdidAsInt=stdid;
		dao.deleteStudent(stdidAsInt);
		result="OK";
		message="Data deleted successfully";
		return "success";
		
	}
	
	public String list() {
		Session session=null;
		try {
			records=dao.getAllStudent();
			
			System.out.println("Records = "+getRecords());
			//setResult("OK");
			result="OK";
		} catch (Exception e) {
			setResult("ERROR");
			setMessage(e.getMessage());
			System.err.println(e.getMessage());
		}
		
	return ActionSupport.SUCCESS;
		
	}
	
	public Integer getStdid() {
		return stdid;
	}

	public void setStdid(Integer stdid) {
		this.stdid = stdid;
	}

	public String getStdname() {
		return stdname;
	}

	public void setStdname(String stdname) {
		this.stdname = stdname;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public Integer getAge() {
		return age;
	}

	public void setAge(Integer age) {
		this.age = age;
	}

	public List<Student> getRecords() {
		return records;
	}

	public void setRecords(List<Student> records) {
		this.records = records;
	}

	public Student getRecord() {
		return record;
	}

	public void setRecord(Student record) {
		this.record = record;
	}

	public String getResult() {
		return result;
	}

	public void setResult(String result) {
		this.result = result;
	}

	public String getMessage() {
		return message;
	}

	public void setMessage(String message) {
		this.message = message;
	}

	public DaoImple getDao() {
		return dao;
	}

	public void setDao(DaoImple dao) {
		this.dao = dao;
	}

	public static long getSerialversionuid() {
		return serialVersionUID;
	}
	
}
