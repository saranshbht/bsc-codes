/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package beans;

import java.beans.IntrospectionException;
import java.beans.MethodDescriptor;
import java.beans.PropertyDescriptor;
import java.beans.SimpleBeanInfo;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author saransh
 */
public class EmployeeBeanInfo extends SimpleBeanInfo {
    public PropertyDescriptor[] getPropertyDescriptors() {
        try {
            PropertyDescriptor pd1 = new PropertyDescriptor("empId", Employee.class);
            PropertyDescriptor pd2 = new PropertyDescriptor("name", Employee.class);
            PropertyDescriptor pd3 = new PropertyDescriptor("address", Employee.class);
            PropertyDescriptor pd4 = new PropertyDescriptor("salary", Employee.class);
            return new PropertyDescriptor[]{pd1, pd2, pd3, pd4};
        } catch (IntrospectionException ex) {
            Logger.getLogger(EmployeeBeanInfo.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }
    
    
    public MethodDescriptor[] getMethodDescriptors() {
        try {
            MethodDescriptor md1 = new MethodDescriptor(Employee.class.getMethod("getEmpId"));
            MethodDescriptor md2 = new MethodDescriptor(Employee.class.getMethod("setName", String.class));
            MethodDescriptor md3 = new MethodDescriptor(Employee.class.getMethod("sum", int.class, int.class));
            MethodDescriptor md4 = new MethodDescriptor(Employee.class.getMethod("abc"));
            return new MethodDescriptor[]{md1, md2, md3, md4};
        } catch (NoSuchMethodException ex) {
            Logger.getLogger(EmployeeBeanInfo.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }
}