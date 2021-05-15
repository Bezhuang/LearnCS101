package com.alibaba;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
@RestController
@SpringBootApplication
public class JavaSpringCloud000AdminClientDemoApplication {

	public static void main(String[] args) {
		SpringApplication.run(JavaSpringCloud000AdminClientDemoApplication.class, args);
	}
	@RequestMapping("/hello")
	public String hello() {
		return "Hello Spring Cloud OrderMicorservice 1";
	}
}
