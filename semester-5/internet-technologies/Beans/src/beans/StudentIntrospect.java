/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package beans;

import java.beans.BeanInfo;
import java.beans.IntrospectionException;
import java.beans.Introspector;
import java.beans.MethodDescriptor;
import java.beans.PropertyDescriptor;

/**
 *
 * @author saransh
 */
public class StudentIntrospect {
    public static void main(String[] args) throws ClassNotFoundException, IntrospectionException {
        Class stud = Class.forName("beans.Student");
        BeanInfo bean = Introspector.getBeanInfo(stud);
        PropertyDescriptor[] propertyDescriptor = bean.getPropertyDescriptors();
        System.out.println("Properties");
        for(PropertyDescriptor pd : propertyDescriptor){
            System.out.println(pd.getName());
        }
        MethodDescriptor[] methodDescriptor = bean.getMethodDescriptors();
        System.out.println("\n\nMethods:");
        for(MethodDescriptor md : methodDescriptor){
            System.out.println(md.getName());
        }
    }
}
