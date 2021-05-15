package com.alibaba;

import java.util.Arrays;

import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
/**
 * 《阿里Java Spring Boot 2.5x开发实战课程》 
 * @author Frank 侠客
 **/
@SpringBootApplication
@Configuration
@ComponentScan
public class Application implements CommandLineRunner {

	public static void main(String[] args) {
		ApplicationContext ctx = SpringApplication.run(Application.class, args);
        //日志打印系统自动化配置的bean
        String[] beanNames = ctx.getBeanDefinitionNames();
        Arrays.sort(beanNames);
        for (String beanName : beanNames) {
            System.out.println("Spring Boot2.5自动化配置："+beanName);
        }
	}
    
	@Override
	public void run(String... arg0) throws Exception {
		// TODO Auto-generated method stub
		System.out.println("阿里巴巴Java Spring Boot2.5实战开发课程");
	}
	
}