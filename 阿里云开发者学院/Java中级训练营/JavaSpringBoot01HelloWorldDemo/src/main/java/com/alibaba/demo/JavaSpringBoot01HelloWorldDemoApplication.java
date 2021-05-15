package com.alibaba.demo;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
@RestController
@SpringBootApplication
public class JavaSpringBoot01HelloWorldDemoApplication {

    public static void main(String[] args) {    	
        SpringApplication.run(JavaSpringBoot01HelloWorldDemoApplication.class, args);
    }
    //公开http接口
    @RequestMapping("/hello")
    public String hello() {
    	String s = "Hello Spring Boot";
    	return s;
    }
}
