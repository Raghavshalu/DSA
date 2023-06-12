package model;

public class Student implements java.io.Serializable{
	private static final long serialVersionUID = 1L;
	Integer stdid;
	String stdname;
	String email;
	Integer age;
	public Student() {
		// TODO Auto-generated constructor stub
	}
//	
	public Integer getStdid() {
		return stdid;
	}
	public Student(Integer stdid, String stdname, String email, Integer age) {
		this.stdid = stdid;
		this.stdname = stdname;
		this.email = email;
		this.age = age;
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
	public static long getSerialversionuid() {
		return serialVersionUID;
	}
}
