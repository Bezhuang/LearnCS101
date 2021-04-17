package com.alibaba;

import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
/**
  *《阿里巴巴Java Spring Boot 2.5开发实战课程》 
 * @author 徐雷 Frank Xu
 **/
@SpringBootApplication
public class Application implements CommandLineRunner {

 
	public static void main(String[] args) {
		SpringApplication.run(Application.class, args);
	}
    
	@Override
	public void run(String... arg0) throws Exception {
		// TODO Auto-generated method stub
		System.out.println("阿里巴巴Java Spring Boot2.5实战开发课程");
	}
	
}