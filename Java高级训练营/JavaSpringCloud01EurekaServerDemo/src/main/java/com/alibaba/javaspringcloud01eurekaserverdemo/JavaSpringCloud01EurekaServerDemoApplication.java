package com.alibaba.javaspringcloud01eurekaserverdemo;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.netflix.eureka.server.EnableEurekaServer;

@EnableEurekaServer
@SpringBootApplication
public class JavaSpringCloud01EurekaServerDemoApplication {

    public static void main(String[] args) {
        SpringApplication.run(JavaSpringCloud01EurekaServerDemoApplication.class, args);
    }

}
