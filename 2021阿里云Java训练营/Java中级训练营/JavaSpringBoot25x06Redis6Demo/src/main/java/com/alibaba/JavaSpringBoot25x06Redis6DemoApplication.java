package com.alibaba;

import java.util.Arrays;

import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;
/**
 * 《阿里巴巴Java Spring Boot 2.5开发实战课程》  
*   徐雷 (侠客)
*  https://developer.aliyun.com/learning/course/71?spm=a2c6h.21254954.0.0.5b0559074wqwvx
**/
@SpringBootApplication
public class JavaSpringBoot25x06Redis6DemoApplication implements CommandLineRunner {

	public static void main(String[] args) {
		ApplicationContext ctx = SpringApplication.run(JavaSpringBoot25x06Redis6DemoApplication.class, args);
        //日志打印系统自动化配置的bean
        String[] beanNames = ctx.getBeanDefinitionNames();
        Arrays.sort(beanNames);
        for (String beanName : beanNames) {
            System.out.println("Spring Boot2.5x实战Redis："+beanName);
        }
	}
    
	@Override
	public void run(String... arg0) throws Exception {
		// TODO Auto-generated method stub
		System.out.println("阿里巴巴Java Spring Boot2.5x实战开发课程");
	}

}
