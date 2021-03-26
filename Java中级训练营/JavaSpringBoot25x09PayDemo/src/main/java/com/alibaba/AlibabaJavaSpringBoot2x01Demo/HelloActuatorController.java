package com.alibaba.AlibabaJavaSpringBoot2x01Demo;

import java.util.Date;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HelloActuatorController {
    @RequestMapping(value = "/hello")
    public String helloActuator() {
        return "Hello Java Spring Boot 2.5 Actuator:" + new Date();
    }
}
