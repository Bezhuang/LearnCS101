package com.alibaba;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import de.codecentric.boot.admin.server.config.EnableAdminServer;
@EnableAdminServer
@SpringBootApplication
public class JavaSpringCloud000AdminServerApplication {

	public static void main(String[] args) {
		SpringApplication.run(JavaSpringCloud000AdminServerApplication.class, args);
	}
}
