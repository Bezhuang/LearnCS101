package com.alibaba.demo;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class welcome {
    @RequestMapping("/hello")
    public String Hello()
    {
        return "Hello Spring Boot 25x";
    }
}
