package com.alibaba.controllers;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HomeController {
	@RequestMapping("/hello")
	public String index() {
		return "Hello Docker！ 阿里巴巴Java Spring Boot2.5.x实战开发课程";
	}
}
