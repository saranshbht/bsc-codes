/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package beans;

/**
 *
 * @author saransh
 */
public class Employee implements java.io.Serializable {
    private int empId;
    private String name;
    private String[] dependents;
    private String address;
    private String department;
    private int salary;

    public int getEmpId() {
        return empId;
    }

    public void setEmpId(int empId) {
        this.empId = empId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String[] getDependents() {
        return dependents;
    }

    public void setDependents(String[] dependents) {
        this.dependents = dependents;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    public int getSalary() {
        return salary;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }
    public int sum(int a, int b){
        return a + b;
    }
    public void abc(){
        System.out.println("Hello World");
    }
}
