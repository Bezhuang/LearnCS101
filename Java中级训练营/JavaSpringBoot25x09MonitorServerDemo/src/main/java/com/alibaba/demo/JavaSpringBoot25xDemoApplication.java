package com.alibaba.demo;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import de.codecentric.boot.admin.server.config.EnableAdminServer;
@EnableAdminServer
@SpringBootApplication
public class JavaSpringBoot25xDemoApplication {

	public static void main(String[] args) {
		SpringApplication.run(JavaSpringBoot25xDemoApplication.class, args);
	}

}
